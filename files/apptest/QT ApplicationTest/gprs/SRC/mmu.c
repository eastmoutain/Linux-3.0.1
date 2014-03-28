/************************************************ 
  NAME    : MMU.C
  DESC	  :
  Revision: 2002.2.28 ver 0.0
 ************************************************/

#include "../inc/def.h"
#include "../inc/config.h"
#include "../inc/board.h"
#include "../inc/utils.h"
#include "../inc/slib.h"
#include "../inc/mmu.h"

// 1) Only the section table is used. 
// 2) The cachable/non-cachable area can be changed by MMT_DEFAULT value.
//    The section size is 1MB.

void MMU_DCacheCleanAll(void)
{
	int i, j;
	
	//If write-back is used,the DCache should be cleared.
	for(i=0; i<64; i++)
		for(j=0; j<8; j++)
			MMU_CleanDCacheIndex((i<<26)|(j<<5));
	__asm {
		mov	r0, #0
		mcr	p15, 0, r0, c7, c10, 4	// drain WB
	}
}

void MMU_DCacheCleanInvalidateAll(void)
{
	int i, j;
	
	//If write-back is used,the DCache should be cleared.
	for(i=0; i<64; i++)
		for(j=0; j<8; j++)
			MMU_CleanInvalidateDCacheIndex((i<<26)|(j<<5));
	__asm {
		mov	r0, #0
		mcr	p15, 0, r0, c7, c10, 4	// drain WB
	}
}

void MMU_Init(MMU_Table table[])
{
	//========================== IMPORTANT NOTE =========================
	//The current stack and code area can't be re-mapped in this routine.
	//If you want memory map mapped freely, your own sophiscated MMU
	//initialization code is needed.
	//===================================================================

	MMU_DisableDCache();
	MMU_DisableICache();
		MMU_InvalidateDCache();	//invalidate data cache all
	MMU_DCacheCleanInvalidateAll();
	MMU_InvalidateICache();
	
	#if 0
	//To complete MMU_Init() fast, Icache may be turned on here.
	MMU_EnableICache(); 
	#endif
    
	MMU_DisableMMU();
	MMU_InvalidateTLB();
	
	for(; table->vEnd; table++)
		MMU_SetMTT(table->vStart, table->vEnd, table->pStart, table->attr);
	
	MMU_SetTTBase(_MMUTT_STARTADDRESS);
	MMU_SetDomain(0x55555550|DOMAIN1_ATTR|DOMAIN0_ATTR); 
	//DOMAIN1: no_access, DOMAIN0,2~15=client(AP is checked)
	MMU_SetProcessId(0x0);
	MMU_EnableAlignFault();
	
	MMU_EnableMMU();
	MMU_EnableICache();
	MMU_EnableDCache(); //DCache should be turned on after MMU is turned on.
}    

// attr=RW_CB,RW_CNB,RW_NCNB,RW_FAULT
void ChangeRomCacheStatus(int attr)
{
    int i,j;
    MMU_DisableDCache();
    MMU_DisableICache();
    //If write-back is used,the DCache should be cleared.
    for(i=0;i<64;i++)
    	for(j=0;j<8;j++)
    	    MMU_CleanInvalidateDCacheIndex((i<<26)|(j<<5));
    MMU_InvalidateICache();
    MMU_DisableMMU();
    MMU_InvalidateTLB();
    MMU_SetMTT(0x00000000,0x07f00000,0x00000000,attr);	//bank0
    MMU_SetMTT(0x08000000,0x0ff00000,0x08000000,attr);	//bank1
    MMU_EnableMMU();
    MMU_EnableICache();
    MMU_EnableDCache();
}    

void MMU_SetMTT(U32 vaddrStart, U32 vaddrEnd, U32 paddrStart, int attr)
{
	U32 *pTT;
	int i, nSec;
	
	pTT = (U32 *)_MMUTT_STARTADDRESS+(vaddrStart>>20);
	nSec = (vaddrEnd>>20)-(vaddrStart>>20);
	for(i=0; i<=nSec; i++)
		*pTT++ = attr|(((paddrStart>>20)+i)<<20);
}

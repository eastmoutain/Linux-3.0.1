#ifndef __CODEC_ENGINE_H
#define __CODEC_ENGINE_H

#include "AvWrapper.h"
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SSBSIPMFCDEC_NONE	-1

enum {
	NONE = -1,
	VIDEO = 0x110,
	AUDIO = 0x119,
};

typedef struct AudioParam
{
	int m_bAudioFreq;
	int m_bAudioChannel;
	int m_bAudioFormat;
}AudioParam;

typedef struct VideoParam
{
	int m_bVideoWidth;
	int m_bVideoHeight;
	enum PixelFormat m_bVideoPixFormat;
	int m_bVideoBitRate;
	int m_bVideoFrameRate;
}VideoParam;

typedef struct PacketInfo
{
	int size;
	
	double pts;
	double dts;

	int64_t apts;
	int64_t adts;

	int index;

	int type;

}PacketCtx;

//�õ����뼶�ĵ�ǰ����ʱ��
int64_t GetTimeHere();

//��ú��뼶�ľ�ȷ��ʱ,ע��ʹ��usʱ��us��С���ܳ���1000
int usSleep(long us);


/*************************************[��Ƶ����ģ��]************************************/

//�ڲ������������е��ʼ���г�ʼ��
void InitDriver();

//�����ļ���ֱ�ӷ��ض�ý�����о��
int CreateOcxByFile(const char *filename);
//��ȡ��Ч����Ƶ��������������Ƶ����Ƶ
void *ExtractStream();

int GetFrameSize(enum PixelFormat pixfmt,int width,int height);

//�������ˣ�ʹ��double���������Ƿ�ֱ�������ǰ֡���뻺��
int SeekPositon(double pts,int flush);

//�ж��Ƿ񵽴��ļ�ĩβ
int GetEof();
//�ж��Ƿ���ִ���
int GetError();

//�ж��Ƿ������Ƶ
int IsExistAuido();
//�ж��Ƿ�������Ƶ
int IsExistVideo();

//����ռ䣬�����ڴ���Ƭ
void *UseAlloc(int size);

//�ͷſռ�
void FreeAlloc(void *ptr);

//�Ƿ����Ӳ������
int IsHardWareAccel();

//��ȡ��Ƶ����
AudioParam GetOcxAudioParam();
//��ȡ��Ƶ����
VideoParam GetOcxVideoParam();

//�����Ƶ����Ƶ����
void FlushBuffers(int type);

//�����Ƶ�ļ�����ʱ��
double GetDuration();

//��Ƶ����ģ��,��ֱ�ӻ�ý�������YUV��ʽ
void *DecodeVideoYUVStream(void *pkt,long *size);
//��Ƶ����ģ��
void *DecodeAudioStream(void *pkt,long *size);

//��ȡ����Ϣ
PacketCtx GetPacketCtx(void *pkt);

//�ֱ�������ԣ�NONE��AUDIO��VIDEO
int GetPacketAttr(void *pkt);

//����һ����
void DestroyPacket(void* pkt);

//��û�׼ʱ��
double GetTimeBase(int type);

//��ʾ��Ϣ
void PrintMessage(const char *fmt,...);

//�ر�����Ƶ�ļ���
void CloseOcxByOCX();

#ifdef __cplusplus
}
#endif

#endif

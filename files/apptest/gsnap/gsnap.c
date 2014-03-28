/*
 * File:    gsnap.c
 * Author:  Li XianJing <xianjimli@hotmail.com>
 * Brief:   snap the linux mobile device screen.
 *
 * Copyright (c) 2009  Li XianJing <xianjimli@hotmail.com>
 *
 * Licensed under the Academic Free License version 2.1
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/*
 * History:
 * ================================================================
 * 2009-08-20 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <linux/fb.h>
#include <linux/kd.h>
#include "jpeglib.h"

struct FB 
{
	int fd;
	unsigned size;
	unsigned short *bits;
	struct fb_fix_screeninfo fi;
	struct fb_var_screeninfo vi;
};

#define fb_width(fb) ((fb)->vi.xres)
#define fb_height(fb) ((fb)->vi.yres)
#define fb_size(fb) ((fb)->vi.xres * (fb)->vi.yres * 2)

static int fb_open(struct FB *fb, const char* fbfilename)
{
	fb->fd = open(fbfilename, O_RDWR);
	if (fb->fd < 0)
	{
		fprintf(stderr, "can't open %s\n", fbfilename);
		return -1;
	}

	if (ioctl(fb->fd, FBIOGET_FSCREENINFO, &fb->fi) < 0)
		goto fail;
	if (ioctl(fb->fd, FBIOGET_VSCREENINFO, &fb->vi) < 0)
		goto fail;

	fb->bits = mmap(0, fb_size(fb), PROT_READ | PROT_WRITE, 
					MAP_SHARED, fb->fd, 0);
	if (fb->bits == MAP_FAILED)
		goto fail;

	return 0;
fail:
	printf("%s is not a framebuffer.\n", fbfilename);
	close(fb->fd);

	return -1;
}

static void fb_close(struct FB *fb)
{
	munmap(fb->bits, fb_size(fb));
	close(fb->fd);
}

static int snap(const char * filename, int quality, struct FB* fb)
{
	int row_stride = 0; 
	FILE * outfile = NULL;
	JSAMPROW row_pointer[1] = {0};
	struct jpeg_error_mgr jerr = {0};
	struct jpeg_compress_struct cinfo = {0};

	cinfo.err = jpeg_std_error(&jerr);
	jpeg_create_compress(&cinfo);

	if ((outfile = fopen(filename, "wb+")) == NULL) 
	{
		fprintf(stderr, "can't open %s\n", filename);

		return -1;
	}

	jpeg_stdio_dest(&cinfo, outfile);
	cinfo.image_width = fb_width(fb);
	cinfo.image_height = fb_height(fb);
	cinfo.input_components = 3;
	cinfo.in_color_space = JCS_RGB;
	jpeg_set_defaults(&cinfo);
	jpeg_set_quality(&cinfo, quality, TRUE);
	jpeg_start_compress(&cinfo, TRUE);

	row_stride = fb_width(fb) * 2;
	JSAMPLE* image_buffer = malloc(3 * fb_width(fb));

	while (cinfo.next_scanline < cinfo.image_height) 
	{
		int i = 0;
		unsigned short* line = fb->bits + cinfo.next_scanline * fb_width(fb);
		for(i = 0; i < fb_width(fb); i++)
		{
			int offset = i * 3;
			unsigned short color = line[i];
			unsigned char r = ((color >> 11) & 0xff) << 3;
			unsigned char g = ((color >> 5) & 0xff)  << 2;
			unsigned char b = (color & 0xff )<< 3;
			image_buffer[offset]     = r;
			image_buffer[offset + 1] = g;
			image_buffer[offset + 2] = b;
		}

		row_pointer[0] = image_buffer;
		(void) jpeg_write_scanlines(&cinfo, row_pointer, 1);
	}

	jpeg_finish_compress(&cinfo);
	fclose(outfile);

	jpeg_destroy_compress(&cinfo);

	return 0;
}

int main(int argc, char* argv[])
{
	struct FB fb = {0};
	const char* filename   = NULL;
	const char* fbfilename = NULL;

	if(argc != 3)
	{	
		printf("\nusage: %s [jpeg] [framebuffer]\n", argv[0]);
		printf("-----------------------------------------\n");
		printf("Powered by forlinx\n");
		return 0;
	}

	filename   = argv[1];
	fbfilename = argv[2];
	if (fb_open(&fb, fbfilename) == 0)
	{
		snap(filename, 100, &fb);
		fb_close(&fb);
	}

	return 0;
}

/*
 * Texture Filtering
 * Version:  1.0
 *
 * Copyright (C) 2007  Hiroshi Morii   All Rights Reserved.
 * Email koolsmoky(at)users.sourceforge.net
 * Web   http://www.3dfxzone.it/koolsmoky
 *
 * this is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * this is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Make; see the file COPYING.  If not, write to
 * the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <memory.h>
#include <stdlib.h>
#include "Ext_TxFilter.h"

extern "C" boolean txfilter_init(int maxwidth, int maxheight, int maxbpp, int options, int cachesize, const char *path, const char *ident, dispInfoFuncExt callback);
extern "C" void txfilter_shutdown(void);
extern "C" boolean txfilter(unsigned char *src, int srcwidth, int srcheight, unsigned short srcformat, uint64 g64crc, GHQTexInfo *info);
extern "C" boolean txfilter_hirestex(uint64 g64crc, uint64 r_crc64, unsigned short *palette, GHQTexInfo *info);
extern "C" uint64 txfilter_checksum(unsigned char *src, int width, int height, int size, int rowStride, unsigned char *palette);
extern "C" boolean txfilter_dmptx(unsigned char *src, int width, int height, int rowStridePixel, unsigned short gfmt, unsigned short n64fmt, uint64 r_crc64);
extern "C" boolean txfilter_reloadhirestex();

void ext_ghq_shutdown(void)
{
    txfilter_shutdown();
}

boolean ext_ghq_init(int maxwidth, int maxheight, int maxbpp, int options, int cachesize,
    const char *path, const char *ident, dispInfoFuncExt callback)
{
    return txfilter_init(maxwidth, maxheight, maxbpp, options, cachesize, path, ident, callback);
}

boolean ext_ghq_txfilter(unsigned char *src, int srcwidth, int srcheight, unsigned short srcformat,
    uint64 g64crc, GHQTexInfo *info)
{
    return txfilter(src, srcwidth, srcheight, srcformat, g64crc, info);;
}

boolean ext_ghq_hirestex(uint64 g64crc, uint64 r_crc64, unsigned short *palette, GHQTexInfo *info)
{
    boolean ret = txfilter_hirestex(g64crc, r_crc64, palette, info);
    return ret;
}

uint64 ext_ghq_checksum(unsigned char *src, int width, int height, int size, int rowStride, unsigned char *palette)
{
    uint64 ret = txfilter_checksum(src, width, height, size, rowStride, palette);
    return ret;
}

boolean ext_ghq_dmptx(unsigned char *src, int width, int height, int rowStridePixel, unsigned short gfmt, unsigned short n64fmt, uint64 r_crc64)
{
    boolean ret = txfilter_dmptx(src, width, height, rowStridePixel, gfmt, n64fmt, r_crc64);
    return ret;
}

boolean ext_ghq_reloadhirestex()
{
    boolean ret = txfilter_reloadhirestex();

    return ret;
}
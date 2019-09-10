/*
 * OpenBOR - http://www.LavaLit.com
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in OpenBOR root for details.
 *
 * Copyright (c) 2004 - 2011 OpenBOR Team
 */

#ifndef        VGA_H
#define        VGA_H
#ifdef __cplusplus
#define PROTOHEADER extern "C"
#else
#define PROTOHEADER
#endif

// Set VGA-type palette
void vga_setpalette(unsigned char *palette);

void vga_set_color_correction(int gm, int br);

PROTOHEADER void vga_wait();

#endif

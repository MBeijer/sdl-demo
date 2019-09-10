/*
 * OpenBOR - http://www.LavaLit.com
 * -----------------------------------------------------------------------
 * Licensed under the BSD license, see LICENSE in OpenBOR root for details.
 *
 * Copyright (c) 2004 - 2011 OpenBOR Team
 */

#ifndef VIDEO_H
#define VIDEO_H
#ifdef __cplusplus
#define PROTOHEADER extern "C"
#else
#define PROTOHEADER
#endif

#include <stdint.h>

typedef struct SDL_Surface {
//	Uint32 flags;				/**< Read-only */
//	SDL_PixelFormat *format;		/**< Read-only */
	int w, h;                /**< Read-only */
//	Uint16 pitch;				/**< Read-only */
	void *pixels;                /**< Read-write */
	int offset;                /**< Private */

	/** Hardware-specific surface info */
//	struct private_hwdata *hwdata;

	/** clipping information */
//	SDL_Rect clip_rect;			/**< Read-only */
//	Uint32 unused1;				/**< for binary compatibility */

	/** Allow recursive locks */
//	Uint32 locked;				/**< Private */

	/** info for fast blit mapping to other surfaces */
//	struct SDL_BlitMap *map;		/**< Private */

	/** format version, bumped at every change to invalidate blit maps */
//	unsigned int format_version;		/**< Private */

	/** Reference count -- used when freeing surface */
//	int refcount;				/**< Read-mostly */} SDL_Surface;
} SDL_Surface;

typedef struct SDL_Color {
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t unused;
} SDL_Color;
#define SDL_Colour SDL_Color

typedef struct SDL_Rect {
	int16_t x, y;
	uint16_t w, h;
} SDL_Rect;

// Frees all VESA shit when returning to textmode
int video_set_mode();
PROTOHEADER int SDL_Flip(SDL_Surface *);
PROTOHEADER int SDL_SetColors(SDL_Surface *surface, SDL_Color *colors, int firstcolor, int ncolors);
PROTOHEADER void SDL_Delay(uint32_t ms);
PROTOHEADER void putpixel(unsigned x, unsigned y, int color, SDL_Surface * screen);

void video_clearscreen();
void video_fullscreen_flip();
void video_stretch(int);
PROTOHEADER int SDL_Init(uint32_t flags);
PROTOHEADER char * SDL_GetError(void);
PROTOHEADER int SDL_ShowCursor(int toggle);
PROTOHEADER void SDL_Quit(void);

#define SDL_SRCCOLORKEY	0x00001000	/**< Blit uses a source color key */

#define SDL_LOGPAL 0x01
#define SDL_PHYSPAL 0x02

#define	SDL_INIT_TIMER		0x00000001
#define SDL_INIT_AUDIO		0x00000010
#define SDL_INIT_VIDEO		0x00000020
#define SDL_INIT_CDROM		0x00000100
#define SDL_INIT_JOYSTICK	0x00000200
#define SDL_INIT_NOPARACHUTE	0x00100000	/**< Don't catch fatal signals */
#define SDL_INIT_EVENTTHREAD	0x01000000	/**< Not supported on all OS's */
#define SDL_INIT_EVERYTHING	0x0000FFFF

/** Available for SDL_CreateRGBSurface() or SDL_SetVideoMode() */
/*@{*/
#define SDL_SWSURFACE	0x00000000	/**< Surface is in system memory */
#define SDL_HWSURFACE	0x00000001	/**< Surface is in video memory */
#define SDL_ASYNCBLIT	0x00000004	/**< Use asynchronous blits if possible */
/*@}*/

/** Available for SDL_SetVideoMode() */
/*@{*/
#define SDL_ANYFORMAT	0x10000000	/**< Allow any video depth/pixel-format */
#define SDL_HWPALETTE	0x20000000	/**< Surface has exclusive palette */
#define SDL_DOUBLEBUF	0x40000000	/**< Set up double-buffered video mode */
#define SDL_FULLSCREEN	0x80000000	/**< Surface is a full screen display */
#define SDL_OPENGL      0x00000002      /**< Create an OpenGL rendering context */
#define SDL_OPENGLBLIT	0x0000000A	/**< Create an OpenGL rendering context and use it for blitting */
#define SDL_RESIZABLE	0x00000010	/**< This video mode may be resized */
#define SDL_NOFRAME	0x00000020	/**< No window caption or edge frame */
/*@}*/

PROTOHEADER void SDL_FreeSurface(SDL_Surface *surface);

PROTOHEADER int SDL_SetColorKey(SDL_Surface *surface, uint32_t flag, uint32_t key);

PROTOHEADER int SDL_BlitSurface(SDL_Surface *src, SDL_Rect *srcrect, SDL_Surface *dst, SDL_Rect *dstrect);

PROTOHEADER int SDL_FillRect(SDL_Surface *dst, SDL_Rect *dstrect, uint32_t color);

PROTOHEADER int SDL_SetPalette(SDL_Surface *surface, int flags, SDL_Color *colors, int firstcolor, int ncolors);

PROTOHEADER SDL_Surface * SDL_SetVideoMode(int width, int height, int bpp, uint32_t flags);

PROTOHEADER SDL_Surface * SDL_CreateRGBSurface(uint32_t flags, int width, int height, int depth, uint32_t Rmask, uint32_t Gmask, uint32_t Bmask, uint32_t Amask);

PROTOHEADER SDL_Surface * SDL_CreateRGBSurfaceFrom(void *pixels, int width, int height, int depth, int pitch,uint32_t Rmask, uint32_t Gmask, uint32_t Bmask, uint32_t Amask);

#endif

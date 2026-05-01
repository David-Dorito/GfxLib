#ifndef GFXLIB_H_
#define GFXLIB_H_

#include <stdint.h>

typedef struct GfxLib_Font {
	const uint8_t** CharBitmaps;
	uint16_t		CharCount;
	uint16_t		CharWidth;
	uint16_t		CharHeight;
	uint8_t			CharSpacing;
	char			StartChar;
} GfxLib_Font;

typedef struct GfxLib_DisplayDrivers {
	void (*DrawPixel)(void* self, uint16_t posX, uint16_t posY, uint32_t color);
} GfxLib_DisplayDrivers;

typedef struct GfxLib_Handle {
	void*				   Display;
	GfxLib_DisplayDrivers* Drivers;
} GfxLib_Handle;

typedef struct GfxLib_Point {
	uint16_t X;
	uint16_t Y;
} GfxLib_Point;

typedef struct GfxLib_FontChar {
	GfxLib_Point Pos;
	GfxLib_Font* Font;
	char		 Char;
} GfxLib_FontChar;

typedef struct GfxLib_FontString {
	GfxLib_Point Pos;
	GfxLib_Font* Font;
	char*		 String;
} GfxLib_FontString;

typedef struct GfxLib_Line {
	GfxLib_Point P1;
	GfxLib_Point P2;
} GfxLib_Line;

typedef struct GfxLib_Triang {
	GfxLib_Point P1;
	GfxLib_Point P2;
	GfxLib_Point P3;
} GfxLib_Triang;

typedef struct GfxLib_Rect {
	GfxLib_Point Pos;
	uint16_t	 Width;
	uint16_t	 Height;
} GfxLib_Rect;

typedef struct GfxLib_Circ {
	GfxLib_Point Pos;
	uint16_t	 Radius;
} GfxLib_Circ;

void GfxLib_DrawChar(GfxLib_Handle* self, GfxLib_FontChar fontChar, uint32_t color);
void GfxLib_DrawString(GfxLib_Handle* self, GfxLib_FontString fontString, uint32_t color);
void GfxLib_DrawLine(GfxLib_Handle* self, GfxLib_Line line, uint32_t color);
void GfxLib_DrawTriang(GfxLib_Handle* self, GfxLib_Triang triangle, uint32_t color);
void GfxLib_DrawRect(GfxLib_Handle* self, GfxLib_Rect rectangle, uint32_t color);
void GfxLib_DrawRectFromPoints(GfxLib_Handle* self, GfxLib_Point p1, GfxLib_Point p2, uint32_t color);
void GfxLib_DrawCirc(GfxLib_Handle* self, GfxLib_Circ circle, uint32_t color);

#endif

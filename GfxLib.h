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

typedef struct GfxLib_Vector2 {
	uint16_t X;
	uint16_t Y;
} GfxLib_Vector2;

void GfxLib_DrawChar(GfxLib_Handle* self, GfxLib_Vector2 pos, uint32_t color, GfxLib_Font* pFont,
					 char character);
void GfxLib_DrawString(GfxLib_Handle* self, GfxLib_Vector2 pos, uint32_t color, GfxLib_Font* font,
					   char* string);
void GfxLib_DrawLine(GfxLib_Handle* self, GfxLib_Vector2 p1, GfxLib_Vector2 p2, uint32_t color);
void GfxLib_DrawTriang(GfxLib_Handle* self, GfxLib_Vector2 p1, GfxLib_Vector2 p2, GfxLib_Vector2 p3,
					   uint32_t color);
void GfxLib_DrawRect(GfxLib_Handle* self, GfxLib_Vector2 p1, GfxLib_Vector2 p2, uint32_t color);
void GfxLib_DrawCircle(GfxLib_Handle* self, GfxLib_Vector2 pos, uint32_t color, uint16_t radius);

#endif

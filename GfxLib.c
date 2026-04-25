#include "GfxLib.h"

typedef int32_t	 i32;
typedef int16_t	 i16;
typedef int8_t	 i8;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t	 u8;

void GfxLib_DrawChar(GfxLib_Handle* pGfxLibHandle, GfxLib_Vector2 pos, uint32_t color,
					 GfxLib_Font* pFont, char character) {
	for (u32 i = 0; i < pFont->CharHeight * pFont->CharWidth; i++) {
		u16 col = i % pFont->CharWidth;
		u16 row = i / pFont->CharWidth;
		u32 pixelIndex = col + row * pFont->CharWidth;
		u8	bitOffset = 7 - (pixelIndex % 8);
		u8	currentPixelActive =
			(pFont->ppCharBitmaps[character - pFont->StartChar][pixelIndex / 8] >> bitOffset) & 1;
		if (currentPixelActive)
			pGfxLibHandle->pTransport->DrawPixelFunc(pGfxLibHandle->pDisplayHandle, pos.X + col,
													 pos.Y + row, color);
	}
}

void GfxLib_DrawString(GfxLib_Handle* pGfxLibHandle, GfxLib_Vector2 pos, uint32_t color,
					   GfxLib_Font* pFont, char* string) {
	for (u16 i = 0; string[i] != '\0'; i++)
		GfxLib_DrawChar(pGfxLibHandle,
						(GfxLib_Vector2){pos.X + i * (pFont->CharWidth + pFont->CharSpacing), pos.Y},
						color, pFont, string[i]);
}

void GfxLib_DrawLine(GfxLib_Handle* pGfxLibHandle, GfxLib_Vector2 p1, GfxLib_Vector2 p2,
					 uint32_t color) {
}

void GfxLib_DrawTriang(GfxLib_Handle* pGfxLibHandle, GfxLib_Vector2 p1, GfxLib_Vector2 p2,
					   GfxLib_Vector2 p3, uint32_t color) {
}

void GfxLib_DrawRect(GfxLib_Handle* pGfxLibHandle, GfxLib_Vector2 p1, GfxLib_Vector2 p2,
					 uint32_t color) {
}

void GfxLib_DrawCircle(GfxLib_Handle* pGfxLibHandle, GfxLib_Vector2 pos, uint32_t color,
					   uint16_t radius) {
}

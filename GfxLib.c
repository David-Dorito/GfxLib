#include "GfxLib.h"

void GfxLib_DrawChar(GfxLib_Handle* pGfxLibHandle, GfxLib_Vector2 pos, uint32_t color,
					 GfxLib_Font* pFont, char character) {
	for (uint32_t i = 0; i < pFont->CharHeight * pFont->CharWidth; i++) {
		uint16_t col = i % pFont->CharWidth;
		uint16_t row = i / pFont->CharWidth;
		uint32_t pixelIndex = col + row * pFont->CharWidth;
		uint8_t	 bitOffset = 7 - (pixelIndex % 8);
		uint8_t	 currentPixelActive =
			(pFont->ppCharBitmaps[character - pFont->StartChar][pixelIndex / 8] >> bitOffset) & 1;
		if (currentPixelActive)
			pGfxLibHandle->pTransport->DrawPixelFunc(pGfxLibHandle->pDisplay, pos.X + col, pos.Y + row,
													 color);
	}
}

void GfxLib_DrawString(GfxLib_Handle* pGfxLibHandle, GfxLib_Vector2 pos, uint32_t color,
					   GfxLib_Font* pFont, char* string) {
	for (uint16_t i = 0; string[i] != '\0'; i++)
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

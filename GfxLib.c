#include "GfxLib.h"

void GfxLib_DrawChar(GfxLib_Handle* self, GfxLib_Vector2 pos, uint32_t color, GfxLib_Font* font,
					 char character) {
	for (uint32_t i = 0; i < font->CharHeight * font->CharWidth; i++) {
		uint16_t col = i % font->CharWidth;
		uint16_t row = i / font->CharWidth;
		uint32_t pixelIndex = col + row * font->CharWidth;
		uint8_t	 bitOffset = 7 - (pixelIndex % 8);
		uint8_t	 currentPixelActive =
			(font->CharBitmaps[character - font->StartChar][pixelIndex / 8] >> bitOffset) & 1;
		if (currentPixelActive)
			self->Drivers->DrawPixel(self->Display, pos.X + col, pos.Y + row, color);
	}
}

void GfxLib_DrawString(GfxLib_Handle* self, GfxLib_Vector2 pos, uint32_t color, GfxLib_Font* font,
					   char* string) {
	for (uint16_t i = 0; string[i] != '\0'; i++)
		GfxLib_DrawChar(self, (GfxLib_Vector2){pos.X + i * (font->CharWidth + font->CharSpacing), pos.Y},
						color, font, string[i]);
}

void GfxLib_DrawLine(GfxLib_Handle* self, GfxLib_Vector2 p1, GfxLib_Vector2 p2, uint32_t color) {
}

void GfxLib_DrawTriang(GfxLib_Handle* self, GfxLib_Vector2 p1, GfxLib_Vector2 p2, GfxLib_Vector2 p3,
					   uint32_t color) {
}

void GfxLib_DrawRect(GfxLib_Handle* self, GfxLib_Vector2 p1, GfxLib_Vector2 p2, uint32_t color) {
}

void GfxLib_DrawCircle(GfxLib_Handle* self, GfxLib_Vector2 pos, uint32_t color, uint16_t radius) {
}

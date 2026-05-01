#include "GfxLib.h"

void GfxLib_DrawChar(GfxLib_Handle* self, GfxLib_FontChar fontChar, uint32_t color) {
	for (uint32_t i = 0; i < fontChar.Font->CharHeight * fontChar.Font->CharWidth; i++) {
		uint16_t col = i % fontChar.Font->CharWidth;
		uint16_t row = i / fontChar.Font->CharWidth;
		uint32_t pixelIndex = col + row * fontChar.Font->CharWidth;
		uint8_t	 bitOffset = 7 - (pixelIndex % 8);
		uint8_t	 currentPixelActive =
			(fontChar.Font->CharBitmaps[fontChar.Char - fontChar.Font->StartChar][pixelIndex / 8] >>
			 bitOffset) &
			1;
		if (currentPixelActive)
			self->Drivers->DrawPixel(self->Display, fontChar.Pos.X + col, fontChar.Pos.Y + row, color);
	}
}

void GfxLib_DrawString(GfxLib_Handle* self, GfxLib_FontString fontString, uint32_t color) {
	for (uint16_t i = 0; fontString.String[i] != '\0'; i++)
		GfxLib_DrawChar(self,
						(GfxLib_FontChar){.Pos = (GfxLib_Point){.X = fontString.Pos.X +
																	 i * (fontString.Font->CharWidth +
																		  fontString.Font->CharSpacing),
																.Y = fontString.Pos.Y},
										  .Font = fontString.Font,
										  .Char = fontString.String[i]},
						color);
}

void GfxLib_DrawLine(GfxLib_Handle* self, GfxLib_Line line, uint32_t color);
void GfxLib_DrawTriang(GfxLib_Handle* self, GfxLib_Triang triangle, uint32_t color);
void GfxLib_DrawRect(GfxLib_Handle* self, GfxLib_Rect rectangle, uint32_t color);
void GfxLib_DrawRectFromPoints(GfxLib_Handle* self, GfxLib_Point p1, GfxLib_Point p2, uint32_t color);
void GfxLib_DrawCirc(GfxLib_Handle* self, GfxLib_Circ circle, uint32_t color);

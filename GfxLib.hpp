#ifndef GFXLIB_HPP_
#define GFXLIB_HPP_

extern "C" {
#include "GfxLib.h"
}

class GfxLib {
  public:
	using Point = GfxLib_Point;
	using Font = GfxLib_Font;
	using DisplayDrivers = GfxLib_DisplayDrivers;
	using Handle = GfxLib_Handle;

	using FontChar = GfxLib_FontChar;
	using FontString = GfxLib_FontString;
	using Line = GfxLib_Line;
	using Triang = GfxLib_Triang;
	using Rect = GfxLib_Rect;
	using Circ = GfxLib_Circ;

	struct Config {
		void*			Display;
		DisplayDrivers* Drivers;
	};

	GfxLib(Config config);

	void DrawChar(FontChar fontChar, uint32_t color);
	void DrawString(FontString fontString, uint32_t color);
	void DrawLine(Line line, uint32_t color);
	void DrawTriang(Triang triangle, uint32_t color);
	void DrawRect(Rect rectangle, uint32_t color);
	void DrawRectFromPoints(Point p1, Point p2, uint32_t color);
	void DrawCirc(Circ circle, uint32_t color);

	static void DrawChar(void* self, FontChar fontChar, uint32_t color);
	static void DrawString(void* self, FontString fontString, uint32_t color);
	static void DrawLine(void* self, Line line, uint32_t color);
	static void DrawTriang(void* self, Triang triangle, uint32_t color);
	static void DrawRect(void* self, Rect rectangle, uint32_t color);
	static void DrawRectFromPoints(void* self, Point p1, Point p2, uint32_t color);
	static void DrawCirc(void* self, Circ circle, uint32_t color);

  private:
	Handle handle{};
};

#endif

#ifndef GFXLIB_HPP_
#define GFXLIB_HPP_

extern "C" {
#include "GfxLib.h"
}

class GfxLib {
  public:
	using Vector2 = GfxLib_Vector2;
	using Font = GfxLib_Font;
	using DisplayDrivers = GfxLib_DisplayDrivers;
	using Handle = GfxLib_Handle;

	struct Config {
		void*			Display;
		DisplayDrivers* Drivers;
	};

	GfxLib(Config config);

	void DrawChar(Vector2 pos, uint32_t color, Font* font, char character);
	void DrawString(Vector2 pos, uint32_t color, Font* font, char* string);
	void DrawLine(Vector2 p1, Vector2 p2, uint32_t color);
	void DrawTriang(Vector2 p1, Vector2 p2, Vector2 p3, uint32_t color);
	void DrawRect(Vector2 p1, Vector2 p2, uint32_t color);
	void DrawCircle(Vector2 pos, uint32_t color, uint16_t radius);

	static void DrawChar(void* self, Vector2 pos, uint32_t color, Font* font, char character);
	static void DrawString(void* self, Vector2 pos, uint32_t color, Font* font, char* string);
	static void DrawLine(void* self, Vector2 p1, Vector2 p2, uint32_t color);
	static void DrawTriang(void* self, Vector2 p1, Vector2 p2, Vector2 p3, uint32_t color);
	static void DrawRect(void* self, Vector2 p1, Vector2 p2, uint32_t color);
	static void DrawCircle(void* self, Vector2 pos, uint32_t color, uint16_t radius);

  private:
	Handle handle{};
};

#endif

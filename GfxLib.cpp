#include "GfxLib.hpp"
#include "GfxLib.h"

GfxLib::GfxLib(Config config) {
	this->handle.Display = config.Display;
	this->handle.Drivers = config.Drivers;
}

void GfxLib::DrawChar(Vector2 pos, uint32_t color, Font* font, char character) {
	GfxLib_DrawChar(&this->handle, pos, color, font, character);
}

void GfxLib::DrawString(Vector2 pos, uint32_t color, Font* font, char* string) {
	GfxLib_DrawString(&this->handle, pos, color, font, string);
}

void GfxLib::DrawLine(Vector2 p1, Vector2 p2, uint32_t color) {
	GfxLib_DrawLine(&this->handle, p1, p2, color);
}

void GfxLib::DrawTriang(Vector2 p1, Vector2 p2, Vector2 p3, uint32_t color) {
	GfxLib_DrawTriang(&this->handle, p1, p2, p3, color);
}

void GfxLib::DrawRect(Vector2 p1, Vector2 p2, uint32_t color) {
	GfxLib_DrawRect(&this->handle, p1, p2, color);
}

void GfxLib::DrawCircle(Vector2 pos, uint32_t color, uint16_t radius) {
	GfxLib_DrawCircle(&this->handle, pos, color, radius);
}

void GfxLib::DrawChar(void* self, Vector2 pos, uint32_t color, Font* font, char character) {
	GfxLib_DrawChar(&static_cast<GfxLib*>(self)->handle, pos, color, font, character);
}

void GfxLib::DrawString(void* self, Vector2 pos, uint32_t color, Font* font, char* string) {
	GfxLib_DrawString(&static_cast<GfxLib*>(self)->handle, pos, color, font, string);
}

void GfxLib::DrawLine(void* self, Vector2 p1, Vector2 p2, uint32_t color) {
	GfxLib_DrawLine(&static_cast<GfxLib*>(self)->handle, p1, p2, color);
}

void GfxLib::DrawTriang(void* self, Vector2 p1, Vector2 p2, Vector2 p3, uint32_t color) {
	GfxLib_DrawTriang(&static_cast<GfxLib*>(self)->handle, p1, p2, p3, color);
}

void GfxLib::DrawRect(void* self, Vector2 p1, Vector2 p2, uint32_t color) {
	GfxLib_DrawRect(&static_cast<GfxLib*>(self)->handle, p1, p2, color);
}

void GfxLib::DrawCircle(void* self, Vector2 pos, uint32_t color, uint16_t radius) {
	GfxLib_DrawCircle(&static_cast<GfxLib*>(self)->handle, pos, color, radius);
}

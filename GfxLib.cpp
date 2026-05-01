#include "GfxLib.hpp"
#include "GfxLib.h"

GfxLib::GfxLib(Config config) {
	this->handle.Display = config.Display;
	this->handle.Drivers = config.Drivers;
}

void GfxLib::DrawChar(FontChar fontChar, uint32_t color) {
	GfxLib_DrawChar(&this->handle, fontChar, color);
}

void GfxLib::DrawString(FontString fontString, uint32_t color) {
	GfxLib_DrawString(&this->handle, fontString, color);
}

void GfxLib::DrawLine(Line line, uint32_t color) {
	GfxLib_DrawLine(&this->handle, line, color);
}

void GfxLib::DrawTriang(Triang triangle, uint32_t color) {
	GfxLib_DrawTriang(&this->handle, triangle, color);
}

void GfxLib::DrawRect(Rect rectangle, uint32_t color) {
	GfxLib_DrawRect(&this->handle, rectangle, color);
}

void GfxLib::DrawRectFromPoints(Point p1, Point p2, uint32_t color) {
	GfxLib_DrawRectFromPoints(&this->handle, p1, p2, color);
}

void GfxLib::DrawCirc(Circ circle, uint32_t color) {
	GfxLib_DrawCirc(&this->handle, circle, color);
}

void GfxLib::DrawChar(void* self, FontChar fontChar, uint32_t color) {
	GfxLib_DrawChar(&static_cast<GfxLib*>(self)->handle, fontChar, color);
}

void GfxLib::DrawString(void* self, FontString fontString, uint32_t color) {
	GfxLib_DrawString(&static_cast<GfxLib*>(self)->handle, fontString, color);
}

void GfxLib::DrawLine(void* self, Line line, uint32_t color) {
	GfxLib_DrawLine(&static_cast<GfxLib*>(self)->handle, line, color);
}

void GfxLib::DrawTriang(void* self, Triang triangle, uint32_t color) {
	GfxLib_DrawTriang(&static_cast<GfxLib*>(self)->handle, triangle, color);
}

void GfxLib::DrawRect(void* self, Rect rectangle, uint32_t color) {
	GfxLib_DrawRect(&static_cast<GfxLib*>(self)->handle, rectangle, color);
}

void GfxLib::DrawRectFromPoints(void* self, Point p1, Point p2, uint32_t color) {
	GfxLib_DrawRectFromPoints(&static_cast<GfxLib*>(self)->handle, p1, p2, color);
}

void GfxLib::DrawCirc(void* self, Circ circle, uint32_t color) {
	GfxLib_DrawCirc(&static_cast<GfxLib*>(self)->handle, circle, color);
}

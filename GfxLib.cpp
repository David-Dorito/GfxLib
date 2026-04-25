#include "GfxLib.hpp"
#include "GfxLib.h"

GfxLib::GfxLib(Config config) {
	this->handle.pDisplayHandle = config.pDisplayHandle;
	this->handle.pTransport = config.pTransport;
}

void GfxLib::DrawChar(Vector2 pos, uint32_t color, Font* pFont, char character) {
	GfxLib_DrawChar(&this->handle, pos, color, pFont, character);
}

void GfxLib::DrawString(Vector2 pos, uint32_t color, Font* pFont, char* string) {
	GfxLib_DrawString(&this->handle, pos, color, pFont, string);
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

void GfxLib::DrawChar(void* pSelf, Vector2 pos, uint32_t color, Font* pFont, char character) {
	GfxLib_DrawChar(&static_cast<GfxLib*>(pSelf)->handle, pos, color, pFont, character);
}

void GfxLib::DrawString(void* pSelf, Vector2 pos, uint32_t color, Font* pFont, char* string) {
	GfxLib_DrawString(&static_cast<GfxLib*>(pSelf)->handle, pos, color, pFont, string);
}

void GfxLib::DrawLine(void* pSelf, Vector2 p1, Vector2 p2, uint32_t color) {
	GfxLib_DrawLine(&static_cast<GfxLib*>(pSelf)->handle, p1, p2, color);
}

void GfxLib::DrawTriang(void* pSelf, Vector2 p1, Vector2 p2, Vector2 p3, uint32_t color) {
	GfxLib_DrawTriang(&static_cast<GfxLib*>(pSelf)->handle, p1, p2, p3, color);
}

void GfxLib::DrawRect(void* pSelf, Vector2 p1, Vector2 p2, uint32_t color) {
	GfxLib_DrawRect(&static_cast<GfxLib*>(pSelf)->handle, p1, p2, color);
}

void GfxLib::DrawCircle(void* pSelf, Vector2 pos, uint32_t color, uint16_t radius) {
	GfxLib_DrawCircle(&static_cast<GfxLib*>(pSelf)->handle, pos, color, radius);
}

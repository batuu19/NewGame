#pragma once

#include "GameObject.h"
#include "Rect.h"

#ifndef ENGINE_API
#define ENGINE_API _declspec(dllexport)
#endif //ENGINE_API

class ExampleSquare : public GameObject
{
public:
	ExampleSquare() : ExampleSquare(0, 0, 50, 50) {};
	ExampleSquare(int x, int y, int width, int height) : ExampleSquare({ {x,y},width,height }) {};
	ExampleSquare(RectI rect);
	void draw(Graphics&);
	void update(float dt);
private:
	RectI rect;
};

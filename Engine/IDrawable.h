#pragma once
#include "Graphics.h"

class IDrawable
{
public:
	virtual void draw(Graphics&) = 0;
};

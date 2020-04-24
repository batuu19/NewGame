#pragma once

#include "Graphics.h"
#include "IDrawable.h"
#include "IEntity.h"
#ifndef ENGINE_API
#define ENGINE_API _declspec(dllexport)
#endif //ENGINE_API

class ENGINE_API GameObject : public IDrawable, public IEntity {
public:
	GameObject();
	virtual ~GameObject();
};

#pragma once
#include "Core/Core.h"
#include "raylib.h"

class DJ
{
public:
	DJ();
	~DJ();
	void Render();
	void Update();

private:
	Texture2D m_Texture;
	Vector2 m_Position;
};
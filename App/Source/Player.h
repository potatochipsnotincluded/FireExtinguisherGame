#pragma once
#include <vector>

#include "raylib.h"

#include "Core/Core.h"

struct Particle
{
	Vector2 Position;
	Vector2 Velocity;
	float LifeTime = 1.0f;
};

inline std::vector<Particle> g_Puffs;

class Player
{
public:
	Player();
	~Player();

	void Render();
	void Update();

private:
	Texture2D m_Body;
	Texture2D m_Spout;
	Texture2D m_Puff;

	Vector2 m_Position;
	Vector2 m_BlasterPosition;

	Vector2 m_Velocity;

	float m_Speed = 250;

	float m_PuffSeconds = 500;

	float m_SpoutRotation = 0;

	Core::ActionID m_MoveRightID;
	Core::ActionID m_MoveLeftID;
	Core::ActionID m_MoveUpID;
	Core::ActionID m_MoveDownID;
	Core::ActionID m_FireDownID;
};
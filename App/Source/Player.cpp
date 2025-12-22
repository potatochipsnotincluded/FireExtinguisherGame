#include "Player.h"

float GetRandomFloat()
{
	return (float)GetRandomValue(0, INT_MAX) / (float)(INT_MAX);
}

Player::Player() : m_Body(Core::UI::LoadFileTexture("/Art/player.png")), m_Spout(Core::UI::LoadFileTexture("/Art/blaster.png")), m_Puff(Core::UI::LoadFileTexture("/Art/puff.png"))
{
	SetTextureFilter(m_Body, TEXTURE_FILTER_BILINEAR);
	SetTextureFilter(m_Spout, TEXTURE_FILTER_BILINEAR);
	SetTextureFilter(m_Puff, TEXTURE_FILTER_BILINEAR);

	m_Position = Vector2(500, 200);
	m_BlasterPosition = Vector2(m_Position.x, m_Position.y);

	m_FireDownID = Core::GetInputSystem()->BindMouseInput("Fire", MOUSE_LEFT_BUTTON);
}

Player::~Player()
{
	UnloadTexture(m_Body);
	UnloadTexture(m_Spout);
}

void Player::Render()
{
	float scale = 0.25f;
	
	// m_Body
	Rectangle srcRec = { 0, 0, (float)m_Body.width, (float)m_Body.height };
	Vector2 origin = { (m_Body.width * scale) / 2.0f, (m_Body.height * scale) / 2.0f }; // scaled origin

	Rectangle dstm_Body = { m_Position.x, m_Position.y, m_Body.width * scale, m_Body.height * scale };
	DrawTexturePro(m_Body, srcRec, dstm_Body, origin, 0.0f, WHITE);

	// m_Spout
	Rectangle srcRec2 = { 0, 0, (float)m_Spout.width, (float)m_Spout.height };
	Vector2 origin2 = { (m_Spout.width * scale) / 2.0f, (m_Spout.height * scale) / 2.0f }; // scaled origin

	Rectangle dstm_Spout = { m_BlasterPosition.x, m_BlasterPosition.y, m_Spout.width * scale, m_Spout.height * scale };
	DrawTexturePro(m_Spout, srcRec2, dstm_Spout, origin2, m_SpoutRotation, WHITE);

	for (auto& puff : g_Puffs)
	{
		Rectangle srcRec3 = { 0, 0, (float)m_Puff.width, (float)m_Puff.height };
		Vector2 origin3 = { (m_Puff.width * scale) / 2.0f, (m_Puff.height * scale) / 2.0f }; // scaled origin

		Rectangle dstm_Puff = { puff.Position.x, puff.Position.y, m_Puff.width * scale, m_Puff.height * scale };
		DrawTexturePro(m_Puff, srcRec3, dstm_Puff, origin3, 0, WHITE);

		puff.Position = puff.Position + puff.Velocity * GetFrameTime();
		puff.LifeTime -= GetFrameTime();

		if (puff.LifeTime <= 0.0f)
		{
			puff = g_Puffs.back();
			g_Puffs.pop_back();

			m_PuffCount++;
		}
	}
}

void Player::Update()
{
	if (Core::GetInputSystem()->IsPressed(m_FireDownID) && m_PuffCount > 0)
	{
		Particle puff;
		puff.Position = m_BlasterPosition;

		Vector2 fireDir = Normalize(m_BlasterPosition - m_Position) * Vector2((GetRandomFloat()*2)+1, (GetRandomFloat()*2)+1);
		puff.Velocity = fireDir * GetRandomValue(400, 500);

		g_Puffs.push_back(puff);

		m_PuffCount--;

		m_Velocity = fireDir * -0.25f;
	}

	if (m_PuffCount == 0)
		m_PuffCount += GetFrameTime() * 10;

	Vector2 direction = GetMousePosition() - m_Position;
	float distance = Length(direction);

	if (distance > 150.0f)
	{
		direction = direction * (150.0f / distance);
	}

	m_BlasterPosition = m_Position + direction;

	m_SpoutRotation = std::atan2f(direction.y, direction.x);

	m_SpoutRotation = m_SpoutRotation * (180.0f / PI);

	if (m_Position.y < GetScreenHeight() - 200)
	{
		m_Velocity.y += 8.5f * GetFrameTime();
	}
	else
	{
		m_Velocity.y = 0;
		m_Position.y = GetScreenHeight() - 200;
	}

	m_Position = m_Position + m_Velocity;
	m_Velocity = m_Velocity * 0.8f;
}

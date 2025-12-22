#include "DJ.h"

DJ::DJ()
	: m_Texture(Core::UI::LoadFileTexture("/Art/evildj.png"))
{
	SetTextureFilter(m_Texture, TEXTURE_FILTER_BILINEAR);
}

DJ::~DJ()
{
	UnloadTexture(m_Texture);
}

void DJ::Render()
{
	float scale = 0.25f;

	m_Position = Vector2((GetScreenWidth() / 2), GetScreenHeight() - (m_Texture.height * scale / 2));

	// m_Body
	Rectangle srcRec = { 0, 0, (float)m_Texture.width, (float)m_Texture.height };
	Vector2 origin = { (m_Texture.width * scale) / 2.0f, (m_Texture.height * scale) / 2.0f }; // scaled origin

	Rectangle dstm_Body = { m_Position.x, m_Position.y, m_Texture.width * scale, m_Texture.height * scale };
	DrawTexturePro(m_Texture, srcRec, dstm_Body, origin, 0.0f, WHITE);
}

void DJ::Update()
{
}
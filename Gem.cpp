#include "MainGame.h"
#include "Gem.h"

Gem::Gem(Point2f pos)
	: Saucer(pos)
{
	m_pos = pos;
    SetType(OBJ_GEM);
    SetDrawOrder(3);
    SetUpdateOrder(3);
}

Gem::~Gem()
{}

void Gem::Draw(GameState& gState) const
{
	PlayBlitter& blit = PlayBlitter::Instance();

	blit.DrawRotated(blit.GetSpriteId("gem"), m_pos, 0, m_rot);
}

void Gem::Update(GameState& gState)
{
    if (!m_dead)
    {
        m_velocity.x = -5 * gState.difficulty;
        m_velocity.y = sin(m_pos.x / 100) * 3;

        if (m_pos.x < -50)
            m_pos = { 1500, 50 };
    }
    else
    {
        m_velocity.x = -5 * gState.difficulty;
        m_velocity.y += 1;
        m_rot += 0.1f * gState.difficulty;

        if (m_pos.y > 720)
            m_active = false;
    }

    m_pos += m_velocity;
}

void Gem::SpawnGem(GameState& gState)
{
    new Gem({ 1700, 50 });
}
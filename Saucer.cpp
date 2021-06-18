#include "MainGame.h"
#include "Saucer.h"

Saucer::Saucer(Point2f pos)
    : GameObject(pos)
{
	m_pos = pos;
    SetType(OBJ_SAUCER);
    SetDrawOrder(3);
    SetUpdateOrder(3);
}

Saucer::~Saucer()
{}

void Saucer::Draw(GameState& gState) const
{
    PlayBlitter& blit = PlayBlitter::Instance();

    blit.DrawRotated(blit.GetSpriteId("Saucer"), m_pos, 0, m_rot);
}

void Saucer::Update(GameState& gState)
{

    if (!m_dead)
    {
        m_velocity.x = -5 * gState.difficulty;
        m_velocity.y = sin(m_pos.x / 100) * 3;

        if (m_pos.x < -50)
            m_pos = { 1500, 150 };
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

void Saucer::SpawnSaucers(GameState& gState)
{
    for (int n = 0; n < gState.difficulty + 5; n++)
    {
        new Saucer({ 1500 + (n * 100), 150 });
    }
    gState.difficulty++;
    PlaySpeaker::Instance().StartSound("reward", false);
}

bool Saucer::GetDeathState() const
{
    return m_dead;
}

void Saucer::SetDeathState(bool dead)
{
    m_dead = dead;
}
#include "MainGame.h"
#include "Laser.h"
#include "Saucer.h"
#include "Gem.h"

Laser::Laser(Point2f pos)
    : GameObject(pos)
{
    m_pos = pos;
    SetType(OBJ_LASER);
    SetVelocity({ 0, -20 });
    SetDrawOrder(2);
    SetUpdateOrder(2);
}

Laser::~Laser() 
{};

void Laser::Update(GameState& gState)
{
    PlaySpeaker& speak = PlaySpeaker::Instance();

    for (GameObject* p : s_vUpdateList)
    {
        Saucer* s = dynamic_cast<Saucer*>(p);

        if (s != nullptr)
        {
            if (s->GetDeathState() == false && HasCollided(m_pos, s->GetPosition()))
            {
                s->SetDeathState(true);
                m_active = false;
                if (s->GetType() != OBJ_GEM)
                {
                    gState.score += 1000;
                    speak.StartSound("clang", false);
                }
                else
                {
                    gState.score += 5000;
                    speak.StartSound("reward", false);
                }
            }
        }
    }

    m_pos += m_velocity;

    if (m_pos.y < 0)
        m_active = false;

}

void Laser::Draw(GameState& gState) const
{
    PlayBlitter& blit = PlayBlitter::Instance();

    blit.Draw(blit.GetSpriteId("Laser"), m_pos, 0);
}
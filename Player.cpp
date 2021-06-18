#include "MainGame.h"
#include "Laser.h"
#include "Saucer.h"
#include "Gem.h"
#include "Player.h"

Player::Player(Point2f pos) 
    : GameObject(pos)
{
    m_pos = pos;
    SetType(OBJ_PLAYER);
    SetDrawOrder(3);
    SetUpdateOrder(3);
}

Player::~Player()
{}

void Player::Update(GameState& gState)
{
    PlayBuffer& buff = PlayBuffer::Instance();
    PlaySpeaker& speak = PlaySpeaker::Instance();

    if (buff.KeyDown(VK_LEFT))
        m_pos.x -= 5;

    if (buff.KeyDown(VK_RIGHT))
        m_pos.x += 5;

    if (buff.KeyPressed(VK_SPACE))
    {
        new Laser({ m_pos.x, m_pos.y - 50 });

        if (gState.score >= 100)
            gState.score -= 100;

        speak.StartSound("laser", false);
    }

    if (GameObject::GetObjectCount(OBJ_SAUCER) == 0 && GameObject::GetObjectCount(OBJ_GEM) == 0)
    {
        Saucer::SpawnSaucers(gState);
        Gem::SpawnGem(gState);
    }
        
    gState.p->SetPosition(m_pos);
}

void Player::Draw(GameState& gState) const
{
    PlayBlitter& blit = PlayBlitter::Instance();

    float yWobble = sin(gState.time * PLAY_PI) * 3;
    blit.Draw(blit.GetSpriteId("Rocket"), { m_pos.x, m_pos.y + yWobble }, 2 * gState.time);
}
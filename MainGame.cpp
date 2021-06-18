// You'll need to #include MainGame.h, Laser.h and Saucer.h BEFORE Play.h

#include "Laser.h"
#include "Saucer.h"
#include "Player.h"
#include "MainGame.h"
#include "GameObject.h"
#define PLAY_IMPLEMENTATION
#include "Play.h"

constexpr int DISPLAY_WIDTH = 1280;
constexpr int DISPLAY_HEIGHT = 720;
constexpr int DISPLAY_SCALE = 1;

GameState gState;

// Stays in MainGame.cpp
int WINAPI WinMain( PLAY_WINARGS_IN )
{
    PlayBuffer& buff = PlayBuffer::Instance( DISPLAY_WIDTH, DISPLAY_HEIGHT, DISPLAY_SCALE, 0 );
    PlayBlitter& blit = PlayBlitter::Instance( "Data\\Sprites\\" );
    PlaySpeaker& speak = PlaySpeaker::Instance( "Data\\Audio\\" );

    blit.SetDisplayBuffer( buff.GetDisplayBuffer(), DISPLAY_WIDTH, DISPLAY_HEIGHT );
    blit.LoadBackground( "Data\\Backgrounds\\background.png" );
    blit.CentreAllSpriteOrigins();

    speak.StartSound( "music", true );
    gState.p = new Player({ 640, 650 });

    return buff.HandleWindows( PLAY_WINARGS_OUT, L"PlayBuffer Framework" );
}

// Stays in MainGame.cpp
bool MainGameUpdate( float elapsedTime )
{
    PlayBuffer& buff = PlayBuffer::Instance();
    PlayBlitter& blit = PlayBlitter::Instance();

    gState.time += elapsedTime;

    blit.DrawBackground();
    GameObject::UpdateAll(gState);
    GameObject::DrawAll(gState);
    blit.DrawStringCentred( blit.GetSpriteId( "105px" ), { DISPLAY_WIDTH / 2, 50 }, "SCORE: " + std::to_string( gState.score ) );
    buff.Present();

    return PlayBuffer::Instance().KeyDown( VK_ESCAPE );
}

// Stays in MainGame.cpp
void MainGameExit( void )
{
    GameObject::DestroyAll();
    PlayBuffer::Destroy();
    PlayBlitter::Destroy();
    PlaySpeaker::Destroy();
}

bool HasCollided( Point2f pos1, Point2f pos2 ) // Stays in MainGame.cpp
{
    Vector2f separation = pos2 - pos1;
    float dist = sqrt( ( separation.x * separation.x ) + ( separation.y * separation.y ) );
    if( dist < 50 )
        return true;
    else
        return false;
}




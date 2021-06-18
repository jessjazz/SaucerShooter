#include <vector>
#include "Play.h"
#pragma once

class Laser;
class Saucer;
class Player;

struct GameState
{
    float time{ 0 };
    int score{ 0 };
    int difficulty{ 1 };
    Player* p;
};

bool HasCollided(Point2f pos1, Point2f pos2);
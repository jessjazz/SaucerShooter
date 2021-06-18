#pragma once
#include "Play.h"
#include "MainGame.h"
#include "GameObject.h"

class Laser : public GameObject
{
public:
    Laser(Point2f pos);
    ~Laser();
    void Draw(GameState& gState) const override;
    void Update(GameState& gState) override;
    static Laser* CreateLaser(Point2f pos);
};
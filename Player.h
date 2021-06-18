#pragma once
#include "Play.h"
#include "GameObject.h"
#include "MainGame.h"

struct GameState;

class Player : public GameObject
{
public:
	Player(Point2f pos);
	void Update(GameState& gState) override;
	void Draw(GameState& gState) const override;
	static Player* CreatePlayer(); // new method
	~Player();
};

#pragma once
#include "Play.h"
#include "MainGame.h"
#include "Saucer.h"

class Gem : public Saucer
{
public:
	Gem(Point2f pos);
	~Gem();
	void Draw(GameState& gState) const override;
	void Update(GameState& gState) override;
	static void SpawnGem(GameState& gState);
	static Gem* CreateGem(Point2f pos);
};
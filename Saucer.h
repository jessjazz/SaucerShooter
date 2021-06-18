#pragma once
#include "Play.h"
#include "MainGame.h"
#include "GameObject.h"

class Saucer : public GameObject
{
public:
	Saucer(Point2f pos);
	~Saucer();
	void Draw(GameState& gState) const override;
	void Update(GameState& gState) override;
	static void SpawnSaucers(GameState& gState);
	bool GetDeathState() const;
	void SetDeathState(bool dead);
	static Saucer* CreateSaucer(Point2f pos);

protected:
	float m_rot{ 0 };
	bool m_dead{ false };
};
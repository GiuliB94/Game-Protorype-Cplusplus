#pragma once
#include "Dragon.h"

class DyvirFight : public sf::Drawable, public Dragon
{
public:
	DyvirFight();
	void update();
	//bool changeStatus();
	void Die();
	int doDamage();
	void updateSpriteHP();
	void damageTaken(int);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};



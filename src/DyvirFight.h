#pragma once
#ifndef DYVIRFIGHT_H
#define DYVIRFIGHT_H

#include "Dragon.h"
#include "Inventory.h"
#include "Ability.h"


class DyvirFight : public Dragon
{
private:
	unsigned short _wins;
	bool _flagWin;
	std::vector <Ability> _abilityEquipment;
	unsigned short _level;
	unsigned short _requiredExperience[3];
public:
	DyvirFight();
	void update(bool) override;
	void Die() override;
	void Win();
	void setStats() { /*completar*/ }
	void increaseXP(int XP);
	unsigned short getWins() { return _wins; }	
	void setWins() { _wins++; }
	std::string setAbilityEquiped(int i, int ability);
	int getInventorySize() { return _abilityEquipment.size(); }
	Ability getAbilityInv(int i) { return _abilityEquipment[i]; }
	std::string getAbilityInvName(int i);
	bool craftAbility(std::string, std::string, int, int);
	void setFightSprite();
	void restoreLife();
};

#endif

#include "stdafx.h"
#include "DyvirFight.h"
#include "AbilityFactory.h"

DyvirFight::DyvirFight() : _abilityInventory(3) {
	//TODO: Implementar leveo, subida de stats, etc.  DEJAR!!!!!!!!!!!!!!!!!!!!!!!!!
	_abilityInventory[0] = _abilityFactory.createFireball();
	_abilityInventory[1] = _abilityFactory.createWindBlow();
	_abilityInventory[2] = _abilityFactory.createHotVampire();
	_HPbase = 1000;
	_XP = 0;
	_level = 1;
	_HP = _HPbase;
	_MPbase = 500;
	_MP = _MPbase;
	_physicalDamagebase = 150;
	_physicalDamage = _physicalDamagebase;
	_physicalDefensebase = 50;
	_magicalDamagebase = 50;
	_magicResistbase = 50;
	this->setFightSprite();
	_isAlive = true;
	_wins = 0;

	//Variables �tiles para los sprites
	_flagDie = true; // Usar para reproducir la animaci�n de muerte
	_flagWin = true;
	_frame = 0;
}

void DyvirFight::update(bool enemyIsAlive) {
	if (enemyIsAlive) {
		if (_isAlive) {
			_frame += 0.15;
			if (_frame >= 8 && _isAlive) {
				_frame = 0;
			}
			_sprite.setTextureRect({ int(_frame) * 260, 0, 260, 230 });
		}
		else {
			this->Die();
		}
	}
	else {
		this->Win();
		this->resetStats();
	}
}

void DyvirFight::Die() {
	if (_flagDie) {
		_frame = 0;
		_texture.loadFromFile("./Textures/Characters/spritesheets/DyvirDead.png");
		_sprite.setTexture(_texture);
		_sprite.setScale(1, 1);
		_flagDie = false;
	}
	_frame += 0.15;
	if (_frame >= 9) {
		_frame = 9;
	}
	_sprite.setTextureRect({ int(_frame) * 170, 0, 170, 110 });
	_sprite.setPosition(85, 480 - _sprite.getGlobalBounds().height);
}

void DyvirFight::Win() {
	if (_flagWin) {
		_frame = 0;
		_texture.loadFromFile("./Textures/Characters/spritesheets/DyvirWin 110x200.png");
		_sprite.setTexture(_texture);
		_sprite.setScale(1, 1);
		_flagWin = false;
	}
	_frame += 0.15;
	if (_frame >= 6) {
		_frame = 0;
	}
	_sprite.setTextureRect({ int(_frame) * 110, 0, 110, 200 });
	_sprite.setPosition(85, 480 - _sprite.getGlobalBounds().height);
}
void DyvirFight::increaseXP(int XP) {

}
void DyvirFight::restoreLife() {
	_HP = _HPbase;
	_MP = _MPbase;
}

std::string DyvirFight::setAbilityEquiped(int i, int ability) {
	{
		if (ability < _abilityInventory.size()) {
			_ability[i] = _abilityInventory[ability];
			return _ability[i].getName();
		}
		else return _ability[i].getName();
	}
}

std::string DyvirFight::getInventoryElementName(int i) {
	if (i >= _abilityInventory.size()) {
		return "Empty";
	}
	else return _abilityInventory[i].getName();
}

void DyvirFight::setAbilityEquiped(Ability& ability, int i) {
	ability = _ability[i];
}

bool DyvirFight::craftAbility(std::string ab1, std::string ab2, int indexAb1, int indexAb2) {
	if (_abilityFactory.craftAbility(ab1, ab2) != CraftError) {
		if (indexAb1 < indexAb2) {
			_abilityInventory.erase(_abilityInventory.begin() + indexAb1);
			_abilityInventory.erase(_abilityInventory.begin() + indexAb2 - 1);
		}
		else {
			_abilityInventory.erase(_abilityInventory.begin() + indexAb2);
			_abilityInventory.erase(_abilityInventory.begin() + indexAb1 - 1);
		}
		_abilityInventory.push_back(_abilityFactory.createAbility(_abilityFactory.craftAbility(ab1, ab2)));
		return true;
	}
	else{ return false; }
}

void DyvirFight::setFightSprite() {
	_texture.loadFromFile("./Textures/Characters/spritesheets/DyvirFight.png");
	_sprite.setTexture(_texture);
	_sprite.setTextureRect({ 0,0,260,230 });
	_sprite.setScale(0.5, 0.5);
	_sprite.setPosition(85, 480 - _sprite.getGlobalBounds().height);
	_flagWin = true;
}

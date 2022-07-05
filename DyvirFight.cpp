#include "stdafx.h"
#include "DyvirFight.h"

DyvirFight::DyvirFight()
{
    _HPMax = 100;
    _HP = _HPMax;
	//_isAlive = false;
    _physicalDamage = 30;
    _texture.loadFromFile("dyvir.png");
	_sprite.setTexture(_texture);
	_sprite.setTextureRect({ 0,0,260,230 });
	_sprite.setScale(0.5, 0.5);
	_sprite.setPosition(85, 480 - _sprite.getGlobalBounds().height);
    _isAlive = true;
    _wins = 0;

    //Variables �tiles para los sprites
    _flagDie = true; // Usar para reproducir la animaci�n de muerte
    _frame = 0;
}

void DyvirFight::update()
{
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

void DyvirFight::Die()
{
    if (_flagDie) {
        _frame = 0;
        _flagDie = false;
        _texture.loadFromFile("Dyvir_dead.png");
        _sprite.setTexture(_texture);
        _sprite.setScale(1, 1);
    }
    _frame += 0.15;
    if (_frame >= 9) {
        _frame = 9;
    }
    _sprite.setTextureRect({ int(_frame) * 170, 0, 170, 110 });

    _sprite.setPosition(85, 480 - _sprite.getGlobalBounds().height);
}

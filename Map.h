#pragma once
#include "DyvirMap.h"
#include "BrickTiles.h"
#include "Dyvirfight.h"
#include "Fight.h"
#include "Enemy.h"

class Map
{
private:
    bool _music;
    sf::Texture _backTexture;
    sf::SoundBuffer bufferPelea;
    sf::Sound musicaPelea;
    sf::View _view;
    std::vector<std::vector<sf::Vector2i>>map;
    BrickTiles tile;
    Fight fight;
    BrickTiles _taux;
    int x, iaux, jaux, win;

public:
    Map();
    int update(DyvirMap&, sf::RenderWindow& window, DyvirFight&);
};



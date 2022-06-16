#pragma once
#include <SFML/Audio.hpp>
#include "DyvirMap.h"


class Map 
{
private:
    bool _music;
    sf::Texture* _backTexture;
    sf::SoundBuffer bufferPelea;
    sf::Sound musicaPelea;
    sf::View* _view;

public:
    Map();
    int update(sf::Sprite&, DyvirMap&, sf::RenderWindow& window);
};


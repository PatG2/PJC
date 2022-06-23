#include "Base.h"

Base::Base(Map* map, float pos_X, float pos_Y, float size_X, float size_Y, int team, int HP)
	:NotMovable(map)
{
	this->position = sf::Vector2f(pos_X, pos_Y);
	
	this->size = sf::Vector2f(size_X, size_Y);
	this->team = team;

	this->HP = HP;
}

Base::~Base()
{
}

void Base::update()
{
}



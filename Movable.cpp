#include "Movable.h"
#include "Map.h"
Movable::Movable(Map* map)
	:Object(map)
{
	
}

Movable::~Movable()
{
}

void Movable::setHP(int HP)
{
	this->HP = HP;
}

int Movable::getHP()
{
	return HP;
}

float Movable::getRange()
{
	return range;
}

void Movable::attack(Object* object)
{
	//std::cout << this->getPosition().x << std::endl;
	//this->position = sf::Vector2f(0.0, 0.0);
	map->initBullets(this->getPosition().x, this->getPosition().y, this->getTeam());
	//jakie podac parametry do inicjalizacji obiektu 
	int HP = object->getHP() - 10;
	object->setHP(HP);

}








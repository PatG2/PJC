#include "Object.h"
#include "Map.h"

Object::Object(Map* map)
{
	this->map = map;
}

Object::~Object()
{
}


sf::Vector2f Object::getPosition()
{
	return position;
}

int Object::getTeam()
{
	return team;
}

bool Object::getIsHitted()
{
	return isHitted;
}

int Object::getHP()
{
	return HP;
}

sf::Vector2f Object::getSize()
{
	return size;
}

bool Object::ObjectInRange(Object* object, float range)
{	
	sf::Vector2f temp = object->getPosition() - this->getPosition();

	if (std::sqrt(std::pow(temp.x, 2) + std::pow(temp.y, 2)) < range) {

		return true;
		
	}

	return false;
}





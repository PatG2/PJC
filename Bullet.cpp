#include "Bullet.h"

Bullet::Bullet(Map* map, float pos_X, float pos_Y, bool team)
	:Movable(map)
{
	this->position = sf::Vector2f(pos_X, pos_Y);
	this->movmentSpeed = 1.f;
	this->range = 10.f;
	this->team = team;
	this->hitRange = 1.f;
	this->isHitted = false;
	this->HP = 1;
}

Bullet::~Bullet()
{

}

bool Bullet::collision()
{
	for (unsigned int i = 0; i < map->getObjects().size(); i++) {
		if ((ObjectInRange(map->getObjects()[i], this->range) == true) && (map->getObjects()[i]->getTeam() != this->getTeam()) && (map->getObjects()[i]->getTeam() != 3 ) ) {
				
			//dzia³a
				if (this->position.x == map->getObjects()[i]->getPosition().x && this->position.y == map->getObjects()[i]->getPosition().y) {//&& this->position.y >= map->getObjects()[i]->getPosition().y && this->position.y + 10.f <= map->getObjects()[i]->getPosition().y + 15.f) {
					return true;
				}
				else {
					return false;
				}
		}
	}
}


void Bullet::move()
{	
	sf::Vector2f destination;
	for (unsigned long int i = 0; i < map->getObjects().size(); i++) {
		if ((ObjectInRange(map->getObjects()[i], 50.f) == true) && (map->getObjects()[i]->getTeam() != this->getTeam()) && (map->getObjects()[i]->getTeam() != 3 )) {
			destination = map->getObjects()[i]->getPosition();
			break;
		}
	}
	if (this->position.x > destination.x) {
		this->position.x = this->position.x - movmentSpeed;
	}
	if (this->position.x < destination.x) {
		this->position.x = this->position.x + movmentSpeed;
	}
	if (this->position.y < destination.y) {
		this->position.y = this->position.y + movmentSpeed;
	}
	if (this->position.y > destination.y) {
		this->position.y= this->position.y - movmentSpeed;
	}

	//std::cout << destination.x << std::endl;

}

void Bullet::update()
{
	for (unsigned int i = 0; i < map->getObjects().size(); i++) {
		if (collision() == true) {
			//std::cout << "weszlo" << std::endl;
			//HP = map->getObjects()[i]->getHP() - 10;
			//map->getObjects()[i]->setHP(HP);
			this->isHitted = true;
			break;
			
		}
		else {
			this->move();

		}
	}	
}

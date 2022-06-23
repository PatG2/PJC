#include "Soldier.h"


Soldier::Soldier(Map* map, float pos_X, float pos_Y, int team)
	:Movable(map)
{
	this->position = sf::Vector2f(pos_X, pos_Y);
	this->HP = 50;
	this->movmentSpeed = 1.f;
	this->range = 50.f;
	this->team = team;
	this->isHitted = false;
}

Soldier::~Soldier()
{
	
}



void Soldier::move()
{
	
	int direction = (std::rand() % 4) + 0;

	if (direction == 0) {

		if (this->position.y <= 0) {

			this->position = this->getPosition() + sf::Vector2f(0.f, movmentSpeed);
		}
		else if (this->position.y >= map->getMapSize("y") - 5.f) {

			this->position = this->getPosition() - sf::Vector2f(0.f, movmentSpeed);
		}
		else {

			this->position = this->getPosition() + sf::Vector2f(0.f, movmentSpeed);
		}
	}
	else if (direction == 1) {

		if (this->position.y >= map->getMapSize("y") - 5.f) {

			this->position = this->getPosition() - sf::Vector2f(0.f, movmentSpeed);
		}
		else if (this->position.y <= 0) {

			this->position = this->getPosition() + sf::Vector2f(0.f, movmentSpeed);
		}
		else {
			this->position = this->getPosition() - sf::Vector2f(0.f, movmentSpeed);
		}
	}
	else if (direction == 2) {
		if (this->position.x <= 0) {

			this->position = this->getPosition() + sf::Vector2f(movmentSpeed, 0.f);
		}
		else if (this->position.x >= map->getMapSize("x") - 5.f) {

			this->position = this->getPosition() - sf::Vector2f(movmentSpeed, 0.f);
		}
		else {
			this->position = this->getPosition() + sf::Vector2f(movmentSpeed, 0.f);
		}
	}
	else if (direction == 3) {
		if (this->position.x >= map->getMapSize("x") - 5.f) {

			this->position = this->getPosition() - sf::Vector2f(movmentSpeed, 0.f);
		}
		else if (this->position.x <= 0) {

			this->position = this->getPosition() + sf::Vector2f(movmentSpeed, 0.f);
		}
		else {

			this->position = this->getPosition() - sf::Vector2f(movmentSpeed, 0.f);
		}
	}
}

void Soldier::update()
{
	int counter = 0;
	for (unsigned long int i = 0; i < map->getObjects().size(); i++) {
		//std::cout << this->getHP() << std::endl;
		//std::cout << map->getObjects()[i]->getHP() << std::endl;
		if (counter <= 5) {
			if ((this->ObjectInRange(map->getObjects()[i], this->range) == true) && (map->getObjects()[i]->getTeam() != this->getTeam()) && (map->getObjects()[i]->getTeam() != 3) && (map->getObjects()[i]->getHP() >= 0) && (this->getHP() >= 0)) {
				this->attack(map->getObjects()[i]);
				counter++;
				break;
			}
			else {
				counter = 0;


			}
		}
	}this->move();
}



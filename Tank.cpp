#include "Tank.h"

Tank::Tank(Map* map, float pos_X, float pos_Y, int team)
	:Movable(map)
{
	this->position = sf::Vector2f(pos_X, pos_Y);
	this->HP = 50;
	this->movmentSpeed = 1.f;
	this->range = 50.f;
	this->team = team;
	this->isHitted = false;
	

}
Tank::~Tank()
{

}
bool Tank::collisionTree()
{
	for (unsigned int i = 0; i < map->getObjects().size(); i++) {
		if ((ObjectInRange(map->getObjects()[i],20.f) == true)) {
			if (Tree* tr = dynamic_cast<Tree*>(map->getObjects()[i])) {
				//dzia³a
				if (this->position.x + 10.f == map->getObjects()[i]->getPosition().x ){//&& this->position.y >= map->getObjects()[i]->getPosition().y && this->position.y + 10.f <= map->getObjects()[i]->getPosition().y + 15.f) {
					return true;
				}
				//dzia³a
				if (this->position.x == map->getObjects()[i]->getPosition().x + 15.f){// && this->position.y >= map->getObjects()[i]->getPosition().y && this->position.y + 10.f <= map->getObjects()[i]->getPosition().y + 15.f) {
					return true;
				}
				//problem
				if (this->position.y == map->getObjects()[i]->getPosition().y + 15.f){// && this->position.x >= map->getObjects()[i]->getPosition().x && this->position.x + 10.f <= map->getObjects()[i]->getPosition().x + 15.f) {
					return true;
				}
				//problem
				if (this->position.y + 10.f == map->getObjects()[i]->getPosition().y){// && this->position.x >= map->getObjects()[i]->getPosition().x && this->position.x + 10.f <= map->getObjects()[i]->getPosition().x + 15.f) {
					return true;
				}
				else {
					return false;
				}
			}
		}
	}
}

void Tank::move()
{
	
	int direction = (std::rand() % 4) + 0;
	//int direction = 1;
	
	if (direction == 0) {

		if (this->position.y <= 0) {

			this->position = this->getPosition() + sf::Vector2f(0.f, movmentSpeed);
		}
		else if (this->position.y >= map->getMapSize("y") - 10.f) {

			this->position = this->getPosition() - sf::Vector2f(0.f, movmentSpeed);
		}
		else if (collisionTree() == true) {

			this->position = this->getPosition() - sf::Vector2f(0.f, movmentSpeed);
		}
		else {

			this->position = this->getPosition() + sf::Vector2f(0.f, movmentSpeed);
		}
	}
	else if (direction == 1) {

		if (this->position.y >= map->getMapSize("y")-10.f) {

			this->position = this->getPosition() - sf::Vector2f(0.f, movmentSpeed);
		}
		else if (this->position.y <= 0) {

			this->position = this->getPosition() + sf::Vector2f(0.f, movmentSpeed);
		}
		else if (collisionTree() == true) {

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
		else if (this->position.x >= map->getMapSize("x") - 10.f) {

			this->position = this->getPosition() - sf::Vector2f(movmentSpeed, 0.f);
		}
		else if (collisionTree() == true) {

			this->position = this->getPosition() - sf::Vector2f(movmentSpeed, 0.f);
		}
		else {

			this->position = this->getPosition() + sf::Vector2f(movmentSpeed, 0.f);
		}

		
	}
	else if (direction == 3) {
		if (this->position.x >= map->getMapSize("x") - 10.f) {

			this->position = this->getPosition() - sf::Vector2f(movmentSpeed, 0.f);
		}
		else if (this->position.x <= 0) {

			this->position = this->getPosition() + sf::Vector2f(movmentSpeed, 0.f);
		}
		else if (collisionTree() == true) {

			this->position = this->getPosition() + sf::Vector2f(movmentSpeed, 0.f);
		}
		else {

			this->position = this->getPosition() - sf::Vector2f(movmentSpeed, 0.f);
		}
	}
}

void Tank::update()
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
//{
//	int counter = 0;
//	for (unsigned long int i = 0; i < map->getObjects().size(); i++) {
//		//std::cout << this->getHP() << std::endl;
//		//std::cout << map->getObjects()[i]->getHP() << std::endl;
//		if (counter <= 5) {
//			if ((ObjectInRange(map->getObjects()[i], this->range) == true) && (map->getObjects()[i]->getTeam() != this->getTeam()) && (map->getObjects()[i]->getTeam() != 3) && (map->getObjects()[i]->getHP() >= 0) && (this->getHP() >= 0)) {
//				this->attack(map->getObjects()[i]);
//				counter++;
//				
//			}
//			else {
//				//counter = 0;
//				
//				
//
//			}
//		}
//	}	this->move();
//}




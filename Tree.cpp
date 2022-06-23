#include "Tree.h"

Tree::Tree(Map* map, float pos_X, float pos_Y, float size_X, float size_Y, int team)
	:NotMovable(map)
{
	this->position = sf::Vector2f(pos_X, pos_Y);
	this->size = sf::Vector2f(size_X, size_Y);
	this->team = team;


}
Tree::~Tree()
{
}

void Tree::update()
{
}
#include "GObject.h"

GObject::GObject(Object* object)
{
	this->object = object;

	this->shape = renderGObjects(object);
}

GObject::~GObject()
{

}

sf::RectangleShape GObject::renderGObjects(Object* object)
{

	sf::RectangleShape shape;

	shape.setPosition(object->getPosition());

	if (Tree* tr = dynamic_cast<Tree*>(object)) {
		shape.setFillColor(sf::Color::Green);
	}
	else if (Base* tr = dynamic_cast<Base*>(object)) {
		shape.setFillColor(sf::Color::White);
	}

	else if (Bullet* tr = dynamic_cast<Bullet*>(object)) {
		shape.setFillColor(sf::Color::Magenta);
	}
	else if (object->getTeam() == 2) {
		shape.setFillColor(sf::Color::Red);
	}
	else if (object->getTeam() == 1) {
		shape.setFillColor(sf::Color::Blue);
	}



	if (Soldier *s = dynamic_cast<Soldier*>(object)) {
		shape.setSize(sf::Vector2f(5.f, 5.f));
	}
	else if (Tank* t = dynamic_cast<Tank*>(object)) {
		shape.setSize(sf::Vector2f(10.f, 10.f));
	}
	else if (Tree* tr = dynamic_cast<Tree*>(object)) {
		shape.setSize(sf::Vector2f(object->getSize()));
	}
	else if (Base* tr = dynamic_cast<Base*>(object)) {
		shape.setSize(sf::Vector2f(object->getSize()));
	}
	else if (Bullet* tr = dynamic_cast<Bullet*>(object)) {
		shape.setSize(sf::Vector2f(3.f,3.f));
	}
	return shape;
}

void GObject::update()
{
	shape.setPosition(object->getPosition());
}

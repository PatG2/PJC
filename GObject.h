#pragma once
#include "Object.h"
#include "Soldier.h"
#include "Tank.h"
#include "Tree.h"
#include "Base.h"
#include "Bullet.h"

class GObject
{
private:
protected:
	Object* object;

public:
	sf::RectangleShape shape;
	GObject(Object* object);
	virtual ~GObject();
	sf::RectangleShape renderGObjects(Object *object);

	void update();
};


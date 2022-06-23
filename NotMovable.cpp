#include "NotMovable.h"

NotMovable::NotMovable(Map* map)
	:Object(map)
{
}

NotMovable::~NotMovable()
{
}

float NotMovable::getRange()
{
	return 0;
}

int NotMovable::getHP()
{
	return HP;
}

void NotMovable::setHP(int HP)
{
	this->HP = HP;
}

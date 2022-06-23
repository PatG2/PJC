#include "Map.h"

//w Objects stworzyc czo³gi i ¿o³nierze 
void Map::initObject()
{
	//wojsko
	Objects.push_back(new Soldier(this, 190.f, 50.f, 1));
	Objects.push_back(new Soldier(this, 190.f, 350.f, 2));
	Objects.push_back(new Soldier(this, 210.f, 50.f, 1));
	Objects.push_back(new Soldier(this, 210.f, 350.f, 2));
	Objects.push_back(new Soldier(this, 230.f, 50.f,1));
	Objects.push_back(new Soldier(this, 230.f, 350.f, 2));
	Objects.push_back(new Soldier(this, 250.f, 50.f, 1));
	Objects.push_back(new Soldier(this, 250.f, 350.f, 2));
	Objects.push_back(new Soldier(this, 270.f, 50.f, 1));
	Objects.push_back(new Soldier(this, 270.f, 350.f, 2));
	Objects.push_back(new Soldier(this, 270.f, 30.f, 2));
	Objects.push_back(new Soldier(this, 290.f, 350.f, 2));
	Objects.push_back(new Soldier(this, 310.f, 50.f, 1));
	Objects.push_back(new Soldier(this, 310.f, 350.f, 2));
	Objects.push_back(new Tank(this, 330.f, 50.f, 1));
	Objects.push_back(new Tank(this, 330.f, 350.f, 2));
	Objects.push_back(new Tank(this, 350.f, 50.f, 1));
	Objects.push_back(new Tank(this, 350.f, 350.f, 2));
	Objects.push_back(new Tank(this, 370.f, 50.f, 1));
	Objects.push_back(new Tank(this, 370.f, 350.f, 2));
	Objects.push_back(new Tank(this, 390.f, 50.f, 1));
	Objects.push_back(new Tank(this, 390.f, 350.f, 2));
	Objects.push_back(new Tank(this, 380.f, 300.f, 1));

	
	//przeszkody
	Objects.push_back(new Tree(this, 450.f, 300.f, 15.f, 15.f,3));
	Objects.push_back(new Tree(this, 435.f, 300.f, 15.f, 15.f,3));
	Objects.push_back(new Tree(this, 420.f, 300.f, 15.f, 15.f,3));
	Objects.push_back(new Tree(this, 405.f, 300.f, 15.f, 15.f,3));

	Objects.push_back(new Tree(this, 200.f, 200.f, 15.f, 15.f,3));
	Objects.push_back(new Tree(this, 215.f, 200.f, 15.f, 15.f,3));
	Objects.push_back(new Tree(this, 230.f, 200.f, 15.f, 15.f,3));
	Objects.push_back(new Tree(this, 245.f, 200.f, 15.f, 15.f,3));

	Objects.push_back(new Tree(this, 160.f, 70.f, 15.f, 15.f,3));
	Objects.push_back(new Tree(this, 175.f, 70.f, 15.f, 15.f,3));
	Objects.push_back(new Tree(this, 190.f, 70.f, 15.f, 15.f,3));
	Objects.push_back(new Tree(this, 205.f, 70.f, 15.f, 15.f,3));

	Objects.push_back(new Tree(this, 350.f, 120.f, 15.f, 15.f,3));
	Objects.push_back(new Tree(this, 365.f, 120.f, 15.f, 15.f,3));
	Objects.push_back(new Tree(this, 380.f, 120.f, 15.f, 15.f,3));
	Objects.push_back(new Tree(this, 395.f, 120.f, 15.f, 15.f,3));

	//Bazy
	Objects.push_back(new Base(this, 260.f, 5.f, 60.f, 30.f, 1 ,500));
	Objects.push_back(new Base(this, 260.f, 365.f, 60.f, 30.f, 2, 500));
	
}

Map::Map()
{
	this->initObject();
	this->max_X = 600;
	this->max_Y = 400;
	this->checkEnd = false;
}


Map::~Map()
{
	for (unsigned long int i = 0; i < Objects.size(); i++) {
			delete Objects[i];
			//std::cout << "Nara" << std::endl;
	}
}

//pêtla dla obiektów 
//obj -> update()

void Map::update()
{
	srand(time(NULL));
	//for (unsigned long int i = 0; i < Objects.size(); i++) {
	//	if (Objects[i]->getHP() == 0) {
	//		Objects.erase(this->Objects.begin() + i);
	//		break;
	//	}
	//	
	//}
	for (unsigned long int i = 0; i < Objects.size(); i++) {
		/*if (Objects[i]->getHP() <= 0) {
			delete Objects[i];
			Objects.erase(Objects.begin()+i);
		}*/
		Objects[i]->update();
	}
	for (unsigned long int i = 0; i < Objects.size(); i++) {
		/*if (Objects[i]->getHP() <= 0) {
			delete Objects[i];
			Objects.erase(Objects.begin()+i);
		}*/
		if (Objects[i]->getIsHitted() == true) {
			Objects.erase(Objects.begin() + i);
		}
		//if (Objects[i]->getHP() < 0) {
	//		Objects.erase(Objects.begin() + i);
	//	}
	}
	for (unsigned long int i = 0; i < Objects.size(); i++) {
		
		if (Objects[i]->getHP() < 0) {
			Objects.erase(Objects.begin() + i);
		}
	}
	for (unsigned long int i = 0; i < Objects.size(); i++) {

		if (Base* tr = dynamic_cast<Base*>(Objects[i])) {
			if (Objects[i]->getHP() == 0) {
				Objects.erase(Objects.begin() + i);
				this->checkEnd = true;
			}
		}
		
	}
}

std::vector<Object*> Map::getObjects()
{
	return Objects;
}

int Map::getMapSize(std::string xory)
{
	if (xory == "x"){
		return max_X;
	}
		
	if (xory == "y"){
		return max_Y;
	}
	else {
		return max_X;
	}
		
}

void Map::initBullets(float pos_X, float pos_Y, bool team)
{
	Objects.push_back(new Bullet(this, pos_X, pos_Y, team));
}

bool Map::geChekcEnd()
{
	return checkEnd;
}



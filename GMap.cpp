#include "GMap.h"

GMap::GMap(Map* map)
{
	gridSize = 20;
	this->map = map;
	//this->initGrid();
	this->initGObject();
}

GMap::~GMap()
{

}



void GMap::initGrid()
{
	//for (int i = 0; i < 30; i++) {
	//	grid.push_back(std::vector<sf::RectangleShape>());
	//	for (int j = 0; j < 20; j++) {
	//		grid[i].push_back(sf::RectangleShape());

	//		grid[i][j].setFillColor(sf::Color::Green);
	//		grid[i][j].setSize(sf::Vector2f(gridSize, gridSize));
	//		grid[i][j].setPosition(i*gridSize, j*gridSize);
//
	//	}
//	}
}


void GMap::initGObject()
{
	for (unsigned long int i = 0; i < map->getObjects().size(); i++) {
		GObjects.push_back(new GObject(map->getObjects()[i]));
	}
	
}

void GMap::updateGObjects()
{
	GObjects.clear();
	for (unsigned long int i = 0; i < map->getObjects().size(); i++) {
			GObjects.push_back(new GObject(map->getObjects()[i]));
	}
}

void GMap::update()
{
	this->updateGObjects();

	/*for (unsigned long int i = 0; i < GObjects.size(); i++) {
		if (map->getObjects()[i]->getHP() <= 0) {
			GObjects.erase(GObjects.begin() + i);
		}
	}*/
	for (unsigned long int i = 0; i < GObjects.size(); i++) {
		/*if (map->getObjects()[i]->getHP() <= 0) {
			delete GObjects[i];
			GObjects.erase(GObjects.begin() + i);
		}*/
		GObjects[i]->update();
	}


}

void GMap::render(sf::RenderTarget& target)
{
	
	//for (int i = 0; i < 30; i++) {
	//	for (int j = 0; j < 20; j++) {
	//		target.draw(grid[i][j]);
	//	}
	//}

	for (unsigned long int i = 0; i < GObjects.size(); i++) {
		target.draw(GObjects[i]->shape);
	}	
	
	
}


#pragma once
#include <iostream>
#include "Map.h"
#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Network.hpp"
#include "GObject.h"
class GMap
{
private:
	Map* map;
	std::vector<std::vector<sf::RectangleShape>> grid;
	float gridSize;
	std::vector<GObject*> GObjects;
	
	

public:
	//Konstruktor i dekonstruktor
	GMap(Map* map);
	virtual ~GMap();
	void initGrid();

	void initGObject();
	void updateGObjects();
	void update();
	void render(sf::RenderTarget& target);
	
};
//jedna klas GObject paramter wskaŸnik do objectu posiada, inicjowaæ obiekty bedzie Gmap
//dla ka¿dego Object tworzy GObject (Object). to w init GObject
//Rozmieszczenie za pomoc¹ logiki koordynaty z object
//stowrzyc pojedynczego zolnierza



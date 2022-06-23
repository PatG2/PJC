#include "CSimulation.h"
#include "GMap.h"

void Simulation::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(600, 400), "War", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(120);
	this->window->setVerticalSyncEnabled(false);
}

void Simulation::initSim()
{
	this->map = new Map;
	this->gmap = new GMap(map);
}

Simulation::Simulation() 
{
	this->initWindow();
	this->initSim();
}

Simulation::~Simulation() 
{
	delete this->window;
	delete this->map;
	delete this->gmap;
}



void Simulation::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render(*window);
	}

}

void Simulation::update()
{
	while (this->window->pollEvent(e))
	{
		if (e.Event::type == sf::Event::Closed) {
			
			this->window->close();
		}
			if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape) {
				
				this->window->close();
			}
			if (map->geChekcEnd() == true) {
				system("cls");
				std::cout << "Simulation over!!!"<<std::endl;
				break;
			}
		map->update();
		gmap->update();

	}
}


void Simulation::render(sf::RenderTarget& target)
{
	this->window->clear();

	this->gmap->render(*window);

	this->window->display();
}





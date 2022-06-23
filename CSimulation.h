#pragma once
#include <iostream>
#include<ctime>
#include<cstdlib>
#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Network.hpp"
#include <vector>


class GMap;
class Map;

/// Klasa odpowiedzialna za tworzenie symulacji
/// 
/// CSimulation zawiera niezbêdne atrybuty oraz metody do inicjalizacji okna symulacji.
class Simulation {
private:
	/// WskaŸnik na obiekt mapy logicznej
	Map* map;
	/// WskaŸnik na obiekt mapy graficznej
	GMap* gmap;
	/// WskaŸnik na typ sf::RenderWidnow
	sf::RenderWindow* window;
	/// Definicja zdarzeñ w grze
	sf::Event e;
	///@brief Funkcja inicjalizacji okna, tworzy nowy element w miejcu gdzie wskazuje *window
	void initWindow();
	/// @brief Funkcja odpowiedzialna za inicjalizacji symulacji, tworzy nowe obiekty w miejscu *map oraz *gmap
	void initSim();
public:
	/// Konstruktor
	///
	/// Tworzy obiekt klasy CSimulation
	Simulation();
	///Destruktor
	///
	/// Niszczy obiekt klasy CSimulation
	~Simulation();

	/// @brief Metoda z g³ówn¹ pêtl¹ symulacji
	void run();
	///@brief Metoda odpowiedzalna za aktualizacjie stanu symulacji
	void update();
	///@brief Metoda renderuje wszystkie obiekty w grze
	void render(sf::RenderTarget& target);
};
#pragma once
#include "CSimulation.h"
class Map;

///@brief Klasa zawieraj�ca implementacje obiekt�w na mapie
class Object
{
protected:
	/// @brief Zmienna przechowuj�ca punkty zdrowia obiektu
	int HP;
	/// @brief Zmienna przechowuj�ca informacje czy obiekt zosta� trafiony
	bool isHitted;
	/// @brief Zmienna przechowuj�ca numer dru�yny obiektu
	int team;
	/// @brief Wska�nik na obiekt mapy logicznej
	Map* map;
	/// @brief Wektor przechowuj�cy rozmiary obiektu
	sf::Vector2f size;

public:
	/// @brief Wektor przechowuj�cy pozycje obiektu
	sf::Vector2f position;
	/// @brief Konstruktur
	/// @param Wska�nik na mape
	Object(Map* map);
	/// @brief Destruktor
	virtual ~Object();
	/// @brief Metoda odpowiedzialna za aktualizacje stanu obiektu. Metoda wirtualna.
	virtual void update() = 0;
	/// @brief Metoda zwracaj�ca zasi�g obiektu. Metoda wirtualna.
	virtual float getRange() = 0;
	/// @brief Metoda zwracaj�ca punkty zdrowia obiektu. Metoda wirtualna.
	virtual int getHP()=0;
	/// @brief Metoda ustawiaj�ca punkty zdrowia obiektu. Metoda wirtualna.
	///@param HP Punkty zdrowia.
	virtual void setHP(int HP) = 0;
	/// @brief Metoda zwracaj�ca pozycj� obiektu.
	sf::Vector2f getPosition();
	/// @brief Metoda zwracaj�ca numer dru�yny obiektu.
	///@return team Numer dru�yny
	int getTeam();
	/// @brief Metoda zwracaj�ca informacj� czy obiekt zosta� trafiony
	/// @return isHitted Informacja o trafieniu
	bool getIsHitted();
	/// @brief Metoda zwracaj�ca rozmiar obiektu.
	/// @return size Wektor wielko�ci obiektu.
	sf::Vector2f getSize();
	/// @brief Metoda zwracaj�ca pozycj� obiekt�w w zasi�gu danego obiektu.
	///@param object Obiekt na mapie.
	/// @param range Zasi�g w kt�rym metoda zwraca obiekty
	/// @return Objects Lista obiekt�w w zasi�gu
	bool ObjectInRange(Object* object, float range);

};


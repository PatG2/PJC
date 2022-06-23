#pragma once
#include "CSimulation.h"
class Map;

///@brief Klasa zawieraj¹ca implementacje obiektów na mapie
class Object
{
protected:
	/// @brief Zmienna przechowuj¹ca punkty zdrowia obiektu
	int HP;
	/// @brief Zmienna przechowuj¹ca informacje czy obiekt zosta³ trafiony
	bool isHitted;
	/// @brief Zmienna przechowuj¹ca numer dru¿yny obiektu
	int team;
	/// @brief WskaŸnik na obiekt mapy logicznej
	Map* map;
	/// @brief Wektor przechowuj¹cy rozmiary obiektu
	sf::Vector2f size;

public:
	/// @brief Wektor przechowuj¹cy pozycje obiektu
	sf::Vector2f position;
	/// @brief Konstruktur
	/// @param WskaŸnik na mape
	Object(Map* map);
	/// @brief Destruktor
	virtual ~Object();
	/// @brief Metoda odpowiedzialna za aktualizacje stanu obiektu. Metoda wirtualna.
	virtual void update() = 0;
	/// @brief Metoda zwracaj¹ca zasiêg obiektu. Metoda wirtualna.
	virtual float getRange() = 0;
	/// @brief Metoda zwracaj¹ca punkty zdrowia obiektu. Metoda wirtualna.
	virtual int getHP()=0;
	/// @brief Metoda ustawiaj¹ca punkty zdrowia obiektu. Metoda wirtualna.
	///@param HP Punkty zdrowia.
	virtual void setHP(int HP) = 0;
	/// @brief Metoda zwracaj¹ca pozycjê obiektu.
	sf::Vector2f getPosition();
	/// @brief Metoda zwracaj¹ca numer dru¿yny obiektu.
	///@return team Numer dru¿yny
	int getTeam();
	/// @brief Metoda zwracaj¹ca informacjê czy obiekt zosta³ trafiony
	/// @return isHitted Informacja o trafieniu
	bool getIsHitted();
	/// @brief Metoda zwracaj¹ca rozmiar obiektu.
	/// @return size Wektor wielkoœci obiektu.
	sf::Vector2f getSize();
	/// @brief Metoda zwracaj¹ca pozycjê obiektów w zasiêgu danego obiektu.
	///@param object Obiekt na mapie.
	/// @param range Zasiêg w którym metoda zwraca obiekty
	/// @return Objects Lista obiektów w zasiêgu
	bool ObjectInRange(Object* object, float range);

};


#pragma once
#include "Soldier.h"
#include "Object.h"
#include "Tank.h"
#include "Tree.h"
#include "Base.h"
#include "Bullet.h"

/// @brief Klasa zawieraj�ca implementacje Mapy
class Map
{
private:
	/// @brief Wektor wska�nik�w do obiekt�w znajduj�cych si� na mapie
	std::vector<Object*> Objects;
	/// @brief Zmienna okre�laj�ca maksymaln� szeroko�� planszy
	int max_X;
	/// @brief Zmienna okre�laj�ca maksymaln� d�ugo�� planszy
	int max_Y;
	/// @brief Metoda inicjalizuj�ca obiekty na mapie
	void initObject();
	/// @brief Zmienna sprawdzaj�ca czy nasta� koniec symulacji
	bool checkEnd;
public:	
	/// @brief Konstruktor
	Map();
	/// @brief Destruktor
	virtual ~Map();
	/// @brief Metoda odpowiedzialna za aktualizacje stanu mapy
	void update();

	/// @brief Metoda zwracaj�ca obiekty istniej�ce na mapie
	/// @return Objects Wektor obiekt�w na mapie
	std::vector<Object*> getObjects();
	/// @brief Metoda zwracaj�ca rozmiar mapy
	/// @param xory Parametr wybieraj�cy kt�r� wielko�� chcemy zwr�ci� X czy Y
	/// @return W zalezno�ci od parametru max_X lub max_T
	int getMapSize(std::string xory);
	/// @brief Metoda inicjalizuj�ca pociski na mapie
	/// @param pox_X Pozycja na mapie(O� x)
	/// @param pox_y Pozycja na mapie(O� y)
	/// @param team Numer dru�yny do kt�rej przynale�y
	void initBullets(float pos_X, float pos_Y, bool team);
	/// @brief Metoda zwracaj�ca zmienn� warunkuj�c� koniec symulacji
	/// @return CheckEnd Zmienna sprawdzaj�ca czy nasta� koniec symulacji
	bool geChekcEnd();

	
};


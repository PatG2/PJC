#pragma once
#include "Soldier.h"
#include "Object.h"
#include "Tank.h"
#include "Tree.h"
#include "Base.h"
#include "Bullet.h"

/// @brief Klasa zawieraj¹ca implementacje Mapy
class Map
{
private:
	/// @brief Wektor wskaŸników do obiektów znajduj¹cych siê na mapie
	std::vector<Object*> Objects;
	/// @brief Zmienna okreœlaj¹ca maksymaln¹ szerokoœæ planszy
	int max_X;
	/// @brief Zmienna okreœlaj¹ca maksymaln¹ d³ugoœæ planszy
	int max_Y;
	/// @brief Metoda inicjalizuj¹ca obiekty na mapie
	void initObject();
	/// @brief Zmienna sprawdzaj¹ca czy nasta³ koniec symulacji
	bool checkEnd;
public:	
	/// @brief Konstruktor
	Map();
	/// @brief Destruktor
	virtual ~Map();
	/// @brief Metoda odpowiedzialna za aktualizacje stanu mapy
	void update();

	/// @brief Metoda zwracaj¹ca obiekty istniej¹ce na mapie
	/// @return Objects Wektor obiektów na mapie
	std::vector<Object*> getObjects();
	/// @brief Metoda zwracaj¹ca rozmiar mapy
	/// @param xory Parametr wybieraj¹cy któr¹ wielkoœæ chcemy zwróciæ X czy Y
	/// @return W zaleznoœci od parametru max_X lub max_T
	int getMapSize(std::string xory);
	/// @brief Metoda inicjalizuj¹ca pociski na mapie
	/// @param pox_X Pozycja na mapie(Oœ x)
	/// @param pox_y Pozycja na mapie(Oœ y)
	/// @param team Numer dru¿yny do której przynale¿y
	void initBullets(float pos_X, float pos_Y, bool team);
	/// @brief Metoda zwracaj¹ca zmienn¹ warunkuj¹c¹ koniec symulacji
	/// @return CheckEnd Zmienna sprawdzaj¹ca czy nasta³ koniec symulacji
	bool geChekcEnd();

	
};


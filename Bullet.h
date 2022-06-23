#pragma once
#include "Map.h"
#include "Movable.h"

#include<iostream>
#include<cstdlib>
#include<ctime>

/// @brief Klasa zawieraj�ca implementacje pocisk�w
class Bullet :
    public Movable
{
private:
    /// @brief Zmienna przechowuj�ca zasi�g ataku pocisku
    float hitRange;

public:
    /// @brief Konstruktor
    /// <param name="map">Wska�nik do mapy</param>
    /// <param name="pos_X">Pozycja na mapie(O� x)</param>
    /// <param name="pos_Y">Pozycja na mapie (O� y)</param>
    /// <param name="team">Numer dru�yny do kt�rej przynale�y</param>
    Bullet(Map* map, float pos_X, float pos_Y, bool team);
    /// @brief Destruktor
    virtual ~Bullet();
    /// @brief Metoda sprawdzaj�ca kolizje pocisku z obiektami na mapie
    /// @return bool Informacja o trafieniu
    bool collision();
    /// @brief Metoda implementujaca spos�b poruszania si� pocisk�w
    void move();
    /// @brief Metoda odpowiedzialna za aktualizacje stanu pocisku 
    void update();
};



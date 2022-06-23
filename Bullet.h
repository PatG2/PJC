#pragma once
#include "Map.h"
#include "Movable.h"

#include<iostream>
#include<cstdlib>
#include<ctime>

/// @brief Klasa zawieraj¹ca implementacje pocisków
class Bullet :
    public Movable
{
private:
    /// @brief Zmienna przechowuj¹ca zasiêg ataku pocisku
    float hitRange;

public:
    /// @brief Konstruktor
    /// <param name="map">WskaŸnik do mapy</param>
    /// <param name="pos_X">Pozycja na mapie(Oœ x)</param>
    /// <param name="pos_Y">Pozycja na mapie (Oœ y)</param>
    /// <param name="team">Numer dru¿yny do której przynale¿y</param>
    Bullet(Map* map, float pos_X, float pos_Y, bool team);
    /// @brief Destruktor
    virtual ~Bullet();
    /// @brief Metoda sprawdzaj¹ca kolizje pocisku z obiektami na mapie
    /// @return bool Informacja o trafieniu
    bool collision();
    /// @brief Metoda implementujaca sposób poruszania siê pocisków
    void move();
    /// @brief Metoda odpowiedzialna za aktualizacje stanu pocisku 
    void update();
};



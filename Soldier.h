#pragma once
#include "Map.h"
#include "Movable.h"

#include<iostream>
#include<cstdlib>
#include<ctime>
/// @brief Klasa zawieraj�ca implementacje �o�nierzy
class Soldier :
    public Movable
{
public:
    /// @brief Konstruktor
    /// <param name="map">Wska�nik do mapy</param>
    /// <param name="pos_X">Pozycja na mapie(O� x)</param>
    /// <param name="pos_Y">Pozycja na mapie (O� y)</param>
    /// <param name="team">Numer dru�yny do kt�rej przynale�y</param>
    Soldier(Map* map, float pos_X, float pos_Y, int team);
    /// @brief Destruktor
    virtual ~Soldier();

    /// @brief Metoda implementujaca spos�b poruszania si� �o�nierzy
    void move();
    /// @brief Metoda odpowiedzialna za aktualizacje stanu �o�nierza
    void update();

};
 

#pragma once
#include "Map.h"
#include "Movable.h"

#include<iostream>
#include<cstdlib>
#include<ctime>
/// @brief Klasa zawieraj¹ca implementacje ¿o³nierzy
class Soldier :
    public Movable
{
public:
    /// @brief Konstruktor
    /// <param name="map">WskaŸnik do mapy</param>
    /// <param name="pos_X">Pozycja na mapie(Oœ x)</param>
    /// <param name="pos_Y">Pozycja na mapie (Oœ y)</param>
    /// <param name="team">Numer dru¿yny do której przynale¿y</param>
    Soldier(Map* map, float pos_X, float pos_Y, int team);
    /// @brief Destruktor
    virtual ~Soldier();

    /// @brief Metoda implementujaca sposób poruszania siê ¿o³nierzy
    void move();
    /// @brief Metoda odpowiedzialna za aktualizacje stanu ¿o³nierza
    void update();

};
 

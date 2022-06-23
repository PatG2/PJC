#pragma once
#include "Map.h"
#include "Movable.h"
#include "Tree.h"

#include<iostream>
#include<cstdlib>
#include<ctime>
/// @brief Klasa zawieraj�ca implementacje czo�g�w
class Tank :
    public Movable
{


public:
    /// @brief Konstruktor
    /// <param name="map">Wska�nik do mapy</param>
    /// <param name="pos_X">Pozycja na mapie(O� x)</param>
    /// <param name="pos_Y">Pozycja na mapie (O� y)</param>
    /// <param name="team">Numer dru�yny do kt�rej przynale�y</param>
    Tank(Map* map, float pos_X, float pos_Y, int team);
    /// @brief Destruktor
    virtual ~Tank();
    /// @brief Metoda sprawdzaj�ca kolizje czo�gu z drzewami na mapie
    /// @return bool Informacja czy nast�pi�a kolizja z drzewem
    bool collisionTree();
    /// @brief Metoda implementujaca spos�b poruszania si� czo�g�w
    void move();
    /// @brief Metoda odpowiedzialna za aktualizacje stanu czo�gu
    void update();
       

};


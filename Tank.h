#pragma once
#include "Map.h"
#include "Movable.h"
#include "Tree.h"

#include<iostream>
#include<cstdlib>
#include<ctime>
/// @brief Klasa zawieraj¹ca implementacje czo³gów
class Tank :
    public Movable
{


public:
    /// @brief Konstruktor
    /// <param name="map">WskaŸnik do mapy</param>
    /// <param name="pos_X">Pozycja na mapie(Oœ x)</param>
    /// <param name="pos_Y">Pozycja na mapie (Oœ y)</param>
    /// <param name="team">Numer dru¿yny do której przynale¿y</param>
    Tank(Map* map, float pos_X, float pos_Y, int team);
    /// @brief Destruktor
    virtual ~Tank();
    /// @brief Metoda sprawdzaj¹ca kolizje czo³gu z drzewami na mapie
    /// @return bool Informacja czy nast¹pi³a kolizja z drzewem
    bool collisionTree();
    /// @brief Metoda implementujaca sposób poruszania siê czo³gów
    void move();
    /// @brief Metoda odpowiedzialna za aktualizacje stanu czo³gu
    void update();
       

};


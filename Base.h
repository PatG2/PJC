#pragma once
#include "NotMovable.h"

///@brief Klasa zawieraj¹ca implementacje bazy
class Base :
    public NotMovable
{
public:
    /// <summary>
    /// @brief Konstruktor
    /// </summary>
    /// <param name="map">WskaŸnik do mapy</param>
    /// <param name="pos_X">Pozycja na mapie(Oœ x)</param>
    /// <param name="pos_Y">Pozycja na mapie (Oœ y)</param>
    /// <param name="size_X">Wielkoœæ wymiar na osi x</param>
    /// <param name="size_Y">Wielkoœæ wymiar na osi y</param>
    /// <param name="team">Numer dru¿yny do której przynale¿y</param>
    /// <param name="HP">Iloœæ punktów zdrowia</param>
    Base(Map* map, float pos_X, float pos_Y, float size_X, float size_Y, int team, int HP);
    /// @brief Destruktor
    virtual ~Base();
    /// @brief Metoda odpowiedzialna za aktualizacje stanu bazy
    void update();
  

};


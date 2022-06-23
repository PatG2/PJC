#pragma once
#include "NotMovable.h"

///@brief Klasa zawieraj�ca implementacje bazy
class Base :
    public NotMovable
{
public:
    /// <summary>
    /// @brief Konstruktor
    /// </summary>
    /// <param name="map">Wska�nik do mapy</param>
    /// <param name="pos_X">Pozycja na mapie(O� x)</param>
    /// <param name="pos_Y">Pozycja na mapie (O� y)</param>
    /// <param name="size_X">Wielko�� wymiar na osi x</param>
    /// <param name="size_Y">Wielko�� wymiar na osi y</param>
    /// <param name="team">Numer dru�yny do kt�rej przynale�y</param>
    /// <param name="HP">Ilo�� punkt�w zdrowia</param>
    Base(Map* map, float pos_X, float pos_Y, float size_X, float size_Y, int team, int HP);
    /// @brief Destruktor
    virtual ~Base();
    /// @brief Metoda odpowiedzialna za aktualizacje stanu bazy
    void update();
  

};


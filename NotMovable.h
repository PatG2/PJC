#pragma once
#include "Object.h"

///@brief Klasa zawieraj¹ca implementacje nie poruszaj¹cych siê obiektów na mapie
class NotMovable :
    public Object
{
private:
protected:
    
public:
    /// @brief Konstruktor
    /// @param map WskaŸnik do mapy
    NotMovable(Map* map);
    /// @brief Destruktor
    virtual ~NotMovable();
    /// @brief Metoda zwracaj¹ca zasiêg obiektu
    /// @return range Zasieg obiekty
    float getRange();
    /// @brief Metoda zwracaj¹ca punkty zdrowia obiektu
    /// @return HP Punkty zdrowia obiekty
    int getHP();
    /// @brief Metoda ustawiaj¹ca punkty ¿ycia obiektu
    /// @param HP Punkty zdrowia obiektu
    void setHP(int HP);
};


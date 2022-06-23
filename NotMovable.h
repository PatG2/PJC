#pragma once
#include "Object.h"

///@brief Klasa zawieraj�ca implementacje nie poruszaj�cych si� obiekt�w na mapie
class NotMovable :
    public Object
{
private:
protected:
    
public:
    /// @brief Konstruktor
    /// @param map Wska�nik do mapy
    NotMovable(Map* map);
    /// @brief Destruktor
    virtual ~NotMovable();
    /// @brief Metoda zwracaj�ca zasi�g obiektu
    /// @return range Zasieg obiekty
    float getRange();
    /// @brief Metoda zwracaj�ca punkty zdrowia obiektu
    /// @return HP Punkty zdrowia obiekty
    int getHP();
    /// @brief Metoda ustawiaj�ca punkty �ycia obiektu
    /// @param HP Punkty zdrowia obiektu
    void setHP(int HP);
};


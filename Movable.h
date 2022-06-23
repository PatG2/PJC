#pragma once

#include "Object.h"

///@brief Klasa zawieraj�ca implementacje poruszaj�cych si� obiekt�w na mapie
class Movable :
    public Object
{
private:
protected:
    /// @brief Parametr opisuj�cy pr�dko�� poruszania si� jednostek na mapie
    float movmentSpeed;
    /// @brief Parametr opisuj�cy zasi�g widzenia oraz ataku obiekt�w na mapie
    float range;
    
public:
    /// @brief Konstruktor
    /// @param map Wska�nik do mapy
    Movable(Map* map);
    /// @brief Destruktor
    virtual ~Movable();

    /// @brief Metoda implementuj�ca poruszanie si� obiek�w. Metoda wirtualna.
    virtual void move() = 0;
    /// @brief Metoda odpowiedzialna za aktualizacje stanu obiektu. Metoda wirtualna.
    virtual void update() = 0;

    /// @brief Metoda ustawiaj�ca punkty �ycia obiektu
    /// @param HP Punkty zdrowia obiektu
    void setHP(int HP);
    /// @brief Metoda zwracaj�ca punkty zdrowia obiektu
    /// @return HP Punkty zdrowia obiekty
    int getHP();
    /// @brief Metoda zwracaj�ca zasi�g obiektu
    /// @return range Zasieg obiekty
    float getRange();
    /// @brief Metoda implemetuj�ca spos�b atakowania obiektu
    /// @param object Wska�nik do obiektu
    void attack(Object *object);

    
};


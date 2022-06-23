#pragma once

#include "Object.h"

///@brief Klasa zawieraj¹ca implementacje poruszaj¹cych siê obiektów na mapie
class Movable :
    public Object
{
private:
protected:
    /// @brief Parametr opisuj¹cy prêdkoœæ poruszania siê jednostek na mapie
    float movmentSpeed;
    /// @brief Parametr opisuj¹cy zasiêg widzenia oraz ataku obiektów na mapie
    float range;
    
public:
    /// @brief Konstruktor
    /// @param map WskaŸnik do mapy
    Movable(Map* map);
    /// @brief Destruktor
    virtual ~Movable();

    /// @brief Metoda implementuj¹ca poruszanie siê obieków. Metoda wirtualna.
    virtual void move() = 0;
    /// @brief Metoda odpowiedzialna za aktualizacje stanu obiektu. Metoda wirtualna.
    virtual void update() = 0;

    /// @brief Metoda ustawiaj¹ca punkty ¿ycia obiektu
    /// @param HP Punkty zdrowia obiektu
    void setHP(int HP);
    /// @brief Metoda zwracaj¹ca punkty zdrowia obiektu
    /// @return HP Punkty zdrowia obiekty
    int getHP();
    /// @brief Metoda zwracaj¹ca zasiêg obiektu
    /// @return range Zasieg obiekty
    float getRange();
    /// @brief Metoda implemetuj¹ca sposób atakowania obiektu
    /// @param object WskaŸnik do obiektu
    void attack(Object *object);

    
};


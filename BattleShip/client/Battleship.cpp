#include "Battleship.h"

Battleship::Battleship() : Ship(4)
{
    m_Type = BATTLESHIP;
    m_hp = m_length;
}

Battleship::~Battleship()
{
}

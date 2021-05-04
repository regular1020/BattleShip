#include "Ship.h"

Ship::Ship(int length)
{
    m_length = length;
    m_Pos.resize(length);
}


Ship::~Ship()
{
}

void Ship::SetPosition(int index, const Position & pos)
{
    m_Pos[index] = pos;
}


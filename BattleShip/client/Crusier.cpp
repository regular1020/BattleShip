#include "Crusier.h"

Cruiser::Cruiser() : Ship(3)
{
    m_Type = CRUISER;
    m_hp = m_length;
}

Cruiser::~Cruiser()
{
}
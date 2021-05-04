#include "Destroyer.h"

Destroyer::Destroyer() : Ship(2)
{
    m_Type = DESTROYER;
    m_hp = m_length;
}

Destroyer::~Destroyer()
{
}
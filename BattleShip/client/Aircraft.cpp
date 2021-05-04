#include "Aircraft.h"

Aircraft::Aircraft() : Ship(5)
{
    m_Type = AIRCRAFT;
    m_hp = m_length;
}

Aircraft::~Aircraft()
{
}
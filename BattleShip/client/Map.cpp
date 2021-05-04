#include "Map.h"

Map::Map()
{
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            m_data[i][j] = DATA_NONE;
        }
    }
}

Map::~Map()
{
}

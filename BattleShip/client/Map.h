// BATTLESHP PROJECT
// 최종수정일자 2018.6.2
// 학번: 20171624 이름: 박정규

#pragma once
#include "../commonDefine.h"

class Map
{
public:
    Map();
    ~Map();

    ShipType GetData(const Position& pos)
    {
        if (pos.x >= MAP_SIZE || pos.y >= MAP_SIZE || pos.x < 0 || pos.y < 0)
        {
            return DATA_ERROR;
        }
        return m_data[pos.x][pos.y];
    }
    void SetData(const Position& pos, ShipType type)
    {
        if (pos.x >= MAP_SIZE || pos.y >= MAP_SIZE || pos.x < 0 || pos.y < 0)
        {
            return;
        }

        m_data[pos.x][pos.y] = type;
    }

protected:
    ShipType m_data[MAP_SIZE][MAP_SIZE];
};
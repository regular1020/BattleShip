// BATTLESHP PROJECT
// 최종수정일자 2018.6.2
// 학번: 20171624 이름: 박정규

#pragma once
#include <vector>
#include <random>
#include <iostream>
#include <ncurses.h>
#include <string.h>

using namespace std;

static const int MAP_SIZE = 8;

struct Position
{
    Position() : x(0), y(0) {}
    int x;
    int y;

    Position operator+(const Position& pos) const
    {
        Position returnpos;
        returnpos.x = x + pos.x;
        returnpos.y = y + pos.y;
        return returnpos;
    }

    Position operator-(const Position& pos) const{
        Position returnpos;
        returnpos.x = x - pos.y;
        returnpos.y = y - pos.y;
        return returnpos;
    }

    bool operator == (const Position& pos) const
    {
        if (x == pos.x && y == pos.y)
        {
            return true;
        }
        return false;
    }
};

/*ostream& operator << (ostream& os, Position pos)
{
    os << "x : " << pos.x << " ";
    os << "y : " << pos.y;
    return os;
}*/

enum ShipType
{
    DATA_ERROR = -1,
    DATA_NONE,
    AIRCRAFT,
    BATTLESHIP,
    CRUISER,
    DESTROYER,
    NOSHIP,
    SHIP,
    DESTROYEDSHIP,
};

enum HitResult
{
    OUTINDEX = -1,
    MISS,
    HIT,
    DESTROY,
};

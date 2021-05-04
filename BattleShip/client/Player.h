#pragma once
#include "../commonDefine.h"
// BATTLESHP PROJECT
// 최종수정일자 2018.6.2
// 학번: 20171624 이름: 박정규

class Map;
class Ship;

#define SHIPS std::vector<Ship*>

class Player
{
public:
    Player();
    ~Player();
    Map *Getmap() const {return m_Map;};


    // Defender
    void SetupShips(const SHIPS& ships);
    HitResult HitCheck(const Position& pos);
    SHIPS GetShips() const {return m_Ships;};

    // Attacker
    Position GetAttackPos();

protected:
    Map* m_Map;
    SHIPS m_Ships;
};
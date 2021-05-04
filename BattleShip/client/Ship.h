// BATTLESHP PROJECT
// 최종수정일자 2018.6.2
// 학번: 20171624 이름: 박정규

#pragma once
#include "../commonDefine.h"

class Ship
{
public:
    Ship(int length);
    virtual ~Ship();

    int Getlength() const {return m_length;};
    ShipType GetType() const {return m_Type;};
    void SetPosition(int index, const Position& pos);
    vector<Position> GetPosition() {return m_Pos;};
    int Gethp() {return m_hp;};
    void reducehp() {m_hp--;};
    void SetType(ShipType type) {m_Type = type;};

protected:
    ShipType m_Type;
    int m_length;
    int m_hp;
    vector<Position> m_Pos;
};
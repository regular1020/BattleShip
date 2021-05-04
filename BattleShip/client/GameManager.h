// BATTLESHP PROJECT
// 최종수정일자 2018.6.2
// 학번: 20171624 이름: 박정규

#pragma once
#include "../commonDefine.h"
#include "../BattleShipApp.h"

class Player;

class GameManager
{
public:
    GameManager();
    ~GameManager();

    void Init();
    void Play();
    void Render();
    void Destroy();

protected:
    Player* m_Attacker;
    Player* m_Defender;
    BattleShipApp bsApp;
    int m_counter = 0;

};
// BATTLESHP PROJECT
// 최종수정일자 2018.6.2
// 학번: 20171624 이름: 박정규

#pragma once
#include "commonDefine.h"
#include "BattleShipMap.h"
#include "StatPane.h"
#include "InputPane.h"

class BattleShipApp
{
public:
    BattleShipApp() {};
    ~BattleShipApp() {};

    BattleShipMap* Getattackmap();
    BattleShipMap* Getdefencemap();
    void Play();
    void Init();
    void Render();
    void Destroy();
    int Getx() {return x;};
    int Gety() {return y;};
    char* Getch() {return ch;};
    InputPane* Getinputpane() {return m_pInputPane;};
    void Initposition() 
    {x = -1;
     y = -1;};

protected:
    BattleShipMap* m_aMap;
    BattleShipMap* m_dMap;
    StatPane* m_pStatPane;
    InputPane* m_pInputPane;
    int x = -1;
    int y = -1;
    char ch[2];

};
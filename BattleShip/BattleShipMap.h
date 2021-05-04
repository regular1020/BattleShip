#include "Pane.h"
#include "commonDefine.h"
// BATTLESHP PROJECT
// 최종수정일자 2018.6.2
// 학번: 20171624 이름: 박정규

class BattleShipMap : Pane
{
public:
    BattleShipMap(int x, int y, int width, int height);
    ~BattleShipMap();

    void Draw();
    void Changestat(Position& pos, char c);

protected:
    char m_mapData[MAP_SIZE][MAP_SIZE];
};
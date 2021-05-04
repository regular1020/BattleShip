// BATTLESHP PROJECT
// 최종수정일자 2018.6.2
// 학번: 20171624 이름: 박정규

#include "Pane.h"

class StatPane : Pane
{
public:
    StatPane(int x, int y, int width, int height);
    ~StatPane() {};

    virtual void Draw();
};


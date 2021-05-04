// BATTLESHP PROJECT
// 최종수정일자 2018.6.2
// 학번: 20171624 이름: 박정규

#pragma once
#include "commonDefine.h"

class Pane
{
public:
    Pane(int x, int y, int width, int height);
    virtual ~Pane();

    virtual void Draw();
    WINDOW* Getwin() {return m_pWindow;};

protected:
    int m_width, m_height;
    int m_x, m_y;
    WINDOW* m_pWindow;

};
// BATTLESHP PROJECT
// 최종수정일자 2018.6.2
// 학번: 20171624 이름: 박정규

#include "Pane.h"

class InputPane : public Pane
{
public:
    InputPane(int x, int y, int width, int height);
    ~InputPane();

    virtual void Draw();

};
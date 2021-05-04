#include "BattleShipApp.h"
#include "commonDefine.h"



void BattleShipApp::Init()
{
    initscr();
    start_color();
    cbreak();
    refresh();

    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);

    m_aMap = new BattleShipMap(4,20, MAP_SIZE+3, MAP_SIZE+2);
    m_dMap = new BattleShipMap(4, 4, MAP_SIZE+3, MAP_SIZE+2);
    m_pStatPane = new StatPane(30, 3, 30, 7);
    m_pInputPane = new InputPane(30, 15, 30, 4);
}

void BattleShipApp::Play()
{
    move(17, 40);
    printw("      ");
    move(17,40);
    /*keypad(m_pInputPane->Getwin(), false);
    scanw("%s", ch);
    if (ch[0] <= 72 && ch[0] >= 65)
    {
        x = ch[0] - 65;
    }
    else
    {
        return;
    }
    if (ch[1] <'9' && ch[1] > '0')
    {
        y = ch[1] -49;
    }
    else
    {return;}
    Position pos;
    pos.x = x;
    pos.y = y;
    m_aMap->Changestat(pos, '1');
    m_aMap->Draw();*/
    refresh();
}

void BattleShipApp::Render()
{
    mvprintw(1, 1, "<< Battle Ship Game >> ");

    m_aMap->Draw();
    m_dMap->Draw();
    m_pStatPane->Draw();
    m_pInputPane->Draw();

    refresh();

    
}

void BattleShipApp::Destroy()
{
    getch();
    endwin();
    delete m_aMap;
    delete m_dMap;
}

BattleShipMap* BattleShipApp::Getattackmap()
{
    return m_aMap;
}

BattleShipMap* BattleShipApp::Getdefencemap()
{
    return m_dMap;
}
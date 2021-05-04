#include "BattleShipMap.h"

BattleShipMap::BattleShipMap(int x, int y, int width, int height) : Pane(x, y, width, height)
{
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            m_mapData[i][j] = '0';
        }
    }

    for (int i = 0; i < MAP_SIZE; i++)
    {
        mvprintw(i + m_y+1, m_x-1, "%c", 'A' + i);
        mvprintw(m_y + m_height, m_x+2+i, "%d", 1+i);
    }

    mvwprintw(m_pWindow, 0, 3, "< MAP >");
}

BattleShipMap::~BattleShipMap()
{
}

void BattleShipMap::Draw()
{
    wattron(m_pWindow, COLOR_PAIR(1));
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            mvwprintw(m_pWindow, i+1, j+2, "%c", m_mapData[i][j]);
        }
    }
    wattroff(m_pWindow, COLOR_PAIR(1));

    wrefresh(m_pWindow);
}

void BattleShipMap::Changestat(Position& pos, char c)
{
    m_mapData[pos.x][pos.y] = c;
}
#include "../commonDefine.h"
#include "GameManager.h"
#include "Player.h"
#include "Battleship.h"
#include "Aircraft.h"
#include "Ship.h"
#include "Crusier.h"
#include "Destroyer.h"
#include "../BattleShipApp.h"
#include "Map.h"
#include <string.h>
#include <unistd.h>

GameManager::GameManager()
{
    m_Attacker = NULL;
    m_Defender = NULL;
}

GameManager::~GameManager()
{
    if (m_Attacker)
    {
        delete m_Attacker;
        m_Attacker = NULL;
    }
    if (m_Defender)
    {
        delete m_Defender;
        m_Defender = NULL;
    }
}

void GameManager::Init()
{
    m_Attacker = new Player();
    m_Defender = new Player();

    std::vector<Ship*> vecShip;
    vecShip.push_back(new Aircraft());
    vecShip.push_back(new Battleship());
    vecShip.push_back(new Cruiser());
    vecShip.push_back(new Destroyer());
    vecShip.push_back(new Destroyer());

    m_Defender->SetupShips(vecShip);

    bsApp.Init();

    for (int i = 0; i < m_Defender->GetShips().size(); i++)
    {
        char shipchar;
        if (m_Defender->GetShips()[i]->GetType() == AIRCRAFT)
        {
            shipchar = 'A';
        }
        else if (m_Defender->GetShips()[i]->GetType() == BATTLESHIP)
        {
            shipchar = 'B';
        }
        else if (m_Defender->GetShips()[i]->GetType() == CRUISER)
        {
            shipchar = 'C';
        }
        else if (m_Defender->GetShips()[i]->GetType() == DESTROYER)
        {
            shipchar = 'D';
        }
        for (int j = 0; j < m_Defender->GetShips()[i]->GetPosition().size(); j++)
        {
            bsApp.Getdefencemap()->Changestat(m_Defender->GetShips()[i]->GetPosition()[j], shipchar);
        }
    }

}

void GameManager::Play()
{
    int gametry = 10;
    double totalcount = 0;
    for (int i = 0; i < gametry; i++)
    {
        bsApp.Render();
        m_counter = 0;
        Init();
    while (true)
    {
        m_counter++;
        bsApp.Play();

        /*char* ch = bsApp.Getch();
        if (strcmp(ch,"gg") == 0)
        {
            break;
        }

        int x = bsApp.Getx();
        int y = bsApp.Gety();*/
        Position pos;
        pos = m_Attacker->GetAttackPos();
        HitResult result = m_Defender->HitCheck(pos);
        if (result == OUTINDEX)
        {
            move(8,32); 
            printw("                  ");
            move(8,32); 
            printw("worng index");
            m_counter--;
            continue;
        }
        else if (result == MISS)
        {
            move(8,32); 
            printw("                    ");
            move(8,32); 
            printw("Current : Miss");
            bsApp.Getattackmap()->Changestat(pos, '1');
            m_Attacker->Getmap()->SetData(pos, NOSHIP);
        }
        else if (result == HIT)
        {
            move(8,32);
            printw("                   ");
            move(8,32); 
            printw("Current : Hit");
            bsApp.Getattackmap()->Changestat(pos, '1');
            bsApp.Getdefencemap()->Changestat(pos, 'X');
            m_Attacker->Getmap()->SetData(pos, SHIP);
        }
        if (result == DESTROY)
        {
            move(8,32);
            printw("                   ");
            bsApp.Getattackmap()->Changestat(pos, '1');
            bsApp.Getdefencemap()->Changestat(pos, 'X');
            m_Attacker->Getmap()->SetData(pos, DESTROYEDSHIP);
            for (int i = 0; i < m_Defender->GetShips().size(); i++)
            {
                if (m_Defender->GetShips()[i]->Gethp() == 0)
                {
                    move(8,32);
                    if (m_Defender->GetShips()[i]->GetType() == AIRCRAFT)
                    {
                        printw("AIRCRAFT DESTROY");
                    }
                    else if (m_Defender->GetShips()[i]->GetType() == BATTLESHIP)
                    {
                        printw("BATTLESHIP DESTROY");
                    }
                    else if (m_Defender->GetShips()[i]->GetType() == CRUISER)
                    {
                        printw("CRUISER DESTROY");
                    }
                    else if (m_Defender->GetShips()[i]->GetType() == DESTROYER)
                    {
                        printw("DESTROYER DESTROY");
                    }
                    m_Defender->GetShips()[i]->SetType(DATA_NONE);
                }
            }
        }
        bsApp.Getattackmap()->Draw();
        bsApp.Render();
        bool isend = true;
        for (auto pShips : m_Defender->GetShips())
        {
            if (pShips->GetType() != DATA_NONE)
            {
                isend = false;
            }
        }
        if (isend)
        {
            move(8,32);
            printw("                  ");
            break;
        }
        bsApp.Initposition();
    }
    totalcount += m_counter;
    }
    totalcount = totalcount/10;
    string s = to_string(totalcount);
    char const *pchar = s.c_str();
    move(8,32);
    printw(pchar);
    printw(" times cost");
}

void GameManager::Render()
{
    bsApp.Render();
}

void GameManager::Destroy()
{
    bsApp.Destroy();
}
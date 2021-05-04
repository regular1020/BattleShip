#include "Player.h"
#include "Map.h"
#include "Ship.h"
#include <unistd.h>

Player::Player()
{
    m_Map = new Map();
}

Player::~Player()
{
    delete m_Map;

    for(auto pShip : m_Ships)
    {
        if(pShip)
        {
            delete pShip;
        }
    }
    m_Ships.clear();
}

void Player::SetupShips(const SHIPS& ships)
{
    m_Ships = ships;

    for(auto pShip : m_Ships)
    {
        srand((unsigned)time(NULL));
        while(true)
        {
            Position pos;
            pos.x = rand() % MAP_SIZE;
            pos.y = rand() % MAP_SIZE;
            ShipType dataType = m_Map->GetData(pos);
            if(dataType != DATA_NONE)
            {
                continue;
            }

            Position dir;

            if(rand() % 2){
                dir.x = rand()%2 ? 1 : -1;
            }
            else{
                dir.y = rand()%2 ? 1 : -1;
            }
            
            pos = pos + dir;

            bool bSuccess = true;

            for (int i = 0; i < pShip->Getlength(); i++)
            {
                pos = pos + dir;
                ShipType dataType = m_Map->GetData(pos);
                if(dataType != DATA_NONE)
                {
                    bSuccess = false;
                    break;
                }

                pShip->SetPosition(i, pos);
            }

            if (bSuccess)
            {   
                for (int i = 0; i < pShip->Getlength(); i++)
                {
                    m_Map->SetData(pShip->GetPosition()[i], pShip->GetType());
                }
                break;
            }
        }
    }
}

HitResult Player::HitCheck(const Position& pos)
{
    if (pos.x < 0 || pos.y < 0 || pos.x > 8 || pos.y > 8)
    {
        return OUTINDEX;
    }
    for (auto pShip : m_Ships)
    {
        for (int i = 0; i < pShip->GetPosition().size(); i++)
        {
            if (pShip->GetPosition()[i] == pos)
            {
                pShip->reducehp();
                if(pShip->Gethp() == 0)
                {
                    return DESTROY;
                }
                return HIT;

            }
        }
    }
    return MISS;
}

Position Player::GetAttackPos()
{
    usleep(100*100);
    Position pos;
    srand((unsigned)time(NULL));
    do
    {
        pos.x = rand() % MAP_SIZE;
        pos.y = rand() % MAP_SIZE;
    }while (m_Map->GetData(pos) != DATA_NONE);


    return pos;
}


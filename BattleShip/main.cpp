#include "./client/GameManager.h"
#include "BattleShipApp.h"

int main()
{
    GameManager gm;
    gm.Init();
    gm.Render();
    gm.Play();
    gm.Destroy();
    return 0;
}

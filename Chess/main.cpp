#include "main.h"
#include "GameManager.h"

int main()
{
    keybd_event(VK_MENU, 0x38, 0, 0);
    keybd_event(VK_SPACE, 0x39, 0, 0);
    keybd_event(0x58, 0x2d, 0, 0);
    keybd_event(VK_MENU, 0xb8, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_SPACE, 0x39, KEYEVENTF_KEYUP, 0);
    keybd_event(0x58, 0x2d, KEYEVENTF_KEYUP, 0);
    Sleep(100);
    
    int gameState = 0;

    while (1)
    {
	    GameManager Game;
        gameState = Game.menu();
        if (gameState == 1)
            break;
    }

    return 0;
}
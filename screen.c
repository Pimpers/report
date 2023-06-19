#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <string.h>
#include "screen.h"

int main() 
{
    char screenBuf[1300];
    int input = 0;
    int secondInput = 0;
    
    while (1)
    {
        system("cls");
        setFirstToScreenBuffer(screenBuf, 30, 15);
        scanf("%d", &input);
        
        if (input == 1)
        {
            loading();
            Game();
            
            tryagin(screenBuf, 30, 15);
            scanf("%d", &input);
            
            if (input == 1)
            {
                loading();
                Game();
                tryagin(screenBuf, 30, 15);
                scanf("%d", &input);
            }
            else if (input == 2)
            {
                loading();
                setFirstToScreenBuffer(screenBuf, 30, 15);
                scanf("%d", &secondInput);
                
                if (secondInput == 2)
                {
                    loading();
                    setsecondToscreenBuf(screenBuf, 30, 15);
                    scanf("%d", &input);
                }
            }
        }
        else if (input == 2)
        {
            setsecondToscreenBuf(screenBuf, 30, 15);
            scanf("%d", &input);
            
            if (input == 1)
            {
                continue;
            }
            else if (input == 2)
            {
                loading();
                setsecondToscreenBuf(screenBuf, 30, 15);
                scanf("%d", &input);
            }
        }
        else if (input == 3)
        {
            break;
        }
    }

    return 0;
}
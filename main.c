#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include"screen.h"
int clearBuffer(char* screenBuf, int width, int height)
{
    int i = 0;    
    int j = 0;      
    while (j < height)
    {
        while (i < width + 1)
        {
            if (i == width)
                screenBuf[i + (j* (width + 1))] = '\n';
            else
            {
                if (i == 0 || i == (width - 1) || j == 0 || j == (height - 1))
                    screenBuf[i + (j * (width + 1))] = '#';
                else
                    screenBuf[i + (j * (width + 1))] = ' ';
            }
            i = i + 1;
        }
        i = 0;
        j = j + 1;
    }
    screenBuf[height * (width + 1) - 1] = '\0';
    Sleep(500); 
}
int writeStringToBuffer(char* screenBuf, const char* string, int x, int y, int width)
{
    int i = 0;
    while (string[i] != '\0')
    {
        screenBuf[x + i + (y * (width + 1))] = string[i];
        system("cls");
        printf("%s\ninput> ", screenBuf);  
        Sleep(10);  
        i++;
    }
    Sleep(100);
    return 0;
}
int setFirstToScreenBuffer(char* screenBuf, int width, int height)
{
    system("cls");
    clearBuffer(screenBuf,30,15);
    writeStringToBuffer(screenBuf,"Marking the professor's name",1,4,width);
    writeStringToBuffer(screenBuf,"1.play", 12,7,width);
    writeStringToBuffer(screenBuf,"2.menu",12,8,width);
    writeStringToBuffer(screenBuf,"3.exit",12,9,width);
}

int setsecondToscreenBuf(char* screenBuf, int width, int height)
{
    system("cls");
    clearBuffer(screenBuf,30,15);
     writeStringToBuffer(screenBuf,"[professor name]",6,1,width);
     writeStringToBuffer(screenBuf,"kimyoungchul",7,3,width);
     writeStringToBuffer(screenBuf,"leeeunseok",7,4,width);
     writeStringToBuffer(screenBuf,"leesung-hyun",7,5,width);
     writeStringToBuffer(screenBuf,"yoonsumi",7,6,width);
     writeStringToBuffer(screenBuf,"kimsunyoung",7,7,width);
     writeStringToBuffer(screenBuf,"nounseok",7,8,width);
     writeStringToBuffer(screenBuf,"return main?",8,10,width);
     writeStringToBuffer(screenBuf,"1.yes        2.no",5,12,width);                 
}
int tryagin(char* screenBuf, int width, int height)
{
    system("cls");
    clearBuffer(screenBuf,30,15);
     writeStringToBuffer(screenBuf,"try again?",10,3,width);
     writeStringToBuffer(screenBuf,"professor name hint is menu",2,6,width);
     writeStringToBuffer(screenBuf,"1.again  or  2.main",7,8,width);
}

// 로딩창
int loading()
{
    clock_t SJTstart;
    SJTstart = clock();

    int i = 0;

    while (i< 4) // 점점의 갯수
    {
        system("cls");

        COORD pos = { 0,0 };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

        printf("loading : "); //로징창

        int j = 0;
        while (j < i)
        {
            printf("*");
            j=j+1;
        }
        Sleep(500); // 시간 조절
        i = i + 1;
    }

    clock_t SJTend;
    SJTend = clock();

    return 0;
}

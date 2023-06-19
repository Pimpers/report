#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <string.h>
#include"screen.h"
int gameclearBuffer(char* screenBuf, int width, int height)
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
         if (j != height - 1)
            screenBuf[i + (j * (width + 1))] = '\n'; 
        i = 0;
        j = j + 1;
        
    }
    screenBuf[height * (width + 1) - 1] = '\0';

    Sleep(10); 
}
int gamewriteStringToBuffer(char* screenBuf, const char* string, int x, int y, int width) {
    int stringLength = strlen(string);

    // 이전 문자열 지우기
    for (int i = 0; i < stringLength; i++) {
        screenBuf[x + i + (y * (width + 1))] = ' ';
    }

    // 새로운 문자열 쓰기
    int i = 0;
    while (string[i] != '\0') {
        screenBuf[x + i + (y * (width + 1))] = string[i];
        i++;
    }

    system("cls");
    printf("%s\ninput> ", screenBuf);
    Sleep(10);

    return 0;
}
int getRandomNumber(int min, int max)
{
    return min + rand() % (max - min + 1);
}
void eraseStringFromBuffer(char* screenBuf, int x, int y, int width, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (x + i < width)
        {
            screenBuf[x + i + (y * (width + 1))] = ' ';
        }
    }
}
int gameBuffer(char* screenBuf, int width, int height)
{
    const char* words[] = {
        "kimyoungchul",
        "leeeunseok",
        "leesung-hyun",
        "yoonsumi",
        "kimsunyoung",
        "nounseok",
    };
    const int numWords = sizeof(words) / sizeof(words[0]);
    const int maxTries = 6;
    int hp = 5; 

      char hpText[16];
    snprintf(hpText, sizeof(hpText), "HP: %d", hp);
    gamewriteStringToBuffer(screenBuf, hpText, 4, 5, width);
    
    srand(time(NULL));
    int select = getRandomNumber(0, numWords - 1);
    const char* selectedWord = words[select];
    int wordLength = strlen(selectedWord);

    char* guessedWord = (char*)malloc((wordLength + 1) * sizeof(char));
    memset(guessedWord, '_', wordLength);
    guessedWord[wordLength] = '\0';

    int tries = 0;
    int found = 0;
    gamewriteStringToBuffer(screenBuf, guessedWord, 7, 10, width); 
 while (tries < maxTries && !found && hp > 0) // 목숨이 0보다 크면 게임 진행
    {
        system("cls");
        printf("%s\ninput> ", screenBuf);

        char guess;
        scanf(" %c", &guess);

        int correct = 0;
        for (int i = 0; i < wordLength; i++)
        {
            if (selectedWord[i] == guess)
            {
                guessedWord[i] = guess;
                correct = 1;
            }
        }

        if (correct)
        {
            gamewriteStringToBuffer(screenBuf, "Correct guess!", 7, 7, width);
        }
        else
        {
            tries++;
            hp--;
            char hpText[16];
            snprintf(hpText, sizeof(hpText), "HP: %d", hp);
            gamewriteStringToBuffer(screenBuf, "*Wrong guess!*", 7, 7, width);
            gamewriteStringToBuffer(screenBuf, hpText, 4, 5, width);
        }

        gamewriteStringToBuffer(screenBuf, guessedWord, 7, 10, width);

        if (strcmp(guessedWord, selectedWord) == 0)
        {
            found = 1;
            eraseStringFromBuffer(screenBuf, 4, 2, width, 20);
            gamewriteStringToBuffer(screenBuf, "[You win!]", 11, 2, width);
        }
          if (hp == 0) {
                eraseStringFromBuffer(screenBuf, 5, 2, width, 20); // "Write One Letter" 문자열 지우기
                gamewriteStringToBuffer(screenBuf, "[Game  Over!]", 8, 2, width); // "Game Over!" 출력
        }
    }
}

int MainGame(char* screenBuf, int width, int height)
{
    gameclearBuffer(screenBuf,30,15);    //화면 창
    gamewriteStringToBuffer(screenBuf,"[Write One Letter]",6,2,width); //글자
      gamewriteStringToBuffer(screenBuf,"hint:menu ",4,4,width); //글자
    gameBuffer(screenBuf, 30, 15); // 게임
}

int Game() //헤더파일에 넣고 실행
{
    char screenBuf[1300];
    system("cls");
    MainGame(screenBuf, 30, 15);
}
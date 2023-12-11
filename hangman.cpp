#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>

#define MAX 50
#define MISTAKE 6
int guess(char word[], char guessed[], char check)
{
    int valid = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == check)
        {
            guessed[i] = check;
            valid++;
        }
    }
    if (!valid) return 1;
    else return 0;
}

void randomWord(const char wordList[][MAX], char word[MAX], int wordCount)
{
    int i = (rand()*rand()+rand()) % wordCount;
    strcpy(word,wordList[i]);
}

void stickman(int mistake, char guessed[MAX], char word[MAX])
{
    setcolor(WHITE);
    settextstyle(0, HORIZ_DIR, 2);

    const int maxLineLength = 34;
    int textY = 10;

    if (mistake>=MISTAKE)
        strncpy(guessed,word,MAX);
    if (strlen(guessed) > maxLineLength - 1)
    {
        char firstLine[MAX] = "", secondLine[MAX] = "";
        strncpy(firstLine, guessed, maxLineLength - 1);
        firstLine[maxLineLength - 1] = '\0';

        strcpy(secondLine, &guessed[maxLineLength - 1]);
        outtextxy(50, textY + textheight("H"), firstLine);
        outtextxy(50, textY + 2 * textheight("H"), secondLine);
    }
    else
        outtextxy(50, textY + textheight("H"), guessed);

    if (mistake >= MISTAKE - 9)
        line(200, 300, 440, 300); // ground
    if (mistake >= MISTAKE - 8)
        line(290, 300, 290, 80); // pole base
    if (mistake >= MISTAKE - 7)
        line(290, 80, 350, 80); // pole upper stick
    if (mistake >= MISTAKE - 6)
        line(350, 80, 350, 115); // rope/noose
    if (mistake >= MISTAKE - 5)
        circle(350, 135, 20); // head
    if (mistake >= MISTAKE - 4)
        line(350, 155, 350, 210); // body
    if (mistake >= MISTAKE - 3)
        line(350, 155, 325, 180); // left arm
    if (mistake >= MISTAKE - 2)
        line(350, 155, 375, 180); // right arm
    if (mistake >= MISTAKE - 1)
        line(350, 210, 325, 235); // left leg
    if (mistake >= MISTAKE)
    {
        line(350, 210, 375, 235); // right leg
        settextstyle(2, HORIZ_DIR, 8);
        outtextxy(230, 320, "You Killed Him!");
        outtextxy(245, 350, "YOU LOSE!!!");
    }
    if (!strcmp(word, guessed)&&(mistake<MISTAKE))
    {
        settextstyle(2, HORIZ_DIR, 8);
        outtextxy(225, 320, "You Saved Him!");
        outtextxy(255, 350, "YOU WIN!!!");
    }
}

int game(const char LVL[][MAX], char word[MAX], char guessed[MAX], int level)
{
    char check;
    char answer[MAX];
    int mistake = 0, pastMistake =0, win=0;

    if (level)
    {
        printf("Level %d:\n", level);
        randomWord(LVL, word, sizeof(LVL));
    }

    for (int i = 0; i < strlen(word); i++)
        guessed[i] = '_';
    guessed[strlen(word)] = '\0';

    stickman(0,guessed,".");

    while (strchr(guessed, '_') != NULL)
    {
        printf("Word: %s\n", guessed);
        scanf(" %c", &check);
        check = tolower(check);
        mistake += guess(word, guessed, check);
        stickman(mistake,guessed,word);
        //printf("Mistakes: %d\n", mistake);
        if (mistake >= MISTAKE)
        {
            //printf("You killed him. You lose! :(((\nThe word was: %s\n", word);
            printf("Do you want to keep playing this mode? (yes/no)\n");
            scanf("%s",&answer);
            if (!strcmp(answer,"yes"))
            {
                system("cls");
                cleardevice();
                return 0;
            }
            else
                return 2;
        }
    }
    //printf("\nThe word was: %s\n", word);
    if (level!=5)
    {
        printf("Do you want to keep playing this mode? (yes/no)\n");
        scanf("%s",&answer);
        if (!strcmp(answer,"yes"))
        {
            system("cls");
            cleardevice();
            return 1;
        }
        else
            return 2;
    }
    else
    {
        delay(2000);
        cleardevice();
        settextstyle(2, HORIZ_DIR, 10);
        outtextxy(110, 100, "CONGRATULATIONS");
        delay(2000);
        outtextxy(110, 300, "YOU WON THE GAME!");
        delay(3000);
        return 2;
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    const char LVL1[][MAX] = {"cat", "door", "fish", "blue", "jump", "apple", "frog", "hat", "banana", "bird"};
    const char LVL2[][MAX] = {"happy", "grape", "music", "blend", "sunny", "quick", "tiger", "beach", "globe", "wrist"};
    const char LVL3[][MAX] = {"chase", "frost", "plush", "swirl", "jazzy", "gears", "trump", "sleek", "oasis", "whale"};
    const char LVL4[][MAX] = {"quest", "blitz", "jumbo", "vivid", "mirth", "azure", "quirk", "lunar", "plaza", "haste"};
    const char LVL5[][MAX] = {"ambitious", "juxtapose", "syndicate", "mnemonic", "labyrinth", "antiderivative", "paradox", "retribution", "boulevard", "peripheral", "parallelogram", "polyglot", "pneumonia", "tritrate", "euphoria", "quizzical", "emulsify", "magnanomous", "quixotic", "pneumonoultramicroscopicsilicovolcanoconiosis"};
    char word[MAX];
    char guessed[MAX];
    char answer[MAX];
    int cont,level;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, " ");

    //printf("Word: %s\n", word);
    //printf("Guessed: %s\n", guessed);
    printf("Do you want to play singleplayer or multiplayer? (S/M)\n");
    scanf(" %c",&answer[0]);
    answer[0] = tolower(answer[0]);
    if (answer[0] == 'm')
    {
        multiplayer:
        while(TRUE)
        {
            printf("Input your word (%d characters max): ",MAX);
            scanf("%s",&word);
            if (strlen(word)<=MAX)
                break;
            printf("\nInvalid Input! Word is too long!\n");
        }
        for (int i=0;i<strlen(word);i++)
            word[i] = tolower(word[i]);
        system("cls");
        cont = game(LVL1,word, guessed,0);
        if (cont==1||cont==0)
            goto multiplayer;
        else
        {
            system("cls");
            printf("Do you want to play singleplayer now? (yes/no)\n");
            scanf("%s",&answer);
            if (!strcmp(answer,"yes"))
                goto start;
            else
                goto end;
        }
    }
    else
    {
        start:
        cleardevice();
        cont = game(LVL1, word, guessed,1);
        if (cont==0)
            goto start;
        else if (cont==2)
            goto end;
        cont = game(LVL2, word, guessed,2);
        if (cont==0)
            goto start;
        else if (cont==2)
            goto end;
        cont = game(LVL3, word, guessed,3);
        if (cont==0)
            goto start;
        else if (cont==2)
            goto end;
        cont = game(LVL4, word, guessed,4);
        if (cont==0)
            goto start;
        else if (cont==2)
            goto end;
        cont = game(LVL5, word, guessed,5);
        if (cont==0||cont==1)
            goto start;
        else if (cont==2)
            goto end;
    }
    end:
    /*printf("\nDo you want to manually choose a level? (yes/no)\n");
    scanf("%s",&answer);
        if (!strcmp(answer,"yes"))
            {
                startmanualgame:
                system("cls");
                printf("What level do you want to play? (1-5)\n");
                scanf("%d", &level);
                switch (level)
                {
                    case 1:
                        cont=game(LVL1, word, guessed, level);
                        if (cont==1)
                            goto startmanualgame;
                        else if (cont==2)
                            goto endmanualgame;
                        break;
                    case 2:
                        cont=game(LVL2, word, guessed, level);
                        if (cont==1)
                            goto startmanualgame;
                        else if (cont==2)
                            goto endmanualgame;
                        break;
                    case 3:
                        cont=game(LVL3, word, guessed, level);
                        if (cont==0)
                            goto startmanualgame;
                        else if (cont==2)
                            goto endmanualgame;
                        break;
                    case 4:
                        cont=game(LVL4, word, guessed, level);
                        if (cont==1)
                            goto startmanualgame;
                        else if (cont==2)
                            goto endmanualgame;
                        break;
                    case 5:
                        cont=game(LVL5, word, guessed, level);
                        if (cont==1)
                            goto startmanualgame;
                        else if (cont==2)
                            goto endmanualgame;
                        break;
                    default: printf("You didn't pick a valid level!");
                }
            }
    endmanualgame:*/
    return 0;
}

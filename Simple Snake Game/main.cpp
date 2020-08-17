#include <iostream>
#include <windows.h>
#include <ctime>
#include <conio.h>
using namespace std;

bool GameOver;
int score;
const int width = 20;
const int high = 20;
int fruitX = rand() % width;
int fruitY = rand() % high;
bool PrintBorder;

int tailX[100], tailY[100];
int nTail = 0;
int tail2X, tail2Y, tail3X, tail3Y;

int playerX = 10;
int playerY = 10;
enum eDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
eDirection dir;

void setup()
{
    GameOver = false;
}
void draw()
{
    for (int i = 0; i < width + 2; i++)
    {
        cout << 'I';
    }

    cout << endl;

    for (int i = 0; i < high; i++)
    {
        cout << 'I';
        for (int j = 0; j < width; j++)
        {
            if (playerY == fruitY && playerX == fruitX)
            {
                nTail = nTail + 1;
                score = score + 10;
                fruitX = rand() % width;
                fruitY = rand() % high;
            }

            if (playerY == i && playerX == j)
                cout << 'O';
            else if (fruitX == j && fruitY == i)
            {
                cout << 'I';
            }
            else
            {
                PrintBorder = true;
                for (int t = nTail; 0 < t; t--)
                {
                    if (tailX[t] == j && tailY[t] == i)
                    {
                        PrintBorder = false;
                        cout << "K";
                    }
                }
                if (PrintBorder == true)
                    cout << ' ';
            }
        }
        cout << 'I' << endl;
    }
    for (int i = 0; i < width + 2; i++)
    {
        cout << 'I';
    }
    cout << endl;
    cout << "fruitX: " << fruitX << endl;
    cout << "fruitY: " << fruitY << endl;
    cout << "Score: " << score << endl;
    /*Walls*/
}
void input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'w':
            dir = UP;
            break;
        case 'x':
            GameOver = true;
            break;
        }
    }
}
void logic()
{
    tailX[0] = playerX;
    tailY[0] = playerY;

    for (int i = nTail; 0 < i; i--)
    {

        tailX[i] = tailX[i - 1];
        tailY[i] = tailY[i - 1];

        cout << tailY[i] << " " << tailX[i] << endl;
    }

    switch (dir)
    {
    case LEFT:
        playerX = playerX - 1;
        break;
    case RIGHT:
        playerX = playerX + 1;
        break;
    case UP:
        playerY = playerY - 1;
        break;
    case DOWN:
        playerY = playerY + 1;
        break;
    default:
        break;
    }
    if (playerY == high)
        playerY = 0;
    else if (playerY < 0)
        playerY = high - 1;
    else if (playerX < 0)
        playerX = width - 1;
    else if (playerX == width)
        playerX = 0;

    for (int i = nTail; 0 < i; i--)
    {
        if (playerX == tailX[i] && playerY == tailY[i])
            GameOver = true;
    }
}
int main()
{
    setup();
    srand(time(NULL));
    while (!GameOver)
    {
        system("cls");
        draw();
        input();
        logic();
    }
    cout << "GameOver!" << endl;
    system("pause");
    return 0;
}

/*
|IIIIIIIIIIIIIIIIIIIIIII|
|I|                   |I|
|I|                   |I|
|I|                   |I|
|I|                   |I|
|I|                   |I|
|I|                   |I|
|IIIIIIIIIIIIIIIIIIIIIII|
 */

#include "Logic.h"

Logic::Logic()
{

}

void Logic::set_vect(vector<int> &tailX, vector<int> &tailY, int &nTail, int &x, int &y)
{
    int prevX = tailX[0];   // previous X coordinate of the tail
    int prevY = tailY[0];   // previous Y coordinate of the tail
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for(int i=1; i<nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
}

/*void Logic::set_snakePos(int &x1, int &y1)
{
    x = x1;
    y = y1;
}*/

void Logic::set_dir(char &dir, int &x, int &y)
{
    switch(dir)
    {
    case 'l':
        x--;
        break;
    case 'r':
        x++;
        break;
    case 'u':
        y--;
        break;
    case 'd':
        y++;
        break;
    default:
        break;
    }
}

void Logic::hitWall(int &x, int &y, int &height, int &width)
{
    if(x >= width) x = 0;
    else if (x < 0) x = width - 1;
    if(y >= height) y = 0;
    else if(y < 0) y = height - 1;
}

void Logic::foodEaten(int &x, int &y, int &fruitx, int &fruity, int &score, int &nTail, int &width, int &height)
{
    if(x == fruitx and y == fruity)
    {
        score += 10;
        fruitx = rand() % width;
        fruity = rand() % height;
        nTail++;
    }
}

void Logic::snakeEatItself(vector<int> &tailX, vector<int> &tailY, int &x, int &y, bool &gameOver, int &nTail)
{
    for(int i=0; i<nTail; i++)
    {
        if(tailX[i] == x and tailY[i] == y)
        {
            gameOver = true;
        }
    }
}

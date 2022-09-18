#include "SetUp.h"

SetUp::SetUp()
{
    gameOver = false;
    height = 20;
    width = 20;
    x = width/2;
    y = height/2;
    fruitx = rand()%width;
    fruity = rand()%height;
    score = 0;
}

pair<int, int> SetUp::get_snakePositions()
{
    pair<int, int> p;
    p.first = x;
    p.second = y;
    return p;
}

pair<int, int> SetUp::get_Dimensions()
{
    pair<int, int> p;
    p.first = height;
    p.second = width;
    return p;
}

pair<int, int> SetUp::get_fruitPositions()
{
    pair<int, int> p;
    p.first = fruitx;
    p.second = fruity;
    return p;
}

int SetUp::get_Score()
{
    int sc = score;
    return sc;
}

bool SetUp::get_gameOver()
{
    bool temp = gameOver;
    return temp;
}

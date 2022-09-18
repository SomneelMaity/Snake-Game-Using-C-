#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include<cstdlib>
#include "SetUp.h"
#include "Logic.h"
using namespace std;

SetUp st;
Logic lg;

bool gameOver;
int x,y,fruitx,fruity,score,height,width;
vector<int> tailX(100,0),tailY(100,0);
char dir;
int nTail;

void Draw()
{
    system("cls");

    //Display Top Border of the Board
    for(int i=0; i<width+2; i++)
    {
        cout<< "#";
    }
    cout<<endl;

    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(j == 0)
            {
                cout<<"#";
            }
            // Print Snake
            if(i == y and j == x)
                cout<<"O";
            // Print Fruit
            else if(i == fruity and j == fruitx)
                cout<<"F";
            else
            {
                bool print = false;
                for(int k = 0; k<nTail; k++)
                {

                    if(tailX[k] == j and tailY[k] == i)
                    {
                        cout<<"o";
                        print = true;
                    }
                }
                if(!print)
                    cout<<" ";
            }
            if(j == width-1) cout<< "#";
        }
        cout<<endl;
    }
    // Display bottom border
    for(int i=0; i<width+2; i++)
    {
        cout<< '#';
    }
}


void Input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
        case 'a':
            dir = 'l';
            break;
        case 's':
            dir = 'd';
            break;
        case 'd':
            dir = 'r';
            break;
        case 'w':
            dir = 'u';
            break;
        case 'q':
            gameOver = true;
            break;
        }
    }
}

void logic()
{
    lg.set_vect(tailX, tailY, nTail, x, y);
    lg.set_dir(dir,x,y);
    lg.hitWall(x,y,height,width);
    /*
    for(int i=0; i<nTail; i++)
    {
        if(tailX[i] == x and tailY[i] == y)
        {
            gameOver = true;
        }
    }*/
    lg.snakeEatItself(tailX,tailY,x,y,gameOver,nTail);

    lg.foodEaten(x,y,fruitx,fruity,score,nTail,width,height);
}

void playGame()
{
    gameOver = st.get_gameOver();
    pair<int, int> p1 = st.get_snakePositions();
    pair<int, int> p2 = st.get_Dimensions();
    pair<int, int> p3 = st.get_fruitPositions();
    x = p1.first;
    y = p1.second;
    height = p2.first;
    width = p2.second;
    fruitx = p3.first;
    fruity = p3.second;
    score = st.get_Score();

    while(!gameOver)
    {
        Draw();
        Input();
        logic();
        Sleep(75);
    }
}

int main()
{
    char response;
    do
    {
        playGame();
        cout<<"Do You Want To Play Again ? Y/N";
        cin>>response;
        if(response == 'N' or response == 'n')
            break;
    }
    while(response == 'y' or response == 'Y');
    cout<<"Thank You\n";
    return 0;
}

#ifndef LOGIC_H
#define LOGIC_H
#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include<cstdlib>
using namespace std;

class Logic
{
private:
    //string dir;
    //vector<int> tailX, tailY;
    //int nTail;
    //int x,y,fruitx,fruity,score,height,width;
public:
    Logic();
    void set_dir(char &, int &, int &);
    void set_vect(vector<int> &, vector<int> &, int &, int &, int &);
    void hitWall(int &,int &,int &,int &);
    void foodEaten(int &,int &,int &,int &,int &,int &, int &, int &);
    void snakeEatItself(vector<int> &, vector<int> &, int &, int &, bool &, int &);
    //void set_nTail(int);
    //void set_snakePos(int &, int &);
    //void set_fruitPos(int &, int &);
    //void set_score(int );
    //void set_dimensions(int , int);
};

#endif // LOGIC_H

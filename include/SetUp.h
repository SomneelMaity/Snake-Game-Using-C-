#ifndef SETUP_H
#define SETUP_H
#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include<cstdlib>
using namespace std;


class SetUp
{
private:
    bool gameOver;
   // enum eDirections {STOP = 0, LEFT, RIGHT, UP, DOWN};
   // eDirections dir;
    int x,y,fruitx,fruity,score,height,width;
public:
    SetUp();
  //  void set_gameOver();
  //  void set_Dimensions();
  //  void set_snakePositions();
  //  void set_fruitPositions();
  //  void set_Score();
    bool get_gameOver();
    pair<int,int> get_Dimensions();
    pair<int, int> get_snakePositions();
    pair<int, int> get_fruitPositions();
    int get_Score();
};

#endif // SETUP_H

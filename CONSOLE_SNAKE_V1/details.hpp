#pragma once
#include<random>
#include<vector>
#include<iostream>

struct Body
{
  int  x;
  int  y;
  char figure {'@'};
};

struct Direction
{
  int dx {0};
  int dy {0};
};

class Food
{
  private:
    std::random_device rd;
    std::default_random_engine engine;
 
    int  x;
    int  y;
    int  width;
    int  height;
    char figure {'*'};
  
  public:
    Food(const int width, const int height);

    void appear(std::vector<std::vector<char>> &desk);
};

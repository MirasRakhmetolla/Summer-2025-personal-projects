#pragma once

#include"details.hpp"



using uint = unsigned int;


class Snake
{
  private:
    Body body;

    uint step  {1};

    uint step_to_grow {0};
    
    int width;
    int height;

  public:
    std::vector<Body> full_body;
    Direction direction;
    uint score {0};

    Snake(const int width, const int height, const int stp, const char figure);
    Snake(const int width, const int height, const char figure);
    Snake(const int width, const int height, const int stp);
    Snake(const int width, const int height);

    void set_direction(int &key);
    void move();
    void place(std::vector<std::vector<char>> &desk);
    void grow();
};

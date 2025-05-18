#pragma once
#include"snake.hpp"


using unt = unsigned int;

class Desk
{
  private:

    int width;
    int height;

  public:
    std::vector<std::vector<char>> desk;
    
    Desk(const int width, const int height);
    
    bool check_colission_(Snake &snake);
    void show_desk();
    void clean_desk();
};

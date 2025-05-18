#include"details.hpp"


Food::Food(const int width, const int height)
{
  this->width  = width;
  this->height = height;
  engine.seed(rd());
}

void Food::appear(std::vector<std::vector<char>> &desk)
{
  std::uniform_int_distribution<int> dist_x(1, width - 2);
  std::uniform_int_distribution<int> dist_y(1, height - 2);

  do
  {
    x = dist_x(engine);
    y = dist_y(engine);
  } while (desk[y][x] != ' ');

  desk[y][x] = figure;
}

#include"desk.hpp"

Desk::Desk(const int width, const int height)
{
  this->width  = width;
  this->height = height;
  
  desk = std::vector<std::vector<char>>(height, std::vector<char>(width, ' '));
  for (int y {0}; y < height; y++)
  {
    for (int x {0}; x < width; x++)
    {
      if (y == 0 || y == height - 1 || x == 0 || x == width - 1)
      { desk[y][x] = '#'; }
    }
  }
}

void Desk::show_desk()
{
  for(int i {0}; i < height; i++)
  {
    for(int j {0}; j < width; j++)
    {
      std::cout << desk[i][j];
    }

    std::cout << '\n';
  }
}

bool Desk::check_colission_(Snake &snake)
{
  const Body &head {snake.full_body.back()};
  int new_x {head.x + snake.direction.dx};
  int new_y {head.y + snake.direction.dy};

  if (new_x == 0 || new_x == width || 
      new_y == 0 || new_y == height)
  { std::cout << "boreder\n"; return false; }


  for (const Body &b : snake.full_body)
  {
    if (&b == &head) 
    { continue; }
    if (b.x == new_x && b.y == new_y)
    { std::cout << "snake body\n"; return false; }
  }
  
  if (desk[new_y][new_x] == '*')
  { snake.grow(); }

  return true;
}

void Desk::clean_desk()
{
  for (int y {0}; y < height; y++)
  {
    for (int x {0}; x < width; x++)
    {
      if (y == 0 || y == height - 1 || x == 0 || x == width - 1)
      { desk[y][x] = '#'; }
      
      else if (desk[y][x] == '*')
      { continue; }
      
      else
      { desk[y][x] = ' '; }
    }
  }
}

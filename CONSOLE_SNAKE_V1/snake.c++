#include"snake.hpp"

Snake::Snake(const int width, const int height, const int stp, const char figure)
{
  this->body.x = (int)(width/ 2);
  this->body.y = (int)(height / 2);
  this->width  = width;
  this->height = height;
  this->body.figure  = figure;
  this->step_to_grow = stp;
  full_body.push_back(body);
}

Snake::Snake(const int width, const int height, const char figure)
{
  this->body.x = (int)(width/ 2);
  this->body.y = (int)(height / 2);
  this->width  = width;
  this->height = height;
  this->body.figure  = figure;
  full_body.push_back(body);
}

Snake::Snake(const int width, const int height, const int stp)
{
  this->body.x = (int)(width/ 2);
  this->body.y = (int)(height / 2);
  this->width  = width;
  this->height = height;
  this->step_to_grow = stp;
  full_body.push_back(body);
}

Snake::Snake(const int width, const int height)
{
  this->body.x = (int)(width/ 2);
  this->body.y = (int)(height / 2);
  this->width  = width;
  this->height = height;
  full_body.push_back(body);
}

void Snake::set_direction(int &key)
{
  switch(key)
  {
    case (72):
    {
      if (direction.dy != step)
      {
        direction.dx = 0;
        direction.dy = -1 * step;
      }
      
      break;
    }

    case (80):
    {
      if (direction.dy != -1 * step)
      {
        direction.dx = 0;
        direction.dy = step;
      }
      
      break;
    }

    case (77):
    {
      if (direction.dx != -1 * step)
      {
        direction.dx = step;
        direction.dy = 0;
      }

      break;
    }

    case (75):
    {
      if (direction.dx != step)
      {
        direction.dx = -1 * step;
        direction.dy = 0;
      }

      break;
    }

    default: { break; }
  }
}

void Snake::move()
{
  Body new_body { 
                  full_body.back().x + direction.dx,
                  full_body.back().y + direction.dy,
                  full_body.back().figure
                };

  for (size_t i {0}; i < full_body.size() - 1; i++)
  { full_body[i] = full_body[i + 1]; }

  full_body.back() = new_body;
}

void Snake::grow()
{
  score++;

  if (step_to_grow != 0 && score % step_to_grow == 0)
  { step++; }

  Body new_body = full_body.back();
  full_body.push_back(new_body);
}

void Snake::place(std::vector<std::vector<char>> &desk)
{
  for (const Body &body : full_body)
  { desk[body.y][body.x] = body.figure; }
}

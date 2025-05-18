#include"desk.hpp"
#include<conio.h>
#include<chrono>
#include<thread>

const int Width  {100};
const int Height {70};

int main()
{
  Desk  desk  (Width, Height);
  Snake snake (Width, Height, '0');
  Food  food  (Width, Height);

  bool game_run {true};
  int  Key;

  snake.place(desk.desk);

  unsigned int timeFlag = 1;

  while (game_run)
  {
    system("cls");
    desk.clean_desk();
    
    if (timeFlag % 10 == 0)
    { food.appear(desk.desk); }

    if (_kbhit())
    {
      Key = _getch();
      snake.set_direction(Key);
    }


    if (!desk.check_colission_(snake)) 
    {
      std::cout << "Collision failed\n";
      std::cout << "Your score: " << snake.score << '\n'; 
      game_run = false;
      break;
    }

    snake.move(); 

    snake.place(desk.desk);
    desk.show_desk();
    std::cout << "Your score: " << snake.score << '\n'; 
    timeFlag++;

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}


  return 0;
}

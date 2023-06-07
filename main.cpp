#include <array>
#include <ctime>

#include "input.h"
#include "graphics.h"
#include "blocks.h"

using namespace Blocks;

int rand_num(){
  return rand() % 5;
}

int main() {

  srand ((unsigned) time(NULL)); //sets seed for rand num

  DroppedBlocks screen[20][10];
  
  int points = 0;
  double speed;

  set_screen();

  while (true) {
    char input = get_input();
    clear_screen();
    print_header(points);
    
  }

  return 0;
}
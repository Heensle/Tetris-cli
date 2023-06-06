#include <array>
#include <ctime>

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

  set_screen();

  while (true) {
    clear_screen();
    print_header(0);

  }

  return 0;
}
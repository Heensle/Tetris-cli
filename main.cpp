#include <array>
#include <ctime>

#include "input.h"
#include "graphics.h"
#include "blocks.h"

using namespace Blocks;

int rand_num(){
  return rand() % 7 + 1;
}

int main() {

  srand ((unsigned) time(NULL)); //sets seed for rand num

  DroppedBlocks screen[20][10];
  
  int points = 0;
  double speed;

  set_screen();

  int start_piece = rand_num();
  
  if (start_piece == 1){
    FallingBlocks piece("Q");
  } else if (start_piece == 2){
    FallingBlocks piece("T");
  } else if (start_piece == 3){
    FallingBlocks piece("LL");
  } else if (start_piece == 4){
    FallingBlocks piece("LR");
  } else if (start_piece == 5){
    FallingBlocks piece("S");
  } else if (start_piece == 6){
    FallingBlocks piece("Z");
  } else if (start_piece == 7){
    FallingBlocks piece("I");
  }

  while (true) {
    char input = get_input();
    clear_screen();
    print_header(points);
    
  }

  return 0;
}
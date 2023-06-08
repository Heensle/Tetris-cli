#include <array>
#include <ctime>
#include <iostream>
#include <chrono>
#include <thread>

#include "input.h"
#include "graphics.h"
#include "blocks.h"

using namespace Blocks;
using namespace Graphics;

int rand_num(){
  return rand() % 7 + 1;
}

int main() {

  srand ((unsigned) time(NULL)); //sets seed for rand num

  string screen[20][10];

  for (int i = 0; i < 20; i++){
    for (int j = 0; j < 10; j++){
      screen[i][j] = "empty";
    }
  }
  
  int points = 0;
  double speed;

  set_screen();

  int start_piece = rand_num();
  int held_piece = 2;
  FallingBlocks piece = FallingBlocks("Q");
  
  if (start_piece == 1){
    piece = FallingBlocks("Q");
  } else if (start_piece == 2){
    piece = FallingBlocks("T");
  } else if (start_piece == 3){
    piece = FallingBlocks("LL");
  } else if (start_piece == 4){
    piece = FallingBlocks("LR");
  } else if (start_piece == 5){
    piece = FallingBlocks("S");
  } else if (start_piece == 6){
    piece = FallingBlocks("Z");
  } else if (start_piece == 7){
    piece = FallingBlocks("I");
  }

  int next_piece = 4;

  while (true) {
    char input = get_input();
    clear_screen();
    print_header(points);
    print_board(screen, piece, held_piece, next_piece);
    std::flush(std::cout);
    std::this_thread::sleep_for(1000ms);
    piece.drop();
  }

  return 0;
}
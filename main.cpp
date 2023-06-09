#include <array>
#include <ctime>
#include <iostream>
#include <chrono>
#include <thread>
#include <ncurses.h>

#include "graphics.h"
#include "blocks.h"
#include "miscellaneous_functions.h"

using namespace Blocks;
using namespace Graphics;
using std::getline;

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
  int speed = 4;
  bool newPiece = false;
  int frame = 0;

  set_screen();

  int start_piece = rand_num();
  int held_piece = 0;
  int next_piece = rand_num();
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

  bool held = false;
  
  while (true) {
    if (points > 1000){
      speed = 3;
    }
    if (points > 5000){
      speed = 2;
    }
    if (points > 10000){
      speed = 1;
    }
    if (newPiece){
      held = false;
      if (next_piece == 1){
        piece = FallingBlocks("Q");
      } else if (next_piece == 2){
        piece = FallingBlocks("T");
      } else if (next_piece == 3){
        piece = FallingBlocks("LL");
      } else if (next_piece == 4){
        piece = FallingBlocks("LR");
      } else if (next_piece == 5){
        piece = FallingBlocks("S");
      } else if (next_piece == 6){
        piece = FallingBlocks("Z");
      } else if (next_piece == 7){
        piece = FallingBlocks("I");
      }
      if (check_loss(screen, piece)){
        cout << "             YOU LOSE" << endl;
        return 0;
      }
      next_piece = rand_num();
      newPiece = false;
    }
    int input;
    while (true){
      input = getch();
      if (input == 'r' || input == 'R'){
        piece.rotate();
      } else if (input == 'a' || input == 'A' || input == KEY_LEFT){
        piece.move_left();
      } else if (input == 'd' || input == 'D' || input == KEY_RIGHT){
        piece.move_right();
      } else if (input == 's' || input == 'S' || input == KEY_DOWN){
        piece.drop(screen);
        points += 2;
      } else if ((input == 'h' || input == 'H') && !held){
        held = true;
        if (held_piece == 0){
          held_piece = piece.get_type_num();
          if (next_piece == 1){
          piece = FallingBlocks("Q");
          } else if (next_piece == 2){
          piece = FallingBlocks("T");
          } else if (next_piece == 3){
          piece = FallingBlocks("LL");
          } else if (next_piece == 4){
          piece = FallingBlocks("LR");
          } else if (next_piece == 5){
          piece = FallingBlocks("S");
          } else if (next_piece == 6){
          piece = FallingBlocks("Z");
          } else if (next_piece == 7){
          piece = FallingBlocks("I");
          }
          next_piece = rand_num();
        } else {
          int temp = piece.get_type_num();
          if (held_piece == 1){
          piece = FallingBlocks("Q");
          } else if (held_piece == 2){
          piece = FallingBlocks("T");
          } else if (held_piece == 3){
          piece = FallingBlocks("LL");
          } else if (held_piece == 4){
          piece = FallingBlocks("LR");
          } else if (held_piece == 5){
          piece = FallingBlocks("S");
          } else if (held_piece == 6){
          piece = FallingBlocks("Z");
          } else if (held_piece == 7){
          piece = FallingBlocks("I");
          }
          held_piece = temp;
        }
      } else if (input == 'p' || input == 'P') {
        clear_screen();
        cout << "       Press ENTER to continue.";
        string con;
        nodelay(stdscr, FALSE);
        nocbreak();
        getline(cin, con);
        nodelay(stdscr, TRUE);
        cbreak();
      } else if (input == '?'){
        
      } else {
        break;
      }
    }
    clear_screen();
    print_header(points);
    print_board(screen, piece, held_piece, next_piece);
    std::flush(std::cout);
    std::this_thread::sleep_for(250ms);
    if (frame < speed){
      frame++;
    } else {
      piece.drop(screen);
      clear_line(screen, points);
      block_fall(screen, piece, newPiece);
      frame = 0;
    }
  }

  return 0;
}
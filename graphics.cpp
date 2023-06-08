#include <iostream>
#include <ncurses.h>

#include "graphics.h"
#include "blocks.h"

using std::cout;
using std::endl;

using namespace Blocks;

namespace Graphics{
  void set_screen() {
    keypad(stdscr, TRUE);
    cbreak();
    noecho();
  }
  
void clear_screen() { cout << "\033[H\033[2J\033[3J"; }
  
  void print_header(int points) {
    char myendl = 10;
    cout << "              ┌────┐              " << myendl << "              │";
    if (points < 10) {
      cout << "  " << points << " ";
    } else if (points < 100) {
      cout << " " << points << " ";
    } else if (points < 1000) {
      cout << " " << points;
    } else if (points < 10000) {
      cout << " " << points / 1000 << "k ";
    } else if (points < 100000) {
      cout << " " << points / 1000 << "k";
    } else if (points < 1000000) {
      cout << points / 1000 << "k";
    } else if (points < 10000000) {
      cout << " " << points / 1000000 << "m ";
    } else if (points < 100000000) {
      cout << " " << points / 1000000 << "m";
    } else {
      cout << " ok ";
    }
  
    cout << "│              " << myendl;
    cout << " HOLD ┌───────┴────┴───────┐ NEXT " << myendl;
  }
  
  void print_board(string (&screen)[20][10], FallingBlocks piece, int held_piece, int next_piece){
    bool odd = true;
    char myendl = 10;
    int row = 19;
    while (true){
      bool present = false;
      if (row == 19){
        cout << "┌─────┤"; 
      } else if (row == 18){
        if (held_piece == 1){
          cout << "│  " << "\u001b[38;5;226m" << "▓▓" << "\u001b[0m" << " │";
        } else if (held_piece == 2){
          cout << "│  " << "\u001b[38;5;128m" << "▓" << "\u001b[0m" << "  │";
        } else if (held_piece == 3){
          cout << "│ " << "\u001b[38;5;69m" << "▓" << "\u001b[0m" << "   │";
        } else if (held_piece == 4){
          cout << "│   " << "\u001b[38;5;214m" << "▓" << "\u001b[0m" << " │";
        } else if (held_piece == 5){
          cout << "│  " << "\u001b[38;5;82m" << "▓▓" << "\u001b[0m" << " │";
        } else if (held_piece == 6){
          cout << "│ " << "\u001b[38;5;196m" << "▓▓" << "\u001b[0m" << "  │";
        } else if (held_piece == 7){
          cout << "│     │";
        } else {
          cout << "│     │";
        }
      } else if (row == 17){
        if (held_piece == 1){
          cout << "│  " << "\u001b[38;5;226m" << "▓▓" << "\u001b[0m" << " │";
        } else if (held_piece == 2){
          cout << "│ " << "\u001b[38;5;128m" << "▓▓▓" << "\u001b[0m" << " │";
        } else if (held_piece == 3){
          cout << "│ " << "\u001b[38;5;69m" << "▓▓▓" << "\u001b[0m" << " │";
        } else if (held_piece == 4){
          cout << "│ " << "\u001b[38;5;214m" << "▓▓▓" << "\u001b[0m" << " │";
        } else if (held_piece == 5){
          cout << "│ " << "\u001b[38;5;82m" << "▓▓" << "\u001b[0m" << "  │";
        } else if (held_piece == 6){
          cout << "│  " << "\u001b[38;5;196m" << "▓▓" << "\u001b[0m" << " │";
        } else if (held_piece == 7){
          cout << "│ " << "\u001b[38;5;51m" << "▓▓▓▓" << "\u001b[0m" << "│";
        } else {
          cout << "\u001b[0m" << "│     │";
        }
      } else if (row == 16){
        cout << "└─────┤";
      } else if (row > 0 && row < 16){
        cout << "      │";
      } else if (row == 0){
        cout << "      └────────────────────┘" << myendl;
        break;
      }
      for (int i = 0; i < 10; i++){
        present = false;
        if (screen[row][i] != "empty"){
          for (int j = 0; j < 2; j++){
            cout << screen[row][i] << "▓";
          }
          cout << "\u001b[0m";
          present = true;
        }

        if ((piece.get_block1x() == i && piece.get_block1y() == row) || (piece.get_block2x() == i && piece.get_block2y() == row) || (piece.get_block3x() == i && piece.get_block3y() == row) || (piece.get_block4x() == i && piece.get_block4y() == row)){
          cout << piece.get_color() << "▓▓";
          cout << "\u001b[0m";
          present = true;
        }
        
        if (!present){
          cout << "\u001b[0m";
          cout << "  ";
        }
      }
      
      if (row == 19){
        
        cout << "├─────┐" << myendl;
      } else if (row == 18){
        if (next_piece == 1){
          cout << "│  " << "\u001b[38;5;226m" << "▓▓" << "\u001b[0m" << " │" << myendl;
        } else if (next_piece == 2){
          cout << "│  " << "\u001b[38;5;128m" << "▓" << "\u001b[0m" << "  │" << myendl;
        } else if (next_piece == 3){
          cout << "│ " << "\u001b[38;5;69m" << "▓" << "\u001b[0m" << "   │" << myendl;
        } else if (next_piece == 4){
          cout << "│   " << "\u001b[38;5;214m" << "▓" << "\u001b[0m" << " │" << myendl;
        } else if (next_piece == 5){
          cout << "│  " << "\u001b[38;5;82m" << "▓▓" << "\u001b[0m" << " │" << myendl;
        } else if (next_piece == 6){
          cout << "│ " << "\u001b[38;5;196m" << "▓▓" << "\u001b[0m" << "  │" << myendl;
        } else if (next_piece == 7){
          cout << "│     │" << myendl;
        } else {
          cout << "│     │" << myendl;
        }
      } else if (row == 17){
        if (next_piece == 1){
          cout << "│  " << "\u001b[38;5;226m" << "▓▓" << "\u001b[0m" << " │" << myendl;
        } else if (next_piece == 2){
          cout << "│ " << "\u001b[38;5;128m" << "▓▓▓" << "\u001b[0m" << " │" << myendl;
        } else if (next_piece == 3){
          cout << "│ " << "\u001b[38;5;69m" << "▓▓▓" << "\u001b[0m" << " │" << myendl;
        } else if (next_piece == 4){
          cout << "│ " << "\u001b[38;5;214m" << "▓▓▓" << "\u001b[0m" << " │" << myendl;
        } else if (next_piece == 5){
          cout << "│ " << "\u001b[38;5;82m" << "▓▓" << "\u001b[0m" << "  │" << myendl;
        } else if (next_piece == 6){
          cout << "│  " << "\u001b[38;5;196m" << "▓▓" << "\u001b[0m" << " │" << myendl;
        } else if (next_piece == 7){
          cout << "│ " << "\u001b[38;5;51m" << "▓▓▓▓" << "\u001b[0m" << "│" << myendl;
        } else {
          cout << "\u001b[0m" << "│     │" << myendl;
        }
      } else if (row == 16){
        cout << "├─────┘" << myendl;
      } else if (row > 0 && row < 16){
        cout << "│" << myendl;
      } else {
        break;
      }
      
      row--;
      
    }
  }
}
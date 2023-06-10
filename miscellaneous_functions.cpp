#include <iostream>
#include <ncurses.h>

#include "blocks.h"
#include "miscellaneous_functions.h"
#include "graphics.h"

using namespace std;
using namespace Blocks;
using namespace Graphics;

void block_fall(string (&screen)[20][10], FallingBlocks &piece, bool &newPiece){
  for (int i = 0; i < 20; i++){
    for (int j = 0; j < 10; j++){
      if (screen[i][j] != "empty"){
        if ((piece.get_block1x() == j && piece.get_block1y() - 1 == i) || (piece.get_block2x() == j && piece.get_block2y() - 1 == i) || (piece.get_block3x() == j && piece.get_block3y() - 1 == i) || (piece.get_block4x() == j && piece.get_block4y() - 1 == i)){
          screen[piece.get_block1y()][piece.get_block1x()] = piece.get_color();
          screen[piece.get_block2y()][piece.get_block2x()] = piece.get_color();
          screen[piece.get_block3y()][piece.get_block3x()] = piece.get_color();
          screen[piece.get_block4y()][piece.get_block4x()] = piece.get_color();
          newPiece = true;
        }
      }
    }
  }
  if (piece.get_block1y() == 0 || piece.get_block2y() == 0 || piece.get_block3y() == 0 || piece.get_block4y() == 0){
    screen[piece.get_block1y() + 1][piece.get_block1x()] = piece.get_color();
          screen[piece.get_block2y() + 1][piece.get_block2x()] = piece.get_color();
          screen[piece.get_block3y() + 1][piece.get_block3x()] = piece.get_color();
          screen[piece.get_block4y() + 1][piece.get_block4x()] = piece.get_color();
    newPiece = true;
  }  
}

bool check_loss(string (&screen)[20][10], FallingBlocks &piece){
  for (int i = 19; i > 17; i--){
    for (int j = 0; j < 10; j++){
      if (screen[i][j] != "empty"){
        if ((piece.get_block1x() == j && piece.get_block1y() == i) || (piece.get_block2x() == j && piece.get_block2y() == i) || (piece.get_block3x() == j && piece.get_block3y() == i) || (piece.get_block4x() == j && piece.get_block4y() == i)){
          return true;
        }
      }
    }
  }
  return false;
}

void clear_line(string (&screen)[20][10], int &points){
  int lines_cleared = 0;
  bool changed = false;
  while (true){
    changed = false;
    for (int j = 0; j < 20; j++){
      int full = 0;
      for (int i = 0; i < 10; i++){
        if (screen[j][i] != "empty"){
          full++;
        }
      }
      if (full == 10){
        changed = true;
        points += 100;
        for (int h = j; h < 19; h++){
          for (int k = 0; k < 10; k++){
            screen[h][k] = screen[h + 1][k];
          }
        }
        for (int k = 0; k < 10; k++){
          screen[19][k] = "empty";
        }
        lines_cleared++;
        if (lines_cleared == 4){
          points += 400;
        }
      }
    }
    if (!changed){
      break;
    }
  }
}

void question(){
  bool incorrect = false;
  while(true){
    clear_screen();
    if (incorrect){
      cout << "\u001b[1000D" << "That isn't a valid input." << endl;
    }
    incorrect = false;
    cout << "\u001b[1000D" << "What would you like to do?" << endl << "\u001b[1000D" << "     1 - How to Play Tetris" << endl << "\u001b[1000D" << "     2 - Program Controls" << endl << "\u001b[1000D" << "     3 - Program Bugs to be Aware of" << endl << "\u001b[1000D" << "     4 - Return to game" << endl << endl << "\u001b[1000D";
    char input;
    while (true){
      input = getch();
      if (input != -1){
        break;
      }
    }
    
    if (input == '1'){
      clear_screen();
      cout << "\u001b[1000D" << "HOW TO PLAY TETRIS" << endl << endl << endl << "\u001b[1000D" << "     ''Tetris (Russian: Тетрис)[a] is a puzzle video game created by the Soviet software engineer Alexey Pajitnov in 1985. In Tetris, players complete lines by moving differently shaped pieces (tetrominoes), which descend onto the playing field. The completed lines disappear and grant the player points, and the player can proceed to fill the vacated spaces. The game ends when the uncleared lines reach the top of the playing field. The longer the player can delay this outcome, the higher their score will be.'' - Wikipedia." << endl << endl << "\u001b[1000D" << "     Press ENTER to continue." << endl << "\u001b[1000D";
      string con;
      nodelay(stdscr, FALSE);
      nocbreak();
      getline(cin, con);
      nodelay(stdscr, TRUE);
      cbreak();
    } else if (input == '2'){
      clear_screen();
      cout << "\u001b[1000D" << "PROGRAM CONTROLS" << endl << endl << endl << "\u001b[1000D" << "     HOLD PIECE = 'p'" << endl << "\u001b[1000D" << "     ROTATE PIECE = 'r'" << endl << "\u001b[1000D" << "     MOVE LEFT = 'a' or left arrow" << endl << "\u001b[1000D" << "     MOVE RIGHT = 'd' or right arrow" << endl << "\u001b[1000D" << "     MOVE DOWN = 's' or down arrow" << endl << "\u001b[1000D" << "     PAUSE = 'p'" << endl << "\u001b[1000D" << "     HELP = '?'" << endl << endl << "\u001b[1000D" << "     Press ENTER to continue." << endl << "\u001b[1000D";
      string con;
      nodelay(stdscr, FALSE);
      nocbreak();
      getline(cin, con);
      nodelay(stdscr, TRUE);
      cbreak();
     } else if (input == '3'){
      clear_screen();
      cout << "\u001b[1000D" << "PROGRAM BUGS TO BE AWARE OF" << endl << endl << endl << "\u001b[1000D" << "     Ongoing list--" << endl << endl << "\u001b[1000D" << "     1: There are no boundaries on the rotation of blocks. This means they can rotate into other blocks, out of the board, etc. This also causes a segmentation error if the player rotates the I teromino above the board and attempts to move left or right." << endl;
      cout << "\u001b[1000D" << "     Press ENTER to continue." << endl << "\u001b[1000D";
      string con;
      nodelay(stdscr, FALSE);
      nocbreak();
      getline(cin, con);
      nodelay(stdscr, TRUE);
      cbreak();
     } else if (input == '4'){
      break;
     } else {
      incorrect = true;
     }
  }
}
#include <iostream>

#include "blocks.h"
#include "miscellaneous_functions.h"

using namespace std;
using namespace Blocks;

void block_fall(string (&screen)[20][10], FallingBlocks &piece, bool &newPiece){
  bool found = false;
  for (int i = 0; i < 20; i++){
    for (int j = 0; j < 10; j++){
      if (screen[i][j] != "empty"){
        if ((piece.get_block1x() == j && piece.get_block1y() - 1 == i) || (piece.get_block2x() == j && piece.get_block2y() - 1 == i) || (piece.get_block3x() == j && piece.get_block3y() - 1 == i) || (piece.get_block4x() == j && piece.get_block4y() - 1 == i)){
          screen[piece.get_block1y()][piece.get_block1x()] = piece.get_color();
          screen[piece.get_block2y()][piece.get_block2x()] = piece.get_color();
          screen[piece.get_block3y()][piece.get_block3x()] = piece.get_color();
          screen[piece.get_block4y()][piece.get_block4x()] = piece.get_color();
          found = true;
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
    found = true;
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
  for (int i = 0; i < 10; i++){
    int full = 0;
    for (int j = 0; j < 20; j++){
      if (screen[j][i] != "empty"){
        full++;
      }
      if (full == 20){
        for (int h = 0; h < 10; h++){
          screen[j][h] = "empty";
        }
        
      }
    }
  }
}
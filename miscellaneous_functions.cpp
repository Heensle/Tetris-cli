#include <iostream>

#include "blocks.h"

using namespace std;
using namespace Blocks;

void block_fall(string (&screen)[20][10], FallingBlocks &piece, bool &newPiece){
  bool found = false;
  for (int i = 0; i < 20; i++){
    for (int j = 0; j < 10; j++){
      if (screen[i][j] != "empty"){
        if ((piece.get_block1x() == j && piece.get_block1y() == i) || (piece.get_block2x() == j && piece.get_block2y() == i) || (piece.get_block3x() == j && piece.get_block3y() == i) || (piece.get_block4x() == j && piece.get_block4y() == i)){
          screen[piece.get_block1x()][piece.get_block1y() + 1] = piece.get_color();
          screen[piece.get_block2x()][piece.get_block2y() + 1] = piece.get_color();
          screen[piece.get_block3x()][piece.get_block3y() + 1] = piece.get_color();
          screen[piece.get_block4x()][piece.get_block4y() + 1] = piece.get_color();
          found = true;
        }
      }
    }
  }
  if (piece.get_block1y() == 0 || piece.get_block2y() == 0 || piece.get_block3y() == 0 || piece.get_block4y() == 0){
    screen[piece.get_block1x()][piece.get_block1y() + 1] = piece.get_color();
          screen[piece.get_block2x()][piece.get_block2y() + 1] = piece.get_color();
          screen[piece.get_block3x()][piece.get_block3y() + 1] = piece.get_color();
          screen[piece.get_block4x()][piece.get_block4y() + 1] = piece.get_color();
    found = true;
  }
  
}
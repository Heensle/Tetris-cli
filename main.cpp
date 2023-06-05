#include "graphics.h"
#include <iostream>
using std::cout;
using std::string;
using std::endl;

class FallingBlocks {

public:
  FallingBlocks(string type);

  void rotate();

  string type; // "Q" (square), "LL" (blue one), "LR" (orange one), "I", "S",
               // "Z", "T"
  string color;

  int i_rotatex;
  int i_rotatey; // only used for the I tetromino: because of the way I've
                 // rendered the rotation, I need an arbitrary rotation point
                 // for the I tetromino specifically :/ (it is the in the
                 // position of the third block in the starting position)

  int block1x;
  int block1y;
  /* Point of rotation
  □
  ■ □
  □

  □ □
    ■ □

    □ □
  □ ■

      □
  □ ■ □

  □
  □ ■ □

  {
  I Tetromino's point of rotation is not a block: block 1 is:

  ■
  □
  □
  □
  }
  */
  int block2x;
  int block2y;
  /*
  ■
  □ □
  □

  ■ □
    □ □

    □ ■
  □ □

      ■
  □ □ □

  ■
  □ □ □

  □
  ■
  □
  □
  */
  int block3x;
  int block3y;
  /*
  □
  □ ■
  □

  □ ■
    □ □

    ■ □
  □ □

      □
  □ □ ■

  □
  ■ □ □

  □
  □
  ■
  □
  */
  int block4x;
  int block4y;
  /*
  □
  □ □
  ■

  □ □
    □ ■

    □ □
  ■ □

      □
  ■ □ □

  □
  □ □ ■

  □
  □
  □
  ■
  */
};

FallingBlocks::FallingBlocks(string type) {
  this->type = type;
  // initializes starting positions
  if (type == "Q") {
    color = "\u001b[38;5;226m";

    block1x = 5;
    block1y = 20;

    block2x = 6;
    block2y = 20;

    block3x = 5;
    block3y = 19;

    block4x = 6;
    block4y = 19;
  } else if (type == "LL") {
    color = "\u001b[38;5;69m";

    block1x = 5;
    block1y = 19;

    block2x = 4;
    block2y = 20;

    block3x = 4;
    block3y = 19;

    block4x = 6;
    block4y = 19;
  } else if (type == "LR") {
    color = "\u001b[38;5;214m";

    block1x = 5;
    block1y = 19;

    block2x = 6;
    block2y = 20;

    block3x = 6;
    block3y = 19;

    block4x = 4;
    block4y = 19;
  } else if (type == "I") {
    color = "\u001b[38;5;51m";

    block1x = 4;
    block1y = 20;

    block2x = 5;
    block2y = 20;

    block3x = 6;
    block3y = 20;

    block4x = 7;
    block4y = 20;

    i_rotatex = 6;
    i_rotatey = 20;
  } else if (type == "S") {
    color = "\u001b[38;5;82m";

    block1x = 5;
    block1y = 19;

    block2x = 6;
    block2y = 20;

    block3x = 5;
    block3y = 20;

    block4x = 4;
    block4y = 19;
  } else if (type == "Z") {
    color = "\u001b[38;5;196m";

    block1x = 5;
    block1y = 19;

    block2x = 4;
    block2y = 20;

    block3x = 5;
    block3y = 20;

    block4x = 6;
    block4y = 19;
  } else if (type == "T") {
    color = "\u001b[38;5;128m";

    block1x = 5;
    block1y = 19;

    block2x = 4;
    block2y = 19;

    block3x = 5;
    block3y = 20;

    block4x = 6;
    block4y = 19;
  }
}

void FallingBlocks::rotate() {

  if (type == "T") {

    if (block2x == block1x - 1 && block2y == block1y){
      block2x = block1x;
      block2y = block1y + 1;
    } else if (block2x == block1x && block2y == block1y + 1){
      block2x = block1x + 1;
      block2y = block1y;
    } else if (block2x == block1x + 1 && block2y == block1y){
      block2x = block1x;
      block2y = block1y - 1;
    } else if (block2x == block1x && block2y == block1y - 1){
      block2x = block1x - 1;
      block2y = block1y;
    }

    if (block3x == block1x && block3y == block1y + 1){
      block3x = block1x + 1;
      block3y = block1y;
    } else if (block3x == block1x + 1 && block3y == block1y){
      block3x = block1x;
      block3y = block1y - 1;
    } else if (block3x == block1x && block3y == block1y - 1){
      block3x = block1x - 1;
      block3y = block1y;
    } else if (block3x == block1x - 1 && block3y == block1y){
      block3x = block1x;
      block3y = block1y + 1;
    }

    if (block4x == block1x + 1 && block4y == block1y){
      block4x = block1x;
      block4y = block1y - 1;
    } else if (block4x == block1x && block4y == block1y - 1){
      block4x = block1x - 1;
      block4y = block1y;
    } else if (block4x == block1x - 1 && block4y == block1y){
      block4x = block1x;
      block4y = block1y + 1;
    } else if (block4x == block1x && block4y == block1y + 1){
      block4x = block1x + 1;
      block4y = block1y;
    }

 
  } else if (type == "LL") {
    if (block2x == block1x - 1 && block2y == block1y + 1) {
      block2x = block1x + 1;
      block2y = block1y + 1;
    } else if (block2x == block1x + 1 && block2y == block1y + 1) {
      block2x = block1x + 1;
      block2y = block1y - 1;
    } else if (block2x == block1x + 1 && block2y == block1y - 1) {
      block2x = block1x - 1;
      block2y = block1y - 1;
    } else if (block2x == block1x - 1 && block2y == block1y - 1) {
      block2x = block1x - 1;
      block2y = block1y + 1;
    }

    if (block3x == block1x - 1 && block3y == block1y) {
      block3x = block1x;
      block3y = block1y + 1;
    } else if (block3x == block1x && block3y == block1y + 1) {
      block3x = block1x + 1;
      block3y = block1y;
    } else if (block3x == block1x + 1 && block3y == block1y) {
      block3x = block1x;
      block3y = block1y - 1;
    } else if (block3x == block1x && block3y == block1y - 1) {
      block3x = block1x - 1;
      block3y = block1y;
    }

    if (block4x == block1x - 1 && block4y == block1y) {
      block4x = block1x;
      block4y = block1y - 1;
    } else if (block4x == block1x && block4y == block1y - 1) {
      block4x = block1x - 1;
      block4y = block1y;
    } else if (block4x == block1x - 1 && block4y - block1y) {
      block4x = block1x;
      block4y = block1y + 1;
    } else if (block4x == block1x && block4y == block1y + 1) {
      block4x = block1x - 1;
      block4y = block1y;
    }
  } else if (type == "LR") {
    if (block2x == block1x + 1 && block2y == block1y + 1) {
      block2x = block1x + 1;
      block2y = block1y - 1;
    } else if (block2x == block1x + 1 && block2y == block1y - 1) {
      block2x = block1x - 1;
      block2y = block1y - 1;
    } else if (block2x == block1x - 1 && block2y == block1y - 1) {
      block2x = block1x - 1;
      block2y = block1y + 1;
    } else if (block2x == block1x - 1 && block2y == block1y + 1) {
      block2x = block1x + 1;
      block2y = block1y + 1;
    }

    if (block3x == block1x - 1 && block3y == block1y) {
      block3x = block1x;
      block3y = block1y + 1;
    } else if (block3x == block1x && block3y == block1y + 1) {
      block3x = block1x + 1;
      block3y = block1y;
    } else if (block3x == block1x + 1 && block3y == block1y) {
      block3x = block1x;
      block3y = block1y - 1;
    } else if (block3x == block1x && block3y == block1y - 1) {
      block3x = block1x - 1;
      block3y = block1y;
    }

    if (block4x == block1x + 1 && block4y == block1y) {
      block4x = block1x;
      block4y = block1y - 1;
    } else if (block4x == block1x && block4y == block1y - 1) {
      block4x = block1x - 1;
      block4y = block1y;
    } else if (block4x == block1x - 1 && block4y == block1y) {
      block4x = block1x;
      block4y = block1y + 1;
    } else if (block4x == block1x && block4y == block1y + 1) {
      block4x = block1x + 1;
      block4y = block1y;
    }
  } else if (type == "S") {
    if (block2x == block1x + 1 && block2y == block1y + 1) {
      block2x = block1x + 1;
      block2y = block1y - 1;
    } else if (block2x == block1x + 1 && block2y == block1y - 1) {
      block2x = block1x - 1;
      block2y = block1y - 1;
    } else if (block2x == block1x - 1 && block2y == block1y - 1) {
      block2x = block1x - 1;
      block2y = block1y + 1;
    } else if (block2x == block1x - 1 && block2y == block1y + 1) {
      block2x = block1x + 1;
      block2y = block1y + 1;
    }

    if (block3x == block1x && block3y == block1y + 1) {
      block3x = block1x + 1;
      block3y = block1y;
    } else if (block3x == block1x + 1 && block3y == block1y) {
      block3x = block1x;
      block3y = block1y - 1;
    } else if (block3x == block1x && block3y == block1y - 1) {
      block3x = block1x - 1;
      block3y = block1y;
    } else if (block3x == block1x - 1 && block3y == block1y) {
      block3x = block1x;
      block3y = block1y + 1;
    }

    if (block4x == block1x - 1 && block4y == block1y) {
      block4x = block1x;
      block4y = block1y + 1;
    } else if (block4x == block1x && block4y == block1y + 1) {
      block4x = block1x + 1;
      block4y = block1y;
    } else if (block4x == block1x + 1 && block4y == block1y) {
      block4x = block1x;
      block4y = block1y - 1;
    } else if (block4x == block1x && block4y == block1y - 1) {
      block4x = block1x - 1;
      block4y = block1y;
    }
  } else if (type == "Z") {
    if (block2x == block1x - 1 && block2y == block1y + 1) {
      block2x = block1x + 1;
      block2y = block1y + 1;
    } else if (block2x == block1x + 1 && block2y == block1y + 1) {
      block2x = block1x + 1;
      block2y = block1y - 1;
    } else if (block2x == block1x + 1 && block2y == block1y - 1) {
      block2x = block1x - 1;
      block2y = block1y - 1;
    } else if (block2x == block1x - 1 && block2y == block1y - 1) {
      block2x = block1x - 1;
      block2y = block1y + 1;
    }

    if (block3x == block1x && block3y == block1y + 1) {
      block3x = block1x + 1;
      block3y = block1y;
    } else if (block3x == block1x + 1 && block3y == block1y) {
      block3x = block1x;
      block3y = block1y - 1;
    } else if (block3x == block1x && block3y == block1y - 1) {
      block3x = block1x - 1;
      block3y = block1y;
    } else if (block3x == block1x - 1 && block3y == block1y) {
      block3x = block1x;
      block3y = block1y + 1;
    }

    if (block4x == block1x + 1 && block4y == block1y) {
      block4x = block1x;
      block4y = block1y - 1;
    } else if (block4x == block1x && block4y == block1y - 1) {
      block4x = block1x - 1;
      block4y = block1y;
    } else if (block4x == block1x - 1 && block4y == block1y) {
      block4x = block1x;
      block4y = block1y + 1;
    } else if (block4x == block1x && block4y == block1y + 1) {
      block4x = block1x + 1;
      block4y = block1y;
    }
  } else if (type == "I") {
    if (block1x == i_rotatex - 2 && block1y == i_rotatey) {
      block1x = i_rotatex;
      block1y = i_rotatey + 1;
    } else if (block1x == i_rotatex && block1y == i_rotatey + 1) {
      block1x = i_rotatex + 1;
      block1y = i_rotatey - 1;
    } else if (block1x == i_rotatex + 1 && block1y == i_rotatey - 1) {
      block1x = i_rotatex - 2;
      block1y = i_rotatey - 2;
    } else if (block1x == i_rotatex - 2 && block1y == i_rotatey - 2) {
      block1x = i_rotatex - 2;
      block1y = i_rotatey;
    }

    if (block2x == i_rotatex - 1 && block2y == i_rotatey) {
      block2x = i_rotatex;
      block2y = i_rotatey + 1;
    } else if (block2x == i_rotatex && block2y == i_rotatey + 1) {
      block2x = i_rotatex;
      block2y = i_rotatey - 1;
    } else if (block2x == i_rotatex && block2y == i_rotatey - 1) {
      block2x = i_rotatex - 2;
      block2y = i_rotatey - 1;
    } else if (block2x == i_rotatex - 2 && block2y == i_rotatey - 1) {
      block2x = i_rotatex - 1;
      block2y = i_rotatey;
    }

    if (block3x == i_rotatex && block3y == i_rotatey) {
      block3x = i_rotatex;
      block3y = i_rotatey - 1;
    } else if (block3x == i_rotatex && block3y == i_rotatey - 1) {
      block3x = i_rotatex - 2;
      block3y = i_rotatey - 1;
    } else if (block3x == i_rotatex - 2 && block3y == i_rotatey - 1) {
      block3x = i_rotatex - 2;
      block3y = i_rotatey;
    } else if (block3x == i_rotatex - 2 && block3y == i_rotatey) {
      block3x = i_rotatex;
      block3y = i_rotatey;
    }

    if (block4x == i_rotatex + 1 && block4y == i_rotatey) {
      block4x = i_rotatex;
      block4y = i_rotatey - 2;
    } else if (block4x == i_rotatex && block4y == i_rotatey - 2) {
      block4x = i_rotatex - 2;
      block4y = i_rotatey - 1;
    } else if (block4x == i_rotatex - 2 && block4y == i_rotatey - 1) {
      block4x = i_rotatex - 2;
      block4y = i_rotatey + 1;
    } else if (block4x == i_rotatex - 2 && block4y == i_rotatey + 1) {
      block4x = i_rotatex + 1;
      block4y = i_rotatey;
    }
  }
}

int main() {

  int points = 0;

  set_screen();

  while (true) {
    clear_screen();
    print_header(0);
    FallingBlocks piece("T");
    piece.rotate();
    piece.rotate();
    
    for (int i = 20; i >= 0; i--) {
      cout << "           ";
      for (int j = 0; j < 10; j++) {
        if ((piece.block1x == j && piece.block1y == i) ||
            (piece.block2x == j && piece.block2y == i) ||
            (piece.block3x == j && piece.block3y == i) ||
            (piece.block4x == j && piece.block4y == i)) {
          cout << "X";
        } else {
          cout << " ";
        }
      }
      cout << endl;
    }
    break;

  }

  return 0;
}
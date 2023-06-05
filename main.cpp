#include "blocks.h"
#include "graphics.h"
#include <iostream>
using std::cout;
using namespace Blocks;

int main() {

  int points = 0;

  set_screen();

  while (true) {
    clear_screen();
    print_header(0);
    FallingBlocks piece("I");
    for (int i = 20; i >= 0; i--) {
      for (int j = 0; j < 10; j++) {
        if ((piece.block1x == j && piece.block1y == i) ||
            (piece.block2x == j && piece.block2y == i) ||
            (piece.block3x == j && piece.block3y == i) ||
            (piece.block4x == j && piece.block4y == i)) {
          cout << "X";
        }
      }
    }
    while (true) {
    }
  }

  return 0;
}
#include <iostream>
#include <string>

#include "blocks.h"
using std::string;

namespace Blocks {

FallingBlocks::FallingBlocks(string type) {
  this->type = type;
  // initializes starting positions
  if (type == "Q") {
    this->type_num = 1;
    this->color = "\u001b[38;5;226m";

    this->block1x = 4;
    this->block1y = 19;

    this->block2x = 5;
    this->block2y = 19;

    this->block3x = 4;
    this->block3y = 18;

    this->block4x = 5;
    this->block4y = 18;
  } else if (type == "LL") {
    type_num = 3;
    color = "\u001b[38;5;69m";

    block1x = 5;
    block1y = 18;

    block2x = 4;
    block2y = 19;

    block3x = 4;
    block3y = 18;

    block4x = 6;
    block4y = 18;
  } else if (type == "LR") {
    type_num = 4;
    color = "\u001b[38;5;214m";

    block1x = 5;
    block1y = 18;

    block2x = 6;
    block2y = 19;

    block3x = 6;
    block3y = 18;

    block4x = 4;
    block4y = 18;
  } else if (type == "I") {
    type_num = 7;
    color = "\u001b[38;5;51m";

    block1x = 4;
    block1y = 19;

    block2x = 5;
    block2y = 19;

    block3x = 6;
    block3y = 19;

    block4x = 7;
    block4y = 19;

    i_rotatex = 6;
    i_rotatey = 19;
  } else if (type == "S") {
    type_num = 5;
    color = "\u001b[38;5;82m";

    block1x = 5;
    block1y = 18;

    block2x = 6;
    block2y = 19;

    block3x = 5;
    block3y = 19;

    block4x = 4;
    block4y = 18;
  } else if (type == "Z") {
    type_num = 6;
    color = "\u001b[38;5;196m";

    block1x = 5;
    block1y = 18;

    block2x = 4;
    block2y = 19;

    block3x = 5;
    block3y = 19;

    block4x = 6;
    block4y = 18;
  } else if (type == "T") {
    type_num = 2;
    color = "\u001b[38;5;128m";

    block1x = 5;
    block1y = 18;

    block2x = 4;
    block2y = 18;

    block3x = 5;
    block3y = 19;

    block4x = 6;
    block4y = 18;
  }
}

void FallingBlocks::rotate() {

  if (type == "T") {

    if (block2x == block1x - 1 && block2y == block1y) {
      block2x = block1x;
      block2y = block1y + 1;
    } else if (block2x == block1x && block2y == block1y + 1) {
      block2x = block1x + 1;
      block2y = block1y;
    } else if (block2x == block1x + 1 && block2y == block1y) {
      block2x = block1x;
      block2y = block1y - 1;
    } else if (block2x == block1x && block2y == block1y - 1) {
      block2x = block1x - 1;
      block2y = block1y;
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

    if (block4x == block1x + 1 && block4y == block1y) {
      block4x = block1x;
      block4y = block1y - 1;
    } else if (block4x == block1x && block4y == block1y - 1) {
      block4x = block1x - 1;
      block4y = block1y;
    } else if (block4x == block1x - 1 && block4y) {
      block4x = block1x;
      block4y = block1y + 1;
    } else if (block4x == block1x && block4y == block1y + 1) {
      block4x = block1x + 1;
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
      block2y = i_rotatey;
    } else if (block2x == i_rotatex && block2y == i_rotatey) {
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
      block3x = i_rotatex - 1;
      block3y = i_rotatey - 1;
    } else if (block3x == i_rotatex - 1 && block3y == i_rotatey - 1) {
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

void FallingBlocks::move_left(string (&screen)[20][10]){
  if (block1x - 1 >= 0 && block2x - 1 >= 0 && block3x - 1 >= 0 && block4x - 1 >= 0 && screen[block1y][block1x - 1] == "empty" && screen[block2y][block2x - 1] == "empty" && screen[block3y][block3x - 1] == "empty" && screen[block4y][block4x - 1] == "empty"){
    block1x--;
    block2x--;
    block3x--;
    block4x--;

    if (type == "I"){
      i_rotatex--;
    }
  }
}

void FallingBlocks::move_right(string (&screen)[20][10]){
  if (block1x + 1 < 10 && block2x + 1 < 10 && block3x + 1 < 10 && block4x + 1 < 10 && screen[block1y][block1x - 1] == "empty" && screen[block2y][block2x - 1] == "empty" && screen[block3y][block3x - 1] == "empty" && screen[block4y][block4x - 1] == "empty"){
    block1x++;
    block2x++;
    block3x++;
    block4x++;

    if(type == "I"){
      i_rotatex++;
    }
  }
}

void FallingBlocks::drop(string (&screen)[20][10]) {
  if (block1y - 1 >= 0 && block2y - 1 >= 0 && block3y - 1 >= 0 && block4y - 1 >= 0 && (screen[block1y - 1][block1x] == "empty" && screen[block2y - 1][block2x] == "empty" && screen[block3y - 1][block3x] == "empty" && screen[block4y - 1][block4x] == "empty")){
    
    block1y--;
    block2y--;
    block3y--;
    block4y--;
  
    if (type == "I") {
      i_rotatey--;
    }
  }
}

int FallingBlocks::get_type_num() const { return this->type_num; }

string FallingBlocks::get_type() const { return this->type; }

string FallingBlocks::get_color() const { return this->color; }

int FallingBlocks::get_i_rotatex() const { return this->i_rotatex; }

int FallingBlocks::get_i_rotatey() const { return this->i_rotatey; }

int FallingBlocks::get_block1x() const { return this->block1x; }

int FallingBlocks::get_block1y() const { return this->block1y; }

int FallingBlocks::get_block2x() const { return this->block2x; }

int FallingBlocks::get_block2y() const { return this->block2y; }

int FallingBlocks::get_block3x() const { return this->block3x; }

int FallingBlocks::get_block3y() const { return this->block3y; }

int FallingBlocks::get_block4x() const { return this->block4x; }

int FallingBlocks::get_block4y() const { return this->block4y; }

} // namespace Blocks
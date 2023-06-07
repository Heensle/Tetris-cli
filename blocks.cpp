#include <iostream>
using std::string;

namespace Blocks {

class FallingBlocks {

public:
  FallingBlocks(string type);

  void rotate();
  void drop();

  string get_type() const;
  string get_color() const;

  int get_i_rotatex() const;
  int get_i_rotatey() const;

  int get_block1x() const;
  int get_block1y() const;
  int get_block2x() const;
  int get_block2y() const;
  int get_block3x() const;
  int get_block3y() const;
  int get_block4x() const;
  int get_block4y() const;

private:
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

void FallingBlocks::drop() {
  block1y--;
  block2y--;
  block3y--;
  block4y--;

  if (type == "I") {
    i_rotatey--;
  }
}

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

class DroppedBlocks {

public:
  DroppedBlocks();
  DroppedBlocks(string color);

  string get_color() const;

private:
  string color;
};

DroppedBlocks::DroppedBlocks() { color = "empty"; }

DroppedBlocks::DroppedBlocks(string color) { this->color = color; }

string DroppedBlocks::get_color() const { return this->color; }

} // namespace Blocks
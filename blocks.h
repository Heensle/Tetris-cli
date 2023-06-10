#pragma once

#include <iostream>
using namespace std;

namespace Blocks {
class FallingBlocks {
public:
  FallingBlocks(string type);

  void rotate();
  void move_left(string (&screen)[20][10]);
  void move_right(string (&screen)[20][10]);
  void drop(string (&screen)[20][10]);

  int get_type_num() const;
  string get_type() const;
  string get_color() const;

  int get_i_rotatex() const;
  int get_i_rotatey() const;

  int get_block1x() const;
  int get_block1y() const;
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
  int get_block2x() const;
  int get_block2y() const;
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
  int get_block3x() const;
  int get_block3y() const;
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
  int get_block4x() const;
  int get_block4y() const;
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

private:
  int type_num;
  string type; // "Q" (square), "LL" (blue one), "LR" (orange one), "I", "S",
               // "Z", "T"
  string color; // only used for the I tetromino: because of the way I've
                 // rendered the rotation, I need an arbitrary rotation point
                 // for the I tetromino specifically :/ (it is the in the
                 // position of the third block in the starting position)

  int block1x;
  int block1y;

  int block2x;
  int block2y;

  int block3x;
  int block3y;

  int block4x;
  int block4y;

  int i_rotatex;
  int i_rotatey;
};
} // namespace Blocks
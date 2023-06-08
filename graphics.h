#pragma once

#include "blocks.h"

using namespace Blocks;

namespace Graphics{
  void set_screen();
  
  void clear_screen();
  
  void print_header(int points);
  
  void print_board(string (&screen)[20][10], FallingBlocks piece, int held_piece, int next_piece);
}
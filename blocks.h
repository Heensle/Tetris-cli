#include <iostream>
using namespace std;

namespace Blocks {
class FallingBlocks {
public:
  FallingBlocks(string type);
  void rotate();

private:
  string type;
  string color;

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

class DroppedBlocks {
public:
  DroppedBlocks();
  DroppedBlocks(string color);

private:
  string color;
};
} // namespace Blocks
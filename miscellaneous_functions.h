#include "blocks.h"

using namespace Blocks;

void block_fall(string (&screen)[20][10], FallingBlocks &piece, bool &newPiece);

bool check_loss(string (&screen)[20][10], FallingBlocks &piece);

void clear_line(string (&screen)[20][10], int &points);
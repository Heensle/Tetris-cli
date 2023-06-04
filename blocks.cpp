#include <iostream>
using std::string;

class FallingBlocks{

  public:

    FallingBlocks(string type);

    void rotate();


  private:

    string type; // "Q" (square), "LL" (blue one), "LR" (orange one), "I", "S", "Z", "T"
    string color;

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

FallingBlocks::FallingBlocks(string type){
  this->type = type;
  //initializes starting positions
  if (type == "Q"){
    color = "\u001b[38;5;226m";
    
    block1x = 5;
    block1y = 20;

    block2x = 6;
    block2y = 20;

    block3x = 5;
    block3y = 19;

    block4x = 6;
    block4y = 19;
  } else if (type == "LL"){
    color = "\u001b[38;5;69m";
    
    block1x = 5;
    block1y = 19;

    block2x = 4;
    block2y = 20;

    block3x = 4;
    block3y = 19;

    block4x = 6;
    block4y = 19;
  } else if (type == "LR"){
    color = "\u001b[38;5;214m";
    
    block1x = 5;
    block1y = 19;

    block2x = 6;
    block2y = 20;

    block3x = 6;
    block3y = 19;

    block4x = 4;
    block4y = 19;
  } else if (type == "I"){
    color = "\u001b[38;5;51m";
    
    block1x = 4;
    block1y = 20;

    block2x = 5;
    block2y = 20;

    block3x = 6;
    block3y = 20;

    block4x = 7;
    block4y = 20;
  } else if (type == "S"){
    color = "\u001b[38;5;82m";
    
    block1x = 5;
    block1y = 19;

    block2x = 6;
    block2y = 20;
    
    block3x = 5;
    block3y = 20;

    block4x = 4;
    block4y = 19;
  } else if (type == "Z"){
    color = "\u001b[38;5;196m";
    
    block1x = 5;
    block1y = 19;

    block2x = 4;
    block2y = 20;

    block3x = 5;
    block3y = 20;

    block4x = 6;
    block4y = 19;
  } else if  (type == "T"){
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

void FallingBlocks::rotate(){

  if (type == "T"){
    
    if (block2x == block1x && block2y == block1y + 1){
      block2x = block1x + 1;
      block2y = block1y;
    } else if (block2x == block1x + 1 && block2y == block1y){
      block2x = block1x;
      block2y = block1y - 1;
    } else if (block2x == block1x && block2y == block2y - 1){
      block2x = block1x - 1;
      block2y = block1y;
    } else if (block1x == block1x - 1 && block2y == block1y){
      block2x = block1x;
      block2y = block1y + 1;
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
    
    if (block4x == block1x && block4y == block1y + 1){
      block4x = block1x + 1;
      block4y = block1y;
    } else if (block4x == block1x + 1 && block4y == block1y){
      block4x = block1x;
      block4y = block1y - 1;
    } else if (block4x == block1x && block4y == block1y - 1){
      block4x = block1x - 1;
      block4y = block1y;
    } else if (block4x == block1x - 1 && block4y == block1y){
      block4x = block1x;
      block4y = block1y + 1;
    }
    
  } else if (type == "LL"){
    if (block2x == block1x - 1 && block2y == block1y + 1){
      block2x = block1x + 1;
      block2y = block1y + 1;
    } else if (block2x == block1x + 1 && block2y == block1y + 1){
      block2x = block1x + 1;
      block2y = block1y - 1;
    } else if (block2x == block1x + 1 && block2y == block1y - 1){
      block2x = block1x - 1;
      block2y = block1y - 1;
    } else if (block2x == block1x - 1 && block2y == block1y - 1){
      block2x = block1x - 1;
      block2y = block1y + 1;
    }

    if (block3x == block1x - 1 && block3y == block1y){
      block3x = block1x;
      block3y = block1y + 1;
    } else if (block3x == block1x && block3y == block1y + 1){
      block3x = block1x + 1;
      block3y = block1y;
    } else if (block3x == block1x + 1 && block3y == block1y){
      block3x = block1x;
      block3y = block1y - 1;
    } else if (block3x == block1x && block3y == block1y - 1){
      block3x = block1x - 1;
      block3y = block1y;
    }

    if (block4x == block1x - 1 && block4y == block1y){
      block4x = block1x;
      block4y = block1y - 1;
    } else if (block4x == block1x && block4y == block1y - 1){
      block4x = block1x - 1;
      block4y = block1y;
    } else if (block4x == block1x - 1 && block4y - block1y){
      block4x = block1x;
      block4y = block1y + 1;
    } else if (block4x == block1x && block4y == block1y + 1){
      block4x = block1x - 1;
      block4y = block1y;
    }
  }



  
}
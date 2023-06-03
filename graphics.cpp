#include <iostream>
#include <ncurses.h>
using std::cout;
using std::endl;

void set_screen(){
  keypad(stdscr, TRUE);
  cbreak();
  noecho();
}

void clear_screen(){
  cout << "\033[H\033[2J\033[3J";
}

void print_header(int points){
  cout << "              ┌────┐              " << endl << "              │";
  if (points < 10){
    cout << "  " << points << " ";
  } else if (points < 100){
    cout << " " << points << " ";
  } else if (points < 1000){
    cout << " " << points;
  } else if (points < 10000){
    cout << " " << points / 1000 << "k ";
  } else if (points < 100000){
    cout << " " << points / 1000 << "k";
  } else if (points < 1000000){
    cout << points / 1000 << "k";
  } else if (points < 10000000){
    cout << " " << points / 1000000 << "m ";
  } else if (points < 100000000){
    cout << " " << points / 1000000 << "m";
  } else {
    cout << " ok ";
  }

  cout << "│              " << endl;
  cout << " HOLD ┌───────┴────┴───────┐ NEXT " << endl;
}


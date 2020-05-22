
#include <iostream>
#include <utility>
#include <cstring>
#include "direction.hpp"
#include "game.hpp"

bool isDebugMode = false;

void parseArg( int argc, char** argv, int* ri, bool* rb ){
  *rb = false;
  if ( argc == 1 ){
    std::cout << "4x4 gird mode." << std::endl;
    *ri = 4;
  } else {
    if ( argc > 2 && !strcmp( argv[2], "true" ) ) *rb = true;
    int t = std::atoi(argv[1]);
    if ( t < 2 ) {
      std::cout << "4x4 gird mode." << std::endl;
      *ri = 4;
    } else {
      printf("%dx%d gird mode.",t,t);
      *ri = t;
    }
  }
  return;
}

int main( int argc, char** argv ){

  int ri;
  bool rb;
  parseArg(argc,argv,&ri,&rb);
  wumpus::Game game( ri, rb );

  while(true){
    while(!game.shouldExit()){
      game.execute();
    }
    std::cout << "Do you want to play again? [y/n]" << std::endl;
    if ( getChar() == 'y' ){
      std::cout << "Do you want to reset map? [y/n]" << std::endl;
      if ( getChar() == 'y'){
        game = *new(&game) wumpus::Game(ri,rb);
      } else {
        game.setNewPlayerPos();
      }
    } else { break; }
  };

}
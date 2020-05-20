
#include <iostream>
#include <ncurses.h>
#include "game.hpp"

int parseArg( int argc, char** argv ){
  if ( argc == 1 ){
    std::cout << "4x4 gird mode." << std::endl;
    return 4;
  } else {
    int t = std::atoi(argv[1]);
    if ( t < 2 ) {
      std::cout << "4x4 gird mode." << std::endl;
      return 4;
    } else {
      printf("%dx%d gird mode.",t,t);
      return t;
    }
  }
}

int main( int argc, char** argv ){

  wumpus::Game game(parseArg(argc,argv));
  std::cout << "hoge" << std::endl;

  while(!game.shouldExit()){
    game.execute();
  }

}
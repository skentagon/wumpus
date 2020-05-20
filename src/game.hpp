
#ifndef SKENTAGON_WUMPUS_GAME_HEADER_INCLUDED
#define SKENTAGON_WUMPUS_GAME_HEADER_INCLUDED
#pragma once

#include <vector>
#include <cstdlib> // or <stdlib.h>
#include <ctime> // or <time.h>
#include "grid.hpp"
#include "player.hpp"

namespace wumpus {
  class Game {
    public:
      Game( int i ) : grid(Grid(i,i)) {
        std::srand(static_cast<unsigned int>(std::time(NULL)));
        while(true){
          int x = static_cast<int>(std::rand()%i);
          int y = static_cast<int>(std::rand()%i);
          if ( grid.grid[x][y].getEvent() != nullptr ){
            grid.grid[x][y].setEvent(new Wumpus);
          }
        }
      };
      bool shouldExit() const { return sw_shouldExit; }
      void execute() {
        //move
        sw_shouldExit = true;
        std::cout << sw_shouldExit << std::endl;
      }
    private:
      Grid grid;
      PlayerState player;
      bool sw_shouldExit = false;
      int allowNum = 3;
  };
}

#endif

#ifndef SKENTAGON_WUMPUS_PLAYER_HEADER_INCLUDED
#define SKENTAGON_WUMPUS_PLAYER_HEADER_INCLUDED
#pragma once

#include <iostream>
#include <string>
#include <utility>
#include "direction.hpp"
#include "arrow.hpp"

namespace wumpus {

  class Grid;
  class Player {
    public:
      void setPos( std::pair<int,int> pos ) { this->pos = pos; }
      std::pair<int,int> getPos() const { return pos; }
      int getLeftArrow() const { return arrow.getLeftArrow(); }
      bool canFire() const { return arrow.canFire(); }
      bool fire( Grid& grid, const util::Direction& dir ){
        return arrow.fire( grid, pos, dir );
      };
      bool hasGold = false;
    private:
      Arrow arrow;
      std::pair<int,int> pos;
      //std::vector<>
  };

}

#endif
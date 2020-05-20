
#ifndef SKENTAGON_WUMPUS_GRID_HEADER_INCLUDED
#define SKENTAGON_WUMPUS_GRID_HEADER_INCLUDED
#pragma once

#include <vector>
#include "room.hpp"

namespace wumpus {
  class Grid {
    public:
      Grid( int x, int y ) :
        grid(std::vector<std::vector<Room>>(x,std::vector<Room>(y)))
        {};
      int getXSize() const { return grid.size(); }
      int getYSize() const { return grid[0].size(); }
      bool canMoveTo( std::pair<int,int> pos ){
        if ( 0 <= pos.first && pos.first < getXSize() && 0 <= pos.second && pos.second < getYSize() ){
          return true;
        }
        return false;
      }
      std::vector<std::vector<Room>> grid;
  };
}

#endif
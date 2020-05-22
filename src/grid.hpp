
#ifndef SKENTAGON_WUMPUS_GRID_HEADER_INCLUDED
#define SKENTAGON_WUMPUS_GRID_HEADER_INCLUDED
#pragma once

#include <vector>
#include "room.hpp"
#include "player.hpp"


namespace wumpus {

  class Game;

  class Grid {
    public:
      Grid( int x, int y ) :
        grid(std::vector<std::vector<Room>>(x,std::vector<Room>(y)))
        {};
      int getXSize() const { return grid.size(); }
      int getYSize() const { return grid[0].size(); }
      Room& at( const util::Pos& p ){ return grid[p.x][p.y]; }
      const Room& at( const util::Pos& p ) const { return grid[p.x][p.y]; }
      bool canMoveTo( util::Pos pos ) const {
        if ( 0 <= pos.x && pos.x < getXSize() && 0 <= pos.y && pos.y < getYSize() ){
          return true;
        }
        return false;
      }
      void show( const Player* player, Game* game ) const;
      std::vector<std::vector<Room>> grid;
    private:
      
  };
}

#endif
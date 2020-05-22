
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
      Room& at( const std::pair<int,int>& p ){ return grid[p.first][p.second]; }
      const Room& at( const std::pair<int,int>& p ) const { return grid[p.first][p.second]; }
      bool canMoveTo( std::pair<int,int> pos ) const {
        if ( 0 <= pos.first && pos.first < getXSize() && 0 <= pos.second && pos.second < getYSize() ){
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
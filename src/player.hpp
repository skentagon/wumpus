
#ifndef SKENTAGON_WUMPUS_PLAYER_HEADER_INCLUDED
#define SKENTAGON_WUMPUS_PLAYER_HEADER_INCLUDED
#pragma once

#include <iostream>
#include <string>
#include <utility>
#include "direction.hpp"

namespace wumpus {

  struct PlayerState {
    std::pair<int,int> pos;
    int leftArrow;
    //std::vector<>
  };

  class Player {
    public:
      void setPos( std::pair<int,int> pos ) { this->pos = pos; }
      std::pair<int,int> getPos() const { return pos; }
    private:
      int leftArrow = 3;
      std::pair<int,int> pos;
  };

}

#endif
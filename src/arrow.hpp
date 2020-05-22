
#ifndef SKENTAGON_WUMPUS_ARROW_HEADER_INCLUDED
#define SKENTAGON_WUMPUS_ARROW_HEADER_INCLUDED
#pragma once

#include "direction.hpp"
#include "pos.hpp"

namespace wumpus {
  class Grid;
  class Arrow {
    public:
      Arrow() : arrowNum(3) {};
      bool canFire() const { return 0 < arrowNum; }
      bool fire( Grid& grid, util::Pos pos, const util::Direction& dir );
      int getLeftArrow() const { return arrowNum; }
    private:
      static const int range = 3;
      int arrowNum;
  };
}

#endif
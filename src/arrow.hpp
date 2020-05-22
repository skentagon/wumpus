
#ifndef SKENTAGON_WUMPUS_ARROW_HEADER_INCLUDED
#define SKENTAGON_WUMPUS_ARROW_HEADER_INCLUDED
#pragma once

#include "direction.hpp"

namespace wumpus {
  class Grid;
  class Arrow {
    public:
      Arrow() = default;
      bool canFire() const { return 0 < arrowNum; }
      bool fire( Grid& grid, std::pair<int,int> pos, const util::Direction& dir );
      int getLeftArrow() const { return arrowNum; }
    private:
      static const int range = 3;
      int arrowNum = 3;
  };
}

#endif
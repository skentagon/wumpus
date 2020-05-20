
#ifndef SKENTAGON_WUMPUS_ARROW_HEADER_INCLUDED
#define SKENTAGON_WUMPUS_ARROW_HEADER_INCLUDED
#pragma once

#include <vector>
#include "grid.hpp"
#include "direction.hpp"

namespace wumpus {
  class Arrow {
    public:
      Arrow();
      bool canFire() const { return 0 < arrowNum; }
      bool fire( const Grid& grid, std::pair<int,int> pos, const util::Direction& dir );
    private:
      int arrowNum = 3;
  };
}

#endif
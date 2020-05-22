
#include <cstdlib>
#include "arrow.hpp"
#include "direction.hpp"
#include "grid.hpp"

namespace wumpus {

  bool Arrow::fire( Grid& grid, util::Pos pos, const util::Direction& dir ){
    --arrowNum;
    auto ap = pos;
    for( size_t i=0; i<range; ++i ){
      if ( grid.canMoveTo( ap + dir.getDirection() ) ){
        ap = ap + dir.getDirection();
        if ( grid.at(ap).getEvent() != nullptr && grid.at(ap).getEvent()->getSymbol() == 'w' ){
          delete grid.at(ap).getEvent();
          grid.at(ap).setEvent();
          return true;
        }
      } else { break; }
    }

    // move wumpus
    if ( rand()%4 <3 ){
      delete grid.at(ap).getEvent();
      while(true){
        grid.at(ap).setEvent();
        int x = static_cast<int>(std::rand()%grid.getXSize());
        int y = static_cast<int>(std::rand()%grid.getYSize());
        if ( grid.grid[x][y].getEvent() == nullptr && pos != util::Pos(x,y) ){
          grid.grid[x][y].setEvent(new Wumpus);
          break;
        }
      }
    }
    return false;
    
  }

}
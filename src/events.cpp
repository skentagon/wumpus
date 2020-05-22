
#include <string>
#include <cstdlib>
#include "player.hpp"
#include "ioplayer.hpp"
#include "grid.hpp"
#include "events.hpp"

namespace wumpus {
  
  bool Bats::encounter( IPlayer* ioplayer, Player* player, Grid* grid ) {
    ioplayer->setOutput(IOPlayer::ActResult::movedBats);
    while(true){
      int x = static_cast<int>(std::rand()%grid->getXSize());
      int y = static_cast<int>(std::rand()%grid->getYSize());
      if ( grid->grid[x][y].getEvent() == nullptr && player->getPos() != std::make_pair(x,y) ){
        player->setPos(std::make_pair(x,y));
        break;
      }
    }
    return false;
  }

  bool Gold::encounter( IPlayer* ioplayer, Player* player, Grid* grid ) {
    if (player->hasGold == false){
      ioplayer->setOutput(IOPlayer::ActResult::getGold);
      player->hasGold = true;
    }
    return false;
  }

}
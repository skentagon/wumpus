
#include <vector>
#include "grid.hpp"
#include "room.hpp"
#include "player.hpp"
#include "game.hpp"

namespace wumpus {

  void Grid::show( const Player* player, Game* game ) const {
    for( int i=0; i<getXSize(); ++i ){
      for( int j=0; j<getYSize(); ++j ){
        std::cout << "+---";
      }
      std::cout << "+\n";
      for( int j=0; j<getYSize(); ++j ){
        std::cout << "|   ";
      }
      std::cout << "|\n";
      for( int j=0; j<getYSize(); ++j ){
        if ( player->getPos() == std::make_pair(i,j) ){
          std::cout << "| * ";
        } else if ( game->isDebugMode && grid[i][j].getEvent() != nullptr ){
          std::cout << "| " << grid[i][j].getEvent()->getSymbol() << " ";
        } else if ( game->isDebugMode && std::make_pair(i,j) == game->escape ) {
          std::cout << "| e ";
        } else {
          std::cout << "|   ";
        }
      }
      std::cout << "|\n";
      for( int j=0; j<getYSize(); ++j ){
        std::cout << "|   ";
      }
      std::cout << "|\n";
    }
    for( int j=0; j<getYSize(); ++j ){
      std::cout << "+---";
    }
    std::cout << "+\n";
  }

}
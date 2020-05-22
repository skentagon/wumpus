
#ifndef SKENTAGON_WUMPUS_GAME_HEADER_INCLUDED
#define SKENTAGON_WUMPUS_GAME_HEADER_INCLUDED
#pragma once

#include <vector>
#include <cstdlib> // or <stdlib.h>
#include <ctime> // or <time.h>
#include "player.hpp"
#include "ioplayer.hpp"
#include "grid.hpp"

namespace wumpus {

  class Game {
    public:
      Game( int i, bool d ) : grid(Grid(i,i)), player(), ioPlayer(nullptr), sw_shouldExit(false), isDebugMode(d) {
        std::srand(static_cast<unsigned int>(std::time(NULL)));
        setRandCell(new Wumpus);
        setRandCell(new Bats);
        setRandCell(new Bats);
        setRandCell(new Pit);
        setRandCell(new Pit);
        setRandCell(new Gold);
        setNewPlayerPos();
        if (doesUseAI) {
          ioPlayer = new AI(i);
        } else {
          ioPlayer = new IOPlayer;
        }
        escape = player.getPos();
      };
      ~Game(){ delete ioPlayer; }
      bool shouldExit() const { return sw_shouldExit; }
      void execute() {
        grid.show( &player, this );
        for( size_t i=0; i<4; ++i ){
          auto ap = player.getPos() + util::Direction(static_cast<int>(i)).getDirection();
          if ( grid.canMoveTo(ap) && grid.at(ap).getEvent() != nullptr ){
            ioPlayer->setOutput(grid.at(ap).getEvent()->percept());
          }
        }
        while(true){
          bool actb;
          util::Direction actd;
          ioPlayer->getAct( &player, &actb, &actd );
          //check
          if ( actb ){
            if ( player.canFire() ){
              if ( player.fire(grid,actd) ){
                ioPlayer->setOutput(IOPlayer::ActResult::killWumpus);
              }
              break;
            } else {
              ioPlayer->setOutput(IOPlayer::ActResult::noLeftArrow);
            }
          } else {
            if ( grid.canMoveTo( player.getPos() + actd.getDirection() ) ){
              player.setPos( player.getPos() + actd.getDirection() );
              break;
            } else {
              ioPlayer->setOutput(IOPlayer::ActResult::mapAreaOut);
            }
          }
        }
        auto event = grid.grid[player.getPos().x][player.getPos().y].getEvent();
        if ( event != nullptr ){
          if (event->encounter(ioPlayer,&player,&grid)){ sw_shouldExit = true; }
        }
        if ( player.hasGold && escape == player.getPos() ){
          ioPlayer->setOutput(IOPlayer::ActResult::win);
          sw_shouldExit = true;
        }
      }
      void setNewPlayerPos(){
        while(true){
          int x = static_cast<int>(std::rand()%grid.getXSize());
          int y = static_cast<int>(std::rand()%grid.getXSize());
          if ( grid.grid[x][y].getEvent() == nullptr ){
            player.setPos(util::Pos(x,y));
            break;
          }
        }
      }
      bool doesUseAI = false;
      bool isDebugMode = false;
      util::Pos escape;
    private:
      Grid grid;
      Player player;
      IPlayer* ioPlayer;
      bool sw_shouldExit = false;
      void setRandCell( Event* event ){
        while(true){
          int x = static_cast<int>(std::rand()%grid.getXSize());
          int y = static_cast<int>(std::rand()%grid.getYSize());
          if ( grid.grid[x][y].getEvent() == nullptr ){
            grid.grid[x][y].setEvent(event);
            break;
          }
        }
      }
  };
}

#endif
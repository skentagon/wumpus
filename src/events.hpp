
#ifndef SKENTAGON_WUMPUS_EVENTS_HEADER_INCLUDED
#define SKENTAGON_WUMPUS_EVENTS_HEADER_INCLUDED
#pragma once

#include <string>
#include <cstdlib>
#include "player.hpp"
#include "ioplayer.hpp"
#include "grid.hpp"

namespace wumpus {
  class Grid;
  class Event {
    public:
      virtual IOPlayer::ActResult percept() const =0;
      virtual char getSymbol() const =0;
      virtual bool encounter( IPlayer* ioplayer, Player* player, Grid* grid ) =0;
      virtual ~Event() {};
  };

  class Wumpus : public Event {
    public:
      ~Wumpus() = default;
      IOPlayer::ActResult percept() const override { return IOPlayer::ActResult::perceptWumpus; }
      char getSymbol() const override { return 'w'; }
      bool encounter( IPlayer* ioplayer, Player* player, Grid* grid ) override {
        ioplayer->setOutput(IOPlayer::ActResult::killedWumpus);
        return true;
      }
    private:
  };

  class Bats : public Event {
    public:
      IOPlayer::ActResult percept() const override { return IOPlayer::ActResult::perceptBats; }
      char getSymbol() const override { return 'b'; }
      bool encounter( IPlayer* ioplayer, Player* player, Grid* grid ) override;
    private:
  };

  class Pit : public Event {
    public:
      IOPlayer::ActResult percept() const override { return IOPlayer::ActResult::perceptPit; }
      char getSymbol() const override { return 'p'; }
      bool encounter( IPlayer* ioplayer, Player* player, Grid* grid ) override {
        ioplayer->setOutput(IOPlayer::ActResult::deadPit);
        return true;
      }
    private:
  };

  class Gold : public Event {
    public:
      IOPlayer::ActResult percept() const override { return IOPlayer::ActResult::perceptGold; }
      char getSymbol() const override { return 'g'; }
      bool encounter( IPlayer* ioplayer, Player* player, Grid* grid ) override;
    private:
  };

}

#endif
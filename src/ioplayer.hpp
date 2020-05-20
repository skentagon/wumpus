
#ifndef SKENTAGON_WUMPUS_IOPLAYER_HEADER_INCLUDED
#define SKENTAGON_WUMPUS_IOPLAYER_HEADER_INCLUDED
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

  class IPlayer {
    public:
      virtual std::pair<bool,util::Direction> getAct( const PlayerState* state ) =0;
      virtual void setPos( std::pair<int,int> pos ) =0;
      virtual void setOutput( const std::string& s ) =0;
  };

  class Player : public IPlayer {
    public:
      std::pair<bool,util::Direction> getAct( const PlayerState* state ) override {
        std::cout << "Please input next action." << std::endl;
        std::string s;
        std::cin >> s;
        if (s[0] == ' '){
          return std::make_pair(true,util::Direction(s[1]));
        } else {
          return std::make_pair(false,util::Direction(s[0]));
        }
      }
      void setPos( std::pair<int,int> pos ) override { this->pos = pos; }
    private:
      std::pair<int,int> pos;
  };

  class AI : public IPlayer {
    public:
      std::pair<bool,util::Direction> getAct( const PlayerState* state ) override {
        //
      }
      void setPos( std::pair<int,int> pos ) override { this->pos = pos; }
    private:
      std::pair<int,int> pos;
  };

}

#endif

#ifndef SKENTAGON_WUMPUS_DIRECTION_HEADER_INCLUDED
#define SKENTAGON_WUMPUS_DIRECTION_HEADER_INCLUDED
#pragma once

#include <vector>
#include <iostream>
#include "pos.hpp"

namespace wumpus::util {

  class Direction {
    public:
      enum DirectionType {
        north = 0,
        south,
        east,
        west
      };
      Direction() = default;
      Direction( DirectionType type ) : type(type) {}
      Direction( int p ) : type(static_cast<DirectionType>(p)) {}
      Direction( char ch ){
        switch(ch){
          case 'w':
            type = DirectionType::north;
            break;
          case 'a':
            type = DirectionType::east;
            break;
          case 's':
            type = DirectionType::south;
            break;
          case 'd':
            type = DirectionType::west;
            break;
          default:
            std::cout << ch << std::endl;
            throw "unexpected char";
            break;
        };
      };
      util::Pos getDirection() const {
        switch(type){
          case DirectionType::north:
            return util::Pos(-1,0);
          case DirectionType::west:
            return util::Pos(0,1);
          case DirectionType::south:
            return util::Pos(1,0);
          case DirectionType::east:
            return util::Pos(0,-1);
          default:
            throw "unexpected type";
        };
      }
    private:
      DirectionType type;
  };
}

#endif
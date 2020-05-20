
#ifndef SKENTAGON_WUMPUS_DIRECTION_HEADER_INCLUDED
#define SKENTAGON_WUMPUS_DIRECTION_HEADER_INCLUDED
#pragma once

#include <vector>
#include <stdexcept>
#include <utility>

namespace wumpus::util {
  class Direction {
    public:
      enum DirectionType {
        north = 0,
        south,
        east,
        west
      };
      Direction( DirectionType type ) : type(type) {}
      Direction( int stat ) : type(static_cast<DirectionType>(stat)) {}
      Direction( char ch ){
        switch(ch){
          case 'w':
            Direction(DirectionType::north);
            break;
          case 'a':
            Direction(DirectionType::west);
            break;
          case 's':
            Direction(DirectionType::south);
            break;
          case 'd':
            Direction(DirectionType::east);
            break;
          default:
            throw std::runtime_error("unexpected char");
            break;
        };
      };
      std::pair<int,int> getDirection() const {
        switch(type){
          case DirectionType::north:
            return std::make_pair(-1,0);
          case DirectionType::west:
            return std::make_pair(-1,0);
          case DirectionType::south:
            return std::make_pair(-1,0);
          case DirectionType::east:
            return std::make_pair(-1,0);
          default:
            throw std::runtime_error("unexpected type");
        };
      }
    private:
      DirectionType type;
  };
}

#endif
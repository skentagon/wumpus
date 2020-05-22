
#ifndef SKENTAGON_WUMPUS_DIRECTION_HEADER_INCLUDED
#define SKENTAGON_WUMPUS_DIRECTION_HEADER_INCLUDED
#pragma once

#include <vector>
#include <stdexcept>
#include <utility>

namespace wumpus::util {

  inline std::pair<int,int> move( const std::pair<int,int>& l, const std::pair<int,int>& r ){
    return std::make_pair(
      l.first + r.first,
      l.second + r.second
    );
  }

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
            throw std::runtime_error("unexpected char");
            break;
        };
      };
      std::pair<int,int> getDirection() const {
        switch(type){
          case DirectionType::north:
            return std::make_pair(-1,0);
          case DirectionType::west:
            return std::make_pair(0,1);
          case DirectionType::south:
            return std::make_pair(1,0);
          case DirectionType::east:
            return std::make_pair(0,-1);
          default:
            throw std::runtime_error("unexpected type");
        };
      }
    private:
      DirectionType type;
  };
}

#endif
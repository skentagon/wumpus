
#ifndef SKENTAGON_WUMPUS_POS_HEADER_INCLUDED
#define SKENTAGON_WUMPUS_POS_HEADER_INCLUDED
#pragma once

namespace wumpus::util {
  class Pos {
    public:
      Pos() = default;
      Pos( int x, int y ) : x(x), y(y) {}
      Pos operator+( const Pos& pos ){
        Pos t(*this);
        t.x += pos.x;
        t.y += pos.y;
        return t;
      }
      bool operator==( const Pos& p ){
        return x == p.x && y == p.y;
      }
      bool operator!=( const Pos& p ){ return !operator==(p); }
      int x;
      int y;
  };
}

#endif
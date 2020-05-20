
#ifndef SKENTAGON_WUMPUS_ROOM_HEADER_INCLUDED
#define SKENTAGON_WUMPUS_ROOM_HEADER_INCLUDED
#pragma once

#include "events.hpp"

namespace wumpus {
  class Room {
    public:
      ~Room(){ delete event; }
      void setEvent( Event* event = nullptr ){ this->event = event; }
      Event* getEvent() { return event; }
    private:
      Event* event = nullptr;
  };
}

#endif
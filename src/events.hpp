
#ifndef SKENTAGON_WUMPUS_EVENTS_HEADER_INCLUDED
#define SKENTAGON_WUMPUS_EVENTS_HEADER_INCLUDED
#pragma once

#include <string>

namespace wumpus {
  class Event {
    public:
      virtual const char* percept() const =0;
      virtual void encounter() =0;
      virtual ~Event() {};
  };

  class Wumpus : public Event {
    public:
      ~Wumpus() = default;
      const char* percept() const override { return "You smell a terrible stench."; }
      void encounter() override {}
    private:
  };

  class Bats : public Event {
    public:
      const char* percept() const override { return "You hear wings flapping."; }
      void encounter() override {}
    private:
  };

  class Pit : public Event {
    public:
      const char* percept() const override { return "You feel a breeze."; }
      void encounter() override {}
    private:
  };

  class Gold : public Event {
    public:
      const char* percept() const override { return "You see a glimmer nearby."; }
      void encounter() override {}
    private:
  };

}

#endif

#ifndef SKENTAGON_WUMPUS_IOPLAYER_HEADER_INCLUDED
#define SKENTAGON_WUMPUS_IOPLAYER_HEADER_INCLUDED
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include "direction.hpp"
#include "player.hpp"
#include "input.hpp"

namespace wumpus {

  class IPlayer {
    public:
      enum ActResult {
        // IOs
        noLeftArrow,
        mapAreaOut,
        // Events
        killWumpus,
        killedWumpus,
        movedBats,
        deadPit,
        getGold,
        // precept
        perceptWumpus,
        perceptBats,
        perceptPit,
        perceptGold,
        win,
      };
      virtual void setOutput( const ActResult& r ) =0;
      virtual std::pair<bool,util::Direction> getAct( const Player* state ) =0;
      virtual ~IPlayer(){};
      //virtual void setPos( std::pair<int,int> pos ) =0;
      //virtual void setOutput( const std::string& s ) =0;
  };

  class IOPlayer : public IPlayer {
    public:
      void setOutput( const ActResult& r ) override {
        switch(r){
          case ActResult::noLeftArrow:
            std::cout << "No arrows are left!" << std::endl;
            break;
          case ActResult::mapAreaOut:
            std::cout << "You cannot move there!" << std::endl;
            break;
          case ActResult::killWumpus:
            std::cout << "You killed wumpus!!" << std::endl;
            break;
          case ActResult::killedWumpus:
            std::cout << "You were killed by wumpus..." << std::endl;
            break;
          case ActResult::movedBats:
            std::cout << "You were transfered to somewhere..." << std::endl;
            break;
          case ActResult::deadPit:
            std::cout << "You fell into a pit..." << std::endl;
            break;
          case ActResult::getGold:
            std::cout << "You find gold!!" << std::endl;
            break;
          case ActResult::perceptWumpus:
            std::cout << "You smell a terrible stench." << std::endl;
            break;
          case ActResult::perceptBats:
            std::cout << "You hear wings flapping." << std::endl;
            break;
          case ActResult::perceptPit:
            std::cout << "You feel a breeze." << std::endl;
            break;
          case ActResult::perceptGold:
            std::cout << "You see a glimmer nearby." << std::endl;
            break;
          case ActResult::win:
            std::cout << "You win!" << std::endl;
          
        }
      }
      std::pair<bool,util::Direction> getAct( const Player* state ) override {
        while(true){
          std::cout << "left arrow : " << state->getLeftArrow() << std::endl;
          std::cout << "Please input next action." << std::endl;
          char c = getChar();
          try {
            if ( c == ' '){
              return std::make_pair(true,util::Direction(getChar()));
            } else {
              return std::make_pair(false,util::Direction(c));
            }
          } catch( ... ){
            std::cout << "invailed input! ";
            continue;
          }
          break;
        }
      }
    private:
  };

  class AI : public IPlayer {
    public:
      AI( int i ) : size(i) {}
      void setSize( int i ){ size = i; }
      void setOutput( const ActResult& r ) override {
        switch(r){
          case ActResult::movedBats:
            std::cout << "You were transfered to somewhere..." << std::endl;
            break;
          case ActResult::deadPit:
            std::cout << "You fell into a pit..." << std::endl;
            break;
          case ActResult::perceptWumpus:
            std::cout << "You smell a terrible stench." << std::endl;
            break;
          case ActResult::perceptBats:
            std::cout << "You hear wings flapping." << std::endl;
            break;
          case ActResult::perceptPit:
            std::cout << "You feel a breeze." << std::endl;
            break;
          case ActResult::perceptGold:
            std::cout << "You see a glimmer nearby." << std::endl;
            break;
          default:
            break;
        };
      }
      std::pair<bool,util::Direction> getAct( const Player* state ) override {
        std::pair<bool,util::Direction> act;
        std::cout << "Press any key..." << std::endl;
        getChar();
        return act;
      }
    private:
      std::pair<int,int> target;
      std::vector<std::pair<int,int>> gold;
      int size;
      class understand {
        public:
          typedef std::vector<bool> Cell;
          /*
            gold,
            wumpus,
            pit,
            bat
          */
          std::vector<std::vector<Cell>> v;
          understand( int i ) :
            v(std::vector<std::vector<Cell>>(i,std::vector<Cell>(4,std::vector<bool>(4,true)))) {}

      };
  };

}

#endif
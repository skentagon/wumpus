#ifndef SKENTAGON_WUMPUS_INPUT_HEADER_INCLUDED
#define SKENTAGON_WUMPUS_INPUT_HEADER_INCLUDED
#pragma once

#if 0
  #include <conio.h>
  inline char getChar(){
    return getch();
  }
  #include <termios.h>
  #include <stdio.h>
  inline char getChar(){
    static termios old,cur;
    tcgetattr( 0, &old );
    cur = old;
    cur.c_lflag &= ~ICANON;
    cur.c_lflag &= ~ECHO;
    tcsetattr( 0, TCSANOW, &cur );
    char ch = getchar();
    tcsetattr(0, TCSANOW, &old);
    if ( ch == 27 ){ std::exit(EXIT_SUCCESS); }
    return ch;
  }
#endif

#include <cstdio>

inline char getChar(){
  return getchar();
}

#endif
#ifndef CLASS_GAMESTATE_H
#define CLASS_GAMESTATE_H

#include <vector>

#include "class_card.h"
#include "gameTypes.h"

namespace casino
{
  class gameState
  {  
    gameType t;
    
  public:
    gameType getGameType();
    virtual void print()=0;
  };
}
#endif

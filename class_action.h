#ifndef CLASS_ACTION_H
#define CLASS_ACTION_H

#include "gameTypes.h"

namespace casino
{  
	class action
	{    
		gameType t;
	public:    
		virtual void print()=0;
	};
}

#endif


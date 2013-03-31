#ifndef CLASS_STRATEGY
#define CLASS_STRATEGY


#include "class_action.h"
#include "class_gameState.h"

namespace casino{
	//Local includes

	class strategy
	{
		gameType t;

	public:
		gameType getGameType();
		virtual action* takeAction(gameState& g)=0;    
	};
}

#endif

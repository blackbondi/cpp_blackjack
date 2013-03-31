#ifndef CLASS_BLACKJACKSTRATEGY_H
#define CLASS_BLACKJACKSTRATEGY_H

#include "class_strategy.h"
#include "controlTypes.h"
#include "class_gameState.h"

namespace casino
{
	class blackjackStrategy : public strategy
	{
	public:
		virtual action* takeAction(gameState& g);
		blackjackStrategy(controlType controlType);
	};
}

#endif

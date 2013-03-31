#include "class_blackjackStrategy.h"
#include "class_blackjackState.h"
#include "class_gameState.h"


namespace casino
{
	blackjackStrategy::blackjackStrategy(controlType controlType)
	{
	}

	action* blackjackStrategy::takeAction(gameState& g)
	{
		blackjackState* blackjackState = dynamic_cast<casino::blackjackState*>(&g);
		action* action(NULL);

		action = new blackjackAction(blackjackState->getOption());
		
		return action;
	}
}

#include "class_blackjackAction.h"


namespace casino
{
	blackjackAction::blackjackAction(atype actionType)
	{
		this->actionType = actionType;
	}

	blackjackAction::atype blackjackAction::getAtype()
	{
		return actionType; 
	}

	void blackjackAction::print()
	{

	}
}

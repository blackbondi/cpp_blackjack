#ifndef CLASS_BLACKJACKACTION_H
#define CLASS_BLACKJACKACTION_H

#include "controlTypes.h"
#include "class_action.h"

namespace casino
{
	class blackjackAction : public action {

	public:
		enum atype{HIT,STAND,SPLIT,DOUBLE};
		atype getAtype();

		virtual void print();

		//Constructor
		blackjackAction(atype actionType);

	private:
		atype actionType;

	};
}

#endif


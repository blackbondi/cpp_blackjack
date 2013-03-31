#ifndef CLASS_BLACKJACKSTATE_H
#define CLASS_BLACKJACKSTATE_H

#include "class_gameState.h"
#include "class_blackjackAction.h"
#include "class_card.h"

//#include "class_card.h"
namespace casino
{
	class blackjackState : public gameState 
	{
		//Forward declaration
		//    class card;

		//One vector of cards for each player
		std::vector< std::vector<cards::card*> > cardsDealt;

		//Location of "my cards" in cardsDealt 
		int ourHero;  
		//Location of dealers cards in cardsDealt
		int dealer;

		blackjackAction::atype m_PlayerOption;

	public:
		blackjackState();
		blackjackState(std::vector<std::vector<cards::card*> > cardv,
			int iHero, int iDealer);

		void print();

		//Special card getters
		std::vector<cards::card*>* dealersCards();
		std::vector<cards::card*>* myCards();

		//General card getter
		std::vector<cards::card*> cardsI(int i);  

		//Special indexes for general card getter
		int getOurHero();
		int getDealer();

		/*
		* Returns whether player has busted (has a total greater than 21)
		*/
		bool isBusted(std::vector<cards::card*> cards);

		void setOption(blackjackAction::atype option);

		blackjackAction::atype getOption() const;

		int getTotal(std::vector<cards::card*> cards);

		void reset();
	};
}

#endif

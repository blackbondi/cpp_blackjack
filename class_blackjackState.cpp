#include "class_blackjackState.h"
#include "class_blackjackAction.h"
#include "class_card.h"

namespace casino
{
          
	blackjackState::blackjackState(std::vector< std::vector<cards::card*> > cardv,
		int iHero, int iDealer)
	{
		cardsDealt = cardv;
		ourHero = iHero;
		dealer = iDealer;
	}

	blackjackState::blackjackState()
	{
		dealer = 0;
		ourHero = 1;
		cardsDealt.reserve(2);
		cardsDealt.push_back(std::vector<cards::card*>());
		cardsDealt.push_back(std::vector<cards::card*>());
		cardsDealt[dealer].reserve(7);
		cardsDealt[ourHero].reserve(7);
	}

	void blackjackState::reset()
	{
		cardsDealt.clear();
		cardsDealt.reserve(2);
		cardsDealt.push_back(std::vector<cards::card*>());
		cardsDealt.push_back(std::vector<cards::card*>());
		cardsDealt[dealer].reserve(7);
		cardsDealt[ourHero].reserve(7);
	}

	void blackjackState::print()
	{
	}

	std::vector<cards::card*>* blackjackState::dealersCards()
	{
		return &cardsDealt[dealer];
	}

	std::vector<cards::card*>* blackjackState::myCards()
	{
		return &cardsDealt[ourHero];
	}

	std::vector<cards::card*> blackjackState::cardsI(int i)
	{
		return cardsDealt[i];
	}

	int blackjackState::getOurHero()
	{
		return ourHero;
	}

	int blackjackState::getDealer()
	{
		return dealer;
	}

	bool blackjackState::isBusted(std::vector<cards::card*> cards)
	{
	  return (getTotal(cards) > 21);
	}


	void blackjackState::setOption(blackjackAction::atype option)
	{
		m_PlayerOption = option;
	}


	blackjackAction::atype blackjackState::getOption() const
	{
		return m_PlayerOption;
	}

	int blackjackState::getTotal(std::vector<cards::card*> cards)
	{
		if (cards.empty()) return 0;

		//if a first card has value of 0, then card is face down; return 0
		if (cards[0]->getValue() == 0) return 0;

		//add up card values, treat each ace as 1
		int total = 0;
		std::vector<cards::card*>::const_iterator iter;
		for (iter = cards.begin(); iter != cards.end(); ++iter)
			total += (*iter)->getValue();

		//determine if hand contains an ace
		bool containsAce = false;
		for (iter = cards.begin(); iter != cards.end(); ++iter)
			if ((*iter)->getValue() == cards::ACE)
				containsAce = true;

		//if hand contains ace and total is low enough, treat ace as 11
		if (containsAce && total <= 11)
		{ //add only 10 since we've already added 1 for the ace
			total += 10;
		}

		return total;
	}
}

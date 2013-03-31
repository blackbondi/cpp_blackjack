#include "class_card.h"


namespace cards
{
	card::card(t_suit _suit, Rank _rank)
	{
		suit = _suit;
		rank = _rank;
		m_IsFaceUp = true;
	}

	std::string card::name()
	{
		return "";
	}

	t_suit card::getSuit()
	{
		return suit;
	}

	Rank card::getRank()
	{
		return rank;
	}

	int card::getValue() const
	{
		// Return 0 if the card is face down
		int value = 0;

		if (m_IsFaceUp)
		{
			// Else return the number's value shown on card
			value = rank;

			//value is 10 for face cards
			if (value > 10) {
				value = 10;
			}
		}

		return value;
	}

	bool card::isFaceUp()
	{
		return m_IsFaceUp;
	}

	void card::flip()
	{
		m_IsFaceUp = !(m_IsFaceUp);
	}
}

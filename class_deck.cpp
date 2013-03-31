#include "class_deck.h"
#include "class_card.h"
#include <algorithm>


namespace cards
{
	deck::deck()
	{
	}

	deck::deck(int deckCount)
	{
		cards.reserve(52 * deckCount);

		for(int i=0; i < deckCount; i++)
		{
			for (int s = SPADES; s <= DIAMONDS; ++s)
			{
				for (int r = ACE; r <= KING; ++r)
				{
					cards.push_back(new card(static_cast<t_suit>(s), static_cast<Rank>(r)));
				}
			}		
		}
	}

	void deck::shuffle()
	{
		random_shuffle(cards.begin(), cards.end());
	}

	//Return one card - remove the card from the deck.
	card* deck::deal()
	{
		if (!cards.empty())
		{
			cards.pop_back();
			return cards.back();
		}
	}

	//Return number of cards left
	int deck::size()
	{
		return cards.size();
	}
}

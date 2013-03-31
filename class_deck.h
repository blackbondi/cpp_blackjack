#ifndef CLASS_DECK
#define CLASS_DECK
#include "class_card.h"

namespace cards{

	//A deck of cards
	class deck{
		//Refer explicitly to namespaces in header files
		std::vector<card*> cards;
	public:
		deck();
		deck(int deckCount);
		
		// Shuffle all decks together
		void shuffle();

		//Return one card - remove the card from the deck.
		card* deal();

		//Return number of cards left
		int size();
	};

}

#endif

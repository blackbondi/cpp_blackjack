#ifndef CLASS_CARD
#define CLASS_CARD

#include <vector>
#include <string>

//Anything card-related goes here
namespace cards{

	//Shorthand enum for suits
	typedef enum{SPADES, HEARTS, CLUBS, DIAMONDS} t_suit; 

	//Rank is OK as char
	typedef char t_rank;

	//Tracking array sizes (Defined ONLY here)
	const int NUM_SUITS = 4;
	const int NUM_RANKS = 13;

	//Suit-names, for printing
	const std::string suit_name[] = {"SPADES", "HEARTS", "CLUBS", "DIAMONDS"};

	//Ranks - both as data and for printing
	const t_rank ranks[NUM_RANKS] = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};

	typedef enum {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING} Rank;


	/// A single card 
	class card
	{
		t_suit suit;
		Rank rank;
		bool m_IsFaceUp;

	public:
		card(t_suit _suit, Rank _rank);
		std::string name();
		t_suit getSuit();
		Rank getRank();

		/*
		* Returns the value of a card between 1 and 11
		*/
		int getValue() const;

		/*
		* Flips a card; if face up, becomes face down and vice versa
		*/
		void flip();

		/*
		* Returns if the card is wehther face down or not
		*/
		bool isFaceUp();
	};
} //End of namespace

#endif

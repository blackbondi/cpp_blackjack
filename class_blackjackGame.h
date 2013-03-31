#ifndef CLASS_BLACKJACKGAME_H
#define CLASS_BLACKJACKGAME_H


#include "class_game.h"
#include "class_blackjackAction.h"
#include "class_blackjackState.h"
#include "class_deck.h"

namespace casino
{  
  class blackjackGame : public game 
  {
    
    //Overridden from game
    virtual void playRound();

	cards::deck* m_Deck;

	blackjackState state;
    
  public:
    
    //Constructor
    blackjackGame(int players=1);

    //Overridden from game
    virtual void start();
    
    // Display the card value
	string displayCardValue(cards::card card);

    // Display all cards of a gambler
	void displayCards(gambler player, std::vector<cards::card*> cards);

	/*
	* Continue to deal a card as long as player isn't busted and
	* wants another hit
	*/
	void additionalCards(gambler player, std::vector<cards::card*>* cards, bool isPlayer);

	/*
	* Announce player's state
	*/
	void announceWin(gambler player);
	void announceLose(gambler player);
	void announcePush(gambler player);
	void announceBust(gambler player);

	/*
	* Flips over the first card of the dealer
	*/
	void flipFirstCard();

	/*
	* Get player's option after receiving the first two cards
	*/
	blackjackAction::atype getPlayerOption(gambler player, bool isPlayer);

    // Add the dealer to gambler's vector
	void addDealer();
  };
}

#endif

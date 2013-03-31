#include "class_blackjackGame.h"
#include "class_gambler.h"
#include "class_blackjackAction.h"
#include "class_blackjackState.h"
#include "class_blackjackStrategy.h"
#include "class_card.h"
#include "class_deck.h"

#include <iostream>
#include <ctime>
#include <sstream>

namespace casino
{
	blackjackGame::blackjackGame(int players)
	{		
		srand(time(0)); // Sets a random starting point.

		m_Deck = new cards::deck(1);
		m_Deck->shuffle();
	}

	void blackjackGame::playRound()
	{
		cout << endl;
		vector<gambler>::iterator pPlayer;

		// Deal initial 2 cards to every player
		for (int i = 0; i < 2; ++i)
		{
			for (pPlayer = gamblers.begin() + 1; pPlayer != gamblers.end(); ++pPlayer)
			{
				state.myCards()->push_back(m_Deck->deal());
			}

			// Deal initial 2 cards to dealer
			state.dealersCards()->push_back(m_Deck->deal());
		}

		// Hide dealer's first card
		flipFirstCard();

		// Display every player's hand
		for (pPlayer = gamblers.begin() + 1; pPlayer != gamblers.end(); ++pPlayer)
		{
			displayCards(*pPlayer, *state.myCards());
		}

		// Display dealer's hand
		displayCards(gamblers[0], *state.dealersCards());

		// Deal additional cards to players
		for (pPlayer = gamblers.begin() + 1; pPlayer != gamblers.end(); ++pPlayer)
		{
			additionalCards(*pPlayer, state.myCards(), true);
		}

		// Reveal dealer's first card
		flipFirstCard();
		displayCards(gamblers[0], *state.dealersCards());

		// Deal additional cards to dealer
		additionalCards(gamblers[0], state.dealersCards(), false);


        // If dealer is busted
		if (state.isBusted(*state.dealersCards()))
		{
			// Every player who still playing wins
			for (pPlayer = gamblers.begin() + 1; pPlayer != gamblers.end(); ++pPlayer)
			{
				if (!(state.isBusted(*state.myCards())))
				{
					announceWin(*pPlayer);
				}
			}
		}
		// If dealer isn't busted
		else
		{
			// Compare each player who still playing to dealer
			for (pPlayer = gamblers.begin() + 1; pPlayer != gamblers.end(); ++pPlayer)
			{
				if (!(state.isBusted(*state.myCards())))
				{
					if (state.getTotal(*state.myCards()) > state.getTotal(*state.dealersCards()))
					{
						announceWin(*pPlayer);
					}
					else if (state.getTotal(*state.myCards()) < state.getTotal(*state.dealersCards()))
					{
						announceLose(*pPlayer);
					}
					else
					{
						announcePush(*pPlayer);
					}
				}
			}
		}

		// Remove player's cards
		state.reset();
	}


	void blackjackGame::addDealer()
	{
		gambler* player = new gambler(TERMINAL);

		(*player).initialize("Dealer", "", 1000);

		(*player).addStrategy(t);

		gamblers.push_back(*player);
	}

	void blackjackGame::start()
	{
         cout << endl << "\t\tWelcome to Blackjack! Have fun playing!\n\n";

		 int numPlayers = 1;

		 // The design of the class blackjackState prevents adding more the one player
		 /*while (numPlayers < 1 || numPlayers > 7)
		 {
                 cout << "How many players? (1 - 7): ";
			     cin  >> numPlayers;
		 } 
		 cout << endl;*/

		// Plus the dealer
		gamblers.reserve(numPlayers + 1);

		addDealer();

		for (int i = 0; i < numPlayers; ++i)
		{
			addPlayer();
		}
		
		double bet;
		
		char again = 'y';
		while (again != 'n' && again != 'N')
		{	
              for (int i = 0; i < numPlayers; ++i)
              {
                  gamblers[i+1].placeBet();
			      playRound();
              }

			  cout << "\nDo you want to play again? (Y/N): ";
			  cin  >> again;
		}
	}

	string blackjackGame::displayCardValue(cards::card card)
	{
		stringstream out;
		const string RANKS[] = 
		{"0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

		const string SUITS[] = {"S", "H", "C", "D"};

		if (card.isFaceUp())
		{
			out << RANKS[card.getRank()] << SUITS[card.getSuit()];
		}
		else
		{
			out << "**";
		}

		return out.str();
	}

	void blackjackGame::displayCards(gambler player, std::vector<cards::card*> cards)
	{
		stringstream out;

		player.sendOutput(player.name() + ":\t");

		vector <cards::card*>::const_iterator pCard;
		if (!cards.empty())
		{
			for (pCard = cards.begin(); pCard != cards.end(); ++pCard)
			{
				player.sendOutput(displayCardValue(*(*pCard)) + "\t");
			}

			if (state.getTotal(cards) != 0)
			{
				out << "(" << state.getTotal(cards) << ")";
				player.sendOutput(out.str());
			}
		}
		else
		{
			player.sendOutput("<empty>");
		}

		out.str("");
		out << endl;
		player.sendOutput(out.str());
	}


	void blackjackGame::additionalCards(gambler player, std::vector<cards::card*>* cards, bool isPlayer)
	{
		while (!(state.isBusted(*cards)) && getPlayerOption(player, isPlayer) == blackjackAction::HIT)
		{
			cards->push_back(m_Deck->deal());
			displayCards(player, *cards);

			if (state.isBusted(*cards)) 
			{
				// Announces that the player busts
				announceBust(player);
			}
		}
	}


	blackjackAction::atype blackjackGame::getPlayerOption(gambler player, bool isPlayer)
	{
		stringstream out;
		blackjackAction::atype action;

		if(isPlayer)
		{
			cout << endl << player.name() + ", do you want a hit? (Y/N): ";
			player.sendOutput(out.str());
			string response = player.getInput();

			out.str("");
			out << endl;
			player.sendOutput(out.str());

			if(response == "y" || response == "Y")
			{
				action = blackjackAction::HIT;
			}
			else
			{
				action = blackjackAction::STAND;
			}
		}
		else 
		{
			// Make the desicion for the dealer
			// Dealer must stand on 17 and must draw to 16
			if(state.getTotal(*state.dealersCards()) <= 16) 
			{
				action = blackjackAction::HIT;
			}
			else
			{
				action = blackjackAction::STAND;
			}
		}


		return action;
	}

	void blackjackGame::flipFirstCard()
	{
		if (!((*state.dealersCards()).empty()))
		{
			(*state.dealersCards())[0]->flip();
		}
	}


	void blackjackGame::announceWin(gambler player)
	{
		stringstream out;
		out << endl << player.name() + " wins!" << endl;
		player.sendOutput(out.str());
	    // "Blackjack" means you win 1.5 the amount of your bet.
	    player.giveMoney(player.getBet() * 1.5);
	}


	void blackjackGame::announceLose(gambler player)
	{
		stringstream out;
		out << endl << player.name() + " loses!" << endl;
		player.sendOutput(out.str());
        // Loose your bet.
	    player.giveMoney(player.getBet() * -1);
	}


	void blackjackGame::announcePush(gambler player)
	{
		stringstream out;
		out << endl << player.name() + " pushes!" << endl;
		player.sendOutput(out.str());
	}


	void blackjackGame::announceBust(gambler player)
	{
		stringstream out;
		out << endl << player.name() + " busts!" << endl;
		player.sendOutput(out.str());
        // Loose your bet.
	    player.giveMoney(player.getBet() * -1);
	}
}

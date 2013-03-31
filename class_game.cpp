#include "class_game.h"
#include "class_gambler.h"
#include "class_blackjackGame.h"
#include "controlTypes.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;


namespace casino
{  
	game::game()
	{
	}

	game::game(gameType gameType, int players)
	{
		t = gameType;
		gamblers.reserve(players);
	}

	gameType game::getType()
	{
		return t;
	}

	game* game::create(unsigned int gameType)
	{
		game* game(NULL);
		switch (gameType)
		{
		case blackjack:
			game = new blackjackGame();
			break;
		default:
			game = NULL;
			break;
		}
		return game;
	}

	void game::displayAvailableControlTypes()
	{
		cout << endl;

		cout << TERMINAL + 1 << ". Terminal" << endl; 

		cout << endl;
	}

	gambler* game::addPlayer() 
	{
		string fname, lname;
		double cash;
		int _controlType;

		cout << endl << "Enter control type. Please choose a number!" << endl;
		displayAvailableControlTypes();
		cout << "Your choice: ";
		cin  >> _controlType;
		cout << endl;
		gambler* player = new gambler((controlType)(_controlType - 1));

		// If it's a remote player then add his connection settings here i. e. the IP address

		(*player).sendOutput("Enter player first name: ");
		fname = (*player).getInput();
		cout << endl;

		(*player).sendOutput("Enter player last name: ");
		lname = (*player).getInput();
		cout << endl;

		(*player).sendOutput("Enter cash: ");
		std::istringstream stm;
		stm.str((*player).getInput());
		stm >> cash;

		(*player).initialize(fname, lname, cash);

		(*player).addStrategy(t);

		gamblers.push_back(*player);

		return player;
	}
}

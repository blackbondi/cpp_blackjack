#include "gameTypes.h"
#include "class_game.h"
#include <iostream>
#include <tchar.h>
using namespace std;

namespace casino
{
	/*
	* Display all available games
	*/
	void displayAvailableGames() 
	{
		cout << "Which game do you want to play? Please choose a number!" << endl << endl;

		cout << blackjack + 1 << ". Blackjack" << endl; 

		cout << endl;
	}


	void PlayGame()
	{
		displayAvailableGames();

		unsigned int gameType = 0;
		cout << "Your choice: ";
		cin  >> gameType;

		while (gameType < blackjack || gameType > roulette)
		{
			displayAvailableGames();
		}

		cout << endl;



		game* game = game::create(gameType - 1);
		(*game).start();
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "\t\tWelcome to our casino! Have fun playing!\n\n";
	casino::PlayGame();
	return 0;
}

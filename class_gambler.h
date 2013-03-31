#ifndef CLASS_GAMBLER_H
#define CLASS_GAMBLER_H

#include <vector>
#include <string>
using namespace std;


//Local includes
#include "class_strategy.h"
#include "class_action.h"
#include "class_game.h"
#include "controlTypes.h"

namespace casino{

	//Forward declaration - WHY?
	// Prevents redefining it again
	class game;

	typedef float cash;

	//class player? If dealer is very similar to a gambler
	class gambler
	{
		static int gamblerNr;
		int gamblerId;
		//Indicate if the player can be used in a game, or too busy
		bool readyToPlay;

		//Is float safe for this purpouse? 
		//Use int if rounding is an issue
		cash wallet;
		cash m_Bet;

		controlType m_controlType;

		std::string firstName,lastName;
		std::vector<strategy*> strategies;    

	public:
		gambler(std::string fname,std::string lname);
		gambler(controlType controlType=TERMINAL);

		//Put money in wallet
		void giveMoney(cash amount);

		cash placeBet();
		
		cash getBet();

		std::string name();

		//getter for readyToPlay
		bool ready();

		//Make an in-game decision based on gameState
		action* takeAction(gameState* g);


		//Join a game. 
		//Might set readyToPlay=0
		//Why not just call takeAction?    
		void joinGame(game& g);
		// - To set currentGame?
		// - To ...?

        /*
        * Sends output to player using the specified terminal
        */
		bool sendOutput(string output);
		
        /*
        * Gets input from player using the specified terminal
        */
		string getInput();

		/*
		* Initialize player's name and cash
		*/
		void initialize(string fname, string lname, double cash);

		/*
		* Add a strategy on the basis of a game type
		*/
		strategy* addStrategy(gameType gameType);

        /*
        * Returns a strategy by a game type
	    */
		strategy* getStrategyByGameType(gameType gameType);

	    /*
	    * Returns the control type
	    */
		controlType getControlType();
	};
}

#endif

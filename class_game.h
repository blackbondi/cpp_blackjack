#ifndef CLASS_GAME_H
#define CLASS_GAME_H

#include <vector>

//Local includes
#include "class_gambler.h"
#include "gameTypes.h"

namespace casino
{  
	//Forward declaration - inclusion guard might keep it from being defined. 
	class gambler;

	class game
	{
	protected:
		gameType t;
		std::vector<gambler> gamblers;

		//Make it possible to play several rounds in one game
		virtual void playRound()=0;

	public:
		game();
		game(gameType gameType, int players=1);
		gameType getType();
		/*
		* Adds a player to the game
		*/
		gambler* addPlayer();
		
		/*
	    * Factory method to create a game on the basis of a game type
	    */
		static game* create(unsigned int gameType);
		
		
		static void displayAvailableControlTypes();
		virtual void start()=0;
	};

}

#endif

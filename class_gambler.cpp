#include "class_gambler.h"
#include "class_blackjackStrategy.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;


namespace casino
{
	int gambler::gamblerNr = 0;

	gambler::gambler(std::string fname, std::string lname)
	{
		firstName = fname;
		lastName = lname;
		gamblerId = gamblerNr++;
	}

	gambler::gambler(controlType controlType)
	{
		m_controlType = controlType;
		gamblerId = gamblerNr++;
	}

	void gambler::giveMoney(cash amount)
	{
		wallet += amount;
		m_Bet = 0;
	}

	cash gambler::placeBet()
	{	
        sendOutput("Enter your bet: ");
        std::istringstream stm;
        stm.str(getInput());
        double bet;
        stm >> bet;
        
        if(bet > wallet)
        {
               sendOutput("You haven't enough money to place a bet!");
               bet = 0;
        }
        
		return m_Bet = bet;
	}
	
	cash gambler::getBet()
	{	
		return m_Bet;
	}

	controlType gambler::getControlType()
	{
		return m_controlType;
	}

	std::string gambler::name()
	{
		return firstName + " " + lastName;
	}

	bool gambler::ready()
	{
		return readyToPlay;
	}

	action* gambler::takeAction(gameState* g)
	{
		action* action;
		return action;
	}

	void gambler::joinGame(game& g)
	{
	}

	bool gambler::sendOutput(string output)
	{
		if(m_controlType == TERMINAL)
		{
			cout << output;
		}
		return true;
	}

	string gambler::getInput()
	{
		if(m_controlType == TERMINAL)
		{
			string input;
			cin >> input;
			return input;
		}
	}

	void gambler::initialize(string fname, string lname, double cash)
	{
		firstName = fname;
		lastName = lname;
		wallet = cash;
	}

	strategy* gambler::addStrategy(gameType gameType)
	{
		strategy* strategy(NULL);

		switch (gameType)
		{
		case blackjack:
			strategy = new blackjackStrategy(m_controlType);
			break;
		default:
			strategy = NULL;
			break;
		}

		if(strategy != NULL)
		{
			strategies.push_back(strategy);
		}

		return strategy;
	}


	strategy* gambler::getStrategyByGameType(gameType gameType)
	{
		vector<strategy*>::iterator pStrategy;
		for (pStrategy = strategies.begin(); pStrategy != strategies.end(); ++pStrategy)
		{
			if((*(*pStrategy)).getGameType() == gameType)
			{
				return *pStrategy;
			}
		}
		return NULL;
	}
}

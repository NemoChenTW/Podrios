/*
 * GamblingTable.cpp
 *
 *  Created on: 2014年10月25日
 *      Author: nemo
 */

#include "GamblingTable.h"
#include <iostream>
using namespace std;
GamblingTable::GamblingTable()
{
	MiLog::createInstance(TRACE, true);

	LOG_TRACE("Construct GamblingTable.");

	pokerGame = new PokerGame(PokerGameType_BigDeuce);
}

GamblingTable::~GamblingTable()
{
	// TODO Auto-generated destructor stub
}

///		Construct and initial the game tool.
void GamblingTable::initialGameTool()
{
	GameTool *gameTool;
	pokerGame->initialGameTool(gameTool);
}

/**
 * @brief	Player join the game.
 *
 * @param 	newPlayer	The player who want to join the game.
 *
 * @retval	0	Join success.
 * @retval	-1	The game table is full.
 */
int GamblingTable::joinGame(Player* newPlayer)
{
	unsigned int numberOfPlayers = _players.size();
	if(numberOfPlayers < pokerGame->numberOfMaxPlayers())
	{
		_players.push_back(newPlayer);
		LOG_INFO("Player join the game.");
		LOG_INFO("Current number of players is %d.", _players.size());
		return 0;
	}
	else
	{
		LOG_WARNING("The game table is already full.");
		return -1;
	}

}

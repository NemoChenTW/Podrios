/*
 * PokerGame.cpp
 *
 *  Created on: 2014年10月25日
 *      Author: nemo
 */

#include "PokerGame.h"

PokerGame::PokerGame(PokerGameType pokerGameType)
:_pokerGameType(pokerGameType)
{
	setGameRule();

}

PokerGame::~PokerGame()
{
	// TODO Auto-generated destructor stub
}

/**
 * 	@brief		Set the game rule according to the _pokerGameType
 */
void PokerGame::setGameRule()
{
	if(_pokerGameType == PokerGameType_BigDeuce)
	{
		setBigDeuceGameRule();
	}

}

/**
 * 	@brief		Set the game rule of game big deuce
 */
void PokerGame::setBigDeuceGameRule()
{
	_numberOfMinPlayers = 2;
	_numberOfMaxPlayers = 4;
	_numberOfInitialCards = 13;
}

/*
 * PokerGame.h
 *
 *  Created on: 2014年10月25日
 *      Author: nemo
 */

#ifndef POKERGAME_H_
#define POKERGAME_H_

#include "GameType.h"
// #include "PokerEnum.h"
#include "GameTools/CardDeck/CardDeck.h"


enum PokerGameType
{
	PokerGameType_0,
	PokerGameType_BigDeuce,

	PokerGameType_MAX
};

class PokerGame: public GameType {
public:
	PokerGame(PokerGameType pokerGameType);
	virtual ~PokerGame();

	///		Initial the game tool "CardDeck"
	void initialGameTool(GameTool *cardDeck);

	PokerGameType pokerGameType() {return _pokerGameType;};

	unsigned int numberOfMinPlayers() 	{return _numberOfMinPlayers;};
	unsigned int numberOfMaxPlayers() 	{return _numberOfMaxPlayers;};
	unsigned int numberOfInitialCards()	{return _numberOfInitialCards;};
	

private:

	PokerGameType _pokerGameType;	///< The poker game type recognized.

	unsigned int _numberOfMinPlayers 	= 0;		///< The minimal number of players.
	unsigned int _numberOfMaxPlayers 	= 0;		///< The maximal number of players.
	unsigned int _numberOfInitialCards	= 0;		///< The number of initial cards for each player.


	///		Set the game rule according to the _pokerGameType
	void setGameRule();

	///		Set the game rule of game big deuce
	void setBigDeuceGameRule();
};

#endif /* POKERGAME_H_ */

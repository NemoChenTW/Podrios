/*
 * GamblingTable.h
 *
 *  Created on: 2014年10月25日
 *      Author: nemo
 */

#ifndef GAMBLINGTABLE_H_
#define GAMBLINGTABLE_H_

#include "Dealer.h"
#include "GameTools/GameTool.h"

#include "GameTypes/PokerGame.h"

#include "Log/Log.h"

class GamblingTable {
public:
	GamblingTable();
	virtual ~GamblingTable();


	///		Construct and initial the game tool.
	void initialGameTool();

private:
	Dealer* _dealer;
	PokerGame *pokerGame;
	std::list <GameTool*> _gameTools;
};

#endif /* GAMBLINGTABLE_H_ */

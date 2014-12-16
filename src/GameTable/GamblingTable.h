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

class GamblingTable {
public:
	GamblingTable();
	virtual ~GamblingTable();

private:
	Dealer* _dealer;
	std::list <GameTool*> _gameTools;
};

#endif /* GAMBLINGTABLE_H_ */

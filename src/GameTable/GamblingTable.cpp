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
	cout << "Construct GamblingTable." << endl;

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

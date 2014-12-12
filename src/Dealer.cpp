/*
 * Dealer.cpp
 *
 *  Created on: 2014年10月25日
 *      Author: nemo
 */

#include "Dealer.h"

Dealer::Dealer()
{
	// TODO Auto-generated constructor stub

}

Dealer::~Dealer()
{
	// TODO Auto-generated destructor stub
}

/**
 * @brief 	Assign working gambling table.
 *
 * @param 	gamblingTable	The input gambling table.
 *
 * @retval	0	Success.
 * @retval	-1	Already have working table,
 * @retval	-9	Otherwise,
 */
int Dealer::assignWorkingTable(GamblingTable* gamblingTable)
{
	if(_workingTable != NULL)
	{
		return -1;
	}
	else
	{
		_workingTable = gamblingTable;
		return 0;
	}

	return -9;
}

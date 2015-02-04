/*
 * Podrios.cpp
 *
 *  Created on: 2014年10月23日
 *      Author: nemo
 */

#include "GameTable/GamblingTable.h"
#include <iostream>
#include <unistd.h>
using namespace std;


int main()
{
	cout << "Start Podrios." << endl;
	
	GamblingTable gamblingTable;
	
	gamblingTable.initialGameTool();


	Player player_1, player_2, player_3, player_4, player_5;

	gamblingTable.joinGame(&player_1);
	gamblingTable.joinGame(&player_2);
	gamblingTable.joinGame(&player_3);
	gamblingTable.joinGame(&player_4);
	gamblingTable.joinGame(&player_5);

	while(true)
		sleep(1);

	return 0;
}

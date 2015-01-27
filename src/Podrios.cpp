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

	while(true)
		sleep(1);

	return 0;
}

/*
 * PokerCard.cpp
 *
 *  Created on: 2014年10月24日
 *      Author: nemo
 */

#include "PokerCard.h"

PokerCard::PokerCard()
:_suit(PokerSuit_0), _point(PokerPoint_0)
{

}

PokerCard::PokerCard(PokerSuit suit, PokerPoint point)
:_suit(suit), _point(point)
{

}

PokerCard::~PokerCard()
{
	// TODO Auto-generated destructor stub
}

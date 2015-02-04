/*
 * PokerCard.cpp
 *
 *  Created on: 2014年10月24日
 *      Author: nemo
 */

#include "PokerCard.h"
#include "Log/Log.h"

PokerCard::PokerCard()
:_suit(Poker::Suit::Nil), _point(Poker::Point::Nil)
{

}

PokerCard::PokerCard(Poker::Suit suit, Poker::Point point)
:_suit(suit), _point(point)
{

}

PokerCard::~PokerCard()
{
	// TODO Auto-generated destructor stub
}

///	Show Poker card suit and point.
void PokerCard::show()
{
	LOG_INFO("Suit: %s, Point: %s", enum2str(suit()), enum2str(point()));
}

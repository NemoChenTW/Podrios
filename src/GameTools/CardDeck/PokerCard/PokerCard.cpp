/*
 * PokerCard.cpp
 *
 *  Created on: 2014年10月24日
 *      Author: nemo
 */

#include "PokerCard.h"

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

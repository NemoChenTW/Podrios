/*
 * GamblingTable.cpp
 *
 *  Created on: 2014年10月25日
 *      Author: nemo
 */

#include "GamblingTable.h"

GamblingTable::GamblingTable()
{
	// TODO Auto-generated constructor stub

}

GamblingTable::~GamblingTable()
{
	// TODO Auto-generated destructor stub
}


/**
 * @brief	Generate new card deck.
 *
 * @return	The new generated card deck pointer.
 */
CardDeck* GamblingTable::newCardDeck()
{
	CardDeck* cardDeckPtr = new CardDeck();
	_cardDeck.push_back(cardDeckPtr);

	return cardDeckPtr;
}

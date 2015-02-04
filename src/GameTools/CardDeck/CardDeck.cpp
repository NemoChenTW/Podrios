/*
 * CardDeck.cpp
 *
 *  Created on: 2014年10月25日
 *      Author: nemo
 */

#include "CardDeck.h"

#include <iostream>

CardDeck::CardDeck()
{
	LOG_TRACE("Construct CardDeck.")

}

CardDeck::~CardDeck()
{
	// TODO Auto-generated destructor stub
}

///	Insert card into card deck.
/**
 * @brief	Insert card into card deck.
 *
 * @param 	card	Input card pointer.
 */
void CardDeck::push_back(Card *card)
{
	_card.push_back(card);
}

///	Show all card in card deck.
void CardDeck::show()
{
	for(auto card :_card)
	{
		card->show();
	}

}

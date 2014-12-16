/*
 * CardPlayer.cpp
 *
 *  Created on: 2014年10月25日
 *      Author: nemo
 */

#include "CardPlayer.h"

CardPlayer::CardPlayer()
{
	// TODO Auto-generated constructor stub

}

CardPlayer::~CardPlayer()
{
	// TODO Auto-generated destructor stub
}

/**
 * @brief 	Assign card to card player.
 *
 * @param 	card	Input card pointer.
 *
 * Assign input card pointer to the player.
 */
void CardPlayer::assignCard(Card *card)
{
	_card.push_back(card);
}

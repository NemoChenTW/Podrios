/*
 * CardPlayer.h
 *
 *  Created on: 2014年10月25日
 *      Author: nemo
 */

#ifndef CARDPLAYER_H_
#define CARDPLAYER_H_

#include "Player.h"
#include "GameTools/CardDeck/Card.h"

#include <list>

class CardPlayer: public Player {
public:
	CardPlayer();
	virtual ~CardPlayer();

	///	Assign card to card player.
	void assignCard(Card *card);

private:
	std::list <Card*> _card;

};

#endif /* CARDPLAYER_H_ */

/*
 * Dealer.h
 *
 *  Created on: 2014年10月25日
 *      Author: nemo
 */

#ifndef DEALER_H_
#define DEALER_H_

#include <CardDeck.h>

#include <list>

class Dealer {
public:
	Dealer();
	virtual ~Dealer();

	///	Shuffle the card in first card deck.
	void shuffle();

private:
	std::list <CardDeck*> _cardDeck;
};

#endif /* DEALER_H_ */

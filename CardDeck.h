/*
 * CardDeck.h
 *
 *  Created on: 2014年10月25日
 *      Author: nemo
 */

#ifndef CARDDECK_H_
#define CARDDECK_H_

#include "Card.h"

#include <list>

class CardDeck {
public:
	CardDeck();
	virtual ~CardDeck();

	///	Return the number of the cards.
	unsigned int num() {return _numberOfCards;};

	///	Return the maximal number of the cards,
	unsigned int maxNum() {return _maxNumberOfCards;};

private:

	std::list <Card*> _card;	///< The point list for all the cards in the card deck

	unsigned int _maxNumberOfCards;	///< The maximal number of the cards in the card deck

	unsigned int _numberOfCards;	///< The number of the cards in the card deck

};

#endif /* CARDDECK_H_ */

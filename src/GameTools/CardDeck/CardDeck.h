/*
 * CardDeck.h
 *
 *  Created on: 2014年10月25日
 *      Author: nemo
 */

#ifndef CARDDECK_H_
#define CARDDECK_H_

#include "GameTools/GameTool.h"
#include "Card.h"
#include "Log/Log.h"
#include <vector>

class CardDeck :public GameTool{
public:
	CardDeck();
	virtual ~CardDeck();

	///	Insert card into card deck.
	void push_back(Card *card);

	///	Return the number of the cards.
	unsigned int num() {return _card.size();};

	///	Return the maximal number of the cards,
	unsigned int maxNum() {return _maxNumberOfCards;};

	///	Show all card in card deck.
	void show();

private:

	std::vector <Card*> _card;	///< The point vector for all the cards in the card deck

	unsigned int _maxNumberOfCards;	///< The maximal number of the cards in the card deck
};

#endif /* CARDDECK_H_ */

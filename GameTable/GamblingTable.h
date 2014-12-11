/*
 * GamblingTable.h
 *
 *  Created on: 2014年10月25日
 *      Author: nemo
 */

#ifndef GAMBLINGTABLE_H_
#define GAMBLINGTABLE_H_

#include "Dealer.h"
#include "CardDeck.h"

class GamblingTable {
public:
	GamblingTable();
	virtual ~GamblingTable();

	//	Generate new card deck.
	CardDeck* newCardDeck();

private:
	Dealer* _dealer;
	std::list <CardDeck*> _cardDeck;
};

#endif /* GAMBLINGTABLE_H_ */

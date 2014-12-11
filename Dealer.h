/*
 * Dealer.h
 *
 *  Created on: 2014年10月25日
 *      Author: nemo
 */

#ifndef DEALER_H_
#define DEALER_H_

#include "GameTools/CardDeck/CardDeck.h"
#include "stddef.h"
#include <list>

class GamblingTable;

class Dealer {
public:
	Dealer();
	virtual ~Dealer();

	///	Assign working gambling table.
	int assignWorkingTable(GamblingTable* gamblingTable);

	///	Shuffle the card in first card deck.
	void shuffle();

private:
	GamblingTable* _workingTable = NULL;	///< The gambling table which the dealer working on,

	std::list <CardDeck*> _cardDeck;	/// All owned card decks.
};

#endif /* DEALER_H_ */

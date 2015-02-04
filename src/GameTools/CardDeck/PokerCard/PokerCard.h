/*
 * PokerCard.h
 *
 *  Created on: 2014年10月24日
 *      Author: nemo
 */

#ifndef POKERCARD_H_
#define POKERCARD_H_

#include "GameTools/CardDeck/Card.h"
#include "PokerEnum.h"

class PokerCard: public Card {
public:
	PokerCard();
	PokerCard(Poker::Suit suit, Poker::Point point);
	virtual ~PokerCard();

	// ===== Setter & Getter =====
	void setSuit(Poker::Suit suit) {_suit = suit;};
	void setPoint(Poker::Point point) {_point = point;};

	Poker::Suit suit(){return _suit;};
	Poker::Point point() {return _point;};
	// ===== Setter & Getter =====

	///	Show Poker card suit and point.
	void show();

private:
	Poker::Suit 	_suit;
	Poker::Point 	_point;


};

#endif /* POKERCARD_H_ */

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
	PokerCard(PokerSuit suit, PokerPoint point);
	virtual ~PokerCard();

	// ===== Setter & Getter =====
	void setSuit(PokerSuit suit) {_suit = suit;};
	void setPoint(PokerPoint point) {_point = point;};

	PokerSuit suit(){return _suit;};
	PokerPoint point() {return _point;};
	// ===== Setter & Getter =====

private:
	PokerSuit 		_suit = PokerSuit_0;
	PokerPoint 		_point = PokerPoint_0;


};

#endif /* POKERCARD_H_ */

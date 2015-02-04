/*
 * Card.h
 *
 *  Created on: 2014年10月24日
 *      Author: nemo
 */

#ifndef CARD_H_
#define CARD_H_

class Card {
public:
	Card();
	virtual ~Card();

	///	Show card info.
	virtual void show()=0;

};

#endif /* CARD_H_ */

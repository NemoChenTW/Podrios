/*
 * PokerEnum.cpp
 *
 *  Created on: 2015年1月30日
 *      Author: nemo
 */

#include "PokerEnum.h"

namespace Poker
{
	Suit operator++(Suit& x) { return x = (Suit)(std::underlying_type<Suit>::type(x) + 1);}
	Suit operator*(Suit c) {return c;}
	Suit begin(Suit r) {return Suit::Clubs;}
	Suit end(Suit r)   {return Suit::Last;}

	const char* enum2str(Suit suit)
	{
		if(suit == Suit::Nil)
			return "Nil";
		else if(suit == Suit::Clubs)
			return "Clubs";
		else if(suit == Suit::Diamonds)
			return "Diamonds";
		else if(suit == Suit::Hearts)
			return "Hearts";
		else if(suit == Suit::Spades)
			return "Spades";
		else
			return "Last";
	}

	Point operator++(Point& x) { return x = (Point)(std::underlying_type<Point>::type(x) + 1);}
	Point operator*(Point c) {return c;}
	Point begin(Point r) {return Point::Ace;}
	Point end(Point r) {return Point::Last;}

	const char* enum2str(Point point)
	{
		if(point == Point::Nil)
			return "Nil";
		else if(point == Point::Ace)
			return "Ace";
		else if(point == Point::Deuce)
			return "Deuce";
		else if(point == Point::Three)
			return "Three";
		else if(point == Point::Four)
			return "Four";
		else if(point == Point::Five)
			return "Five";
		else if(point == Point::Six)
			return "Six";
		else if(point == Point::Seven)
			return "Seven";
		else if(point == Point::Eight)
			return "Eight";
		else if(point == Point::Nine)
			return "Nine";
		else if(point == Point::Ten)
			return "Ten";
		else if(point == Point::Jack)
			return "Jack";
		else if(point == Point::Queen)
			return "Queen";
		else if(point == Point::King)
			return "King";
		else
			return "Last";

	}


}

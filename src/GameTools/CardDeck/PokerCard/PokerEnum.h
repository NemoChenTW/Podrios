#ifndef POKERENUM_H_
#define POKERENUM_H_

#include <type_traits>

namespace Poker
{
	enum class Suit
	{
		Nil,
		Clubs,
		Diamonds,
		Hearts,
		Spades,

		Last,
		First=Clubs
	};
	Suit operator++(Suit& x);
	Suit operator*(Suit c);
	Suit begin(Suit r);
	Suit end(Suit r);
	const char* enum2str(Suit suit);

	enum class Point
	{
		Nil,
		Ace,
		Deuce,
		Three,
		Four,
		Five,
		Six,
		Seven,
		Eight,
		Nine,
		Ten,
		Jack,
		Queen,
		King,

		Last,
		First=Ace
	};
	Point operator++(Point& x);
	Point operator*(Point c);
	Point begin(Point r);
	Point end(Point r);
	const char* enum2str(Point point);
}
#endif

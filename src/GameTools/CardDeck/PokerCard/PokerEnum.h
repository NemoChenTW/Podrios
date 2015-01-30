#ifndef POKERENUM_H_
#define POKERENUM_H_
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
	const char* enum2str(Point point);
}
#endif

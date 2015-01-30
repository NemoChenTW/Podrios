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
}
#endif

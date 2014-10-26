#ifndef POKERENUM_H_
#define POKERENUM_H_

enum PokerSuit
{
	PokerSuit_0,
	PokerSuit_Clubs,
	PokerSuit_Diamonds,
	PokerSuit_Hearts,
	PokerSuit_Spades,

	PokerSuit_MAX
};

enum PokerPoint
{
	PokerPoint_0,
	PokerPoint_A,
	PokerPoint_1,
	PokerPoint_2,
	PokerPoint_3,
	PokerPoint_4,
	PokerPoint_5,
	PokerPoint_6,
	PokerPoint_7,
	PokerPoint_8,
	PokerPoint_9,
	PokerPoint_10,
	PokerPoint_J,
	PokerPoint_Q,
	PokerPoint_K,

	PokerPoint_MAX
};

enum PokerGameType
{
	PokerGameType_0,
	PokerGameType_BigDeuce,

	PokerGameType_MAX
};

#endif

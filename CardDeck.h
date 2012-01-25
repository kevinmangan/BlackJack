// Kevin Mangan
// CISC 2000 Blackjack Lab
// CardDeck.h

#ifndef CardDeck_H
#define CardDeck_H
#include "PlayingCard.h"

class CardDeck{

	public:

		PlayingCard deck[52];
		void shuffle();
		static int numCard;

};

#endif

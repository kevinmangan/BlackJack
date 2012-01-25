// Kevin Mangan
// CISC 2000 Blackjack Lab
// Dealer.h

#ifndef DEALER_H
#define DEALER_H
#include <string>
#include "CardDeck.h"
#include "BlackJack.h"
using namespace std;

class Dealer : public BlackJack{

        public:

		Dealer(){};
		Dealer(string namee, double moneyEarnedd){
			name = namee;
			moneyEarned = moneyEarnedd;
		}

		
                string name;
		double moneyEarned;
		PlayingCard hand[13];
		int score, ties;

};

#endif

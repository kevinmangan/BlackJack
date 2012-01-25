// Kevin Mangan
// CISC 2000 BlackJack Lab
// Player.h

#ifndef PLAYER_H
#define PLAYER_H
#include "Dealer.h"
#include "CardDeck.h"

class Player : public Dealer{

	public:
		
		Player(){};
		Player(string namee, int money) : Dealer(namee, money){}	


		int getTotal();
		bool action(CardDeck);
		void scoreboard();
		void displayCards();
		void displayDealer(bool);
		void displayWins(Player);
		void win(Player);
		void deal(CardDeck);		
		bool dealerAction(CardDeck);
		double bet;
};

#endif

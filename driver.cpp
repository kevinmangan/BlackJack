// Kevin Mangan
// CISC 2000
// driver.cpp

#include <iostream>
#include <string>
#include "CardGame.h"
#include "BlackJack.h"
#include "PlayingCard.h"
#include "CardDeck.h"
#include "Dealer.h"
#include "Player.h"
using namespace std;


int main(){

	string dealerr = "dealer";
	int numOfPlayers;
	Player players[4];


	cout << "\n\tHow many players will be in this game? ";
	cin >> numOfPlayers;

	for(int b = 0; b < numOfPlayers; b++){

		cout << "\n\tPlayer " << b+1 << " , what is your name? ";
		cin >> players[b].name;
		players[b].moneyEarned = 10;
	}

	 for(int a = 0; a < numOfPlayers; a++){

		cout << "\n\t" << players[a].name << ", how much would you like to bet? ";
		cin >> players[a].bet;
		cout << endl << endl;
	}


	Player dealer(dealerr, 10);

	CardDeck deck;

	deck.shuffle();

	dealer.deal(deck);

	dealer.displayDealer(false);

	for(int c = 0; c < numOfPlayers; c++)
		players[c].deal(deck);

	for(int d = 0; d < numOfPlayers; d++){
		cout << "\n\n---------------------------------------------------" << endl << endl;
		cout << "\n\tAction for " << players[d].name << endl << endl;
		players[d].action(deck);
		cout << endl << endl;
	}

	dealer.dealerAction(deck);

	for(int e = 0; e < numOfPlayers; e++){
		cout << "\n\n---------------------------------------------------" << endl << endl;
		players[e].win(dealer);
		
		cout << endl << "\tYour earnings so far are " << players[e].moneyEarned << endl << endl;
	}

	for(int f = 0; f < numOfPlayers; f++)
		players[f].scoreboard();

}

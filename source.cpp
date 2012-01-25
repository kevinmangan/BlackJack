// Kevin Mangan
// CISC 2000 BlackJack Lab
// source.cpp

#include <ctime>
#include <iostream>
#include "CardGame.h"
#include "BlackJack.h"
#include "CardDeck.h"
#include "Dealer.h"
#include "PlayingCard.h"
#include "Player.h"
#include <cstdlib>
using namespace std;
int CardDeck::numCard = 0;


// Shuffle the cards
void CardDeck::shuffle(){
	
	srand((unsigned)time(NULL));
	bool picked[52];
	int card, a = 0;

	for (a; a <= 51; a++)
	{
		deck[a].value = -1;
		picked[a] = false;
	}

	for (int b = 0; b <= 51; b++)
	{
		do{
			card = rand() % 52; // a random number from 0 to 51
			if (picked[card] == false)
			{
				deck[b].value = card;
				picked[card] = true;
			}
		}while (deck[b].value == -1);
	}
}


// Deal cards
void Player::deal(CardDeck deck){
	
	int a = 0;

	for (a; a <= 1; a++){
		
		hand[a] = (deck.deck[deck.numCard]);
		deck.numCard++; // numCard keeps track of which card form the deck is being drawn
	}
}


// Hit or stay?
bool Player::action(CardDeck deck){

	bool done = false;	
	int total;

	char hitOrStay;
	while(!done){
		for (int a=2; a <= 12; a++)
		{
			total = getTotal();
			if (total >= 21)
			{
				done = true;
				break;
			}

			cout << endl << "\n\tYou have " << total << " would you like to hit, or stay? (h/s) ";
			cin >> hitOrStay;
			if (hitOrStay == 'h')
			{
				hand[a] = deck.deck[deck.numCard];
				deck.numCard++;
				displayCards();
			}
			else if (hitOrStay == 's')
			{
				done = true;
				break;
			}
			else
			{
				a--;
				cout << hitOrStay <<"\n\tInvalid Input" << endl;
			}
		}
	}

	return done;

}


// Dealer hit or stay?
bool Player::dealerAction(CardDeck deck){

	int total = getTotal();

	if ((total <= 21) && (hand[12].value == -1)){

		if ((total == 21)){
			

		}
		else{
			for (int a = 2; a <= 13; a++){

				total = getTotal();

				if (total <= 16){

					hand[a] = deck.deck[deck.numCard];
					deck.numCard++;
				}

				else{
					
				}
			}
		}
	}
	

	displayDealer(false);
}


// Display hand
void Player::displayCards()
{	
	cout << "\nYour Hand: " << endl;
	for (int a = 0; a <= 12; a++)
	{
		if (hand[a].value != -1)
			cardValue(hand[a].value);
		
	}
}



// Show dealer's hand
void Player::displayDealer(bool done){

	if(done){

		cout << "\nDealer's Hand: " << endl;
		for (int a = 0; a <= 12; a++){
		
			if (hand[a].value != -1)
				cardValue(hand[a].value);
		}
		cout << endl;
	}

	else{

		cout << "\nDealer's Hand: " << endl;
		cardValue(hand[0].value);
	}
	cout << endl;
	
}


// Display actual card
void CardGame::cardValue(int card){
	
	switch (card/4){
	
		case 0:
			cout << "Ace";
			break;
		case 10:
			cout << "Jack";
			break;
		case 11:
			cout << "Queen";
			break;
		case 12:
			cout << "King";
			break;
		default:
			cout << ((card/4));
	}

	cout << " of ";

	switch (card%4){
	
		case 0:
			cout << "Clubs"<<endl;
			break;
		case 1:
			cout << "Spades"<<endl;
			break;
		case 2:
			cout << "Hearts"<<endl;
			break;
		case 3:
			cout << "Diamonds"<<endl;
			break;
	}
}



// Get the total for the hand
int Player::getTotal(){

	int total = 0;

	for (int a = 0; a <= 12; a++){

		// Player Total
		if (( (hand[a].value) / 4 ) >= 10){

			total += 10;
		}

		else if (hand[a].value != -1){

			total += ((hand[a].value / 4));

			if((hand[a].value / 4) == 0)
				total += 1;
		}
		
		
	}

	for (int b = 0; b <= 12; b++){

		if ((hand[b].value/4) == 0){

			if (total < 12){

				total += 10;
			}
		}
	

	}
	
	return total;

}


// Find out if the user beat the dealer, and dish out the winnings
void Player::win(Player dealer)
{
	score = 0;
	ties = 0;

	int total = getTotal();
	int dealerTotal = dealer.getTotal();

	cout << "\n\tThese are your cards, " << name << " :" << endl;
	displayCards();
	cout << "\n\tThese are the dealer's cards: " << endl;
	dealer.displayDealer(true);


	cout << endl;

	if ((total == 21) && (hand[2].value == -1))
	{
		if ((total==21) && (dealer.hand[2].value == -1))
		{
			cout << "\n\tYou both have a BlackJack!" << endl;
			dealer.ties++;
		}
		else
		{
			cout << "\n\tPlayer " << name << ", you have Blackjack!" << endl;
			score++;
			moneyEarned += bet;
		}
	}
	else if ((dealerTotal == 21) && (dealer.hand[2].value == -1)){

		cout << "\n\tDealer has a Blackjack!"<<endl;
		dealer.score++;
		moneyEarned -= bet;
	}

	else{

		if (total > 21){

			cout << "\n\tPlayer " << name << ", you busted - you lose!";
			moneyEarned -= bet;
		}

		else if (dealerTotal > 21){

			cout << "\n\tDealer busted - you win Player " << name << "!";
			score++;
			moneyEarned += bet;
		}

		else{

			cout <<endl << "\n\tYou have " <<total<<" and I have " << dealerTotal<<" so ";
			
			if (total > dealerTotal){

				cout << "\n\tPlayer " << name << ", you win!";
				score++;
				moneyEarned += bet;
			}
			
			else if (dealerTotal > total){

				cout << "\n\tPlayer " << name << ", you lose!";
				moneyEarned -= bet;
				dealer.score++;
			}
			
			else{
				cout << "\n\tWe have a tie!";
				dealer.ties++;
			}
		}
	}

}


void Player::displayWins(Player dealer){

		cout << "\n\t-------------------------"<<endl;
		cout << "\t" << name << ", you have won " << score << " times." << endl;
		cout << "\tThe dealer has won " << dealer.score << " times." << endl;
		cout << "\tYou have tied " << ties << " times." << endl;
		cout << "\t-------------------------" << endl;
}



void Player::scoreboard(){

	
		cout << endl << "-------------------------" << endl;
		cout << "\n\t" << name << ", you have won " << score << " times." << endl;
		cout << "\n\tYou have tied " << ties << " times." << endl;
		cout << "-------------------------" << endl;
}

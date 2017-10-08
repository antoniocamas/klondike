/*
 * main.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: antonio
 */

#include <iostream>
#include <vector>
//#include "Klondike.h"

//Delete. Just Tests
#include "Suit.h"
#include "Card.h"
#include "CardStack.h"
#include "Deck.h"

using namespace std;
using namespace card;

int main ()
{
	cout << "Clondike Project" << endl;

	//klondike::Klondike game;
	//game.startGame();

/////////////////////////////////
	Suit club("clubs", "black");
	Suit spade("spades", "black");
	Suit heart("hearts", "red");
	Suit diamon("diamons", "red");

	if (club.isSameColor(spade))
		cout << "Same Color" <<endl;

	if (heart == heart)
		cout << "Same Suit" <<endl;

////////////////////////////////////
	Card card1(1, club);
	Card card2(2, spade);
	Card card3(2, club);
	Card card4(4, heart);
	Card card5(5, spade);

	if (card1.isUpTurned())
		cout << card1.card2string() << endl;

	card1.turn();

	if (card1.isUpTurned())
		cout <<"Now the card upTurned: "<< card1.card2string() << endl;

	card1.turn();

	if(card1.isConsecutiveNumber(card3) and card1.isSameSuit(card3))
		cout << card3.card2string() << " can go on top of " << card1.card2string()
		     << " in a foundation" << endl;

	if(card5.isReverseConsecutiveNumber(card4) and !card5.isSameColor(card4))
			cout << card4.card2string() << " can be put on top of "
			     << card5.card2string() << " in a pile." << endl;

	///////////////////////////

	CardStack cardstack;

	if (cardstack.isEmpty())
		cout << "Empty cardStack" << endl;

	cardstack.putCardOnTop(card1);

	if (!cardstack.isEmpty())
			cout << "cardStack with cards." << endl;

	card2.turn();
	cardstack.putCardOnTop(card2);
	cardstack.putCardOnTop(card3);
	card4.turn();
	cardstack.putCardOnTop(card4);
	card2.turn();
	card4.turn();

	for (Card card : cardstack.getUpTurnedCards())
		cout << "Visible: " << card.card2string() << endl;

	card5.turn();
	vector<Card> auxCards {card3, card5};
	cardstack.putCardOnTop(auxCards);

	for (Card card : cardstack.getUpTurnedCards())
			cout << "After putting. Visible: " << card.card2string() << endl;

	Card card6 = cardstack.giveTopCardAway();
	cout << "Retrieved: " << card6.card2string() << endl;

	card6 = Card(6, diamon);

	cardstack.shuffle();

	for (Card card : cardstack.getUpTurnedCards())
				cout << "After getting. Visible: " << card.card2string() << endl;


	cout << cardstack.getNumberOfCards() << " Remaining" << endl;
	cardstack.giveTopCardAway(4);
	cout << cardstack.getNumberOfCards() << " Remaining" << endl;
	cardstack.giveTopCardAway(2);
	cout << cardstack.getNumberOfCards() << " Remaining" << endl;

	if (cardstack.isEmpty())
			cout << "Empty cardStack" << endl;

	////////////////////////////////

	{
	Deck deck;
	deck.shuffle();
	vector<Card> allCards;

	allCards = deck.giveTopCardAway(deck.getNumberOfCards());
	for (auto card : allCards)
		cout << card.card2string() << endl;
	deck = Deck();

	}



	return 0;
}



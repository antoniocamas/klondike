/*
 * main.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: antonio
 */

#include "Klondike.h"

//Delete. Just Tests
#include <iostream>
#include <vector>

#include "controller/movement/MovementController.h"
#include "controller/movement/Pile2PileController.h"
#include "Pile.h"
#include "Foundation.h"
#include "Card.h"
#include "CardIterator.h"
#include "CardStack.h"
#include "Deck.h"
#include "model/card/CardStackShowcase.h"
#include "Suit.h"
#include "Table.h"
#include "view/ViewConsoleLinux.h"

using namespace std;
using namespace card;

int main ()
{
	cout << "Clondike Project" << endl;

	Klondike game;
	game.play();

	return 0;
/////////////////////////////////
//	cout << "Testing Suit" << endl;
//
	const int nCards = 13;
//
	const map<int, string> frechNicknames = {
			{1, "A"}, {11, "J"}, {12, "Q"}, {13, "K"}
	};

	Suit club("clubs", "black", nCards);
	Suit spade("spades", "black", nCards);
	Suit heart("hearts", "red", nCards);
	Suit diamon("diamons", "red", nCards);
//
//	{
//		cout << "\t" << "club nickname for 1 is " << club.getNickName(1) << endl;
//		cout << "\t" << "club nickname for 13 is " << club.getNickName(13) << endl;
//
//		if (club.isLastNumberOfSuit(13))
//			cout << "\t" << "13 Last number of clubs" <<endl;
//
//		if (club.isSameColor(spade))
//			cout << "\t" << "Same Color" <<endl;
//
//		if (heart == heart)
//			cout << "\t" << "Same Suit" <<endl;
//	}

////////////////////////////////////
//	cout << "Testing Card" << endl;
//
	Card card1(1, club);
//	cout << "\t" <<"Print the Nickname: "<< card1.card2string() << endl;
//
	Card card2(2, spade);
	Card card3(2, club);
	Card card4(4, heart);
	Card card5(5, spade);
//
//	{
//		if (card1.isUpTurned())
//			cout << "\t" << card1.card2string() << endl;
//
//		card1.turn();
//
//		if (card1.isUpTurned()){
//			cout << "\t" << "Before Card to string. club nickname for 1 is " << club.getNickName(1) << endl;
//			cout << "\t" <<"Now the card upTurned: "<< card1.card2string() << endl;
//		}
//
//		card1.turn();
//
//		if(card1.isConsecutiveNumber(card3) and card1.isSameSuit(card3))
//			cout << "\t" << card3.card2string() << " can go on top of " << card1.card2string()
//			<< " in a foundation" << endl;
//
//		if(card5.isReverseConsecutiveNumber(card4) and !card5.isSameColor(card4))
//			cout << "\t" << card4.card2string() << " can be put on top of "
//			<< card5.card2string() << " in a pile." << endl;
//
//		Card card6 = card1;
//
//		if (card1 == card6)
//			cout << "\t" << card1.card2string() << " and " << card6.card2string() << " are equal\n";
//		if (card1 != card2)
//		cout << "\t" << card1.card2string() << " and " << card2.card2string() << " are different\n";
//
//	}
//	///////////////////////////
//	cout << "Testing CardStack" << endl;
//	{
//		CardStack cardstack;
//
//		if (cardstack.isEmpty())
//			cout << "\t" << "Empty cardStack" << endl;
//
//		cardstack.putCardOnTop(card1);
//
//		if (!cardstack.isEmpty())
//			cout << "\t" << "cardStack with cards." << endl;
//
//		card2.turn();
//		cardstack.putCardOnTop(card2);
//		cardstack.putCardOnTop(card3);
//		card4.turn();
//		cardstack.putCardOnTop(card4);
//		card2.turn();
//		card4.turn();
//
//		for (Card card : cardstack.getUpTurnedCards())
//			cout << "\t" << "Visible: " << card.card2string() << endl;
//
//		card5.turn();
//		vector<Card> auxCards {card3, card5};
//		cardstack.putCardOnTop(auxCards);
//
//		for (Card card : cardstack.getUpTurnedCards())
//			cout << "\t" << "After putting. Visible: " << card.card2string() << endl;
//
//		Card card6 = cardstack.giveTopCardAway();
//		cout << "\t" << "Retrieved: " << card6.card2string() << endl;
//
//		card6 = Card(6, diamon);
//
//		cardstack.shuffle();
//
//		for (Card card : cardstack.getUpTurnedCards())
//			cout << "\t" << "After getting. Visible: " << card.card2string() << endl;
//
//
//		cout << cardstack.getNumberOfCards() << " Remaining" << endl;
//		cardstack.giveTopCardAway(4);
//		cout << cardstack.getNumberOfCards() << " Remaining" << endl;
//		cardstack.giveTopCardAway(2);
//		cout << cardstack.getNumberOfCards() << " Remaining" << endl;
//
//		if (cardstack.isEmpty())
//			cout << "\t" << "Empty cardStack" << endl;
//	}
//	////////////////////////////////
//	cout << "Testing Deck" << endl;
//
//	{
//		cout << "\t" << "French Deck" << endl;
//		Deck deck;
//		deck.shuffle();
//		vector<Card> allCards;
//
//		allCards = deck.giveTopCardAway(deck.getNumberOfCards());
//		for (auto card : allCards)
//			cout << card.card2string() << endl;
//
//	}
//	{
//		cout << "\t" << "Spanish Deck" << endl;
//		const map<string, string> othersuits = {{"bastos", "verde"},
//				{"copas", "rojo"}, {"oros", "amarillo"}, {"espadas", "azul"}};
//		const map<int, string> spanishNicknames {};
//		Deck deck(3,othersuits, spanishNicknames);
//		vector<Card> allCards;
//
//		allCards = deck.giveTopCardAway(deck.getNumberOfCards());
//		for (auto card : allCards)
//			cout << "\t" << card.card2string() << endl;
//
//
//	}
//	{
//		cout << "Testing Pile" << endl;
//		Pile pile1;
//		card3.upTurn();
//		card4.upTurn();
//		card5.upTurn();
//		vector<Card> auxCards {card1, card2, card3, card4, card5};
//		pile1.putCardOnTop(auxCards);
//
//		vector<Card> returnedCards;
//
//		returnedCards = pile1.giveTopCardAway(Card(3, diamon));
//		if (returnedCards.empty())
//			cout << "\t" << "Card not found\n";
//
//		returnedCards = pile1.giveTopCardAway(card3);
//		if (!returnedCards.empty())
//			cout << "\t" << "Card found\n";
//
//		cout << "\t" << "Extracted Cards" << endl;
//		for (auto card : returnedCards)
//			cout << "\t" << card.card2string() << endl;
//
//		vector<Card> allCards;
//
//		cout << "\t" << "Remaining Cards" << endl;
//		allCards = pile1.giveTopCardAway(int(pile1.getNumberOfCards()));
//		for (auto card : allCards)
//			cout << "\t" << card.card2string() << endl;
//
//		Card card6 = Card(3,diamon);
//		if (pile1.isPuttingDownPossible(card6))
//			cout << "\t" << "It is possible to put a " << card6.card2string()
//			     << " on top of pile1 because it is empty" << endl;
//
//		Card card7(13, club);
//		if (pile1.isPuttingDownPossible(card7))
//			cout << "\t" << "It is possible to put a " << card7.card2string()
//			     << " on top of pile1 because it is empty and this is the last card of the suite\n";
//
//		vector<Card> auxCards2 {card1, card5};
//
////		pile1.putCardOnTop(auxCards2);
////		cout << "\t" << pile1.cards2string() << endl;
////		if (pile1.isPuttingDownPossible(card4))
////			cout << "\t" << "It is possible to put a " << card4.card2string()
////			<< " on top of pile1" << endl;
////
////		if (!pile1.isPuttingDownPossible(card3))
////			cout << "\t" << "It is NOT possible to put a " << card3.card2string()
////			<< " on top of pile1\n";
//	}
//
//	cout << "Testing Foundation" << endl;
//
//	Card cardClub1(1, club);
//	Card cardClub2(2, club);
//	Card cardClub3(3, club);
//	Card cardClub4(4, club);
//	Card cardClub5(5, club);
//	Card cardClub6(6, club);
//	Card cardClub7(7, club);
//	Card cardClub8(8, club);
//	Card cardClub9(9, club);
//	Card cardClub10(10, club);
//	Card cardClub11(11, club);
//	Card cardClub12(12, club);
//	Card cardClub13(13, club);
//
//	{
//		Foundation foundation1;
//
//		if(!foundation1.isComplete())
//			cout << "\t" << "Foundation1 is not complete" << endl;
//
//		if(foundation1.isPuttingDownPossible(card1))
//			cout << "\t" << "It is possible to put " << card1.card2string() << " because it is the first card of the suite" << endl;
//
//		if(!foundation1.isPuttingDownPossible(card2))
//			cout << "\t" << "It is not possible to put " << card2.card2string() << " because it is empty" << endl;
//
//		foundation1.putCardOnTop(card1);
//
//		vector<Card> clubCards {cardClub2, cardClub3, cardClub4, cardClub5,
//			cardClub6, cardClub7, cardClub8, cardClub9, cardClub10, cardClub11,
//			cardClub12};
//
//		foundation1.putCardOnTop(clubCards);
//
////		cout << "\t" << foundation1.cards2string() << endl;
//
//		if(!foundation1.isComplete())
//			cout << "\t" << "Foundation1 is not complete" << endl;
//
//		if(!foundation1.isPuttingDownPossible(cardClub12))
//			cout << "\t" << "It is not possible to put that card again" << endl;
//
//		Card cardSpade13(13, spade);
//		if(!foundation1.isPuttingDownPossible(cardSpade13))
//			cout << "\t" << "It is not possible to put a card of a differente suit" << endl;
//
//		if(foundation1.isPuttingDownPossible(cardClub13))
//			foundation1.putCardOnTop(cardClub13);
//
//		if(foundation1.isComplete())
//			cout << "\t" << "Foundation1 is complete!!!" << endl;
//
//	}
//
//	cout << "Testing Score" << endl;
//	{
//		Score score;
//
//		cout << "\t" << "Score: " << score.getPoints() << endl;
//
//		score.addPoints(10);
//
//		cout << "\t" << "Score: " << score.getPoints() << endl;
//
//		score.addPoints(-9);
//
//		cout << "\t" << "Score: " << score.getPoints() << endl;
//
//		score.addPoints(-10);
//
//		cout << "\t" << "Score: " << score.getPoints() << endl;
//
//	}
//
//	cout << "Testing CardIterator" << endl;
//	{
//		vector<Card> clubCards {cardClub1, cardClub2, cardClub3, cardClub4, cardClub5,
//					cardClub6, cardClub7, cardClub8, cardClub9, cardClub10, cardClub11,
//					cardClub12, cardClub13};
//
//		CardIterator from(&clubCards.front());
//		CardIterator until(&clubCards.back()+1);
//
//		cout << "\t" << "First element of vector<Card> is: "
//				<< clubCards.front().card2string()
//				<< " with address: "<< &clubCards.front() << endl;
//		cout << "\t" << "Last element of vector<Card> is: "
//				<< clubCards.back().card2string()
//				<< " with address: "<< &clubCards.back() << endl;
//
//		for (CardIterator it=from; it!=until; ++it)
//		    cout << "\t" << (*it).card2string() << " address: " << &(*it) << endl;
//
//		cout << "\t" << "The address pointed by from is:" << &(*from) << endl;
//		cout << "\t" << "The address pointed by until is:" << &(*until) << endl;
//
//	}
//
//	cout << "Testing CardStackRepresenter" << endl;
//	{
//		vector<Card> clubCards {cardClub1, cardClub2, cardClub3, cardClub4, cardClub5,
//			cardClub6, cardClub7, cardClub8, cardClub9, cardClub10, cardClub11,
//			cardClub12, cardClub13};
//
//		CardStack mystack;
//		mystack.putCardOnTop(clubCards);
//
//		CardStackView cardRepresenter = mystack.getCardsRepresenter();
//
//		cout << "\t" << "ClubCards: ";
//		for (auto cardRepresentation : cardRepresenter.allCard2String())
//			cout << cardRepresentation << " ";
//		cout << endl;
//
//		cout << "\t" << "Last 2 ClubCards: ";
//		for (auto cardRepresentation : cardRepresenter.topCard2String(3))
//			cout << cardRepresentation << " ";
//		cout << endl;
//
//		cout << "\t" << "Top ClubCards: " << cardRepresenter.topCard2String() << endl;
//	}
//
//	cout << "Testing Tableau" << endl;
//
//	{
//		Table tableau;
//		CardStackView cardRepresenter;
//		cout << "\t" << "Remainder: ";
//
//		cardRepresenter = tableau.getRemainderRepresenter();
//
//		for (auto card : cardRepresenter.allCard2String())
//			cout << "\t" << card;
//		cout << endl;
//
//
//		for (int i=0; i < 7; ++i){
//			cout << "\t" << "P[" << i+1 << "]: ";
//			cardRepresenter = tableau.getPileRepresenter(i);
//			for (auto card : cardRepresenter.allCard2String()){
//				cout << "["<< card;
//			}
//			cout <<"]"<< endl;
//		}
//
//
//	}
//
////	cout << "Testing UInterface" << endl;
////
////	{
////		Tableau tableau;
////		UInterface uinterface;
////
////		uinterface.showTableau(tableau);
////
////	}
//
//	cout << "Testing Movement" << endl;
//
//	{
////		Pile pile1;
////		Foundation foundation1;
////
////		vector<Card> clubCards {cardClub1, cardClub2, cardClub3, cardClub4, cardClub5,
////			cardClub6, cardClub7, cardClub8, cardClub9, cardClub10, cardClub11,
////			cardClub12};
////
////		foundation1.putCardOnTop(clubCards);
////
////		vector<Card> otherCards {card1, card2, cardClub12};
////		pile1.putCardOnTop(otherCards);
////
//		Card card2move = cardClub1;
////		Movement movement("pile", 1, "foundation", 3, card2move);
////
////		Tableau tableau;
////
////		tableau.applyMovement(movement);
//
//	}
//
//	cout << "Testing CardStack Polymorphism" << endl;
//
//	{
//		CardStack * stack;
//		Pile * pile1 = new Pile();
//		Pile pile2;
//		Foundation foundation1;
//
//		stack = pile1;
//		stack->isPuttingDownPossible(card1);
//
//		stack = &pile2;
//		stack->isPuttingDownPossible(card1);
//
//
//	}

	return 0;
}



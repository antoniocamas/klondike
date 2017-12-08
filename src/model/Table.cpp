#include "Table.h"
#include "GameDeck.h"
#include "TableMemento.h"

Table::Table(){
    this->deal();
}

void Table::deal()
{
    GameDeck deck;
    deck.shuffle();
    card::Card card;

    int numberOfPiles= piles.size();

    for (int pilesFull = 0; pilesFull < numberOfPiles; ++pilesFull) {
	for (int i=numberOfPiles-1 ; i > pilesFull-1 ; --i){
	    card = deck.giveTopCardAway();
	    if (i == pilesFull)
		card.upTurn();
	    this->piles[i].putCardOnTop(card);
	}
    }
    this->remainder.putCardOnTop(deck.giveTopCardAway(deck.getNumberOfCards()));
}

bool Table::areAllFoundationsComplete() const {
    for (unsigned int i = 0; i < this->foundations.size(); ++i){
	if(!this->foundations[i].isComplete())
	    return false;
    }

    return true;
}

TableMemento* Table::createMemento() {
    TableMemento * memento = new TableMemento();
    memento->setState(piles, foundations, remainder, waste);
    return memento;
}

void Table::setMemento(TableMemento* tableMemento) {
    remainder = tableMemento->getStateRemainder();
    waste = tableMemento->getStateWaste();
    piles = tableMemento->getStatePiles();
    foundations = tableMemento->getStateFoundation();
}

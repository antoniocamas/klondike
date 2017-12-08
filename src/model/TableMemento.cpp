#include "TableMemento.h"

void TableMemento::setState(array<Pile,7> p, array<Foundation,4> f,
			    GameCardStack r, GameCardStack w) {
    this->piles = p;
    this->foundations = f;
    this->remainder = r;
    this->waste = w;
}

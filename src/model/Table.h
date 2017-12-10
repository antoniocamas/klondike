#ifndef TABLE_H_
#define TABLE_H_

#include <vector>
#include <array>
#include <string>

#include "CardStackShowcase.h"
#include "Pile.h"
#include "Foundation.h"
#include "GameCardStack.h"

class TableMemento;
using namespace std;

class Table {
private:
    array<Pile, 7> piles;
    array<Foundation,4> foundations;
    GameCardStack remainder;
    GameCardStack waste;

    void deal();

public:
    Table();
    virtual ~Table(){};

    bool areAllFoundationsComplete() const;
    inline int getNumberOfPiles() const {return piles.size();}
    inline int getNumberOfFundations() const {return foundations.size();}
    CardStackShowcase getRemainderRepresenter() const {return this->remainder.getCardsRepresenter();}
    CardStackShowcase getWasterRepresenter() const {return this->waste.getCardsRepresenter();}
    CardStackShowcase getFoundationRepresenter(int foundationNumber) const {return this->foundations.at(foundationNumber).getCardsRepresenter();}
    CardStackShowcase getPileRepresenter(int pileNumber) const {return this->piles.at(pileNumber).getCardsRepresenter();}

    GameCardStack* getRemainder(){return &this->remainder;}
    GameCardStack* getWaste(){return &this->waste;}
    Pile* getPile(int pileNumber){return &this->piles[pileNumber];}
    Foundation* getFoundation(int foundationNumber){return &this->foundations[foundationNumber];}

    TableMemento* createMemento();
    void setMemento(TableMemento*);
};


#endif /* TABLE_H_ */

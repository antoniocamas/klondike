#ifndef TABLEMEMENTO_H_
#define TABLEMEMENTO_H_

#include <vector>
#include <string>
#include <array>

#include "Pile.h"
#include "Foundation.h"
#include "GameCardStack.h"

using namespace std;

class TableMemento {
private:
    array<Pile,7> piles;
    array<Foundation,4> foundations;
    GameCardStack remainder;
    GameCardStack waste;

public:
    virtual ~TableMemento(){};

private:
    friend class Table;
    friend class TableMarshaller;
    TableMemento(){};

    void setState(array<Pile,7> p, array<Foundation,4> f, GameCardStack r, GameCardStack w);
    array<Pile,7> getStatePiles(){return piles;};
    array<Foundation,4> getStateFoundation(){return foundations;};
    GameCardStack getStateRemainder(){return remainder;};
    GameCardStack getStateWaste(){return waste;};
};


#endif /* TABLEMEMENTO_H_ */

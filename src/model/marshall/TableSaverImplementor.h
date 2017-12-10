#ifndef TABLESAVERIMPLEMENTOR_H_
#define TABLESAVERIMPLEMENTOR_H_

#include <string>
#include <array>

#include "Pile.h"
#include "Foundation.h"
#include "GameCardStack.h"

using namespace std;

class TableSaverImplementor {
protected:
    string savingName;
public:
    TableSaverImplementor(string name): savingName(name){};
    virtual ~TableSaverImplementor(){};

    virtual void serializePiles(array<Pile,7>) = 0;
    virtual void serializeFoundations(array<Foundation,4>) = 0;
    virtual void serializeRemainder(GameCardStack) = 0;
    virtual void serializeWaste(GameCardStack) = 0;
};

#endif /* TABLESAVERIMPLEMENTOR_H_ */

#ifndef TABLELOADERIMPLEMENTOR_H_
#define TABLELOADERIMPLEMENTOR_H_

#include <string>
#include <array>
#include <vector>
#include "Pile.h"
#include "Foundation.h"
#include "GameCardStack.h"

using namespace std;

class TableLoaderImplementor {
protected:
    string savingName;
public:
    TableLoaderImplementor(){};
    virtual ~TableLoaderImplementor(){};

    virtual void setSavingName(string n){savingName = n;};
    virtual vector<string> getSavedGames() = 0;
    virtual array<Pile,7> deserializePiles() = 0;
    virtual array<Foundation,4> deserializeFoundations() = 0;
    virtual GameCardStack deserializeGameCardStack(string) = 0;
};

#endif /* TABLELOADERIMPLEMENTOR_H_ */

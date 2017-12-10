#ifndef TABLESAVERFILESYSTEM_H_
#define TABLESAVERFILESYSTEM_H_

#include <string>
#include <array>
#include <fstream>
#include "TableSaverImplementor.h"
#include "Card.h"

using namespace std;

class TableSaverFileSystem: public TableSaverImplementor {
private:
    std::array<const string, 4> delimiters;
    std::ofstream saveFile;
public:
    TableSaverFileSystem(string name);
    virtual ~TableSaverFileSystem();

    void serializePiles(array<Pile,7> p);
    void serializeFoundations(array<Foundation,4>);
    void serializeRemainder(GameCardStack);
    void serializeWaste(const GameCardStack);

private:
    void serializeCardStack(const GameCardStack*);
    void serializeCard(const card::Card*);
};

#endif /* TABLESAVERFILESYSTEM_H_ */

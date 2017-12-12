#ifndef TABLELOADERFILESYSTEM_H_
#define TABLELOADERFILESYSTEM_H_

#include <string>
#include <array>
#include <fstream>
#include "TableLoaderImplementor.h"
#include "Card.h"
#include "Pile.h"
#include "Foundation.h"
#include "GameCardStack.h"

using namespace std;

class TableLoaderFileSystem: public TableLoaderImplementor {
private:
    std::array<const string, 4> delimiters;
    std::ifstream savingFile;
    std::string directory;
    std::string extension;
    
public:
    TableLoaderFileSystem();
    virtual ~TableLoaderFileSystem();

    vector<string> getSavedGames();
    array<Pile,7> deserializePiles();
    array<Foundation,4> deserializeFoundations();
    GameCardStack deserializeGameCardStack(string);
    

private:
    vector<card::Card> deserializeCardStack(string);
    Card deserializeCard(string);
    array<string,2> findElement(string);
    array<string,2> findCard(string);
};

#endif /* TABLELOADERFILESYSTEM_H_ */

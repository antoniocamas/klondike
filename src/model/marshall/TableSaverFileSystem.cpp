#include "TableSaverFileSystem.h"
#include "Configurator.h"
using namespace std;

TableSaverFileSystem::TableSaverFileSystem(string name):
    TableSaverImplementor(name), delimiters({":", " ", ",", "\n"}) {

    string dir = Configurator::getInstance()->getSavingsDirectory();
    saveFile.open(dir + "/" + savingName + ".sav");
};

TableSaverFileSystem::~TableSaverFileSystem() {
    saveFile.close();
}

void TableSaverFileSystem::serializePiles(array<Pile,7> piles) {
    for(int i=0; i < piles.size(); i++) {
	saveFile << "pile" << delimiters[1] << to_string(i) << delimiters[0];
	serializeCardStack(&piles[i]);
    }
};

void TableSaverFileSystem::serializeFoundations(array<Foundation,4> foundations) {
    for(int i=0; i < foundations.size(); i++) {
	saveFile << "foundation" << delimiters[1] << to_string(i) << delimiters[0];
	serializeCardStack(&foundations[i]);
    }
}

void TableSaverFileSystem::serializeRemainder(const GameCardStack r) {
    saveFile << "remainder" << delimiters[0];
    serializeCardStack(&r);
}

void TableSaverFileSystem::serializeWaste(const GameCardStack w) {
    saveFile << "waste" << delimiters[0];
    serializeCardStack(&w);
}

void TableSaverFileSystem::serializeCardStack(const GameCardStack* stack) {
    for (auto card : stack->getCardsRepresenter().all())
	serializeCard(card);
    saveFile << delimiters[3];
}

void TableSaverFileSystem::serializeCard(const card::Card* card){
    saveFile << card->getNumber() << delimiters[1] << card->getSuitName()
	     << delimiters[1] << to_string(card->isUpTurned()) << delimiters[2];
}

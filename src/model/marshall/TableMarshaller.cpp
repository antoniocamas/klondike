#include "TableMarshaller.h"
#include "TableSaverFileSystem.h"
#include "TableLoaderFileSystem.h"

using namespace std;

TableMarshaller::TableMarshaller(): memento(nullptr) {
}

TableMarshaller::~TableMarshaller() {
    if (memento != nullptr)
    delete memento;
}

void TableMarshaller::setSavingName(string name) {
    savingName = name;
};

void TableMarshaller::setTableMemento(TableMemento* tableMemento) {
    memento = tableMemento;
}

void TableMarshaller::save() {
    saverImp = make_shared<TableSaverFileSystem>(savingName);

    saverImp->serializePiles(memento->getStatePiles());
    saverImp->serializeFoundations(memento->getStateFoundation());
    saverImp->serializeRemainder(memento->getStateRemainder());
    saverImp->serializeWaste(memento->getStateWaste());
}

vector<string> TableMarshaller::getSavedGames() {
    loaderImp = make_shared<TableLoaderFileSystem>();
    return loaderImp->getSavedGames();
}

TableMemento* TableMarshaller::load() {
    TableMemento * loadedMemento = new TableMemento();
    loaderImp->setSavingName(savingName);
    loadedMemento->setState(loaderImp->deserializePiles(),
			    loaderImp->deserializeFoundations(),
			    loaderImp->deserializeGameCardStack("remainder"),
			    loaderImp->deserializeGameCardStack("waste"));
    return loadedMemento;
}

#include "TableMarshaller.h"
#include "TableSaverFileSystem.h"
#include "TableLoaderFileSystem.h"

using namespace std;

TableMarshaller::TableMarshaller(string name): savingName(name), memento(nullptr) {
}

TableMarshaller::~TableMarshaller() {
    if (memento != nullptr)
    delete memento;
}

void TableMarshaller::setTableMemento(TableMemento* tableMemento) {
    memento = tableMemento;
};
void TableMarshaller::save() {
    saverImp = make_shared<TableSaverFileSystem>(savingName);

    saverImp->serializePiles(memento->getStatePiles());
    saverImp->serializeFoundations(memento->getStateFoundation());
    saverImp->serializeRemainder(memento->getStateRemainder());
    saverImp->serializeWaste(memento->getStateWaste());
}

TableMemento* TableMarshaller::load() {
    loaderImp = make_shared<TableLoaderFileSystem>(savingName);
    TableMemento * loadedMemento = new TableMemento();
    
    loadedMemento->setState(loaderImp->deserializePiles(),
			    loaderImp->deserializeFoundations(),
			    loaderImp->deserializeGameCardStack("remainder"),
			    loaderImp->deserializeGameCardStack("waste"));
    return loadedMemento;
}

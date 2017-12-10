#include "LoadController.h"
#include "TableMarshaller.h"
#include "TableMemento.h"

LoadController::LoadController(
    Table * t, std::shared_ptr<View> v,  TableRegistry* tr):
    Controller(t, v), tableRegistry(tr) {
};

void LoadController::control() {
    TableMarshaller tableMarshaller("SavedGame");
    TableMemento * memento = tableMarshaller.load();
    table->setMemento(memento);
    tableRegistry->clear();
    tableRegistry->updateHistory(table);
    delete memento;
}

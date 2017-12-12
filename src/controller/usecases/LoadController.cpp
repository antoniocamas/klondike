#include "LoadController.h"
#include "TableMemento.h"

LoadController::LoadController(
    Table * t, std::shared_ptr<View> v,  TableRegistry* tr):
    Controller(t, v), tableRegistry(tr) {
    tableMarshaller = TableMarshaller();
};

void LoadController::control() {
    this->view->accept(this);
}

vector<string> LoadController::getSavedGames() {
    return tableMarshaller.getSavedGames();
}

void LoadController::visit(string savingName) {
    tableMarshaller.setSavingName(savingName);
    TableMemento * memento = tableMarshaller.load();
    
    table->setMemento(memento);
    tableRegistry->clear();
    tableRegistry->updateHistory(table);
    delete memento;
}

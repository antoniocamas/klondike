#include "SaveController.h"

using namespace std;

SaveController::SaveController(Table * t, std::shared_ptr<View> v):
    Controller(t, v) {
    tableMarshaller = TableMarshaller();
};

void SaveController::control() {
    this->view->accept(this);
}

void SaveController::visit(string savingName) {
    tableMarshaller.setSavingName(savingName);
    tableMarshaller.setTableMemento(table->createMemento());
    tableMarshaller.save();
}

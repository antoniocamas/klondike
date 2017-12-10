
#include "SaveController.h"
#include "TableMarshaller.h"

SaveController::SaveController(Table * t, std::shared_ptr<View> v):
    Controller(t, v) {
};

void SaveController::control() {
    TableMarshaller tableMarshaller("SavedGame");
    tableMarshaller.setTableMemento(table->createMemento());
    tableMarshaller.save();
}

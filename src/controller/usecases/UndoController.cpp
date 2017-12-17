#include "UndoController.h"

UndoController::UndoController(
    std::shared_ptr<Table> t, std::shared_ptr<View> v, std::shared_ptr<TableRegistry> tr):
    Controller(t, v), tableRegistry(tr) {
};

void UndoController::control() {
    if (tableRegistry->isUndoPossible()) {
	table->setMemento(tableRegistry->undo());
    }
}

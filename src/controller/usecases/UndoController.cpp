
#include "UndoController.h"

UndoController::UndoController(Table * t, std::shared_ptr<View> v, TableRegistry* tr):
    Controller(t, v), tableRegistry(tr) {
};

void UndoController::control() {
    if (tableRegistry->isUndoPossible()) {
	table->setMemento(tableRegistry->undo());
    }
}

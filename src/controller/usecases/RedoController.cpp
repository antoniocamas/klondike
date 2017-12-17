#include "RedoController.h"

RedoController::RedoController(
    std::shared_ptr<Table> t, std::shared_ptr<View> v,
    std::shared_ptr<TableRegistry> tr): Controller(t, v), tableRegistry(tr) {
};

void RedoController::control() {
    if (tableRegistry->isRedoPossible()) {
	table->setMemento(tableRegistry->redo());
    }
}

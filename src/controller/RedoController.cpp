
#include "RedoController.h"

RedoController::RedoController(Table * t, std::shared_ptr<View> v, TableRegistry* tr):
    Controller(t, v), tableRegistry(tr) {
};

void RedoController::control() {
    if (tableRegistry->isRedoPossible()) {
	table->setMemento(tableRegistry->redo());
    }
}

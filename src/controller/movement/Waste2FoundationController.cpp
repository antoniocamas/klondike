
#include "Waste2FoundationController.h"

Waste2FoundationController::Waste2FoundationController(Table * table, int foundationNumber){
    this->destination = &(*table->getFoundation(foundationNumber));
    this->origin = table->getWaste();
}

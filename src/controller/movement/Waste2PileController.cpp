
#include "Waste2PileController.h"

Waste2PileController::Waste2PileController(Table * table, int pileNumber){
    this->destination = &(*table->getPile(pileNumber));
    this->origin = table->getWaste();
};

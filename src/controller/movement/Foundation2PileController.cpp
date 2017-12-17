#include "Foundation2PileController.h"

Foundation2PileController::Foundation2PileController(
    Table * table, int originFoundationNumber, int destinationPileNumber){

    this->origin = &(*table->getFoundation(originFoundationNumber));
    this->destination = &(*table->getPile(destinationPileNumber));
}

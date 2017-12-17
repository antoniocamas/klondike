#include "MovementClassifierBuilder.h"
#include "MovementClassfRemainder.h"
#include "MovementClassfWaste2Pile.h"
#include "MovementClassfWaste2Foundation.h"
#include "MovementClassfPile2Foundation.h"
#include "MovementClassfPile2Pile.h"
#include "MovementClassfFoundation2Pile.h"

shared_ptr<MovementClassifier> MovementClassifierBuilder::getMovementClassifer(
    string origin, string destination) {

    shared_ptr<MovementClassifier> classifier = nullptr;
    
    shared_ptr<MovementClassfPile2Foundation> pile2Foundation =
	make_shared<MovementClassfPile2Foundation>(origin, destination);
    
    shared_ptr<MovementClassfPile2Pile> Pile2Pile =
	make_shared<MovementClassfPile2Pile>(origin, destination, pile2Foundation);
    
    shared_ptr<MovementClassfFoundation2Pile> foundation2Pile =
	make_shared<MovementClassfFoundation2Pile>(origin, destination, Pile2Pile);
    
    shared_ptr<MovementClassfWaste2Foundation> waste2foundation =
	make_shared<MovementClassfWaste2Foundation>(origin, destination, foundation2Pile);
    
    shared_ptr<MovementClassfWaste2Pile> waste2pile =
	make_shared<MovementClassfWaste2Pile>(origin, destination, waste2foundation);
    
    shared_ptr<MovementClassfRemainder> remainder =
	make_shared<MovementClassfRemainder>(origin, destination, waste2pile);

    classifier = remainder;
    return remainder;
}

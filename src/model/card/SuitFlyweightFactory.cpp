#include "SuitFlyweightFactory.h"

using namespace card;
using namespace std;


map<string, shared_ptr<Suit>> SuitFlyweightFactory::suitPool;

shared_ptr<Suit> SuitFlyweightFactory::getSuit(string name, string color, int numberOfCardsperSuit) {

    map<string, shared_ptr<Suit>>::iterator it = suitPool.find(name);
    if (it == suitPool.end()) {
        suitPool[name] = make_shared<Suit>(name, color, numberOfCardsperSuit);
    }
    return suitPool[name];
}

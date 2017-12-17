#include "SuitFlyweightFactory.h"

using namespace card;
using namespace std;

map<string, shared_ptr<Suit>> SuitFlyweightFactory::suitPool;

SuitFlyweightFactory::SuitFlyweightFactory() {
    suitPool["null"] = make_shared<Suit>();
}

shared_ptr<Suit> SuitFlyweightFactory::getSuit(
    string name, string color, int numberOfCardsperSuit) {

    if (!isSuitCreated(name)) {
	suitPool[name] = make_shared<Suit>(name, color, numberOfCardsperSuit);
    }
    return suitPool[name];
}

shared_ptr<Suit> SuitFlyweightFactory::getSuitIfExists(string name) {
    return !isSuitCreated(name) ? suitPool["null"] : suitPool[name];
}

bool SuitFlyweightFactory::isSuitCreated(string name) {
    map<string, shared_ptr<Suit>>::iterator it = suitPool.find(name);
    return it != suitPool.end();
}

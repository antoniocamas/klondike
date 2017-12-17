#ifndef SUITFLYWEIGHTFACTORY_H_
#define SUITFLYWEIGHTFACTORY_H_

#include <map>
#include <string>
#include <memory>
#include "Suit.h"

using namespace std;

namespace card {

class SuitFlyweightFactory {
public:
    static map<string, std::shared_ptr<Suit>> suitPool;

    SuitFlyweightFactory();
    virtual ~SuitFlyweightFactory(){};

    shared_ptr<card::Suit> getSuitIfExists(string name);
    shared_ptr<card::Suit> getSuit(string name, string color, int numberOfCardsperSuit);

private:
    bool isSuitCreated(string);

};

} /* namespace card */

#endif /* SUITFLYWEIGHTFACTORY_H_ */

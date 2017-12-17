#ifndef DECK_H_
#define DECK_H_

#include <map>
#include <string>
#include "CardStack.h"

using namespace std;

namespace card {

class Deck: public CardStack {
public:
    Deck(const int nCards, const map<string, string> suitsDefinition);
    virtual ~Deck(){};
};

}
#endif /* DECK_H_ */

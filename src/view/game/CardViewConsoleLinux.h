#ifndef SRC_VIEW_CARDVIEWCONSOLELINUX_H_
#define SRC_VIEW_CARDVIEWCONSOLELINUX_H_

#include <string>
#include "Suit.h"
#include "Card.h"

using namespace card;

class CardViewConsoleLinux {
private:
    Card card;
public:
    CardViewConsoleLinux(){};
    CardViewConsoleLinux(Card card): card(card) {};
    virtual ~CardViewConsoleLinux(){};

    string getRepresentation(Card c);
    void createCardfromRepresentation(string repr);
    bool isCardCreated(){return !card.isEmpty();}
    Card getCard()const {return card;};

private:
    shared_ptr<Suit> getSuitfromRepresentation(string);
    string getSuitNamefromRepresentation(string) const;
    int getNumberfromRepresentation(string);

};

#endif /* SRC_VIEW_CARDVIEWCONSOLELINUX_H_ */

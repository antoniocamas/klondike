#ifndef SRC_VIEW_VIEWCARDCONSOLELINUX_H_
#define SRC_VIEW_VIEWCARDCONSOLELINUX_H_

#include <string>
#include "Suit.h"
#include "Card.h"

using namespace card;

class ViewCardConsoleLinux {
private:
    Card card;
public:
    ViewCardConsoleLinux(){};
    ViewCardConsoleLinux(Card card): card(card) {};
    virtual ~ViewCardConsoleLinux(){};

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

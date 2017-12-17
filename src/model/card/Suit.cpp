#include <string>
#include "Suit.h"

using namespace std;
using namespace card;

namespace card {

Suit::Suit():numberOfCardsperSuit(0), name(""), color(""){
};

Suit::Suit(string name, string color,
	   int numberOfCards) {
    this->name = name;
    this->color = color;
    this->numberOfCardsperSuit = numberOfCards;
}

Suit& Suit::operator =(Suit other) {
    this->name = other.name;
    this->color = other.color;
    this->numberOfCardsperSuit = other.numberOfCardsperSuit;
    return *this;
}

} /* namespace card */

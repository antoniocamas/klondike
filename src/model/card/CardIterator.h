/*
 * CardIterator.h
 *
 *  Created on: Oct 13, 2017
 *      Author: antonio
 */

#ifndef SRC_MODEL_CARD_CARDITERATOR_H_
#define SRC_MODEL_CARD_CARDITERATOR_H_

#include <iterator>

#include "Card.h"
namespace card {

class CardIterator : public std::iterator<std::input_iterator_tag, Card>{
Card* pointer;

public:
	CardIterator(Card* x) :pointer(x) {}
	//CardIterator(Card& x) :pointer(&x) {}
	CardIterator(const CardIterator& mit) : pointer(mit.pointer) {}
	CardIterator& operator++() {++pointer;return *this;}
	//CardIterator operator++(int) {CardIterator tmp(*this); operator++(); return tmp;}
	CardIterator& operator+(int number) {this->pointer = this->pointer + number; return *this;}
	Card& operator*() {return *pointer;}
	bool operator==(const CardIterator& other) const {return pointer==other.pointer;}
	bool operator!=(const CardIterator& other) const {return pointer!=other.pointer;}
	CardIterator();
	virtual ~CardIterator(){};
};

} /* namespace card */

#endif /* SRC_MODEL_CARD_CARDITERATOR_H_ */

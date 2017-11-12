/*
 * Configurator.cpp
 *
 *  Created on: Nov 4, 2017
 *      Author: antonio
 */


#include "Configurator.h"
#include "LinuxTerminalColor.h"

Configurator* Configurator::instance = nullptr;

Configurator::Configurator() {

	this->suitNumberOfCards = 13;
	this->suitModel = {
		{"Clubs", "black"}, {"Diamonds", "red"}, {"Spades", "black"}, {"Hearts", "red"}
	};
	this->suitRepresentationGuide =  {
		{"Clubs", {BLACK,string("C")}}, {"Hearts", {RED, string("H")}},
		{"Spades", {BLACK, string("S")}}, { "Diamonds", {RED, string("D")}}
};
	this->cardNicknames = {{1, "A"}, {11, "J"}, {12, "Q"}, {13, "K"}};
}



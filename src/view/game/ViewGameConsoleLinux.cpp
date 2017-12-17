#include <string>
#include <vector>
#include "CardStackShowcase.h"
#include "InputManagerTextMode.h"
#include "MovementDescriber.h"
#include "ViewCardConsoleLinux.h"
#include "ViewGameConsoleLinux.h"

using namespace std;
using namespace card;

void ViewGameConsoleLinux::showTable() {
    io.printHeader();

    io.printRemainder(table->getRemainderRepresenter().getNumberOfCardsInTheStack() > 0);
    io.printWaste(cards2String(table->getWasterRepresenter().top(1)));

    for (int i = 0; i < table->getNumberOfFundations(); ++i)
	io.printFoundation(cards2String(table->getFoundationRepresenter(i).top(1)), i+1);

    io.printNewLine();
    io.printSplitter();

    for (int i = 0; i < table->getNumberOfPiles(); ++i)
	io.printPile(cards2String(table->getPileRepresenter(i).all()), i+1);
}

void ViewGameConsoleLinux::showWinMessage() {
    showTable();
    io.printSplitter();
    io.printMessage("\tCongratulations, you have won Klondike!!!\n");
}

vector<string> ViewGameConsoleLinux::cards2String(vector<const Card*> cardsReferences){
    vector<string> cardRepresentation;
    ViewCardConsoleLinux viewcard;
    for (auto it = cardsReferences.begin(); it != cardsReferences.end(); ++it)
	cardRepresentation.push_back(viewcard.getRepresentation(*(*it)));

    return cardRepresentation;
}

MovementDescriber ViewGameConsoleLinux::getNextMovement() {

    io.printMenuMessage();
    io.printSplitter();
    string message = "\tEnter the ";

    InputManagerTextMode inputManager(this->table, this->tableElementRepresenter);
    do{
	io.printMessage(message + inputManager.getNextExpectedElement() + ": ");
	string input = io.getInput();

	if (input == "m") {
	    return MovementDescriber();
	}

	if (inputManager.isInputCorrect(input)){
	    inputManager.addNewInput(input);
	}
	else
	    io.printMessage("\tI coudn't understand what you mean \n");

    }while(!inputManager.isEnoughInput());

    return inputManager.getMovement();
}

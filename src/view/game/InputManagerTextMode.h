#ifndef SRC_VIEW_INPUTMANAGERTEXTMODE_H_
#define SRC_VIEW_INPUTMANAGERTEXTMODE_H_

#include <string>
#include <regex>
#include <map>
#include "Table.h"
#include "Card.h"
#include "MovementDescriber.h"

using namespace std;

class InputManagerTextMode {
    regex validCommandsRegex;
    MovementDescriber movement;
    map<string, string> inputDictionary;

public:
    InputManagerTextMode(Table* t, map<string, string>& r);
    virtual ~InputManagerTextMode(){};

    bool isInputCorrect(string data)const;
    bool isEnoughInput();
    void addNewInput(string data);
    string getNextExpectedElement() const;
    MovementDescriber getMovement(){return this->movement;}

private:
    void setOriginCard(string data);
    void setOrigin(string data);
    void setDestination(string data);

    void translateInput2Stack(string, string&, unsigned int&);
    card::Card translateInput2Card(string input);
};

#endif /* SRC_VIEW_INPUTMANAGERTEXTMODE_H_ */

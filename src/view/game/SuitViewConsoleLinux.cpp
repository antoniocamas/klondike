
#include <map>
#include <string>
#include "SuitViewConsoleLinux.h"

string SuitViewConsoleLinux::getColor(string suiteName) {
    return representationGuide[suiteName].at(0);
}

string SuitViewConsoleLinux::getShortName(string suiteName) {
    return representationGuide[suiteName].at(1);
}

string SuitViewConsoleLinux::getNickName(int number) const {

    std::map<int,string>::const_iterator iterator;

    iterator = this->cardNicknames.find(number);
    if (iterator != this->cardNicknames.end())
	return iterator->second;

    return to_string(number);
}

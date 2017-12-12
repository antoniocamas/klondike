
#include <map>
#include <string>
#include "ViewSuitConsoleLinux.h"

string ViewSuitConsoleLinux::getColor(string suiteName) {
    return representationGuide[suiteName].at(0);
}

string ViewSuitConsoleLinux::getShortName(string suiteName) {
    return representationGuide[suiteName].at(1);
}

string ViewSuitConsoleLinux::getNickName(int number) const {

    std::map<int,string>::const_iterator iterator;

    iterator = this->cardNicknames.find(number);
    if (iterator != this->cardNicknames.end())
	return iterator->second;

    return to_string(number);
}

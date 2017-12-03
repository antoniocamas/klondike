#ifndef SRC_VIEW_SUITVIEWCONSOLELINUX_H_
#define SRC_VIEW_SUITVIEWCONSOLELINUX_H_

#include <map>
#include <string>
#include <vector>
#include "Configurator.h"

using namespace std;

class SuitViewConsoleLinux {
private:
    map<string,vector<string>> representationGuide;
    map<int, string> cardNicknames;

public:
    SuitViewConsoleLinux():
	representationGuide(Configurator::getInstance()->getSuitRepresentationGuide()),
	cardNicknames(Configurator::getInstance()->getSuitNicknames()) {};
    virtual ~SuitViewConsoleLinux(){};

    string getColor(string suiteName);
    string getShortName(string suiteName);
    string getNickName(int number) const;
};

#endif /* SRC_VIEW_SUITVIEWCONSOLELINUX_H_ */

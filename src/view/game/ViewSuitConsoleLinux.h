#ifndef SRC_VIEW_VIEWSUITCONSOLELINUX_H_
#define SRC_VIEW_VIEWSUITCONSOLELINUX_H_

#include <map>
#include <string>
#include <vector>
#include "Configurator.h"

using namespace std;

class ViewSuitConsoleLinux {
private:
    map<string,vector<string>> representationGuide;
    map<int, string> cardNicknames;

public:
    ViewSuitConsoleLinux():
	representationGuide(Configurator::getInstance()->getSuitRepresentationGuide()),
	cardNicknames(Configurator::getInstance()->getSuitNicknames()) {};
    virtual ~ViewSuitConsoleLinux(){};

    string getColor(string suiteName);
    string getShortName(string suiteName);
    string getNickName(int number) const;
};

#endif /* SRC_VIEW_VIEWSUITCONSOLELINUX_H_ */

#ifndef SRC_IOCONSOLELINUX_H_
#define SRC_IOCONSOLELINUX_H_

#include <vector>
#include <string>
#include "LinuxTerminalColor.h"

using namespace std;

class IOConsoleLinux {
public:
    IOConsoleLinux(){};
    virtual ~IOConsoleLinux(){};

    void printHeader();
    void printMessage(string message);
    void printSplitter();
    void printNewLine();

    string getInput();
};

void clear_screen();

#endif /* SRC_IOCONSOLELINUX_H_ */

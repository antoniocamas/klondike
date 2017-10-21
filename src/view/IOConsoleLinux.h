/*
 * UIConsoleLinux.h
 *
 *  Created on: Oct 15, 2017
 *      Author: antonio
 */

#ifndef SRC_UICONSOLELINUX_H_
#define SRC_UICONSOLELINUX_H_

#include "LinuxTerminalColor.h"
#include <vector>
#include <string>

using namespace std;

const char backCardRepresentation = '@';
class IOConsoleLinux {
public:
	IOConsoleLinux();
	virtual ~IOConsoleLinux();

	string niceConsoleCard(string card);
	void printHeader();
	void printRemainder(bool cardLeft);
	void printWaste(vector<string> cardsRepresentation);
	void printFoundation(string cardsRepresentation, int foundationNumber);
	void printPile(vector<string> cardsRepresentation, int pileNumber);
	void printMessage(string message);
	void printSplitter();
	void printNewLine();

	string getInput();

private:
	void lowercase(string* message);

};

void clear_screen();
#endif /* SRC_UICONSOLELINUX_H_ */

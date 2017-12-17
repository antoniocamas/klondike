#include <algorithm>
#include "StringHandler.h"

void StringHandler::keepNlastChars(int numOfChars) {
	 target = target.substr(max(0, (int)target.length()-numOfChars),target.length());
}

void StringHandler::lowercase() {
	std::transform(target.begin(), target.end(), target.begin(), ::tolower);
}

void StringHandler::cutNlastChars(int numOfChars) {
	target = target.substr(0, max((int)target.length()-numOfChars, 0));
}

void StringHandler::uppercase() {
	std::transform(target.begin(), target.end(), target.begin(), ::toupper);
}

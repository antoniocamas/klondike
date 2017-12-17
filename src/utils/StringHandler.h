#ifndef STRINGHANDLER_H_
#define STRINGHANDLER_H_

#include <string>

using namespace std;

class StringHandler {
private:
	string target;

public:
	StringHandler(string t): target(t){};
	virtual ~StringHandler(){};

	string getString(){return target;};
	void cutNlastChars(int numOfChars);
	void keepNlastChars(int numOfChars);
	void lowercase();
	void uppercase();


};

#endif /* STRINGHANDLER_H_ */

/*
 * Configurator.h
 *
 *  Created on: Nov 4, 2017
 *      Author: antonio
 */

#ifndef SRC_CONFIGURATOR_H_
#define SRC_CONFIGURATOR_H_

#include <map>
#include <vector>
#include <string>

using namespace std;

class Configurator {
private:
	int suitNumberOfCards;
	map<string, string> suitModel;
	map<string,vector<string>> suitRepresentationGuide;
	map<int, string> cardNicknames;

	static Configurator* instance;
	Configurator();

public:
	static Configurator* getInstance(){
		if (Configurator::instance == nullptr)
			instance = new Configurator;
		return instance;
	};

	virtual ~Configurator(){};
	map<int, string> getSuitNicknames() const{return cardNicknames;};
	map<string,vector<string>> getSuitRepresentationGuide() const {return suitRepresentationGuide;};
	const int getSuitNumberOfCards() const {return suitNumberOfCards;}
	const map<string, string> getSuitModel(){return suitModel;}
};

#endif /* SRC_CONFIGURATOR_H_ */

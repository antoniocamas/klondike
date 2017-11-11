/*
 * Logic.h
 *
 *  Created on: Nov 9, 2017
 *      Author: antonio
 */

#ifndef SRC_CONTROLLER_LOGIC_H_
#define SRC_CONTROLLER_LOGIC_H_

#include <memory>
#include "Table.h"
#include "Controller.h"
#include "View.h"
#include "State.h"

class Logic {
private:
	State state;
	std::shared_ptr<View> view;
	Table table;

public:
	Logic(std::shared_ptr<View> v): state(State::START),view(v){view->setTable(&table);};
	virtual ~Logic(){};

	std::shared_ptr<Controller> getController();
	bool isTimeToExit(){ return (state == State::EXIT);}


};

#endif /* SRC_CONTROLLER_LOGIC_H_ */

/*
 * Logic.h
 *
 *  Created on: Nov 9, 2017
 *      Author: antonio
 */

#ifndef SRC_LOGIC_H_
#define SRC_LOGIC_H_

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
	Logic(std::shared_ptr<View> v): state(START),view(v){view->setTable(&table);};
	virtual ~Logic(){};

	std::shared_ptr<Controller> getController();
	bool isTimeToExit(){ return (state == EXIT);}


};

#endif /* SRC_LOGIC_H_ */

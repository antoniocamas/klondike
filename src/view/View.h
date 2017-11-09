/*
 * View.h
 *
 *  Created on: Nov 9, 2017
 *      Author: antonio
 */

#ifndef SRC_VIEW_VIEW_H_
#define SRC_VIEW_VIEW_H_

#include <memory>
#include "ActionController.h"

class View {
protected:
	Table * table;
public:
	View();
	virtual ~View();

	virtual void setTable(Table *t){table = t;};
	virtual void showTable() = 0;
	virtual void showWinMessage() = 0;
	virtual shared_ptr<ActionController> getAction() = 0;
};

#endif /* SRC_VIEW_VIEW_H_ */

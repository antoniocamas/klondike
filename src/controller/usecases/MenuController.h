#ifndef SRC_CONTROLLER_MENUCONTROLLER_H_
#define SRC_CONTROLLER_MENUCONTROLLER_H_

#include <map>
#include "State.h"
#include "Controller.h"
#include "OptionMenu.h"

class MenuController: public Controller {
private:
    State& state;
    std::map<const int, State> optionStateMap = {
	{1, State::NEWGAME}, {2, State::INGAME},
	{3, State::UNDO}, {4, State::REDO},
	{5, State::SAVE}, {6, State::LOAD},
	{0, State::EXIT}
    };

public:
    MenuController(std::shared_ptr<Table>, std::shared_ptr<View>, State&);
    virtual ~MenuController(){};
    void control();
    void visit(OptionMenu op);
};

#endif /* SRC_CONTROLLER_MENUCONTROLLER_H_ */


#include <memory>
#include "Klondike.h"
#include "Logic.h"
#include "ViewConsoleLinux.h"

void Klondike::play(){
    std::shared_ptr<ViewConsoleLinux> view = std::make_shared<ViewConsoleLinux>();
    Logic logic(view);
    std::shared_ptr<Controller> controller;

    do{
	controller = logic.getController();
	if (controller)
	    controller->control();
    }while(!logic.isTimeToExit());
}

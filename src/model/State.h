#ifndef SRC_STATE_CLASS_H_
#define SRC_STATE_CLASS_H_

enum class State {
    NEWGAME,
    INGAME,
    MENU,
    UNDO,
    REDO,
    SAVE,
    LOAD,
    FINISH,
    EXIT
};

#endif

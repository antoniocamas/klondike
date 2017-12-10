#ifndef SRC_OPTION_CLASS_H_
#define SRC_OPTION_CLASS_H_

#include <string>

using namespace std;

class Option final {
  public:
    static const Option NEWGAME;
    static const Option PLAY;
    static const Option UNDO;
    static const Option REDO;
    static const Option SAVE;
    static const Option LOAD;
    static const Option QUIT;

    int getValue(void) const;
    string const& getString(void) const;

  private:
    Option(int value, string str);

    int value;
    string name;


};

#endif

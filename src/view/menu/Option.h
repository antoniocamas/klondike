#ifndef SRC_OPTION_CLASS_H_
#define SRC_OPTION_CLASS_H_

#include <string>

using namespace std;

class Option final {
  public:
    static const Option QUIT;
    static const Option PLAY;
    static const Option NEWGAME;

    int getValue(void) const;
    string const& getString(void) const;

  private:
    Option(int value, string str);

    int value;
    string name;


};

#endif

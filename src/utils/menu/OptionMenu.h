#ifndef SRC_OPTIONMENU_CLASS_H_
#define SRC_OPTIONMENU_CLASS_H_

#include <string>

using namespace std;

class OptionMenu {
  private:
    int value;
    string name;
    
  public:
    OptionMenu(int value, string str);
    ~OptionMenu(){};
    
    int getValue(void) const;
    string const& getString(void) const;
};

#endif /* SRC_OPTIONMENU_CLASS_H_ */

#ifndef TABLEREGISTRY_H_
#define TABLEREGISTRY_H_

#include <vector>
#include <string>
#include "Table.h"
#include "TableMemento.h"

using namespace std;

class TableRegistry {
private:
    vector<TableMemento*> history;
    unsigned int historyMarker;

public:
    TableRegistry();
    virtual ~TableRegistry();

    void updateHistory(Table*);
    void clear();
    TableMemento * undo();
    TableMemento * redo();

    bool isUndoPossible();
    bool isRedoPossible();

private:
    void beheadHistory();
};


#endif /* TABLEREGISTRY_H_ */

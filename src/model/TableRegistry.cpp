#include "TableRegistry.h"

using namespace std;

TableRegistry::TableRegistry() {
    historyMarker = history.size();
}

TableRegistry::~TableRegistry() {
    for (auto it : history)
	delete it;
}

void TableRegistry::updateHistory(Table *table) {

    beheadHistory();
    history.push_back(table->createMemento());
    historyMarker = history.size()-1;
}

void TableRegistry::beheadHistory() {
    int range = history.size()-historyMarker-1;
    for (int i=0; i < range; i++){
	delete history.back();
	history.pop_back();
    }
}

bool TableRegistry::isUndoPossible() {
    return history.size() > 1 and historyMarker > 0;
}

bool TableRegistry::isRedoPossible() {
    return history.size()-historyMarker-1 > 0;
}

TableMemento * TableRegistry::undo() {
    historyMarker--;
    return history.at(historyMarker);
}

TableMemento * TableRegistry::redo() {
    historyMarker++;
    return history.at(historyMarker);
}

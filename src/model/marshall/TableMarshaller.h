#ifndef TABLEMARSHALLER_H_
#define TABLEMARSHALLER_H_

#include <memory>
#include <string>
#include "TableMemento.h"
#include "TableLoaderImplementor.h"
#include "TableSaverImplementor.h"

class TableMarshaller {
private:
    shared_ptr<TableSaverImplementor> saverImp;
    shared_ptr<TableLoaderImplementor> loaderImp;
    TableMemento * memento;
    string savingName;
public:
    TableMarshaller(string);
    virtual ~TableMarshaller();

    void setTableMemento(TableMemento*);
    void save();
    TableMemento* load();
};

#endif /* TABLEMARSHALLER_H_ */

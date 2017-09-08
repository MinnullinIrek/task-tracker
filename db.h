#ifndef DB_H
#define DB_H

#include <QtSql>
#include "element.h"

class DB
{
    QSqlDatabase sdb;
public:
    DB();
    void createTables();
    void showError();
    void updateTables(Element *element);
    void insertTables(Element *element);
    QList<Element *> selectTables();
};

#endif // DB_H

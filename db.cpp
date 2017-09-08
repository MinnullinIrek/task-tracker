#include "db.h"


#include <QDialog>

DB::DB()
{
    sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("db_name.sqlite");

    if (sdb.open()) {
        createTables();

        QSqlQuery query("SELECT country FROM artist");
        while (query.next()) {
            QString country = query.value(0).toString();
        }

    }
    else
    {
        showError();
    }

}

void DB::createTables()
{
    QSqlQuery queruCreate("Create if not exists tasks (id int PRIMARY KEY, start, end, task, performer, ready);");

    if(!queruCreate.exec()) {
        showError();
    }
}

void  DB::showError()
{
    QDialog *dialog = new QDialog;
    dialog->show();
}

void DB::updateTables(Element *element)
{

    QSqlQuery queruCreate(QString("update tasks set end = %1, task = %2, performer = %3, ready = %4 where id = %5").arg(element->end.text()).arg(element->taskText.toPlainText()).
            arg(element->performer.text()).arg(static_cast<int>(element->isReady.isChecked())).arg(element->primaryKey));

    if(!queruCreate.exec()) {
        showError();
    }
}

void DB::insertTables(Element *element)
{
    QSqlQuery queruCreate(QString("insert into tasks (id, start) values(%1, %2)").arg(element->primaryKey).arg(element->start.text()));

    if(!queruCreate.exec()) {
        showError();
    }
}


QList<Element*> DB::selectTables()
{
    QSqlQuery query("select * from tasks");

    QList<Element*> elems;


    while (query.next()) {
             int id= query.value(0).toInt();
             QString start = query.value(1).toString();
             QString end = query.value(2).toString();
             QString task = query.value(3).toString();
             QString performer = query.value(4).toString();
             bool ready = query.value(5).toBool();
             //do_something(country);
             Element * elem = new Element;

             elem->primaryKey = id;
             elem->performer.setText(performer);
             elem->taskText.setText(task);
             elem->isReady.setChecked(ready);

            elems.push_back(elem);
    }
    return elems;
}

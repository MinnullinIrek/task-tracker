
#include <QApplication>
#include "element.h"
#include "tasks.h"
#include "tabwidget.h"
#include "db.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Element w;

    //Tasks w;
    TabWidget w;
    w.show();

    DB db;

    return a.exec();
}

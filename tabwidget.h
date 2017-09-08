#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QTabWidget>
#include "db.h"

class Tasks;

class TabWidget : public QTabWidget
{
    Q_OBJECT
public:
    explicit TabWidget(QWidget *parent = nullptr);

    void init();

    DB db;
    Tasks* task1 ;
    Tasks* task2 ;

signals:

public slots:
    void createTask();
    void taskChanged();
};

#endif // TABWIDGET_H

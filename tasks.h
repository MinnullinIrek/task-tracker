#ifndef TASKS_H
#define TASKS_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QScrollArea>

class Element;

class Tasks : public QWidget
{
    Q_OBJECT
public:
    explicit Tasks(QWidget *parent = nullptr);

    void init();

    QPushButton add;
    QGridLayout layout;
    QScrollArea scrollArea;

    QVBoxLayout scrollLayout;
    QWidget scWidget;


    void addTask(Element *elem);
};

#endif // TASKS_H

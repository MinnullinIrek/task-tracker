#include <QScrollBar>

#include "tasks.h"


#include "element.h"

Tasks::Tasks(QWidget *parent) : QWidget(parent)
{
    init();
}

void Tasks::init()
{

    this->add.setText("add task");

    layout.addWidget(&add, 0, 1, 2, 1);

    layout.addWidget(&scrollArea, 0, 0, 1, 1);
    this->setLayout(&layout);

    scWidget.setLayout(&scrollLayout);
    scrollArea.setWidget(&scWidget);

    scrollArea.setWidgetResizable(true);
    scrollArea.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

   // connect(&add, &QPushButton::clicked, this, &Tasks::addTask);
}

void Tasks::addTask(Element *elem)
{
    scrollLayout.addWidget(elem);
}

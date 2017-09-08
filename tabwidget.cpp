#include "tabwidget.h"
#include "tasks.h"

TabWidget::TabWidget(QWidget *parent) : QTabWidget(parent)
{
    init();
}

void TabWidget::init()
{
    task1 = new Tasks;
    task2 = new Tasks;

    this->addTab(task1, "unready");
    this->addTab(task2, "ready");

    QList<Element*> elems = db.selectTables();

    for( auto el : elems) {
        if(el->isReady.isChecked())
            task2->scrollLayout.addWidget(el);
        else
            task1->scrollLayout.addWidget(el);

    }

    connect(&task1->add, &QPushButton::clicked, this, &TabWidget::createTask);



}

void TabWidget::createTask()
{
    auto elem = new Element;

    task1->addTask(elem);
    this->db.insertTables(elem);

    connect(&elem->taskText, &decltype(elem->taskText)::textChanged, this, &TabWidget::taskChanged);



}
void TabWidget::taskChanged()
{
    db.updateTables(qobject_cast<Element*>(QObject::sender()));
}

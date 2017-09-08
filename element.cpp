#include "element.h"
#include <QLayout>
#include <QGridLayout>

int Element::id = 0;

Element::Element(QWidget *parent) : QWidget(parent), primaryKey(id)
{
    init();
}

void Element::becomeReady(int)
{
    isReady.setEnabled(false);
    end.setDateTime(QDateTime::currentDateTime());
    this->setEnabled(false);
}

void Element::init()
{
    this->setMaximumHeight(200);
    auto layout = new QGridLayout();

    layout->addWidget(&start, 0, 0, 1, 1);
    layout->addWidget(&end, 1, 0, 1, 1);

    layout->addWidget(&taskText, 0, 1, 2, 1, Qt::AlignHCenter);
    layout->addWidget(&performer, 0, 2, 2, 1, Qt::AlignRight);
    layout->addWidget(&isReady, 0, 3, 2, 1, Qt::AlignRight);

    this->setLayout(layout);


    start.setDateTime(QDateTime::currentDateTime());

    start.setEnabled(false);
    end.setEnabled(false);

    connect(&isReady, &QCheckBox::stateChanged, this, &Element::becomeReady );
}

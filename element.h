#ifndef ELEMENT_H
#define ELEMENT_H

#include <QWidget>

#include <QTextEdit>
#include <QCheckBox>
#include <QDateTimeEdit>
#include <QLineEdit>

class Element : public QWidget
{
    Q_OBJECT
static int id;
public:
    explicit Element(QWidget *parent = nullptr);

    void init();

    const int primaryKey = 0;

    QTextEdit taskText;
    QCheckBox isReady;
    QDateTimeEdit start;
    QDateTimeEdit end;
    QLineEdit performer;

signals:

public slots:
    void becomeReady(int);
};

#endif // ELEMENT_H

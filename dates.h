#ifndef DATES_H
#define DATES_H

#include <QWidget>
#include <QDateTimeEdit>

class Dates : public QWidget
{
    Q_OBJECT
public:
    explicit Dates(QWidget *parent = nullptr);
    void init();
    QDateTimeEdit start;
    QDateTimeEdit end;

signals:

public slots:
};

#endif // DATES_H

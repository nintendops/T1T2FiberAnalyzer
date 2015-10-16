#ifndef ERRORREPORTER_H
#define ERRORREPORTER_H

#include <QMessageBox>
#include <iostream>

class ErrorReporter : public QMessageBox
{
    Q_OBJECT
public:
    explicit ErrorReporter(QWidget *parent = 0);
    static void fire(std::string);
signals:

public slots:

};

#endif // ERRORREPORTER_H

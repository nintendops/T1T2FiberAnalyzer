#include "errorreporter.h"

ErrorReporter::ErrorReporter(QWidget *parent) :
    QMessageBox(parent)
{
}

void ErrorReporter::fire(std::string str){
    ErrorReporter::warning(0,"Warning",QString::fromStdString(str),QMessageBox::Ok);
}

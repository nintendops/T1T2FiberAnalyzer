#include "include/errorreporter.h"


void ErrorReporter::fire(std::string str){
    ErrorReporter::warning(0,"Warning",QString::fromStdString(str),QMessageBox::Ok);
}

#ifndef Load_T1T2FiberAnalyzer_H
#define Load_T1T2FiberAnalyzer_H

#include <QCoreApplication>
#include <QString>
#include <QDebug>
#include <map>
#include <QFile>
#include <QStringList>
#include <iostream>
#include "Model_T1T2FiberAnalyzer.h"
#include <QXmlStreamReader>


class Load_T1T2FiberAnalyzer{

  QString tmpClassName;
  QString tmpClassType;
public:

  Model_T1T2FiberAnalyzer load(Model_T1T2FiberAnalyzer& model , std::string filename );

};
#endif
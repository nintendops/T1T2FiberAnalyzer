#ifndef conf_Load_T1T2FiberAnalyzer_H
#define conf_Load_T1T2FiberAnalyzer_H

#include <QCoreApplication>
#include <QString>
#include <QDebug>
#include <map>
#include <QFile>
#include <QStringList>
#include <iostream>
#include "conf_Model_T1T2FiberAnalyzer.h"
#include <QXmlStreamReader>


class conf_Load_T1T2FiberAnalyzer{

  QString tmpClassName;
  QString tmpClassType;
public:

  conf_Model_T1T2FiberAnalyzer load(conf_Model_T1T2FiberAnalyzer& model , std::string filename );

};
#endif
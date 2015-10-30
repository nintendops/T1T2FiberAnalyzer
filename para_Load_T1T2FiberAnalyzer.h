#ifndef para_Load_T1T2FiberAnalyzer_H
#define para_Load_T1T2FiberAnalyzer_H

#include <QCoreApplication>
#include <QString>
#include <QDebug>
#include <map>
#include <QFile>
#include <QStringList>
#include <iostream>
#include "para_Model_T1T2FiberAnalyzer.h"
#include <QXmlStreamReader>


class para_Load_T1T2FiberAnalyzer{

  QString tmpClassName;
  QString tmpClassType;
public:

  para_Model_T1T2FiberAnalyzer load(para_Model_T1T2FiberAnalyzer& model , std::string filename );

};
#endif
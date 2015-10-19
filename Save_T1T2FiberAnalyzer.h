#ifndef Save_T1T2FiberAnalyzer_H
#define Save_T1T2FiberAnalyzer_H
#include <QXmlStreamWriter>
#include <QFile>

#include <QString>

#include <string>

#include "Model_T1T2FiberAnalyzer.h"

#include <QDebug>

class Save_T1T2FiberAnalyzer{ 

public: 

	void save(Model_T1T2FiberAnalyzer& m , std::string filename );
	void saveToXML(Model_T1T2FiberAnalyzer& m,QXmlStreamWriter& writer);
};
#endif

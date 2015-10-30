#ifndef para_Save_T1T2FiberAnalyzer_H
#define para_Save_T1T2FiberAnalyzer_H
#include <QXmlStreamWriter>
#include <QFile>

#include <QString>

#include <string>

#include "para_Model_T1T2FiberAnalyzer.h"

#include <QDebug>

class para_Save_T1T2FiberAnalyzer{ 

public: 

	void save(para_Model_T1T2FiberAnalyzer& m , std::string filename );
	void saveToXML(para_Model_T1T2FiberAnalyzer& m,QXmlStreamWriter& writer);
};
#endif

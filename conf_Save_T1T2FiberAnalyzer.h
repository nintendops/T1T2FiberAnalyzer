#ifndef conf_Save_T1T2FiberAnalyzer_H
#define conf_Save_T1T2FiberAnalyzer_H
#include <QXmlStreamWriter>
#include <QFile>

#include <QString>

#include <string>

#include "conf_Model_T1T2FiberAnalyzer.h"

#include <QDebug>

class conf_Save_T1T2FiberAnalyzer{ 

public: 

	void save(conf_Model_T1T2FiberAnalyzer& m , std::string filename );
	void saveToXML(conf_Model_T1T2FiberAnalyzer& m,QXmlStreamWriter& writer);
};
#endif

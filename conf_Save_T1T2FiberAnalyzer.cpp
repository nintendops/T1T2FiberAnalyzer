#include "conf_Save_T1T2FiberAnalyzer.h"
	void conf_Save_T1T2FiberAnalyzer::save(conf_Model_T1T2FiberAnalyzer& m , std::string filename){
		//First, address the appropriate instantiate
		QFile file(filename.c_str());
		if(!file.open(QIODevice::WriteOnly)){
			//handle file open errors here 
			 qDebug()<<file.exists();
		}

		QXmlStreamWriter writer(&file);

		//write each field stored in model into xml
		saveToXML(m,writer);

	}


	void conf_Save_T1T2FiberAnalyzer::saveToXML(conf_Model_T1T2FiberAnalyzer& m,QXmlStreamWriter& writer){

		writer.setAutoFormatting(true);

		writer.writeStartDocument();


		writer.writeStartElement("conf_Parameters");
		writer.writeEmptyElement("Parameter");
		writer.writeAttribute("type","QString");
		writer.writeAttribute("name","conf_DTIStatPath");
		writer.writeAttribute("value",m.getconf_DTIStatPath());
		writer.writeEmptyElement("Parameter");
		writer.writeAttribute("type","QString");
		writer.writeAttribute("name","conf_FiberProcessPath");
		writer.writeAttribute("value",m.getconf_FiberProcessPath());
		writer.writeEmptyElement("Parameter");
		writer.writeAttribute("type","QString");
		writer.writeAttribute("name","conf_pypath");
		writer.writeAttribute("value",m.getconf_pypath());
		writer.writeEndElement();

		writer.writeEndDocument();

	}

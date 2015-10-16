#include "include/Save_T1T2FiberAnalyzer.h"

	void Save_T1T2FiberAnalyzer::save(Model_T1T2FiberAnalyzer& m, std::string filename){
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


	void Save_T1T2FiberAnalyzer::saveToXML(Model_T1T2FiberAnalyzer& m,QXmlStreamWriter& writer){

		writer.setAutoFormatting(true);

		writer.writeStartDocument();


		writer.writeStartElement("Parameters");
		writer.writeEmptyElement("Parameter");
		writer.writeAttribute("type","QString");
		writer.writeAttribute("name","DTIComboPath");
		writer.writeAttribute("value",m.getDTIComboPath());
		writer.writeEmptyElement("Parameter");
		writer.writeAttribute("type","QString");
		writer.writeAttribute("name","DTIComboSID");
		writer.writeAttribute("value",m.getDTIComboSID());
		writer.writeEmptyElement("Parameter");
		writer.writeAttribute("type","QString");
		writer.writeAttribute("name","T12ComboPath");
		writer.writeAttribute("value",m.getT12ComboPath());
		writer.writeEmptyElement("Parameter");
		writer.writeAttribute("type","QString");
		writer.writeAttribute("name","T12ComboSID");
		writer.writeAttribute("value",m.getT12ComboSID());
		writer.writeEmptyElement("Parameter");
		writer.writeAttribute("type","QString");
		writer.writeAttribute("name","DTIFiber_Path");
		writer.writeAttribute("value",m.getDTIFiber_Path());
		writer.writeEmptyElement("Parameter");
		writer.writeAttribute("type","QString");
		writer.writeAttribute("name","DTIdefInputText");
		writer.writeAttribute("value",m.getDTIdefInputText());
		writer.writeEmptyElement("Parameter");
		writer.writeAttribute("type","QString");
		writer.writeAttribute("name","T12MapInputText");
		writer.writeAttribute("value",m.getT12MapInputText());
		writer.writeEmptyElement("Parameter");
		writer.writeAttribute("type","QString");
		writer.writeAttribute("name","lineEdit_2");
		writer.writeAttribute("value",m.getlineEdit_2());
		writer.writeEmptyElement("Parameter");
		writer.writeAttribute("type","QString");
		writer.writeAttribute("name","lineEdit_3");
		writer.writeAttribute("value",m.getlineEdit_3());
		writer.writeEmptyElement("Parameter");
		writer.writeAttribute("type","QString");
		writer.writeAttribute("name","pyPath");
		writer.writeAttribute("value",m.getpyPath());
		writer.writeEndElement();

		writer.writeEndDocument();

	}

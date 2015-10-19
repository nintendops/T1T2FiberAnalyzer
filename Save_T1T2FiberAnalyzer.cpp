#include "Save_T1T2FiberAnalyzer.h"
	void Save_T1T2FiberAnalyzer::save(Model_T1T2FiberAnalyzer& m , std::string filename){
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
		writer.writeAttribute("name","DTIStatPath");
		writer.writeAttribute("value",m.getDTIStatPath());
		writer.writeEmptyElement("Parameter");
		writer.writeAttribute("type","QString");
		writer.writeAttribute("name","DTIdefInputText");
		writer.writeAttribute("value",m.getDTIdefInputText());
		writer.writeEmptyElement("Parameter");
		writer.writeAttribute("type","QString");
		writer.writeAttribute("name","FiberProcessPath");
		writer.writeAttribute("value",m.getFiberProcessPath());
		writer.writeEmptyElement("Parameter");
		writer.writeAttribute("type","QString");
		writer.writeAttribute("name","T12MapInputText");
		writer.writeAttribute("value",m.getT12MapInputText());
		writer.writeEmptyElement("Parameter");
		writer.writeAttribute("type","QString");
		writer.writeAttribute("name","pyPath");
		writer.writeAttribute("value",m.getpyPath());
		writer.writeEmptyElement("Parameter");
		writer.writeAttribute("type","std::map<QString,bool>");
		writer.writeAttribute("name","CSVMatchTable");
		std::map<QString,bool> map_CSVMatchTable = m.getCSVMatchTable();
		std::map<QString,bool>::iterator it_CSVMatchTable = map_CSVMatchTable.begin();
		for( int count = 0 ; it_CSVMatchTable != map_CSVMatchTable.end() ; count++ , it_CSVMatchTable++ )
		{
			std::string item = "item" + QString::number(count).toStdString() ;
			std::string itemName = item+"Name" ;
			writer.writeAttribute(itemName.c_str(),it_CSVMatchTable->first);
			std::string itemState = item+"isChecked" ;
			writer.writeAttribute(itemState.c_str(),QString::number(it_CSVMatchTable->second));
		}
		writer.writeEmptyElement("Parameter");
		writer.writeAttribute("type","std::map<QString,bool>");
		writer.writeAttribute("name","Fiber_Tracts_Table");
		std::map<QString,bool> map_Fiber_Tracts_Table = m.getFiber_Tracts_Table();
		std::map<QString,bool>::iterator it_Fiber_Tracts_Table = map_Fiber_Tracts_Table.begin();
		for( int count = 0 ; it_Fiber_Tracts_Table != map_Fiber_Tracts_Table.end() ; count++ , it_Fiber_Tracts_Table++ )
		{
			std::string item = "item" + QString::number(count).toStdString() ;
			std::string itemName = item+"Name" ;
			writer.writeAttribute(itemName.c_str(),it_Fiber_Tracts_Table->first);
			std::string itemState = item+"isChecked" ;
			writer.writeAttribute(itemState.c_str(),QString::number(it_Fiber_Tracts_Table->second));
		}
		writer.writeEndElement();

		writer.writeEndDocument();

	}

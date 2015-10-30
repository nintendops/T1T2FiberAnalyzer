#include "para_Save_T1T2FiberAnalyzer.h"
	void para_Save_T1T2FiberAnalyzer::save(para_Model_T1T2FiberAnalyzer& m , std::string filename){
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


	void para_Save_T1T2FiberAnalyzer::saveToXML(para_Model_T1T2FiberAnalyzer& m,QXmlStreamWriter& writer){

		writer.setAutoFormatting(true);

		writer.writeStartDocument();


		writer.writeStartElement("para_Parameters");
		writer.writeEmptyElement("Parameter");
		writer.writeAttribute("type","QString");
		writer.writeAttribute("name","para_DTIComboPath");
		writer.writeAttribute("value",m.getpara_DTIComboPath());
		writer.writeEmptyElement("Parameter");
		writer.writeAttribute("type","QString");
		writer.writeAttribute("name","para_DTIComboSID");
		writer.writeAttribute("value",m.getpara_DTIComboSID());
		writer.writeEmptyElement("Parameter");
		writer.writeAttribute("type","QString");
		writer.writeAttribute("name","para_T12ComboPath");
		writer.writeAttribute("value",m.getpara_T12ComboPath());
		writer.writeEmptyElement("Parameter");
		writer.writeAttribute("type","QString");
		writer.writeAttribute("name","para_T12ComboSID");
		writer.writeAttribute("value",m.getpara_T12ComboSID());
		writer.writeEmptyElement("Parameter");
		writer.writeAttribute("type","QString");
		writer.writeAttribute("name","para_DTIFiber_Path");
		writer.writeAttribute("value",m.getpara_DTIFiber_Path());
		writer.writeEmptyElement("Parameter");
		writer.writeAttribute("type","QString");
		writer.writeAttribute("name","para_DTIdefInputText");
		writer.writeAttribute("value",m.getpara_DTIdefInputText());
		writer.writeEmptyElement("Parameter");
		writer.writeAttribute("type","QString");
		writer.writeAttribute("name","para_T12MapInputText");
		writer.writeAttribute("value",m.getpara_T12MapInputText());
		writer.writeEmptyElement("Parameter");
		writer.writeAttribute("type","std::map<QString,bool>");
		writer.writeAttribute("name","para_CSVMatchTable");
		std::map<QString,bool> map_para_CSVMatchTable = m.getpara_CSVMatchTable();
		std::map<QString,bool>::iterator it_para_CSVMatchTable = map_para_CSVMatchTable.begin();
		for( int count = 0 ; it_para_CSVMatchTable != map_para_CSVMatchTable.end() ; count++ , it_para_CSVMatchTable++ )
		{
			std::string item = "item" + QString::number(count).toStdString() ;
			std::string itemName = item+"Name" ;
			writer.writeAttribute(itemName.c_str(),it_para_CSVMatchTable->first);
			std::string itemState = item+"isChecked" ;
			writer.writeAttribute(itemState.c_str(),QString::number(it_para_CSVMatchTable->second));
		}
		writer.writeEmptyElement("Parameter");
		writer.writeAttribute("type","std::map<QString,bool>");
		writer.writeAttribute("name","para_Fiber_Tracts_Table");
		std::map<QString,bool> map_para_Fiber_Tracts_Table = m.getpara_Fiber_Tracts_Table();
		std::map<QString,bool>::iterator it_para_Fiber_Tracts_Table = map_para_Fiber_Tracts_Table.begin();
		for( int count = 0 ; it_para_Fiber_Tracts_Table != map_para_Fiber_Tracts_Table.end() ; count++ , it_para_Fiber_Tracts_Table++ )
		{
			std::string item = "item" + QString::number(count).toStdString() ;
			std::string itemName = item+"Name" ;
			writer.writeAttribute(itemName.c_str(),it_para_Fiber_Tracts_Table->first);
			std::string itemState = item+"isChecked" ;
			writer.writeAttribute(itemState.c_str(),QString::number(it_para_Fiber_Tracts_Table->second));
		}
		writer.writeEndElement();

		writer.writeEndDocument();

	}

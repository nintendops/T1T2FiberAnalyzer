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
		writer.writeAttribute("type","std::vector<std::vector<QString> >");
		writer.writeAttribute("name","para_CSVMatchTable");
		{
			std::vector<std::vector<QString> > table = m.getpara_CSVMatchTable();
			if( !table.empty() )
			{
				writer.writeAttribute("row", QString::number(table.size()) );
				writer.writeAttribute("column", QString::number(table[0].size()) );
			}
			std::vector<std::vector<QString> >::iterator it_table_1 = table.begin();
			for( size_t count = 0 ; it_table_1 != table.end() ; count++ , it_table_1++ )
			{
				std::vector<QString> list_2 = *it_table_1;
				std::vector<QString>::iterator it_table_2 = list_2.begin();
				for( std::vector<QString>::size_type count2 = 0 ; it_table_2 != list_2.end() ; count2++ , it_table_2++ )
				{
					std::string item = "item_" + QString::number(count).toStdString() + "_" + QString::number(count2).toStdString() ;
					writer.writeAttribute(item.c_str(),*it_table_2);
				}
			}
		}
		writer.writeEmptyElement("Parameter");
		writer.writeAttribute("type","std::vector<std::vector<QString> >");
		writer.writeAttribute("name","para_Fiber_Tracts_Table");
		{
			std::vector<std::vector<QString> > table = m.getpara_Fiber_Tracts_Table();
			if( !table.empty() )
			{
				writer.writeAttribute("row", QString::number(table.size()) );
				writer.writeAttribute("column", QString::number(table[0].size()) );
			}
			std::vector<std::vector<QString> >::iterator it_table_1 = table.begin();
			for( size_t count = 0 ; it_table_1 != table.end() ; count++ , it_table_1++ )
			{
				std::vector<QString> list_2 = *it_table_1;
				std::vector<QString>::iterator it_table_2 = list_2.begin();
				for( std::vector<QString>::size_type count2 = 0 ; it_table_2 != list_2.end() ; count2++ , it_table_2++ )
				{
					std::string item = "item_" + QString::number(count).toStdString() + "_" + QString::number(count2).toStdString() ;
					writer.writeAttribute(item.c_str(),*it_table_2);
				}
			}
		}
		writer.writeEndElement();

		writer.writeEndDocument();

	}

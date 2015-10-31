#include "para_Load_T1T2FiberAnalyzer.h"

  para_Model_T1T2FiberAnalyzer para_Load_T1T2FiberAnalyzer::load(para_Model_T1T2FiberAnalyzer& model , std::string filename)
  {
    std::map<std::pair<QString, QString>, QString> xmlTokens;
    typedef std::map<std::pair<QString, QString>, QString> Dict;
    typedef Dict::const_iterator It;

    QFile* data = new QFile(filename.c_str());
    if (!data->open(QIODevice::ReadOnly | QIODevice::Text)) 
    {
      qDebug() << "Not read only";
    }

    QXmlStreamReader readXML(data);
    std::map<QString , QList< std::pair< QString , QString > > > attributes ;
    while(!readXML.atEnd() && !readXML.hasError()) 
    {
      QXmlStreamReader::TokenType token = readXML.readNext();
      if(token == QXmlStreamReader::StartDocument) 
      {
        continue;
      }
      else if (readXML.isEndElement() != true) 
      {
        if(readXML.attributes().size()>2)
        {
          QList< std::pair< QString , QString > > currentAttributes;
          for( int i = 0 ; i < readXML.attributes().size() ; i++ )
          {
            std::pair< QString , QString > xmlAttribute ;
            xmlAttribute = std::make_pair( readXML.attributes()[i].name().toString() , readXML.attributes()[i].value().toString() ) ;
            currentAttributes.append( xmlAttribute ) ;
          }
          attributes[ readXML.attributes().value("name").toString() ] = currentAttributes ;
          xmlTokens[std::make_pair(readXML.attributes().value("type").toString(), readXML.attributes().value("name").toString())] = readXML.attributes().value("value").toString();
        }
      }
    }

    tmpClassType = "QString";
    tmpClassName = "para_DTIComboPath";

    for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
    {
      if((it -> first.second).compare(tmpClassName) == 0) 
      {
          model.setpara_DTIComboPath((QString)(it->second));
      }
    }

    tmpClassType = "QString";
    tmpClassName = "para_DTIComboSID";

    for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
    {
      if((it -> first.second).compare(tmpClassName) == 0) 
      {
          model.setpara_DTIComboSID((QString)(it->second));
      }
    }

    tmpClassType = "QString";
    tmpClassName = "para_T12ComboPath";

    for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
    {
      if((it -> first.second).compare(tmpClassName) == 0) 
      {
          model.setpara_T12ComboPath((QString)(it->second));
      }
    }

    tmpClassType = "QString";
    tmpClassName = "para_T12ComboSID";

    for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
    {
      if((it -> first.second).compare(tmpClassName) == 0) 
      {
          model.setpara_T12ComboSID((QString)(it->second));
      }
    }

    tmpClassType = "QString";
    tmpClassName = "para_DTIFiber_Path";

    for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
    {
      if((it -> first.second).compare(tmpClassName) == 0) 
      {
          model.setpara_DTIFiber_Path((QString)(it->second));
      }
    }

    tmpClassType = "QString";
    tmpClassName = "para_DTIdefInputText";

    for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
    {
      if((it -> first.second).compare(tmpClassName) == 0) 
      {
          model.setpara_DTIdefInputText((QString)(it->second));
      }
    }

    tmpClassType = "QString";
    tmpClassName = "para_T12MapInputText";

    for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
    {
      if((it -> first.second).compare(tmpClassName) == 0) 
      {
          model.setpara_T12MapInputText((QString)(it->second));
      }
    }

    tmpClassType = "std::vector<std::vector<QString> >";
    tmpClassName = "para_CSVMatchTable";

    for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
    {
      if((it -> first.second).compare(tmpClassName) == 0) 
      {
      }
    }

    tmpClassType = "std::vector<std::vector<QString> >";
    tmpClassName = "para_Fiber_Tracts_Table";

    for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
    {
      if((it -> first.second).compare(tmpClassName) == 0) 
      {
      }
    }

    return model;
  }
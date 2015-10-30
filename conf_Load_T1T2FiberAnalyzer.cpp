#include "conf_Load_T1T2FiberAnalyzer.h"

  conf_Model_T1T2FiberAnalyzer conf_Load_T1T2FiberAnalyzer::load(conf_Model_T1T2FiberAnalyzer& model , std::string filename)
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
    tmpClassName = "conf_DTIStatPath";

    for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
    {
      if((it -> first.second).compare(tmpClassName) == 0) 
      {
          model.setconf_DTIStatPath((QString)(it->second));
      }
    }

    tmpClassType = "QString";
    tmpClassName = "conf_FiberProcessPath";

    for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
    {
      if((it -> first.second).compare(tmpClassName) == 0) 
      {
          model.setconf_FiberProcessPath((QString)(it->second));
      }
    }

    tmpClassType = "QString";
    tmpClassName = "conf_pypath";

    for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
    {
      if((it -> first.second).compare(tmpClassName) == 0) 
      {
          model.setconf_pypath((QString)(it->second));
      }
    }

    return model;
  }
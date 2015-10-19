#include "Load_T1T2FiberAnalyzer.h"

  Model_T1T2FiberAnalyzer Load_T1T2FiberAnalyzer::load(Model_T1T2FiberAnalyzer& model , std::string filename)
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
    tmpClassName = "DTIComboPath";

    for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
    {
      if((it -> first.second).compare(tmpClassName) == 0) 
      {
          model.setDTIComboPath((QString)(it->second));
      }
    }

    tmpClassType = "QString";
    tmpClassName = "DTIComboSID";

    for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
    {
      if((it -> first.second).compare(tmpClassName) == 0) 
      {
          model.setDTIComboSID((QString)(it->second));
      }
    }

    tmpClassType = "QString";
    tmpClassName = "T12ComboPath";

    for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
    {
      if((it -> first.second).compare(tmpClassName) == 0) 
      {
          model.setT12ComboPath((QString)(it->second));
      }
    }

    tmpClassType = "QString";
    tmpClassName = "T12ComboSID";

    for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
    {
      if((it -> first.second).compare(tmpClassName) == 0) 
      {
          model.setT12ComboSID((QString)(it->second));
      }
    }

    tmpClassType = "QString";
    tmpClassName = "DTIFiber_Path";

    for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
    {
      if((it -> first.second).compare(tmpClassName) == 0) 
      {
          model.setDTIFiber_Path((QString)(it->second));
      }
    }

    tmpClassType = "QString";
    tmpClassName = "DTIStatPath";

    for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
    {
      if((it -> first.second).compare(tmpClassName) == 0) 
      {
          model.setDTIStatPath((QString)(it->second));
      }
    }

    tmpClassType = "QString";
    tmpClassName = "DTIdefInputText";

    for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
    {
      if((it -> first.second).compare(tmpClassName) == 0) 
      {
          model.setDTIdefInputText((QString)(it->second));
      }
    }

    tmpClassType = "QString";
    tmpClassName = "FiberProcessPath";

    for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
    {
      if((it -> first.second).compare(tmpClassName) == 0) 
      {
          model.setFiberProcessPath((QString)(it->second));
      }
    }

    tmpClassType = "QString";
    tmpClassName = "T12MapInputText";

    for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
    {
      if((it -> first.second).compare(tmpClassName) == 0) 
      {
          model.setT12MapInputText((QString)(it->second));
      }
    }

    tmpClassType = "QString";
    tmpClassName = "pyPath";

    for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
    {
      if((it -> first.second).compare(tmpClassName) == 0) 
      {
          model.setpyPath((QString)(it->second));
      }
    }

    tmpClassType = "std::map<QString,bool>";
    tmpClassName = "CSVMatchTable";

    for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
    {
      if((it -> first.second).compare(tmpClassName) == 0) 
      {
          std::map<QString,bool> CSVMatchTableMap ;
          QList< std::pair< QString , QString > > currentAttributes = attributes[ "CSVMatchTable" ];
          if( currentAttributes.size() % 2 == 1 || currentAttributes.size() < 4 )
          {
            std::cerr << "Wrong number of attributes for "<< it->first.second.toStdString() << ":" << currentAttributes.size() << std::endl ;
            continue ;
          }
          currentAttributes.removeFirst();
          currentAttributes.removeFirst();
          int itemNb = 0 ;
          while( currentAttributes.size() > 1 )
          {
            std::pair<QString , QString> attributeName = currentAttributes[ 0 ];
            QString name = QString("item") + QString::number(itemNb) + "Name";
            std::pair<QString , QString> attributeIsChecked = currentAttributes[ 1 ];
            QString isChecked = QString("item") + QString::number(itemNb) + "isChecked";
            if( !attributeName.first.compare(name) && !attributeIsChecked.first.compare(isChecked))
            {
              CSVMatchTableMap[ attributeName.second ] = ( attributeIsChecked.second.toInt() != 0 ? true : false ) ;
            }
            currentAttributes.removeFirst();
            currentAttributes.removeFirst();
            itemNb++;
          }
          model.setCSVMatchTable(CSVMatchTableMap) ;
       }
    }

    tmpClassType = "std::map<QString,bool>";
    tmpClassName = "Fiber_Tracts_Table";

    for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it) 
    {
      if((it -> first.second).compare(tmpClassName) == 0) 
      {
          std::map<QString,bool> Fiber_Tracts_TableMap ;
          QList< std::pair< QString , QString > > currentAttributes = attributes[ "Fiber_Tracts_Table" ];
          if( currentAttributes.size() % 2 == 1 || currentAttributes.size() < 4 )
          {
            std::cerr << "Wrong number of attributes for "<< it->first.second.toStdString() << ":" << currentAttributes.size() << std::endl ;
            continue ;
          }
          currentAttributes.removeFirst();
          currentAttributes.removeFirst();
          int itemNb = 0 ;
          while( currentAttributes.size() > 1 )
          {
            std::pair<QString , QString> attributeName = currentAttributes[ 0 ];
            QString name = QString("item") + QString::number(itemNb) + "Name";
            std::pair<QString , QString> attributeIsChecked = currentAttributes[ 1 ];
            QString isChecked = QString("item") + QString::number(itemNb) + "isChecked";
            if( !attributeName.first.compare(name) && !attributeIsChecked.first.compare(isChecked))
            {
              Fiber_Tracts_TableMap[ attributeName.second ] = ( attributeIsChecked.second.toInt() != 0 ? true : false ) ;
            }
            currentAttributes.removeFirst();
            currentAttributes.removeFirst();
            itemNb++;
          }
          model.setFiber_Tracts_Table(Fiber_Tracts_TableMap) ;
       }
    }

    return model;
  }
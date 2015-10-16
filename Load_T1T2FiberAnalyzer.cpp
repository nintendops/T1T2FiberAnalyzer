#include "include/Load_T1T2FiberAnalyzer.h"

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
    tmpClassName = "DTIdefInputText";

    for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it)
    {
        if((it -> first.second).compare(tmpClassName) == 0)
        {
            model.setDTIdefInputText((QString)(it->second));
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
    tmpClassName = "lineEdit_2";

    for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it)
    {
        if((it -> first.second).compare(tmpClassName) == 0)
        {
            model.setlineEdit_2((QString)(it->second));
        }
    }

    tmpClassType = "QString";
    tmpClassName = "lineEdit_3";

    for (It it= xmlTokens.begin(); it != xmlTokens.end(); ++it)
    {
        if((it -> first.second).compare(tmpClassName) == 0)
        {
            model.setlineEdit_3((QString)(it->second));
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

    return model;
}

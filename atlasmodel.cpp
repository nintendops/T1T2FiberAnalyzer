#include "atlasmodel.h"
#include <iostream>

AtlasModel::AtlasModel(QObject *parent, std::map<std::string,tool::TractData> db1,
                       std::map<std::string,tool::TractData> db2) :
    QAbstractTableModel(parent)
{
    tract_db.clear();

    // store the union of db1 and db2 into vector
    for(std::map<std::string,tool::TractData>::iterator it = db1.begin(); it!= db1.end(); ++it){
        std::string key = it->first;

        for(std::map<std::string,tool::TractData>::iterator itt = db2.begin(); itt!= db2.end(); ++itt){
            std::string mkey = itt->first;
            if(key == mkey){
                tool::MapData mapd = {
                    it->second.csv_path,
                    itt->second.csv_path,
                    QString::fromStdString(key),
                    ""
                };
                tract_db.push_back(mapd);
            }
            else if(key.length() <= mkey.length() && mkey.find(key) != std::string::npos){
                tool::MapData mapd = {
                    it->second.csv_path,
                    itt->second.csv_path,
                    QString::fromStdString(key),
                    QString::fromStdString(mkey)
                };
                tract_db.push_back(mapd);
            }
            else if(mkey.length() < key.length() && key.find(mkey) != std::string::npos){
                tool::MapData mapd = {
                    it->second.csv_path,
                    itt->second.csv_path,
                    QString::fromStdString(key),
                    QString::fromStdString(mkey)
                };
                tract_db.push_back(mapd);
            }

        }
    }

}

int AtlasModel::rowCount(const QModelIndex &parent) const{
    return tract_db.size();
}

int AtlasModel::columnCount(const QModelIndex &parent) const{
    return 1 + TRACT_CSV_COL_NUM;
}


QVariant AtlasModel::data(const QModelIndex &index, int role) const{
    int row = index.row();
    int col = index.column();

    if (role == Qt::DisplayRole){
        switch(col){
        case 1:
            return tract_db[row].subjectID;
        case 2:
            return tract_db[row].mapID;
        case 3:
            return tract_db[row].t12_path;
        case 4:
            return tract_db[row].def_path;
        }
    }
    else if (role == Qt::CheckStateRole){
        if(col == 0){
            return checkedState;
        }
    }

    return QVariant();

}

bool AtlasModel::setData(const QModelIndex & index, const QVariant & value, int role){
    if(role == Qt::CheckStateRole && index.column() == 0){
        if((Qt::CheckState)value.toInt() == Qt::Checked){
            checkedState = Qt::Checked;
            return true;
        }else{
            checkedState = Qt::Unchecked;
            return true;
        }
    }
    return false;
}

QVariant AtlasModel::headerData(int section, Qt::Orientation orientation, int role) const{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal){
        switch (section){
            case 0:
                return "";
            case 1:
                return "Subject ID";
            case 2:
                return "Mapped ID";
            case 3:
                return "T1/T2 Map Path";
            case 4:
                return "Deformation Field Path";
        }
    }

    return QVariant();

}

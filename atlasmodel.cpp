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
        auto found = db2.find(key);
        if(found != db2.end()){
            std::cout << "found union element " << key << "\n";
            // found union element
            tract_db.push_back(it->second);
        }
    }

}

AtlasModel::AtlasModel(QObject *parent, std::vector<tool::TractData> db) :
    QAbstractTableModel(parent){
    tract_db = db;
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
       if(col==1){
            return tract_db[row].subjectID;
        }else if(col==2){
            return tract_db[row].csv_path;
        }
    }
    else if (role == Qt::CheckStateRole){
        if(col == 0){
            return Qt::Checked;
        }
    }

    return QVariant();

}

QVariant AtlasModel::headerData(int section, Qt::Orientation orientation, int role) const{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal){
        switch (section){
            case 0:
                return "Selected";
            case 1:
                return "Subject ID";
            case 2:
                return "CSV Path";
        }
    }

    return QVariant();

}

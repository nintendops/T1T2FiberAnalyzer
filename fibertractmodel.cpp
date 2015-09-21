#include "fibertractmodel.h"
#include <iostream>

FiberTractModel::FiberTractModel(QObject *parent, std::map<std::string,tool::TractData> db1,
                                 std::map<std::string,tool::TractData> db2) :
    QAbstractTableModel(parent)
{


    // store the union of db1 and db2 into vector
    for (const auto x : db1){
         // std::unordered_set<tool::TractData>::const_iterator got =
    }

}


int FiberTractModel::rowCount(const QModelIndex &parent) const{
    return tract_db.size();
}

int FiberTractModel::columnCount(const QModelIndex &parent) const{
    return 1 + TRACT_CSV_COL_NUM;
}


QVariant FiberTractModel::data(const QModelIndex &index, int role) const{
    int row = index.row();
    int col = index.column();

    if (role == Qt::DisplayRole){
       if(col==1){
            return tract_db[row].csv_path;
        }else if(col==2){
            return tract_db[row].subjectID;
        }
    }
    else if (role == Qt::CheckStateRole){
        if(col == 0){
            return Qt::Checked;
        }
    }

    return QVariant();

}

QVariant FiberTractModel::headerData(int section, Qt::Orientation orientation, int role) const{
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

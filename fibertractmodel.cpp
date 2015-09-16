#include "fibertractmodel.h"

FiberTractModel::FiberTractModel(QObject *parent, std::vector<tool::TractData> db) :
    QAbstractTableModel(parent)
{
    tract_db = db;
}


int rowCount(const QModelIndex &parent) const{
    return tract_db.size();
}

int columnCount(const QModelIndex &parent) const{
    return 1 + tool::TRACT_CSV_COL_NUM;
}


QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const{
    if (role == Qt::DisplayRole){
        int row = index.row();
        int col = index.column();
        if(col==1){
            return tract_db[row].csv_path;
        }else if(col==2){
            return tract_db[row].subjectID;
        }
    }
    else if (role == Qt::CheckStateRole){
        if(row==1 && col == 0){
            return Qt::Checked;
        }
    }

    return QVariant();

}

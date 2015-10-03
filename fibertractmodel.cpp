#include "fibertractmodel.h"
#include "stacktrace.h"
#include <iostream>


FiberTractModel::FiberTractModel(QObject *parent, std::vector<tool::TractData> db) :
    QAbstractTableModel(parent){
    tract_db = db;

    checkedState = new Qt::CheckState[tract_db.size()]();

    for(int i =0; i< tract_db.size(); i++){
        checkedState[i] = Qt::Checked;
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
        }
    }
    else if (role == Qt::CheckStateRole){
        if(col == 0){
            return checkedState[row];
        }
    }

    return QVariant();
}

Qt::ItemFlags FiberTractModel::flags(const QModelIndex &index) const{
    Qt::ItemFlags flags = QAbstractItemModel::flags(index);
    if (index.column() == 0){
        flags |= Qt::ItemIsUserCheckable;
    }
    return flags;
}

QVariant FiberTractModel::headerData(int section, Qt::Orientation orientation, int role) const{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal){
        switch (section){
        case 0:
            return "Selected";
        case 1:
            return "Tract File Name";
        }
    }

    return QVariant();

}


bool FiberTractModel::setData(const QModelIndex & index, const QVariant & value, int role){
    if(role == Qt::CheckStateRole && index.column() == 0){
        //print_stacktrace();
        if((Qt::CheckState)value.toInt() == Qt::Checked){
            //std::cout << "set checked\n";
            checkedState[index.row()] = Qt::Checked;
            return true;
        }else{
            //std::cout << "set unchecked\n";
            checkedState[index.row()] = Qt::Unchecked;
            return true;
        }
    }
    return false;
}


void FiberTractModel::resetModel(Qt::CheckState state){
    this->beginResetModel();
    for(int i =0; i< tract_db.size(); i++){
        checkedState[i] = state;
    }
    this->endResetModel();
}

#ifndef ATLASMODEL_H
#define ATLASMODEL_H
#define TRACT_CSV_COL_NUM 4

#include <QAbstractTableModel>
#include "tfatool.h"

class AtlasModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit AtlasModel(QObject *parent = 0,
                            std::map<std::string,tool::TractData> db1 = std::map<std::string,tool::TractData>(),
                            std::map<std::string,tool::TractData> db2 = std::map<std::string,tool::TractData>());    
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    void resetModel(Qt::CheckState state);
private:
    Qt::CheckState* checkedState;
    std::vector<tool::MapData> tract_db;
signals:

public slots:

};

#endif // ATLASMODEL_H

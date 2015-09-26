#ifndef ATLASMODEL_H
#define ATLASMODEL_H
#define TRACT_CSV_COL_NUM 2

#include <QAbstractTableModel>
#include "tfatool.h"

class AtlasModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit AtlasModel(QObject *parent = 0,
                            std::map<std::string,tool::TractData> db1 = std::map<std::string,tool::TractData>(),
                            std::map<std::string,tool::TractData> db2 = std::map<std::string,tool::TractData>());
    explicit AtlasModel (QObject *parent = 0, std::vector<tool::TractData> db = std::vector<tool::TractData>());
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
private:
    std::vector<tool::TractData> tract_db;
    QVariant checkedState = Qt::Checked;
signals:

public slots:

};

#endif // ATLASMODEL_H

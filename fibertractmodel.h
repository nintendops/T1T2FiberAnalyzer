#ifndef FIBERTRACTMODEL_H
#define FIBERTRACTMODEL_H
#define TRACT_CSV_COL_NUM 2

#include <QAbstractTableModel>
#include "tfatool.h"

class FiberTractModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit FiberTractModel(QObject *parent = 0,
                            std::map<std::string,tool::TractData> db1 = std::map<std::string,tool::TractData>(),
                            std::map<std::string,tool::TractData> db2 = std::map<std::string,tool::TractData>());
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
private:
    std::vector<tool::TractData> tract_db;

signals:

public slots:

};

#endif // FIBERTRACTMODEL_H

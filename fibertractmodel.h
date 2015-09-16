#ifndef FIBERTRACTMODEL_H
#define FIBERTRACTMODEL_H

#include <QAbstractTableModel>

#include "tfatool.h"

class FiberTractModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit FiberTractModel(QObject *parent = 0, std::vector<tool::TractData> db = std::vector<tool::TractData>());
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

private:
    std::vector<tool::TractData> tract_db;

signals:

public slots:

};

#endif // FIBERTRACTMODEL_H

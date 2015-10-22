/********************************************************************************
** Form generated from reading UI file 'csvbrowser.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSVBROWSER_H
#define UI_CSVBROWSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CSVBrowser
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *BrowseTable;
    QPushButton *CSVbrwOK;

    void setupUi(QDialog *CSVBrowser)
    {
        if (CSVBrowser->objectName().isEmpty())
            CSVBrowser->setObjectName(QStringLiteral("CSVBrowser"));
        CSVBrowser->resize(687, 444);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CSVBrowser->sizePolicy().hasHeightForWidth());
        CSVBrowser->setSizePolicy(sizePolicy);
        CSVBrowser->setLayoutDirection(Qt::RightToLeft);
        verticalLayout = new QVBoxLayout(CSVBrowser);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        BrowseTable = new QTableView(CSVBrowser);
        BrowseTable->setObjectName(QStringLiteral("BrowseTable"));
        sizePolicy.setHeightForWidth(BrowseTable->sizePolicy().hasHeightForWidth());
        BrowseTable->setSizePolicy(sizePolicy);
        BrowseTable->setLayoutDirection(Qt::RightToLeft);

        verticalLayout->addWidget(BrowseTable);

        CSVbrwOK = new QPushButton(CSVBrowser);
        CSVbrwOK->setObjectName(QStringLiteral("CSVbrwOK"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(CSVbrwOK->sizePolicy().hasHeightForWidth());
        CSVbrwOK->setSizePolicy(sizePolicy1);
        CSVbrwOK->setMaximumSize(QSize(132, 16777215));

        verticalLayout->addWidget(CSVbrwOK);


        retranslateUi(CSVBrowser);

        QMetaObject::connectSlotsByName(CSVBrowser);
    } // setupUi

    void retranslateUi(QDialog *CSVBrowser)
    {
        CSVBrowser->setWindowTitle(QApplication::translate("CSVBrowser", "csv Browser", 0));
        CSVbrwOK->setText(QApplication::translate("CSVBrowser", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class CSVBrowser: public Ui_CSVBrowser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSVBROWSER_H

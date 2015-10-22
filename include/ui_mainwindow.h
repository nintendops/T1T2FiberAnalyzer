/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_7;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *T12MapInputText;
    QToolButton *T12MapInputBtn;
    QFormLayout *formLayout;
    QPushButton *T12BrowseBtn;
    QLabel *label_3;
    QComboBox *T12ComboPath;
    QLabel *label_4;
    QComboBox *T12ComboSID;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *DTIdefInputText;
    QToolButton *DTIdefInputBtn;
    QFormLayout *formLayout_2;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *DTIBrowseBtn;
    QComboBox *DTIComboPath;
    QComboBox *DTIComboSID;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *MatchResultBtn;
    QPushButton *MatchTableSelectAll;
    QPushButton *MatchTableDeselectAll;
    QTableView *CSVMatchTable;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *DTIFiber_Path;
    QToolButton *DTIAtlasPathBtn;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *FiberTableSelectAll;
    QPushButton *FiberTableDeselectAll;
    QTableView *Fiber_Tracts_Table;
    QWidget *tab_3;
    QLabel *label_9;
    QTextBrowser *textBrowser;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *DTIStatPath;
    QToolButton *toolButton_3;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *FiberProcessPath;
    QToolButton *toolButton_2;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *pyPath;
    QToolButton *pyPathBtn;
    QLabel *label_10;
    QLabel *label_11;
    QMenuBar *menuBar;
    QMenu *menuT1_T2_Fiber_Analyzer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1117, 582);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_7 = new QHBoxLayout(centralWidget);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        horizontalLayout_8 = new QHBoxLayout(tab);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        frame = new QFrame(tab);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMaximumSize(QSize(367, 16777215));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_7 = new QVBoxLayout(frame);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        T12MapInputText = new QLineEdit(frame);
        T12MapInputText->setObjectName(QStringLiteral("T12MapInputText"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(T12MapInputText->sizePolicy().hasHeightForWidth());
        T12MapInputText->setSizePolicy(sizePolicy1);
        T12MapInputText->setMaximumSize(QSize(16777215, 27));
        T12MapInputText->setLayoutDirection(Qt::RightToLeft);
        T12MapInputText->setReadOnly(true);

        horizontalLayout->addWidget(T12MapInputText);

        T12MapInputBtn = new QToolButton(frame);
        T12MapInputBtn->setObjectName(QStringLiteral("T12MapInputBtn"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(T12MapInputBtn->sizePolicy().hasHeightForWidth());
        T12MapInputBtn->setSizePolicy(sizePolicy2);
        T12MapInputBtn->setMinimumSize(QSize(24, 0));
        T12MapInputBtn->setMaximumSize(QSize(0, 27));

        horizontalLayout->addWidget(T12MapInputBtn);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_7->addLayout(verticalLayout);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setHorizontalSpacing(3);
        formLayout->setVerticalSpacing(3);
        T12BrowseBtn = new QPushButton(frame);
        T12BrowseBtn->setObjectName(QStringLiteral("T12BrowseBtn"));
        sizePolicy.setHeightForWidth(T12BrowseBtn->sizePolicy().hasHeightForWidth());
        T12BrowseBtn->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::LabelRole, T12BrowseBtn);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(0, 0));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        T12ComboPath = new QComboBox(frame);
        T12ComboPath->setObjectName(QStringLiteral("T12ComboPath"));
        sizePolicy2.setHeightForWidth(T12ComboPath->sizePolicy().hasHeightForWidth());
        T12ComboPath->setSizePolicy(sizePolicy2);
        T12ComboPath->setMaximumSize(QSize(180, 16777215));

        formLayout->setWidget(2, QFormLayout::FieldRole, T12ComboPath);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(0, 0));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        T12ComboSID = new QComboBox(frame);
        T12ComboSID->setObjectName(QStringLiteral("T12ComboSID"));
        sizePolicy2.setHeightForWidth(T12ComboSID->sizePolicy().hasHeightForWidth());
        T12ComboSID->setSizePolicy(sizePolicy2);

        formLayout->setWidget(4, QFormLayout::FieldRole, T12ComboSID);


        verticalLayout_7->addLayout(formLayout);


        verticalLayout_5->addWidget(frame);

        frame_2 = new QFrame(tab);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setMaximumSize(QSize(367, 16777215));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_8 = new QVBoxLayout(frame_2);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(label_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        DTIdefInputText = new QLineEdit(frame_2);
        DTIdefInputText->setObjectName(QStringLiteral("DTIdefInputText"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(DTIdefInputText->sizePolicy().hasHeightForWidth());
        DTIdefInputText->setSizePolicy(sizePolicy3);
        DTIdefInputText->setMaximumSize(QSize(16777215, 27));
        DTIdefInputText->setLayoutDirection(Qt::RightToLeft);
        DTIdefInputText->setReadOnly(true);

        horizontalLayout_2->addWidget(DTIdefInputText);

        DTIdefInputBtn = new QToolButton(frame_2);
        DTIdefInputBtn->setObjectName(QStringLiteral("DTIdefInputBtn"));
        sizePolicy.setHeightForWidth(DTIdefInputBtn->sizePolicy().hasHeightForWidth());
        DTIdefInputBtn->setSizePolicy(sizePolicy);
        DTIdefInputBtn->setMinimumSize(QSize(24, 0));
        DTIdefInputBtn->setMaximumSize(QSize(16777215, 27));

        horizontalLayout_2->addWidget(DTIdefInputBtn);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_8->addLayout(verticalLayout_2);

        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(200, 0));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_6);

        label_7 = new QLabel(frame_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(200, 0));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_7);

        DTIBrowseBtn = new QPushButton(frame_2);
        DTIBrowseBtn->setObjectName(QStringLiteral("DTIBrowseBtn"));
        sizePolicy.setHeightForWidth(DTIBrowseBtn->sizePolicy().hasHeightForWidth());
        DTIBrowseBtn->setSizePolicy(sizePolicy);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, DTIBrowseBtn);

        DTIComboPath = new QComboBox(frame_2);
        DTIComboPath->setObjectName(QStringLiteral("DTIComboPath"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, DTIComboPath);

        DTIComboSID = new QComboBox(frame_2);
        DTIComboSID->setObjectName(QStringLiteral("DTIComboSID"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, DTIComboSID);


        verticalLayout_8->addLayout(formLayout_2);


        verticalLayout_5->addWidget(frame_2);


        horizontalLayout_8->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(2);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setSizeConstraint(QLayout::SetMaximumSize);
        MatchResultBtn = new QPushButton(tab);
        MatchResultBtn->setObjectName(QStringLiteral("MatchResultBtn"));
        MatchResultBtn->setEnabled(false);
        sizePolicy.setHeightForWidth(MatchResultBtn->sizePolicy().hasHeightForWidth());
        MatchResultBtn->setSizePolicy(sizePolicy);
        MatchResultBtn->setMinimumSize(QSize(150, 0));
        MatchResultBtn->setMaximumSize(QSize(160, 27));

        horizontalLayout_10->addWidget(MatchResultBtn, 0, Qt::AlignLeft);

        MatchTableSelectAll = new QPushButton(tab);
        MatchTableSelectAll->setObjectName(QStringLiteral("MatchTableSelectAll"));
        MatchTableSelectAll->setEnabled(false);
        sizePolicy.setHeightForWidth(MatchTableSelectAll->sizePolicy().hasHeightForWidth());
        MatchTableSelectAll->setSizePolicy(sizePolicy);
        MatchTableSelectAll->setMinimumSize(QSize(120, 0));
        MatchTableSelectAll->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_10->addWidget(MatchTableSelectAll);

        MatchTableDeselectAll = new QPushButton(tab);
        MatchTableDeselectAll->setObjectName(QStringLiteral("MatchTableDeselectAll"));
        MatchTableDeselectAll->setEnabled(false);
        sizePolicy.setHeightForWidth(MatchTableDeselectAll->sizePolicy().hasHeightForWidth());
        MatchTableDeselectAll->setSizePolicy(sizePolicy);
        MatchTableDeselectAll->setMinimumSize(QSize(120, 0));
        MatchTableDeselectAll->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_10->addWidget(MatchTableDeselectAll, 0, Qt::AlignLeft);

        horizontalLayout_10->setStretch(1, 1);
        horizontalLayout_10->setStretch(2, 100);

        verticalLayout_6->addLayout(horizontalLayout_10);

        CSVMatchTable = new QTableView(tab);
        CSVMatchTable->setObjectName(QStringLiteral("CSVMatchTable"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(CSVMatchTable->sizePolicy().hasHeightForWidth());
        CSVMatchTable->setSizePolicy(sizePolicy4);
        CSVMatchTable->setMinimumSize(QSize(700, 0));
        CSVMatchTable->setMaximumSize(QSize(9990000, 16777215));
        CSVMatchTable->setLayoutDirection(Qt::LeftToRight);
        CSVMatchTable->setTextElideMode(Qt::ElideLeft);

        verticalLayout_6->addWidget(CSVMatchTable);


        horizontalLayout_8->addLayout(verticalLayout_6);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        horizontalLayout_9 = new QHBoxLayout(tab_2);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setMinimumSize(QSize(0, 25));
        label_8->setMaximumSize(QSize(16777215, 25));
        label_8->setFrameShape(QFrame::NoFrame);

        verticalLayout_4->addWidget(label_8);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        DTIFiber_Path = new QLineEdit(tab_2);
        DTIFiber_Path->setObjectName(QStringLiteral("DTIFiber_Path"));
        sizePolicy3.setHeightForWidth(DTIFiber_Path->sizePolicy().hasHeightForWidth());
        DTIFiber_Path->setSizePolicy(sizePolicy3);
        DTIFiber_Path->setMaximumSize(QSize(235, 27));
        DTIFiber_Path->setReadOnly(true);

        horizontalLayout_4->addWidget(DTIFiber_Path, 0, Qt::AlignTop);

        DTIAtlasPathBtn = new QToolButton(tab_2);
        DTIAtlasPathBtn->setObjectName(QStringLiteral("DTIAtlasPathBtn"));
        sizePolicy.setHeightForWidth(DTIAtlasPathBtn->sizePolicy().hasHeightForWidth());
        DTIAtlasPathBtn->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(DTIAtlasPathBtn, 0, Qt::AlignTop);


        verticalLayout_4->addLayout(horizontalLayout_4);


        horizontalLayout_9->addLayout(verticalLayout_4);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_10->addWidget(label_2);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(2);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setSizeConstraint(QLayout::SetFixedSize);
        FiberTableSelectAll = new QPushButton(tab_2);
        FiberTableSelectAll->setObjectName(QStringLiteral("FiberTableSelectAll"));
        FiberTableSelectAll->setEnabled(false);
        sizePolicy.setHeightForWidth(FiberTableSelectAll->sizePolicy().hasHeightForWidth());
        FiberTableSelectAll->setSizePolicy(sizePolicy);
        FiberTableSelectAll->setMinimumSize(QSize(120, 0));
        FiberTableSelectAll->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_11->addWidget(FiberTableSelectAll);

        FiberTableDeselectAll = new QPushButton(tab_2);
        FiberTableDeselectAll->setObjectName(QStringLiteral("FiberTableDeselectAll"));
        FiberTableDeselectAll->setEnabled(false);
        sizePolicy.setHeightForWidth(FiberTableDeselectAll->sizePolicy().hasHeightForWidth());
        FiberTableDeselectAll->setSizePolicy(sizePolicy);
        FiberTableDeselectAll->setMinimumSize(QSize(120, 0));
        FiberTableDeselectAll->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_11->addWidget(FiberTableDeselectAll, 0, Qt::AlignLeft);

        horizontalLayout_11->setStretch(1, 99);

        verticalLayout_10->addLayout(horizontalLayout_11);

        Fiber_Tracts_Table = new QTableView(tab_2);
        Fiber_Tracts_Table->setObjectName(QStringLiteral("Fiber_Tracts_Table"));
        Fiber_Tracts_Table->setMinimumSize(QSize(800, 427));

        verticalLayout_10->addWidget(Fiber_Tracts_Table);


        horizontalLayout_9->addLayout(verticalLayout_10);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label_9 = new QLabel(tab_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(240, 230, 88, 17));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setMaximumSize(QSize(597, 17));
        textBrowser = new QTextBrowser(tab_3);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(240, 100, 597, 100));
        sizePolicy.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy);
        textBrowser->setMinimumSize(QSize(597, 100));
        textBrowser->setMaximumSize(QSize(597, 100));
        layoutWidget = new QWidget(tab_3);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 370, 806, 31));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget);
        horizontalLayout_6->setSpacing(1);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_6->setContentsMargins(180, 0, 0, 0);
        DTIStatPath = new QLineEdit(layoutWidget);
        DTIStatPath->setObjectName(QStringLiteral("DTIStatPath"));
        sizePolicy.setHeightForWidth(DTIStatPath->sizePolicy().hasHeightForWidth());
        DTIStatPath->setSizePolicy(sizePolicy);
        DTIStatPath->setMinimumSize(QSize(600, 0));
        DTIStatPath->setMaximumSize(QSize(700, 27));
        DTIStatPath->setReadOnly(true);

        horizontalLayout_6->addWidget(DTIStatPath, 0, Qt::AlignRight);

        toolButton_3 = new QToolButton(layoutWidget);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setMaximumSize(QSize(24, 25));

        horizontalLayout_6->addWidget(toolButton_3, 0, Qt::AlignLeft);

        layoutWidget1 = new QWidget(tab_3);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(60, 310, 806, 29));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_5->setSpacing(1);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_5->setContentsMargins(180, 0, 0, 0);
        FiberProcessPath = new QLineEdit(layoutWidget1);
        FiberProcessPath->setObjectName(QStringLiteral("FiberProcessPath"));
        sizePolicy.setHeightForWidth(FiberProcessPath->sizePolicy().hasHeightForWidth());
        FiberProcessPath->setSizePolicy(sizePolicy);
        FiberProcessPath->setMinimumSize(QSize(600, 0));
        FiberProcessPath->setMaximumSize(QSize(700, 27));
        FiberProcessPath->setReadOnly(true);

        horizontalLayout_5->addWidget(FiberProcessPath, 0, Qt::AlignRight);

        toolButton_2 = new QToolButton(layoutWidget1);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setMaximumSize(QSize(24, 25));

        horizontalLayout_5->addWidget(toolButton_2, 0, Qt::AlignLeft);

        layoutWidget2 = new QWidget(tab_3);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(60, 250, 806, 29));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setSpacing(1);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_3->setContentsMargins(180, 0, 0, 0);
        pyPath = new QLineEdit(layoutWidget2);
        pyPath->setObjectName(QStringLiteral("pyPath"));
        pyPath->setEnabled(true);
        sizePolicy.setHeightForWidth(pyPath->sizePolicy().hasHeightForWidth());
        pyPath->setSizePolicy(sizePolicy);
        pyPath->setMinimumSize(QSize(600, 0));
        pyPath->setMaximumSize(QSize(700, 27));
        pyPath->setReadOnly(true);

        horizontalLayout_3->addWidget(pyPath, 0, Qt::AlignRight);

        pyPathBtn = new QToolButton(layoutWidget2);
        pyPathBtn->setObjectName(QStringLiteral("pyPathBtn"));
        sizePolicy.setHeightForWidth(pyPathBtn->sizePolicy().hasHeightForWidth());
        pyPathBtn->setSizePolicy(sizePolicy);
        pyPathBtn->setMaximumSize(QSize(24, 25));

        horizontalLayout_3->addWidget(pyPathBtn, 0, Qt::AlignLeft);

        label_10 = new QLabel(tab_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(240, 290, 95, 17));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setMaximumSize(QSize(95, 17));
        label_11 = new QLabel(tab_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(240, 350, 96, 17));
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);
        label_11->setMaximumSize(QSize(96, 17));
        tabWidget->addTab(tab_3, QString());

        horizontalLayout_7->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1117, 25));
        menuT1_T2_Fiber_Analyzer = new QMenu(menuBar);
        menuT1_T2_Fiber_Analyzer->setObjectName(QStringLiteral("menuT1_T2_Fiber_Analyzer"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuT1_T2_Fiber_Analyzer->menuAction());

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "T1/T2 Fiber Analyzer", 0));
        label->setText(QApplication::translate("MainWindow", "Load CSV of T1/T2 Path: ", 0));
        T12MapInputBtn->setText(QApplication::translate("MainWindow", "...", 0));
        T12BrowseBtn->setText(QApplication::translate("MainWindow", "Browse Table", 0));
        label_3->setText(QApplication::translate("MainWindow", "Header Name of T1/T2 path:", 0));
        label_4->setText(QApplication::translate("MainWindow", "Header Name of Subject ID:", 0));
        label_5->setText(QApplication::translate("MainWindow", "Load CSV of Deformation Path:", 0));
        DTIdefInputBtn->setText(QApplication::translate("MainWindow", "...", 0));
        label_6->setText(QApplication::translate("MainWindow", "Header Name of Def Field:", 0));
        label_7->setText(QApplication::translate("MainWindow", "Header Name of Subject ID:", 0));
        DTIBrowseBtn->setText(QApplication::translate("MainWindow", "Browse Table", 0));
        MatchResultBtn->setText(QApplication::translate("MainWindow", "Match Result", 0));
        MatchTableSelectAll->setText(QApplication::translate("MainWindow", "Select All", 0));
        MatchTableDeselectAll->setText(QApplication::translate("MainWindow", "Deselect All", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Data Definition", 0));
        label_8->setText(QApplication::translate("MainWindow", "DTI Fiber Path:", 0));
        DTIAtlasPathBtn->setText(QApplication::translate("MainWindow", "...", 0));
        label_2->setText(QApplication::translate("MainWindow", "Available Fiber Tracts:", 0));
        FiberTableSelectAll->setText(QApplication::translate("MainWindow", "Select All", 0));
        FiberTableDeselectAll->setText(QApplication::translate("MainWindow", "Deselect All", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Attribute Fibers ", 0));
        label_9->setText(QApplication::translate("MainWindow", "Python Path:", 0));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-style:italic;\">Warning: The program reads python path from environment variable $TFA_PYTHON by default. If no value is stored in the variable, it reads from the result of  &quot;which python&quot; </span></p></body></html>", 0));
        toolButton_3->setText(QApplication::translate("MainWindow", "...", 0));
        toolButton_2->setText(QApplication::translate("MainWindow", "...", 0));
        pyPathBtn->setText(QApplication::translate("MainWindow", "...", 0));
        label_10->setText(QApplication::translate("MainWindow", "Fiber Process:", 0));
        label_11->setText(QApplication::translate("MainWindow", "DTI Tract Stat:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Software Configuration", 0));
        menuT1_T2_Fiber_Analyzer->setTitle(QApplication::translate("MainWindow", "T1/T2 Fiber Analyzer", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

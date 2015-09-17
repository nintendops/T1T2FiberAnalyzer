#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fibertractmodel.h"
#include "Resources/csv.h"
#include <QApplication>
#include <QFileDialog>
#include <QtDebug>
#include <QTableView>
#include <iostream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*setting DTIAtlas Path */
void MainWindow::on_toolButton_3_clicked()
{
    /* setting path in edit line*/
    QString fileName = QFileDialog::getOpenFileName(this,tr("Select File"),"/home/haiweich/Dev/repo/T1T2FiberAnalyzer/test_data/");
    ui->DTIAtlas_Path->setText(fileName);

    /* parsing csv */
    io::CSVReader<2> atlas(fileName.toStdString());
    atlas.read_header(io::ignore_extra_column,"csv_path","subjectID");
    char* csv_path;
    char* subjectID;
    std::vector<tool::TractData> tractData;

    while(atlas.read_row(csv_path,subjectID)){
        std::cout << csv_path << ":" << subjectID << "\n";
        tool::TractData newTract = {
            QString::fromStdString(csv_path),  // csv path
            QString::fromStdString(subjectID)  //subject ID
        };

        tractData.push_back(newTract);
    }
    FiberTractModel *mm = new FiberTractModel(0,tractData);
    QItemSelectionModel *m =ui->Fiber_Tracts_Table->selectionModel();
    ui->Fiber_Tracts_Table->setModel(mm);
    ui->Fiber_Tracts_Table->horizontalHeader()->setStretchLastSection(true);
    if(m) delete m;
//    ui->Fiber_Tracts_Table->show();
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
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

void MainWindow::on_T12MapInputBtn_clicked()
{
    /* setting path in edit line*/
    QString fileName = QFileDialog::getOpenFileName(this,tr("Select File"),"/home/haiweich/Dev/repo/T1T2FiberAnalyzer/test_data/");
    ui->T12MapInputText->setText(fileName);

    // read header names from spinBox
    std::string path_hname = ui->T12pathHeaderName->text().toStdString();
    std::string sid_hname = ui->T12sidHeaderName->text().toStdString();
    /* parsing csv */
    io::CSVReader<2> atlas(fileName.toStdString());
    atlas.read_header(io::ignore_extra_column,sid_hname,path_hname);

    char* csv_path;
    char* subjectID;

    T12TractData.clear();

    while(atlas.read_row(csv_path,subjectID)){
        std::cout << csv_path << ":" << subjectID << "\n";
        tool::TractData newTract = {
            QString::fromStdString(csv_path),  // csv path
            QString::fromStdString(subjectID)  //subject ID
        };

        T12TractData.insert(std::pair<std::string,tool::TractData>(newTract.subjectID,newTract));

    }
    FiberTractModel *mm = new FiberTractModel(0,T12TractData,DTITractData);
    QItemSelectionModel *m =ui->Fiber_Tracts_Table->selectionModel();
    ui->Fiber_Tracts_Table->setModel(mm);
    ui->Fiber_Tracts_Table->horizontalHeader()->setStretchLastSection(true);
    if(m) delete m;
//    ui->Fiber_Tracts_Table->show();
}




void MainWindow::on_DTIdefInputBtn_clicked()
{
    /* setting path in edit line*/
    QString fileName = QFileDialog::getOpenFileName(this,tr("Select File"),"/home/haiweich/Dev/repo/T1T2FiberAnalyzer/test_data/");
    ui->DTIdefInputText->setText(fileName);

    // read header names from spinBox
    std::string path_hname = ui->DTIpathHeaderName->text().toStdString();
    std::string sid_hname = ui->DTIsidHeaderName->text().toStdString();
    /* parsing csv */
    io::CSVReader<2> atlas(fileName.toStdString());
    atlas.read_header(io::ignore_extra_column,sid_hname,path_hname);

    char* csv_path;
    char* subjectID;

    DTITractData.clear();

    while(atlas.read_row(csv_path,subjectID)){
        std::cout << csv_path << ":" << subjectID << "\n";
        tool::TractData newTract = {
            QString::fromStdString(csv_path),  // csv path
            QString::fromStdString(subjectID)  //subject ID
        };

        DTITractData.insert(std::pair<std::string,tool::TractData>(newTract.subjectID,newTract));

    }
    FiberTractModel *mm = new FiberTractModel(0,T12TractData,DTITractData);
    QItemSelectionModel *m =ui->Fiber_Tracts_Table->selectionModel();
    ui->Fiber_Tracts_Table->setModel(mm);
    ui->Fiber_Tracts_Table->horizontalHeader()->setStretchLastSection(true);
    if(m) delete m;
}

void MainWindow::on_DTIAtlasPathBtn_clicked()
{

}

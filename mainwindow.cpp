#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "csvbrowser.h"
#include "errorreporter.h"
#include <QApplication>
#include <QFileDialog>
#include <QDialog>
#include <QtDebug>
#include <QTableView>
#include <iostream>
#include <utility>
#include <functional>

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
    QString fileName = QFileDialog::getOpenFileName(this,tr("Select File"),DEFAULT_DIR);
    if(fileName == NULL) return;
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

    while(atlas.read_row(subjectID,csv_path)){
        //std::cout << csv_path << ":" << subjectID << "\n";
        tool::TractData newTract = {
            QString::fromStdString(csv_path),  // csv path
            QString::fromStdString(subjectID)  //subject ID
        };

        auto element = std::make_pair(subjectID,newTract);
        T12TractData.insert(element);

    }
    AtlasModel *mm = new AtlasModel(0,T12TractData,DTITractData);
    QItemSelectionModel *m =ui->CSVMatchTable->selectionModel();
    ui->CSVMatchTable->setModel(mm);
    ui->CSVMatchTable->horizontalHeader()->setStretchLastSection(true);
    if(m) delete m;
}




void MainWindow::on_DTIdefInputBtn_clicked()
{
    /* setting path in edit line*/
    QString fileName = QFileDialog::getOpenFileName(this,tr("Select File"),DEFAULT_DIR);
    if(fileName == NULL) return;
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

    while(atlas.read_row(subjectID,csv_path)){
        //std::cout << csv_path << ":" << subjectID << "\n";
        tool::TractData newTract = {
            QString::fromStdString(csv_path),  // csv path
            QString::fromStdString(subjectID)  //subject ID
        };

        auto element = std::make_pair(subjectID,newTract);
        DTITractData.insert(element);

    }
    AtlasModel *mm = new AtlasModel(0,T12TractData,DTITractData);
    QItemSelectionModel *m =ui->CSVMatchTable->selectionModel();
    ui->CSVMatchTable->setModel(mm);
    ui->CSVMatchTable->horizontalHeader()->setStretchLastSection(true);
    if(m) delete m;
}

void MainWindow::on_DTIAtlasPathBtn_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this,tr("Open Directory"),DEFAULT_DIR,
                                                    QFileDialog::ShowDirsOnly);
    if(dir == NULL) return;
    ui->DTIFiber_Path->setText(dir);
    std::vector<tool::TractData> filelist;
    tool::getnrrdfiles(dir.toStdString(),filelist);

    FiberTractModel *mm = new FiberTractModel(0,filelist);
    QItemSelectionModel *m =ui->CSVMatchTable->selectionModel();
    ui->Fiber_Tracts_Table->setModel(mm);
    ui->Fiber_Tracts_Table->horizontalHeader()->setStretchLastSection(true);
    if(m) delete m;
}

void MainWindow::on_T12BrowseBtn_clicked()
{
    QString dir = ui->T12MapInputText->text();
    if(dir == NULL) return;
    std::vector<std::vector<std::string>> csv_results;
    std::vector<std::string> headers;
    if(dir != NULL){
        try{
        csv_results = tool::parseCSV(dir.toStdString(),headers);
        }
        catch(io::error::can_not_open_file e){
            ErrorReporter::fire("CSV file is not found!");
            return;
        }
    }
    CSVBrowser *bd = new CSVBrowser();
    bd->show();
    bd->loadTable(csv_results,headers);

}

void MainWindow::on_DTIBrowseBtn_clicked()
{
    QString dir = ui->DTIdefInputText->text();
    std::vector<std::vector<std::string>> csv_results;
    std::vector<std::string> headers;
    if(dir != NULL){
        csv_results = tool::parseCSV(dir.toStdString(),headers);
    }
    CSVBrowser *bd = new CSVBrowser();
    bd->show();
    bd->loadTable(csv_results,headers);
}

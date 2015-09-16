#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tfatool.h"
#include "Resources/csv.h"
#include <QApplication>
#include <QFileDialog>
#include <QtDebug>

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

    while(atlas.read_row(csv_path,subjectID)){
        std::cout << csv_path << ":" << subjectID << "\n";
    }
}

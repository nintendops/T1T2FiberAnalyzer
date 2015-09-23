#include "csvbrowser.h"
#include "ui_csvbrowser.h"

CSVBrowser::CSVBrowser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CSVBrowser)
{
    ui->setupUi(this);
}

CSVBrowser::~CSVBrowser()
{
    delete ui;
}

void CSVBrowser::on_CSVbrwOK_clicked()
{
    delete this;
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "fibertractmodel.h"
#include "Resources/csv.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_T12MapInputBtn_clicked();

    void on_DTIdefInputBtn_clicked();

    void on_DTIAtlasPathBtn_clicked();

private:
    Ui::MainWindow *ui;
    std::map<std::string,tool::TractData> T12TractData;
    std::map<std::string,tool::TractData> DTITractData;



};

#endif // MAINWINDOW_H

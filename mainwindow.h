#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define DEFAULT_DIR "/home/haiweich/Dev/repo/T1T2FiberAnalyzer/test_data/"
#define PYVERSION_SCRIPT_PATH "./version.py"

#include <QMainWindow>

#include "fibertractmodel.h"
#include "atlasmodel.h"
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

    void initializePyPath();
    bool checkPyVersion(std::string path);
    
private slots:
    void on_T12MapInputBtn_clicked();

    void on_DTIdefInputBtn_clicked();

    void on_DTIAtlasPathBtn_clicked();

    void on_T12BrowseBtn_clicked();

    void on_DTIBrowseBtn_clicked();

    void checkHeaderSelection();

    void on_MatchResultBtn_clicked();

    void on_pyPathBtn_clicked();

    void on_MatchTableSelectAll_clicked();

    void on_MatchTableDeselectAll_clicked();

    void on_FiberTableSelectAll_clicked();

    void on_FiberTableDeselectAll_clicked();

signals:
    void headerSelected();

private:
    Ui::MainWindow *ui;
    std::map<std::string,tool::TractData> T12TractData;
    std::map<std::string,tool::TractData> DTITractData;
    std::vector<std::string> T12headers;
    std::vector<std::string> DTIheaders;
    const QString* DEFAULT_PATH;


};

#endif // MAINWINDOW_H

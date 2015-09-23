#ifndef CSVBROWSER_H
#define CSVBROWSER_H

#include <QDialog>

namespace Ui {
class CSVBrowser;
}

class CSVBrowser : public QDialog
{
    Q_OBJECT

public:
    explicit CSVBrowser(QWidget *parent = 0);
    ~CSVBrowser();

private slots:
    void on_CSVbrwOK_clicked();

private:
    Ui::CSVBrowser *ui;
};

#endif // CSVBROWSER_H

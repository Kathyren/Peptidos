#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stdlib.h>
#include <time.h>


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
    void on_cmdEntrenar_clicked();

    void on_cmdPruebas_clicked();

    void on_btnCalular_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H

#include "red.h"
#include "ui_red.h"

Red::Red(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Red)
{
    ui->setupUi(this);
}

Red::~Red()
{
    delete ui;
}

void Red::on_btnCalcular_clicked()
{

}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include "redneuronal.h"

RedNeuronal * redNeuronal;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(NULL));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void cargarDatos(QString archivoTexto){
    double clasesEntren [NUM_ENTREN][NUM_SALIDAS];
    double datosEntren [NUM_ENTREN][NUM_CARS];
    QString dato;
    QFile archivo(archivoTexto);
    archivo.open(QIODevice::ReadOnly);
    QTextStream textoArchivo(&archivo);
    int contSC=0;
    int contE=0;
    while (!textoArchivo.atEnd())
    {
        textoArchivo >> dato;
        if (contSC<NUM_SALIDAS){
            clasesEntren[contE][contSC]=dato.toDouble();
        }
        else{
            //Recordar que los primeros NUM_SALIDAS valores corresponden a las clases y no a características
            datosEntren[contE][contSC-NUM_SALIDAS]=dato.toDouble();
        }
        contSC++;
        if (contSC==NUM_SALIDAS+NUM_CARS){
            contE++;
            contSC=0;
        }
    }
    archivo.close();

    redNeuronal=new RedNeuronal(clasesEntren,datosEntren);

}

void MainWindow::on_cmdEntrenar_clicked()
{
    cargarDatos(ui->txtArchivoEntrenamiento->text());

    redNeuronal->entrenar();
}

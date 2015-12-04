#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include "redneuronal.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

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
void cargarDatosP(QString archivoTexto){
    double clasesEntren [NUM_Pruebas][NUM_SALIDAS];
    double datosEntren [NUM_Pruebas][NUM_CARS];
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
   // redNeuronal->preProbar(clasesEntren,datosEntren);
redNeuronal->probar(clasesEntren,datosEntren);


}
QString cargarDatosC(QString archivoTexto){

    double datosEntren [NUM_Calculos][NUM_CARS];
    QString dato;
    QFile archivo(archivoTexto);
    archivo.open(QIODevice::ReadOnly);
    QTextStream textoArchivo(&archivo);
    int contSC=0;
    int contE=0;
    while (!textoArchivo.atEnd())
    {
    textoArchivo >> dato;

            //Recordar que los primeros NUM_SALIDAS valores corresponden a las clases y no a características
            datosEntren[contE][contSC]=dato.toDouble();

        contSC++;
        if (contSC==NUM_CARS)
        {
            contE++;
            contSC=0;
        }
    }
    archivo.close();

return redNeuronal->Resultado( datosEntren);
return "a";

}
void MainWindow::on_cmdEntrenar_clicked()
{

    QString fileName =  QFileDialog::getOpenFileName(
                      this,
                      tr("Abrir archivo de entrenamiento"),
                      "C://Users//Karen//Documents//Peptidos//RedesNeuronales",
                      " Text File (*.txt)"
                      );
    if (fileName!="")
    {
        ui->txtArchivoEntrenamiento->setText(fileName);
    cargarDatos(fileName);
}
    redNeuronal->entrenar();
    QMessageBox::information(this,tr("File Name"),"Entrenamiento finalizado");
}

void MainWindow::on_cmdPruebas_clicked()
{

    QString fileName =  QFileDialog::getOpenFileName(
                      this,
                      tr("Abrir archivo de prueba"),
                      "C://Users//Karen//Documents//Peptidos//RedesNeuronales",
                      "Text File (*.txt)"
                      );
    if (fileName!="")
    {
        ui->txtArchivoPrueba->setText(fileName);
    cargarDatosP(fileName);
}


}

void MainWindow::on_btnCalular_clicked()
{

    QString fileName =  QFileDialog::getOpenFileName(
                      this,
                      tr("Abrir archivo para calcular"),
                      "C://Users//Karen//Documents//Peptidos//RedesNeuronales",
                      "Text File (*.txt)"
                      );
    QString texto="";
if (fileName!="")
{
    texto=cargarDatosC(fileName);

    QString st =  QFileDialog::getSaveFileName(
                      this,tr("Guardar"),
                      "C://Users//Karen//Documents//Peptidos//RedesNeuronales",
                      "All files (*.*);; Text File (*.txt)"
                      );
    QFile file1(st);
        file1.open(QIODevice::WriteOnly|QIODevice::Text);
        QTextStream in (&file1);
//double datosEntren [NUM_Calculos][NUM_CARS];//
//texto=redNeuronal->Resultado(datosEntren);//
       // cargarDatosC(texto)
    in << texto;
    file1.close();
        texto.clear();
QMessageBox::information(this,tr("Exito"),"Archivo guardado como: "+st);
}

}

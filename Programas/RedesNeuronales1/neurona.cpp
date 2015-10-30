#include <neurona.h>
#include <QtCore/qmath.h>



double Neurona:: funcionActivacion(double x)
{

    double r= 1+ e^x;
    r=1/r;
    salida=r;
    return r;
}
void Neurona::setSalida(double s)
{
    salida=s;
}
double Neurona::getSalida()
{}

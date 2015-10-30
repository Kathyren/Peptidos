#ifndef LARED
#define LARED
#include <neurona.h>



class laRed
{

public:

     int capas[1];
     double w[1];
     Neurona* a[1];
     double y[1];


public :

     laRed (int []);///Cantidad de neuronas en cada capa
    double funcionActivacion(double , double );
    void generarWs();///de forma aletoria
    bool entrenar(double[], double[]);//con las entradas y las salidas
    double error(double[]);


};


#endif // LARED


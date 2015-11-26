#ifndef REDNEURONAL_H
#define REDNEURONAL_H

#include "constantes.h"

class RedNeuronal
{

private:
    double clasesEntren [NUM_ENTREN][NUM_SALIDAS];
    double datosEntren [NUM_ENTREN][NUM_CARS];
    double x[NUM_CARS];
    double a2[NUM_NEUS_C2];
    double y[NUM_SALIDAS];
    double S[NUM_SALIDAS];
    double w1[NUM_CARS][NUM_NEUS_C2];
    double w2[NUM_NEUS_C2][NUM_SALIDAS];
    double u2[NUM_NEUS_C2];
    double u3[NUM_SALIDAS];
    double alfa;

public:
    RedNeuronal(double[][NUM_SALIDAS],double[][NUM_CARS]);
    void inicializa();
    void entrenar();
    double sumatoriaW1(double [NUM_CARS][NUM_NEUS_C2], double [NUM_CARS], int);
    double sumatoriaW2(double [NUM_NEUS_C2][NUM_SALIDAS], double [NUM_NEUS_C2], int);
    double CambioW2(double*, double*, double*, int);
};

#endif // REDNEURONAL_H

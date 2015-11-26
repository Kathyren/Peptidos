#include "partedaniel.h"
#include <iostream>
#include <stdlib.h>






    double ParteDaniel::ObtenerSalida(int x[], double w1[], double w2[] , double y[])
    {
      float y = 0;
      float a20 = x0 * w100 + x1 * w110 + x2 * w120;
      float a21 = x0 * w101 + x1 * w111 + x2 * w121;
      y = a20 * w20y + a21 * w21y;
      return y;
    }

        double ::Sumatoria(int x[], double)
        {

        }



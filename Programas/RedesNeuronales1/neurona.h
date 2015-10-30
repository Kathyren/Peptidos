#ifndef NEURONA
#define NEURONA


class Neurona
{

public:

    double umbral;
    double salida;
    double entrada;


public :
    Neurona();
    Neurona(double u);
    double funcionActivacion(double, double );
   void setSalida(double);
   double getSalida();



};

#endif // NEURONA

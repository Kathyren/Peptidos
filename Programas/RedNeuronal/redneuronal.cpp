#include "redneuronal.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <QtMath>

RedNeuronal::RedNeuronal(double clases[][NUM_SALIDAS], double datos[][NUM_CARS])
{
    for (int contE=0; contE<NUM_ENTREN; contE++){
        for (int contS=0; contS<NUM_SALIDAS; contS++)
        {
            clasesEntren[contE][contS]=clases[contE][contS];
        }
        for (int contC=0; contC<NUM_CARS; contC++){
            datosEntren[contE][contC]=datos[contE][contC];
        }
    }

    for (int contE=0; contE<NUM_ENTREN; contE++){
        std::cout<<std::endl;
        for (int contS=0; contS<NUM_SALIDAS; contS++)
        {
            std::cout<<clasesEntren[contE][contS]<<" ";
        }
        std::cout<<" - ";
        for (int contC=0; contC<NUM_CARS; contC++){
            std::cout<<(int)datosEntren[contE][contC]<<" ";
        }
    }
    std::cout<<std::endl;
}

void RedNeuronal::inicializa()
{
    for (int contC=0; contC<NUM_CARS; contC++){
        for (int contNC2=0; contNC2<NUM_NEUS_C2; contNC2++)
        {
            w1[contC][contNC2]=rand()%10000/10000.0*2-1;
        }
    }
    for (int contNC2=0; contNC2<NUM_NEUS_C2; contNC2++){
        for (int contS=0; contS<NUM_SALIDAS; contS++)
        {
            w2[contNC2][contS]=rand()%10000/10000.0*2-1;
        }
    }
    for (int contNC2=0; contNC2<NUM_NEUS_C2; contNC2++)
    {
        u2[contNC2]=rand()%10000/10000.0*2-1;
    }
    for (int contS=0; contS<NUM_SALIDAS; contS++)
    {
        u3[contS]=rand()%10000/10000.0*2-1;
    }
    alfa=0.5;
}

double f(double x)
{
    return 1/(1+qPow(2.718,-x));
}

bool condicion(double S, double y)
{
    //Falta generalizar
    if (qAbs(S-y)<EPSILON)
        return true;
    else
        return false;
}

void RedNeuronal::entrenar(){
    inicializa();
    int epoca=0;
    bool continuar=true;
    while(continuar)
    {
        epoca++;
        continuar=false;
        std::cout<<"----------------------------------------------------------------------------------------"<<std::endl;
        for (int contE=0; contE<NUM_ENTREN; contE++)
        {
            for (int contC=0; contC<NUM_CARS; contC++)
            {
                x[contC]=datosEntren[contE][contC];
            }
            for (int contS=0; contS<NUM_SALIDAS; contS++)
            {
                S[contS]=clasesEntren[contE][contS];
            }

            //A partir de aquí falta generalizar
            a2[0]=f(u2[0]+w1[0][0]*x[0]+w1[1][0]*x[1]);
            y[0]=f(u3[0]+w2[0][0]*f(u2[0]+w1[0][0]*x[0]+w1[1][0]*x[1]));

            std::cout<<"epoca="<<epoca
                     <<" x="<<x[0]<<" x="<<x[1]<<" S="<<S[0]<<" y="<<y[0]
                     <<" w1="<<w1[0][0]<<" w1="<<w1[1][0]<<" w2="<<w2[0][0]
                     <<" u2="<<u2[0]<<" u3="<<u3[0]<<" "<<std::endl;

            if (!condicion(S[0],y[0]))
            {
                w1[0][0]=w1[0][0]+(S[0]-y[0])*y[0]*(1-y[0])*w2[0][0]*a2[0]*(1-a2[0])*x[0]*alfa;
                w1[1][0]=w1[1][0]+(S[0]-y[0])*y[0]*(1-y[0])*w2[0][0]*a2[0]*(1-a2[0])*x[1]*alfa;
                w2[0][0]=w2[0][0]+(S[0]-y[0])*y[0]*(1-y[0])*a2[0]*alfa;
                u2[0]=u2[0]+(S[0]-y[0])*y[0]*(1-y[0])*w2[0][0]*a2[0]*(1-a2[0])*alfa;
                u3[0]=u3[0]+(S[0]-y[0])*y[0]*(1-y[0])*alfa;
                continuar=true;
           }
        }
    }
}













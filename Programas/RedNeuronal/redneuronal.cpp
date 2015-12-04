#include "redneuronal.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <QtMath>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void RedNeuronal:: preProbar(double clases[][NUM_SALIDAS], double datos[][NUM_CARS])
{

    for (int contE=0; contE<NUM_ENTREN; contE++){
        for (int contS=0; contS<NUM_SALIDAS; contS++)
        {
            clasesPrueba[contE][contS]=clases[contE][contS];
        }
        for (int contC=0; contC<NUM_CARS; contC++){
            datosPrueba[contE][contC]=datos[contE][contC];
        }
    }
}
void RedNeuronal:: preCalcular( double datos[][NUM_CARS])
{
    for (int contE=0; contE<NUM_ENTREN; contE++){
        for (int contS=0; contS<NUM_CARS; contS++)
        {
            datosCalcular[contE][contS]=datos[contE][contS];
        }

    }
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
bool RedNeuronal::condiciones()
{
    for (int i=0; i<NUM_SALIDAS;i++)
    {
       if( !condicion(S[i],y[i]))
           return false;

    }
    return true;
}
bool RedNeuronal::condicion(double S, double y)
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
            for (int i=0; i<NUM_NEUS_C2; i++)
            {
            a2[i]=f(u2[i]+sumatoriaW1(w1,x,i));
            }
            for (int i=0; i<NUM_SALIDAS; i++)
            y[i]=f(u3[i]+ sumatoriaW2(w2,a2,i));

            std::cout<<"epoca="<<epoca
                     <<" x="<<x[0]<<" x="<<x[1]<<" S="<<S[0]<<" y="<<y[0]
                     <<" w1="<<w1[0][0]<<" w1="<<w1[1][0]<<" w2="<<w2[0][0]
                     <<" u2="<<u2[0]<<" u3="<<u3[0]<<" "<<std::endl;

            if (!condiciones())
            {

                //w1[0][0]=w1[0][0]+(S[0]-y[0])*y[0]*(1-y[0])*w2[0][0]*a2[0]*(1-a2[0])*x[0]*alfa;
                //w1[1][0]=w1[1][0]+(S[0]-y[0])*y[0]*(1-y[0])*w2[0][0]*a2[0]*(1-a2[0])*x[1]*alfa;
                double errores[NUM_SALIDAS];

                for(int n = 0; n < NUM_SALIDAS; n++) {
                    errores[n] = (S[n]-y[n])*y[n]*(1-y[n]);
                }

//w1
                for(int i = 0; i < NUM_CARS; i++)
                {
                    for(int j = 0; j < NUM_NEUS_C2; j++)
                    {
                        double erroreSalida = 0;
                        for(int n = 0; n < NUM_SALIDAS; n++)
                        {
                            erroreSalida = erroreSalida + errores[n]*w2[j][n]*a2[j]*(1-a2[j])*x[i];
                        }
                        w1[i][j] = w1[i][j]+erroreSalida*alfa;
                    }
                }

                //W2
                for(int i = 0; i <  NUM_NEUS_C2; i++)
                {
                    for(int j = 0; j < NUM_SALIDAS; j++)
                    {
                        w2[i][j] = w2[i][j] + S[j] - y[j] * (y[j] * (1-y[j]) * a2[i]) * alfa;
                    }

                }

                //u2
                for(int i = 0; i < NUM_CARS; i++) {
                    double errorSalida = 0;
                    for(int n = 0; n < NUM_SALIDAS; n++) {
                        errorSalida = errorSalida + errores[n];
                    }
                    u2[i] = u2[i] + errorSalida*a2[i]*alfa;
                }


                //Umbral3
                for(int i = 0; i <  NUM_SALIDAS; i++)
                {
                    u3[i]=u3[i] + errores[i] * alfa;
                }

                //w2[0][0]=w2[0][0]+(S[0]-y[0])*y[0]*(1-y[0])*a2[0]*alfa;
                //u2[0]=u2[0]+(S[0]-y[0])*y[0]*(1-y[0])*w2[0][0]*a2[0]*(1-a2[0])*alfa;
                //u3[0]=u3[0]+(S[0]-y[0])*y[0]*(1-y[0])*alfa;
                continuar=true;
           }
        }
    }
}
double RedNeuronal:: sumatoriaW1(double w1 [NUM_CARS][NUM_NEUS_C2], double x [NUM_CARS], int neuronaC2)
{

    double r;
    r=0;
    for (int i=0; i<NUM_CARS;i++)
        r+= w1[i][neuronaC2] * x[i];
    return r;



}
double RedNeuronal:: sumatoriaW2 (double w2 [NUM_NEUS_C2][NUM_SALIDAS], double a2[NUM_NEUS_C2], int numeronaSalida)
{
    double r;
    //double err=0;
    r=0;
    for (int i=0; i<NUM_NEUS_C2;i++)
    {
        //w2[j][i]*f(u2[j]+sumatoriaW1(w1,x,j)), en vez de multiplicar por la funcion, multiplicara por lo que obteemos

         r+= w2[i][numeronaSalida] * a2[i];

    }
    return r;

}
double RedNeuronal::probar(double clases[][NUM_SALIDAS], double datos[][NUM_CARS]){

    for (int contE=0; contE<NUM_Pruebas; contE++){
        for (int contS=0; contS<NUM_SALIDAS; contS++)
        {
            clasesPrueba[contE][contS]=clases[contE][contS];
        }
        for (int contC=0; contC<NUM_CARS; contC++){
            datosPrueba[contE][contC]=datos[contE][contC];
        }
    }

    for (int contE=0; contE<NUM_Pruebas; contE++){
        std::cout<<std::endl;
        for (int contS=0; contS<NUM_SALIDAS; contS++)
        {
            std::cout<<clasesPrueba[contE][contS]<<" ";
        }
        std::cout<<" - ";
        for (int contC=0; contC<NUM_CARS; contC++){
            std::cout<<(int)datosPrueba[contE][contC]<<" ";
        }
    }
    std::cout<<std::endl;
    double err = 0;

        std::cout<<"----------------------------------------------------------------------------------------"<<std::endl;
        for (int contE=0; contE<NUM_Pruebas; contE++)
        {
            for (int contC=0; contC<NUM_CARS; contC++)
            {
                x[contC]=datosPrueba[contE][contC];
            }
            for (int contS=0; contS<NUM_SALIDAS; contS++)
            {
                S[contS]=clasesPrueba[contE][contS];
            }

            //A partir de aquí falta generalizar
            for (int i=0; i<NUM_NEUS_C2; i++)
            {
            a2[i]=f(u2[i]+sumatoriaW1(w1,x,i));
            }
            for (int i=0; i<NUM_SALIDAS; i++)
            y[i]=f(u3[i]+ sumatoriaW2(w2,a2,i));
            for (int i=0; i<NUM_SALIDAS; i++)
            {
            std::cout<<"Valor: "<<contE
                     <<"S="<<S[i]<<" y="<<y[i]<<" "<<std::endl;


            }
            if(!condiciones())
            {
                err++;
            }


        }


        std::cout
                 <<"Se equivoco en;  "<<err<<std::endl;
        return err;

}
QString RedNeuronal::Resultado( double datos[][NUM_CARS])
{
   QString texto="";
    for (int contE=0; contE<NUM_Calculos; contE++)
    {

        for (int contC=0; contC<NUM_CARS; contC++)
        {
            datosCalcular [contE][contC]=datos[contE][contC];
        }

    }
    std::cout<<std::endl;



  std::cout<<"----------------------------------------------------------------------------------------"<<std::endl;
        for (int contE=0; contE<NUM_Calculos; contE++)
        {
            for (int contC=0; contC<NUM_CARS; contC++)
            {
                x[contC]=datosCalcular[contE][contC];
            }



            for (int i=0; i<NUM_NEUS_C2; i++)
            {
            a2[i]=f(u2[i]+sumatoriaW1(w1,x,i));
            }
            for (int i=0; i<NUM_SALIDAS; i++)
            {y[i]=f(u3[i]+ sumatoriaW2(w2,a2,i));
            }
            for(int i=0;i<NUM_SALIDAS;i=i+1)
                {

                    texto+=QString::number(y[i]);
                    texto+=" ";
                    std::cout<<"Valor: "<<contE
                             <<"="<<i<<"    y="<<y[i]<<" "<<std::endl;


                }

            texto+="\n";

        }




return texto;

}

/*double RedNeuronal :: CambioW2(double s[NUM_SALIDAS], double y[NUM_SALIDAS], double a2[NUM_NEUS_C2], int NumW )
{
    double valor= 0;
    for(int i = 0; i < NUM_NEUS_C2; i++) {
        for (int j = 0; j < NUM_SALIDAS; j++) {
          valor += (s[i]-y[i])*y[i]*(1-y[i])*a2[j]*alfa;
        }
    }
    w2[NumW]= w2[NumW]+ valor;
    return w2[NumW];
}*/













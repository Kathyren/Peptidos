#include <lared.h>
#include <neurona.h>


laRed::laRed (int capas[], int longitud)
{
    int as=capas[0];//cantidad de neuronas en total para el arreglo
    int ws=0;// cantidad de pesos totales
    int i=1;
    for (; i<longitud;i++)
    {
        ws+= capas[i]*capas[i-1];
        as+=capas[i];
    }
    a[0]=new Neurona();
    y= new double ;
    w=new double[ws];
    i=0;
    for (;i<ws;i++)
    {
        w[i]=.5;
    }
    for (i=0;as;i++)
    {
        a[i]->setSalida=0;
    }
    for (i=0;y;i++)
    {

        y[i]=0;
    }

}
 bool laRed::entrenar(double entradas[], double salidas[])
 {
     if (entradas->Count != capas[0] ||salidas->Count != y->count)
         return false;
     int i=0;
     for (; i<capa[0];i++)
     {
         a[i]-> setSalida(entradas[i]);
     }

    int k=0;
    int limiteCapas=capa[0];
     for (int n=0; n<as;n++)
     {

         limiteCapas+= capa[n+1];
         int limiteWs= capa[n]*capa[n+1];
         int capas=n+1;
         for (;i<limiteCapas;i++)
            {
             limiteWs=limiteWs-capa[0]+1;
             double x=0;
             int j=0;
             for (; k<capas[n];i++)
             {
                     for (j=k; j<limiteWs;j+capas[n+1])///se ubica en la primer peso, y aumenta segun la cantidad de nueronas en la capa sig
                      {
                             x+=a[k]->getSalida*w[j];
                      }
                     limiteWs++;
             }
             a[i]->funcionActivacion(x);
            }
         k=capa[n];
     }

 }

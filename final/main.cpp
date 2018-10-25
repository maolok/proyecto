/*
 *
 *
 *
 *
 en esta aplicacion se declaran e incializan las formulas usadas para el tiro parabolico de un objeto

Las componentes de la velocidad del proyectil en función del tiempo son:

vx=v0·cosθ
vy=v0·senθ-g·t

La posición del proyectil en función del tiempo es

x= v0·cosθ·t
y= h+v0·senθ·t-g·t2/2

tiempo de vuelo = 2*v0*senθ/g
distancia maxima = v20*sen2θ/g
altura maxima = v20*sen2θ/2g



 */


#include <iostream>
#include <math.h>

using namespace std;

#define PI 3.1416
#define G 9.8

double vinicialX(double vinicial, double angulo); // se declara funcion para hallar velocidad inicial en X
double vinicialY (double vinicial, double angulo); // se declara funcion para hallar velocidad inicial en Y


double Tvuelo (double vinicial, double angulo); // se declara funcion para hallar tiempo total de vuelo del tiro parabolico.
double Xmax (double vinicial, double angulo); // se declara funcion para hallar la distancia maxima que alcanza el objeto.
double Altmax (double vinicial, double angulo); // funcion para hallar la altura maxima que alcanza el objeto.
double X (double vinicial, double angulo, double tiempo);  // calcular posicion en X en un tiempo dado.
double Y (double vinicial, double angulo, double tiempo);  // calcular posicion en Y en un tiempo dado.


int main()
{
   //llamado de funciones para verificar su funcionamiento
    cout<<vinicialX(26,40)<<endl;
    cout<<vinicialY(26,40)<<endl;
    cout<<Tvuelo(26,40)<<endl;
    cout<<Xmax(26,40)<<endl;
    cout<<Altmax(26,40)<<endl;



    return 0;
}

//definicion de funciones con formulas


double vinicialX(double vinicial, double angulo)
{

    double vinicialx =(vinicial*(cos(angulo*PI/180)));
    return vinicialx;

}

double vinicialY(double vinicial, double angulo)
{

    double vinicialy =(vinicial*(sin(angulo*PI/180)));
    return vinicialy;

}

double Tvuelo (double vinicial, double angulo)
{

    double tvuelo = ((2*vinicial*sin(angulo*PI/180))/G);
    return tvuelo;

}
double Xmax (double vinicial, double angulo)
{
     double newangulo = angulo*2;
     double xmax = (((vinicial*vinicial)*(sin(newangulo*PI/180)))/G);
     return xmax;

}
double Altmax (double vinicial, double angulo)
{
     double altmax = (((vinicial*vinicial)*(sin(angulo*PI/180)*sin(angulo*PI/180)))/(2*G));
     return altmax;

}
double X (double vinicial, double angulo, double tiempo)
{

    double x = ((vinicial*(cos(angulo*PI/180)))*tiempo);
    return x;

}
double Y (double vinicial, double angulo, double tiempo, double altinicial)
{

    double y = (altinicial + ((vinicial*(sin(angulo*PI/180)))*tiempo) - ((G*(tiempo*tiempo))/2));
    return y;

}



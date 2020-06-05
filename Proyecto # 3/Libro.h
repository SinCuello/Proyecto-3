#include <iostream>
#include <string>
#pragma once
#include "Material.h"

using namespace std;

class Libro:public Material
{

private:
    int numPag;
    string Autor;
public:
    Libro();
    Libro(int, string, int, string);

    void setNumpag(int _numPag){numPag=_numPag;};
    int getNumPag(){return numPag;};

    void setAutor(string _Autor){Autor=_Autor;};
    string getAutor(){return Autor;};

    void muestraDatos();
    int cantidadDiasPrestamo();

};

Libro::Libro():Material()
{
    numPag=0;
    Autor=" ";
}

Libro::Libro(int _idMaterial, string _titulo, int _numPag, string _Autor):Material(_idMaterial, _titulo)
{
    numPag=_numPag;
    Autor=_Autor;
}

void Libro::muestraDatos()
{
    cout<<"Datos del libro "<<endl;
    cout<<"Id del libro "<<idMaterial<<endl;
    cout<<"Titulo del libro "<<titulo<<endl;
    cout<<"Numero de paginas "<<numPag<<endl;
    cout<<"Nombre del autor "<<Autor<<endl;
}

int Libro::cantidadDiasPrestamo()
{
    return 7;
}


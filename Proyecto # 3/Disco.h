#include <iostream>
#include <string>
#pragma once
#include "Material.h"

using namespace std;

class Disco : public Material
{
private:
    int duracion;
    string Genero;
public:
    Disco();
    Disco(int, string, int, string);

    void setDuracion(int _duracion){duracion=_duracion;};
    int getDuracion(){return duracion;};

    void setGenero(string _Genero){Genero=_Genero;};
    string getGenero(){return Genero;};

    void muestraDatos();
    int cantidadDiasPrestamo();

};

Disco::Disco():Material()
{
    duracion=0;
    Genero=" ";
}

Disco::Disco(int _idMaterial, string _titulo, int _duracion, string _Genero):Material(_idMaterial, _titulo)
{
    duracion=_duracion;
    Genero=_Genero;
}

void Disco::muestraDatos()
{
    cout<<"Datos del disco "<<endl;
    cout<<"Id del disco "<<idMaterial<<endl;
    cout<<"Titulo del disco "<<titulo<<endl;
    cout<<"Duracion del disco "<<duracion<<endl;
    cout<<"Genero del disco "<<Genero<<endl;
}

int Disco::cantidadDiasPrestamo()
{
    return 2;
}












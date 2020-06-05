#include <iostream>
#include <string>
#pragma once
#include "Material.h"

using namespace std;

class Software:public Material
{
private:
    int Version;
    string SO;
public:
    Software();
    Software(int, string, int, string);

    void setVersion(int _Version){Version=_Version;};
    int getVersion(){return Version;};

    void setSO(string _SO){SO=_SO;};
    string getSO(){return SO;};

    void muestraDatos();
    int cantidadDiasPrestamo();
};

Software::Software():Material()
{
    Version=0;
    SO=" ";
}

Software::Software(int _idMaterial, string _titulo, int _Version, string _SO):Material(_idMaterial, _titulo)
{
    Version=_Version;
    SO=_SO;
}

void Software::muestraDatos()
{
    cout<<"Datos del Software "<<endl;
    cout<<"Id del Software "<<idMaterial<<endl;
    cout<<"Titulo del Software "<<titulo<<endl;
    cout<<"Version del Software "<<Version<<endl;
    cout<<"SO del Software "<<SO<<endl;
}

int Software::cantidadDiasPrestamo()
{
    return 1;
}








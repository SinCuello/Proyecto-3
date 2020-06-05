#include <iostream>
#include <string>
#pragma once
using namespace std;

class Material
{
protected:
    int idMaterial;
    string titulo;
public:
    virtual void muestraDatos()=0;
    virtual int cantidadDiasPrestamo()=0;

    Material();
    Material(int, string);

    void setIdMaterial(int _idMaterial){idMaterial=_idMaterial;};
    int getIdMaterial(){return idMaterial;};

    void setTitulo(string _titulo){titulo=_titulo;};
    string getTitulo(){return titulo;};

};

Material::Material()
{
    idMaterial=0;
    titulo=" ";
}

Material::Material(int _idMaterial, string _titulo)
{
    idMaterial=_idMaterial;
    titulo=_titulo;
}

#include <iostream>
#include <iostream>
#include <fstream>

#include "Reserva.h"
#include "Libro.h"
#include "Disco.h"
#include "Software.h"

using namespace std;

//Implementacion de funciones friend
ostream &operator<<(ostream &os, Fecha c2)
{
    os<<c2.dd<<"/"<<c2.nombreMes()<<"/"<<c2.aa;
    return os;
}

istream &operator>>(istream &os, Fecha &c2)
{
    cout<<"Dame el dia"<<endl;
    os>>c2.dd;
    cout<<"Dame el mes"<<endl;
    os>>c2.mm;
    cout<<"Dame el anio"<<endl;
    os>>c2.aa;
    return os;
}


int main()
{
    Material *Materiales[30];
    Libro Libros[30];
    Disco Discos[30];
    Software Softwares[30];


    Reserva Reservaciones[60];


    ifstream archivoEntrada,_archivoEntrada;
    int idMaterial, numPag, duracion, Version;
    char clave;
    string titulo,Autor, Genero, SO;
    archivoEntrada.open("Material.txt");

    int i=0, l=0, d=0, s=0;
    while(archivoEntrada>>idMaterial>>titulo>>clave)
    {
        if(clave=='L')
        {
            archivoEntrada>>numPag>>Autor;
            Libros[l].setIdMaterial(idMaterial);
            Libros[l].setTitulo(titulo);
            Libros[l].setNumpag(numPag);
            Libros[l].setAutor(Autor);
            Materiales[i]=&Libros[l];
            l++;
        }
        if(clave=='D')
        {
            archivoEntrada>>duracion>>Genero;
            Discos[d].setIdMaterial(idMaterial);
            Discos[d].setTitulo(titulo);
            Discos[d].setDuracion(duracion);
            Discos[d].setGenero(Genero);
            Materiales[i]=&Discos[d];
            d++;
        }
        if(clave=='S')
        {
            archivoEntrada>>Version>>SO;
            Softwares[s].setIdMaterial(idMaterial);
            Softwares[s].setTitulo(titulo);
            Softwares[s].setVersion(Version);
            Softwares[s].setSO(SO);
            Materiales[i]=&Softwares[s];
            s++;
        }
        i++;
    }

    archivoEntrada.close();
    _archivoEntrada.open("Reserva.txt");
    int x=0;
    int dd, mm, aa, idCliente;

    while(_archivoEntrada>>dd>>mm>>aa>>idMaterial>>idCliente)
    {

        Fecha a(0,0,0);
        Fecha b(dd,mm,aa);
        a=b;
        Reservaciones[x].setAa(aa);
        Reservaciones[x].setDd(dd);
        Reservaciones[x].setMm(mm);
        Reservaciones[x].setFechaReservacion(a);
        Reservaciones[x].setIdCliente(idCliente);
        Reservaciones[x].setIdMaterial(idMaterial);
        x++;
    }
    _archivoEntrada.close();
    char letra;
    bool mal=true;
    do
    {
        cout<<"\n-----MENU PRINCIPAL-----";
        cout<<"\n A CONSULTA LISTA DE MATERIALES";
        cout<<"\n B CONSULTA LISTA DE RESERVACIONES";
        cout<<"\n C CONSULTA LAS RESERVACIONES DE UN MATERIAL DADO";
        cout<<"\n D CONSULTA LAS RESERVACIONES DE UNA FECHA DADA";
        cout<<"\n E HACER UNA RESERVACION";
        cout<<"\n F TERMINAR";
        cout<<"\n-------------------------"<<endl;
        cout<<"Digita una letra"<<endl;
        cin>>letra;
        switch(letra)
        {
        case 'A':
            {
                for(int z=0; z<i; z++)
                {
                    cout<<"Material numero "<<z<<" ";
                    Materiales[z]->muestraDatos();
                    cout<<endl;
                }
            }
            break;
        case 'B':
            {
                cout<<"LISTA DE RESERVACIONES "<<endl<<endl;
                for(int z=0; z<x; z++)
                {
                    cout<<"Material numero "<<z<<endl;
                    cout<<"Fecha de reservacion "<<Reservaciones[z].getFechaReservacion()<<endl;
                    cout<<"Fecha de fin de reservacion ";
                    Fecha a;
                    a=Reservaciones[z].calculaFechaFinReserva(Materiales[z]->cantidadDiasPrestamo());
                    cout<<a<<endl;

                    cout<<"Id del material "<<Reservaciones[z].getIdMaterial()<<endl;
                    cout<<"Id del cliente "<<Reservaciones[z].getIdCliente()<<endl;
                    cout<<endl;

                }
            }
            break;
        case 'C':
            {
                cout<<"DIGITE EL ID DEL MATERIAL"<<endl;
                int id, iRes=-1, iMat;
                bool seguro=true;
                cin>>id;
                for(int z=0; z<x; z++)
                {
                    if(Reservaciones[z].getIdMaterial()==id)
                    {
                        iRes=z;
                    }
                }
                if(iRes!=-1)
                {
                    for(int z=0; z<i; z++)
                    {
                        if(Materiales[z]->getIdMaterial()==id)
                        {
                            iMat=z;
                        }
                    }
                    cout<<"El titulo del material es "<<Materiales[iMat]->getTitulo()<<endl;
                    cout<<"Fecha de reservacion "<<Reservaciones[iRes].getFechaReservacion()<<endl;
                    Fecha a;
                    a=Reservaciones[iRes].calculaFechaFinReserva(Materiales[iMat]->cantidadDiasPrestamo());
                    cout<<"Fecha de fin de reservacion ";
                    cout<<a<<endl;
                }
                else
                {
                    cout<<"DIGITE UN ID VALIDO "<<endl;
                }
            }
            break;
        case 'D':
            {
                int dia, mes, anio;
                bool _seguro=true;
                do
                {
                    cout<<"DIGITE EL DIA"<<endl;
                    cin>>dia;
                    cout<<"DIGITE EL MES"<<endl;
                    cin>>mes;
                    cout<<"DIGITE EL ANIO"<<endl;
                    cin>>anio;
                    if(dia>=1 && dia<=31)
                    {
                        if(mes>=1 && mes<=12)
                        {
                            if(anio!=0)
                            {
                                cout<<"Su fecha es valida"<<endl;
                                for(int z=0; z<x; z++)
                                {
                                    Fecha a,b;
                                    a=Reservaciones[z].calculaFechaFinReserva(Materiales[z]->cantidadDiasPrestamo());//FECHA DE TERMINACION
                                    b=Reservaciones[z].getFechaReservacion();//FECHA DE INICIO
                                    Fecha d(dia,mes,anio);//FECHA DE CONSULTA
                                    if(d>=b && d<=a)
                                    {
                                        cout<<"Material numero "<<z<<endl;
                                        cout<<"El titulo del material es "<<Materiales[z]->getTitulo()<<endl;
                                        cout<<Reservaciones[z].getFechaReservacion()<<endl;
                                        cout<<endl;
                                    }
                                }
                                _seguro=false;
                            }
                            else{
                                cout<<"Ingrese una fecha valida"<<endl;
                            }
                        }
                        else{
                            cout<<"Ingrese una fecha valida"<<endl;
                        }
                    }
                    else{
                        cout<<"Ingrese una fecha valida "<<endl;
                    }
                }while(_seguro==true);
                break;
            }
        case 'E':
            {
                int idMat, iRes=-1, iMat;
                bool _seguro=true;
                cout<<"Digite el Id del material"<<endl;
                cin>>idMat;
                for(int z=0; z<x; z++)
                {
                    if(Reservaciones[z].getIdMaterial()==idMat)
                    {
                        iRes=z;
                    }
                }
                if(iRes!=-1)
                {
                    for(int z=0; z<i; z++)
                    {
                        if(Materiales[z]->getIdMaterial()==idMat)
                        {
                            iMat=z;
                        }
                    }
                    do
                    {
                        int dia, mes, anio;
                        cout<<"DIGITE EL DIA"<<endl;
                        cin>>dia;
                        cout<<"DIGITE EL MES"<<endl;
                        cin>>mes;
                        cout<<"DIGITE EL ANIO"<<endl;
                        cin>>anio;
                        if(dia>=1 && dia<=31)
                        {
                            if(mes>=1 && mes<=12)
                            {
                                if(anio!=0)
                                {
                                    Fecha a,b;
                                    a=Reservaciones[iRes].calculaFechaFinReserva(Materiales[iMat]->cantidadDiasPrestamo());//FECHA DE TERMINACION
                                    b=Reservaciones[iRes].getFechaReservacion();//FECHA DE INICIO
                                    Fecha d(dia,mes,anio);//FECHA DE CONSULTA
                                    if(d>=b && d<=a)
                                    {
                                        cout<<"No se puede hacer la reservacion en esa fecha"<<endl;
                                    }
                                    else
                                    {
                                        int idClie;
                                        cout<<"Dame tu Id de Cliente "<<endl;
                                        cin>>idClie;
                                        Fecha a(0,0,0);
                                        Fecha b(dia,mes,anio);
                                        a=b;
                                        Reservaciones[x].setAa(anio);
                                        Reservaciones[x].setDd(dia);
                                        Reservaciones[x].setMm(mes);
                                        Reservaciones[x].setFechaReservacion(a);
                                        Reservaciones[x].setIdCliente(idClie);
                                        Reservaciones[x].setIdMaterial(idMat);
                                        //Se muestra tu reservacion
                                        cout<<"Se ha realizado tu reserva"<<endl;
                                        cout<<"Fecha de reservacion "<<Reservaciones[x].getFechaReservacion()<<endl;
                                        cout<<"Id del cliente "<<Reservaciones[x].getIdCliente()<<endl;
                                        cout<<"Id del material "<<Reservaciones[x].getIdMaterial()<<endl;
                                        x++;
                                        _seguro=false;
                                    }
                                }
                                else{
                                    cout<<"Ingrese una fecha valida"<<endl;
                                }
                            }
                            else{
                                cout<<"Ingrese una fecha valida"<<endl;
                            }
                        }
                        else{
                            cout<<"Ingrese una fecha valida "<<endl;
                        }
                    }while(_seguro==true);
                }
                else
                {
                    cout<<"Digite un ID valido"<<endl;
                }
            }
            break;
        case 'F':
            {
                ofstream archSalida;
                archSalida.open("Reserva.txt", ios::trunc);
                for(int z=0; z<x; z++)
                {
                    archSalida<<Reservaciones[z].getDd()<<" "<<Reservaciones[z].getMm()<<" "<<Reservaciones[z].getAa()<<" "<<Reservaciones[z].getIdMaterial()<<" "<<Reservaciones[z].getIdCliente()<<endl;
                }
                archSalida.close();
                exit(0);
            }
        default:
            {
                cout<<"Opcion no valida"<<endl;
            }
        }
    }while(mal==true);

    return 0;
}





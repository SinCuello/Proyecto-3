#include <iostream>
#include "Fecha.h"
#pragma once
using namespace std;

class Reserva : public Fecha
{
private:
    int idMaterial, idCliente;
    Fecha fechaReservacion;
public:
    Reserva();
    Reserva(int, int, int, int, int, Fecha);

    void setIdMaterial(int _idMaterial){idMaterial=_idMaterial;};
    int getIdMaterial(){return idMaterial;};

    void setIdCliente(int _idCliente){idCliente=_idCliente;};
    int getIdCliente(){return idCliente;};

    void setFechaReservacion(Fecha _fechaReservacion){fechaReservacion=_fechaReservacion;};
    Fecha getFechaReservacion(){return fechaReservacion;};

    Fecha calculaFechaFinReserva(int cantDias);// Falta por hacer
};

Reserva::Reserva():Fecha()
{
    idMaterial=0;
    idCliente=0;
    Fecha c(0,0,0);
    fechaReservacion=c;
}

Reserva::Reserva(int _dd, int _mm, int _aa, int _idMaterial, int _idCliente, Fecha _fechaReservacion):Fecha(_dd, _mm, _aa)
{
    idMaterial=_idMaterial;
    idCliente=_idCliente;
    fechaReservacion=_fechaReservacion;
}

Fecha Reserva::calculaFechaFinReserva(int cantDias)
{
    return fechaReservacion+cantDias;
}



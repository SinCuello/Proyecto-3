#pragma once
#include <iostream>
using namespace std;
class Fecha
{
private:
    int dd, mm, aa;
public:
    Fecha();
    Fecha(int, int, int);

    void setDd(int _dd){dd=_dd;};
    int getDd(){return dd;};

    void setMm(int _mm){mm=_mm;};
    int getMm(){return mm;};

    void setAa(int _aa){aa=_aa;};
    int getAa(){return aa;};



    void setFecha(int _dd, int _mm, int _aa){dd=_dd, mm=_mm, aa=_aa;};

    void mostrarFecha();
    string nombreMes();

    Fecha operator+(Fecha c2);
    Fecha operator+(int cantdias);

    int operator>=(Fecha c2);
    int operator<=(Fecha c2);
    int operator>(Fecha c2);
    int operator<(Fecha c2);
    int operator==(Fecha c2);

    friend ostream &operator<< (ostream &os, Fecha c2);
    friend istream &operator>> (istream &os, Fecha &c2);
};


Fecha::Fecha()
{
    dd=0;
    mm=0;
    aa=0;
}

Fecha Fecha::operator+(int cantdias)
{
    int nuevosdias=dd+cantdias;
    if( mm==4 || mm==6 || mm==9 || mm==11)//meses con 30 dias
    {
        if(nuevosdias>30)
        {
            mm++;
            nuevosdias=nuevosdias-30;
        }
    }
    if( mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12)//meses con 31 dias
    {
        if(nuevosdias>31)
        {
            mm++;
            nuevosdias=nuevosdias-31;
        }
    }
    if(mm==2)
    {
        if(nuevosdias>28)
        {
            mm++;
            nuevosdias=nuevosdias-28;
        }
    }
    return Fecha(nuevosdias,mm,aa);
}

Fecha Fecha::operator+(Fecha c2)//hacer la misma funcion con int
{
    int nuevosdias=dd+c2.dd;

    if( mm==4 || mm==6 || mm==9 || mm==11)//meses con 30 dias
    {
        if(nuevosdias>30)
        {
            mm++;
            nuevosdias=nuevosdias-30;
        }
    }
    if( mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12)//meses con 31 dias
    {
        if(nuevosdias>31)
        {
            mm++;
            nuevosdias=nuevosdias-31;
        }
    }
    if(mm==2)
    {
        if(nuevosdias>28)
        {
            mm++;
            nuevosdias=nuevosdias-28;
        }
    }
    return Fecha(nuevosdias,mm,aa);
}

int Fecha::operator>=(Fecha c2)
{
    if(aa>=c2.aa)
    {
        return 1;
    }
    if(aa>=c2.aa && mm>=c2.aa)
    {
        return 1;
    }
    if(aa>=c2.aa && mm>=c2.aa && dd>=c2.dd)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Fecha::operator<=(Fecha c2)
{
    if(aa<=c2.aa)
    {
        return 1;
    }
    if(aa<=c2.aa && mm<=c2.aa)
    {
        return 1;
    }
    if(aa<=c2.aa && mm<=c2.aa && dd<=c2.dd)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Fecha::operator>(Fecha c2)
{
    if(aa>c2.aa)
    {
        return 1;
    }
    if(aa>c2.aa && mm>c2.aa)
    {
        return 1;
    }
    if(aa>c2.aa && mm>c2.aa && dd>c2.dd)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Fecha::operator<(Fecha c2)
{
    if(aa<c2.aa)
    {
        return 1;
    }
    if(aa<c2.aa && mm<c2.aa)
    {
        return 1;
    }
    if(aa<c2.aa && mm<c2.aa && dd<c2.dd)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Fecha::operator==(Fecha c2)
{
    if(aa==c2.aa && mm==c2.aa && dd==c2.dd)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

Fecha::Fecha(int _dd, int _mm, int _aa)
{
    dd=_dd;
    mm=_mm;
    aa=_aa;
}

void Fecha::mostrarFecha()
{
    cout<<"La fecha es "<<dd<<"/"<<mm<<"/"<<aa<<endl;
}

string Fecha :: nombreMes(){
    switch ( mm )
    {
        case  1 : return "Ene" ;
                break;
        case  2 : return "Feb";
                  break;
        case  3 : return "Mar";
                  break;
        case  4 : return "Abr";
                  break;
        case  5 : return "May";
                  break;
        case  6 : return "Jun";
                  break;
        case  7 : return "Jul";
                  break;
        case  8 : return "Ago";
                  break;
        case  9 : return "Sept";
                  break;
        case 10 : return "Oct";
                  break;
        case 11 : return "Nov";
                  break;
        case 12 : return "Dic";
                  break;
        default: return "Error";
                  break;

    }
}



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

    void mostrarFecha();

    Fecha operator+(Fecha c2);
    int operator>=(Fecha c2);
    int operator<=(Fecha c2);
    int operator>(Fecha c2);
    int operator<(Fecha c2);
    int operator==(Fecha c2);

};

Fecha::Fecha()
{
    dd=0;
    mm=0;
    aa=0;
}
Fecha Fecha::operator+(Fecha c2)
{
    //Number of  days I want add is c2 "ne"
    int m2[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int k=0;// donde se storea la nueva fecha
    int p,a;
    for(int i=0; i<mm; i++)
    {
        k=k+m2[i];
        k=k+dd+c2.dd;
    }
    cout<<"Nueva fecha"<<endl;
    if(k<=365)
    {
        for(int i=0; i<13; i++)
        {
            p=k-m2[i];
            if(p<=m2[i+1])
            {
                a=i+1;break;
            }
            else
            {
              k=p;
            }
        }
        Fecha nueva(p,a,aa);
        return nueva;
    }
    else
    {
        k=k-365;
        for(int i=0; i<13;i++)
        {
            p=k-m2[i];
            if(p<=m2[i+1])
            {
                a=i+1;break;
            }
            else
            {
                k=p;
            }
            Fecha nueva(p,a,aa+1);
        }
    }
}

int Fecha::operator>=(Fecha c2)
{
    if(dd>=c2.dd && mm>=c2.mm && aa>=c2.aa)
        return 1;
    else
        return 1;
}

int Fecha::operator<=(Fecha c2)
{
    if(dd<=c2.dd && mm<=c2.mm && aa<=c2.aa)
        return 1;
    else
        return 0;
}

int Fecha::operator>(Fecha c2)
{
    if(dd>c2.dd && mm>c2.mm && aa>c2.aa)
        return 1;
    else
        return 0;
}

int Fecha::operator<(Fecha c2)
{
    if(dd<c2.dd && mm<c2.mm && aa<c2.aa)
        return 1;
    else
        return 0;
}

int Fecha::operator==(Fecha c2)
{
    if(dd==c2.dd && mm==c2.mm && aa==c2.aa)
        return 1;
    else
        return 0;
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

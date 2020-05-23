
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

    Fecha suma(Fecha c2);
};

Fecha Fecha::suma(Fecha c2)
{
    int m2[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int i,k=0,p,a;
    for(i=0; i<m i++)
    {
        k=k+m2[i];//AQUI SUMA EL SUBINDICE HASTA LLEGAR AL DIA
        k=k+dd;Aqui suma el dia
    }
}

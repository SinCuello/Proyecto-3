#include <iostream>
#include "Fecha.h"
using namespace std;

int main()
{
    Fecha hoy(9,1,2025);
    Fecha hoy2(25,1,2030);
    hoy.mostrarFecha();
    hoy2.mostrarFecha();
    if(hoy>=hoy2)
    {
        cout<<"hoy es mayor"<<endl;
    }
    else
    {
        cout<<"hoy es menor"<<endl;
    }
    return 0;
}

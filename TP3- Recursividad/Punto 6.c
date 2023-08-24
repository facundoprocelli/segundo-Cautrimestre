#include <stdio.h>
#include <stdlib.h>


/*
6. Sumar en forma recursiva los elementos de un arreglo de enteros y retornar el total de la suma.
*/

int main()
{

    int arreglo[5] = {5,5,5,5,5};

    int rta = sumarArreglo(arreglo, 5, 0);

    printf("\%i", rta);
    return 0;
}


int sumarArreglo(int arreglo[], int validos, int pos)
{
    int rta;

    if (pos == validos)// condicion de corte
    {
        rta = 0;// solucion trivial
    }
    else
    {
        rta = arreglo[pos] + sumarArreglo(arreglo, validos, pos + 1); // llamado recursivo
        // acercamiento al corte
    }

    return rta;
}

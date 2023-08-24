#include <stdio.h>
#include <stdlib.h>


/*
7. Buscar el menor elemento de un arreglo en forma recursiva.
*/

int main()
{

    int arreglo[5] = {5,4,1,7,3};

    int menor = arreglo[0];

    menor = buscarMenor(arreglo, 5, 0, menor);
    printf("\%i", menor);
    return 0;
}


int buscarMenor(int arreglo[], int validos, int pos, int menor)
{


    if (pos == validos)// condicion de corte
    {
        // Se cumple la condicion de salida por lo tnato corta la recursividad
    }

    else
    {

        if (arreglo[pos] < menor) // condicional para buscar el menor
        {
            menor = arreglo[pos]; // cambio de valor del menor
        }
        menor = buscarMenor(arreglo, validos, pos + 1, menor); // recursividad
        //  acercameinto al corte
    }

    return menor;

}

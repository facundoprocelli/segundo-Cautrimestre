#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define archivoNais "archivo.bin"

/*
12. Determinar si un arreglo contiene un determinado elemento de forma recursiva.
(Pueden intentarlo también con una función void)(Tener en cuenta para un arreglo
desordenado y el caso para un arreglo ordenado
*/

int main()
{
    char carac;
    char elemento[10] = {'w','d','l','c','g','i','u','y','t','s'};
    printf("Que caracter desea buscar: ");
    fflush(stdin);
    scanf("%c", &carac);
    buscarElemento(elemento,carac, 10, 0);

    return 0;
}


void buscarElemento(char elemento[],char carac, int validos, int i)
{

    char caracAux;

    if (i >= validos)
    {
        printf("No se encuentra el elemento en el arreglo\n");
    }
    else
    {
        if (elemento[i] == carac)
        {
            printf("La letra '%c' se encuentra en el arreglo.\n", carac);
        }
        else
        {
            buscarElemento(elemento,carac,validos, i+1);
        }

    }
}






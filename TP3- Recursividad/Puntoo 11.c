#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define archivoNais "archivo.bin"

/*
11. Ingresar valores a una variable de tipo char (por teclado)
 y mostrarlo en el orden inverso (hasta ingresar un ‘*’) de forma recursiva. NO usar arreglos.
*/

int main()
{

char carac = 'a';
    cargarLetras(carac);

    return 0;
}


void cargarLetras(char carac)
{


    if (carac == '*')
    {

    }
    else
    {
        printf("Ingrese un caracter: ");
        fflush(stdin);
        scanf("%c", &carac);
        cargarLetras(carac);



        printf("%c", carac);


    }

}






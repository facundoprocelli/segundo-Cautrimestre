#include <stdio.h>
#include <stdlib.h>


/*
4. Recorrer un arreglo comenzando desde la posición 0 y mostrar sus elementos en
forma invertida (recursivo).
*/

int main()
{

    int arreglo[5] = {1,2,3,4,5};

    mostrarArreglo(arreglo, 5, 0);

    return 0;
}


void mostrarArreglo(int arreglo[], int validos, int vuelta)
{

    int rta;

    if (validos == vuelta)  // condicion de corte
    {

    }
    else
    {

        mostrarArreglo(arreglo, validos, vuelta + 1); // llamada recursvia

        printf("\n%i", arreglo[vuelta]); // print resultados
        // Al poner la imprecion de resultados despues de la recursividad, se imprimen los resultados
        //de manera inversa
        
        //Esto se debe a que la funcion cae y cuanco cae primero se imprime el final

    }

}


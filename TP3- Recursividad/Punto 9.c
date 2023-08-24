#include <stdio.h>
#include <stdlib.h>

#define archivoNais "archivo.bin"

/*
9. Invertir los elementos de un archivo de números enteros de forma recursiva
(si no te sale, primero proba con invertir los elementos de un arreglo de int)
*/

int main()
{

    cargarArchivo();
    mostrarArchivo();
    invertirArchivo();
    printf("\n\n");
    mostrarArchivo();


    return 0;
}


void cargarArchivo()
{
    FILE *archi = fopen(archivoNais, "wb");

    int valores[] = {1, 2, 3, 4, 5};
    int numValores = sizeof(valores) / sizeof(int);

    fwrite(valores, sizeof(int), numValores, archi);

    fclose(archi);
}

void mostrarArchivo()
{
    FILE *archi = fopen(archivoNais, "rb");
    int a;

    while (fread(&a, sizeof (int), 1, archi ) > 0)
    {

        printf("\n%i", a);
    }
}


void invertirArchivoRegistros(FILE * archi, int inicio, int fin) // tengo como parametros el archivo, la posicion 0 y el ultimo elemtno 
{

    int valorInicio, valorFin; // defino variables donde alamcenar los elemtos a intercmabiar

    if (inicio > fin) // condicion de crote
    {



    }
    else
    {


        fseek(archi, inicio * sizeof(int), SEEK_SET);     // me acomodo en la  posicion incio
        fread(&valorInicio, sizeof(int), 1, archi); // Leo y alamaceno el primer valor

        fseek(archi,fin *  sizeof(int), SEEK_SET); // me acomodo en la  posicion fin
        fread(&valorFin, sizeof(int), 1, archi); // leo y almaceno el ultimo vlaor

        fseek(archi, inicio *sizeof(int), SEEK_SET); // me acomodo en la  posocion inicio
        fwrite(&valorFin, sizeof(int), 1, archi); // Escribo el vlaor fin 

        fseek(archi, fin *sizeof(int), SEEK_SET); // me caomodo en la poscion fin
        fwrite(&valorInicio, sizeof(int), 1, archi);  // escribo el valor inicio 


        fflush(stdin); // limpio todo

        invertirArchivoRegistros(archi, inicio + 1, fin - 1); // llamo a la funcion recursiva
                                        // acercamientos al corte
    }

}

// Esta funcion sirve solo para abrir el archivo


void invertirArchivo()
{
    FILE* archi = fopen(archivoNais, "rb+"); // abrimos el archivo

    fseek(archi, sizeof(int), SEEK_END); // me posiciono en el final
    int tamano = ftell(archi) / sizeof(int); // calculo el tamñao del archivo
    invertirArchivoRegistros(archi,0, tamano - 2 ); // envio la funcion 


    fclose(archi);
}

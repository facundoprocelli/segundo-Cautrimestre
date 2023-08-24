#include <stdio.h>
#include <stdlib.h>

#define archivoNais "archivo.bin"

/*
10. Recorrer un archivo y mostrar sus elementos en forma invertida de forma recursiva.
*/

int main()
{

    cargarArchivo();
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






void mostrarElementosArchvio(FILE* archi, int validos, int pos)  // decalro la funcion
{

    int dato; // aca almaceno lo que voy a escribir

    if (pos == validos)  // condicion de corte
    {


    }
    else
    {

        fseek(archi, pos * sizeof(int), SEEK_SET); // me acomodo en la posicion correspondiente
        fread(&dato, sizeof(int), 1, archi); // leo el dato
        printf("\n%i", dato); // imprimo el dato
        mostrarElementosArchvio(archi, validos, pos+1); // llamo a la recursiva
        //acercameinto al corte

    }

}

// Esta funcion sirve solo para abrir el archivo


void mostrarArchivo()
{
    FILE* archi = fopen(archivoNais, "rb"); // abrimos el archivo

    fseek(archi, sizeof(int), SEEK_END); // me posiciono en el final
    int tamano = ftell(archi) / sizeof(int); // calculo el tamñao del archivo
    mostrarElementosArchvio(archi, tamano - 1, 0);

    fclose(archi);
}

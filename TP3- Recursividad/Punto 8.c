#include <stdio.h>
#include <stdlib.h>

#define archivoNais "archivo.bin"

/*
8. Buscar el menor elemento de un archivo de números enteros de forma recursiva. (desde el mismo archivo)
*/

int main()
{

    cargarArchivo();
    mostrarArchivo();
    buscarMenorArchi();


    return 0;
}


void cargarArchivo()
{
    FILE *archi = fopen(archivoNais, "wb");

    int valores[] = {5, 3, 1, 7, 5};
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




int buscarMenorRegistro(FILE* archi)// recibe el archivo abierto
{

    int menor,i;

    if (fread(&i, sizeof(int), 1, archi) > 0) // se ejecuta simepre que no este en el final
    {
        printf("\n bsuque el menor");
        menor = buscarMenorRegistro(archi); // el menor va a ser igual al proximo valor menor


        //aca lo que hace es recorrer el archivo hasta el ultimo elemento.
        //Esto lo que hace es que se vayan comprando todos los numeros
        //sacando el menor de el total

        //una vez que cae la funcion empeizan las comparaciones
        if (menor > i)
        {
            printf("cambie el menor a %i", i);
            menor = i; // se intercambia el vlaor final
        }

    }
    else
    {
        fseek(archi,sizeof(int)*-1,2); // en caso de que ninguno de los elemtnos sea el menor
        // se mueve a la ultimo posicion para hacer que sea el menor

        //se lee el dato
        fread(&menor,sizeof(int), 1, archi);
        //se lee el dato
    }
    return menor;// se retorna
}







// Esta funcion se crea unicamente para abrir el archivo
//Porque si abrimos el archivo en la recursiva, se vana  abrir cientos de archivos

void buscarMenorArchi()
{
    FILE* archi = fopen(archivoNais, "rb"); // abrimos el archivo

    int menor = buscarMenorRegistro (archi); // llamamos a la funcion

    printf("\n\n%i", menor);


    fclose(archi);
}

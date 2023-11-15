#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARCHI_ANIMALES "animales.dat"

typedef struct
{
    char animal[30];
    int cant;
    int habitat;
    int idEspecie;
    char especie[20];
} registroArchivo;

typedef struct
{
    char nombreAnimal [30];
    int cantidad;
    int habitat;
// 1 - selva, 2- savana, 3-bosque, 4-mar
} animal;

typedef struct
{
    animal dato;
    struct nodoArbol * izq;
    struct nodoArbol * der;
} nodoArbol;

typedef struct
{
    int idEspecie;
    char especie [20];
    // "Mamiferos", "Aves"
    // "Reptiles", "Peces",”Anfibios”
    nodoArbol * arbolDeAnimales;
} celdaEspecie;


//Yo voy a sacer los datos que esten almacenados  en el archivo pero primero tengo que hacer todas las funciones de arreglo de Arbol
animal pasarDeRegistroToAnimal(registroArchivo registro);
nodoArbol* agregarNodoArbol(nodoArbol* raiz, nodoArbol* NN);
nodoArbol* crearNodoArbol(animal ani);

registroArchivo cargarRegistroArchivo(nodoArbol* raiz, int idEspecie, char especie[]);


int main()
{
    int dimension = 5;
    celdaEspecie arregloDeArboles[dimension];


    int validos = pasarDeArchivoToADA(arregloDeArboles, validos);
    //mostrarArreglo(arregloDeArboles, 5);
    // recorrerYmostrar(arregloDeArboles, validos);


    pasarDeADAToArchivo(arregloDeArboles, validos);

    mostrarArchivoEspecies();
    //mostrarArchivo();

    return 0;
}


void mostrarArchivoEspecies(celdaEspecie ADA[], int validos)
{

    FILE* archi;


    for (int i = 0; i < validos; i++)
    {


        archi = fopen(ADA[i].especie, "rb");

        printf("\n==================================================\n");
        printf("\t   Archivo de %s", ADA[i].especie);
        printf("\n==================================================\n");


        mostrarArchivoEspecieParticular(archi);

    }


}


void mostrarArchivoEspecieParticular( FILE* archi)
{

    registroArchivo aux;

    while (fread(&aux, sizeof(registroArchivo), 1, archi) > 0)
    {

        mostrarRegistroArchivo(aux);

    }
}

void pasarDeADAToArchivo(celdaEspecie ADA[], int validos)
{

    FILE * archi;

    for (int i = 0; i < validos; i++)
    {

        archi=fopen(ADA[i].especie,"wb");

        arbolToArchivo(ADA[i].arbolDeAnimales, ADA[i].idEspecie, ADA[i].especie, archi);

        fclose(archi);

    }
}

void arbolToArchivo(nodoArbol* raiz, int idEspecie, char especie[], FILE* buffer)
{



    if (raiz != NULL)
    {

        arbolToArchivo(raiz->izq, idEspecie, especie, buffer);

        registroArchivo reg = cargarRegistroArchivo(raiz, idEspecie, especie);
        fwrite(&reg, sizeof(registroArchivo), 1, buffer);

        arbolToArchivo(raiz->der, idEspecie, especie, buffer);

    }
}


registroArchivo cargarRegistroArchivo(nodoArbol* raiz, int idEspecie, char especie[])
{

    registroArchivo aux;

    aux.cant = raiz->dato.cantidad;
    aux.habitat = raiz->dato.habitat;
    aux.idEspecie = idEspecie;
    strcpy(aux.animal, raiz->dato.nombreAnimal);
    strcpy(aux.especie, especie);


    return aux;
}

void mostrarArreglo(celdaEspecie ADA[], int validos)
{

    for (int i = 0; i < validos; i++)
    {

        printf("Materia:  %s", ADA[i].especie);

    }


}

void inicArregloArbol(celdaEspecie ADA[])
{

    int dim = 5;

    char* especies[] = {"Mamiferos","Aves", "Reptiles","Peces","Anfibios"};

    for (int i = 0; i < dim; i++)
    {

        strcpy(ADA[i].especie, especies[i]);
        ADA[i].arbolDeAnimales = NULL;
        ADA[i].idEspecie = i;
    }




}
int pasarDeArchivoToADA(celdaEspecie ADA[], int dimension)
{

    FILE* archi = fopen(ARCHI_ANIMALES, "rb");

    registroArchivo aux;
    int validos = 0;
    while (fread(&aux, sizeof(registroArchivo), 1, archi) > 0 && validos < dimension)
    {

        char especie[20];
        strcpy(especie, aux.especie);


        animal ani = pasarDeRegistroToAnimal(aux);

        validos = alta(ADA, ani, especie, validos);

    }

    fclose(archi);
    return validos;
}


int alta(celdaEspecie ADA[], animal ani, char especie[], int validos)
{

    nodoArbol* NN = crearNodoArbol(ani);

    int pos = buscarPosArreglo(ADA, validos, especie);
    //Implementacion en alta

    if (pos == -1)
    {
        validos = agregarMateria(ADA, validos, especie);
        pos = validos-1;

    }


    ADA[pos].arbolDeAnimales = agregarNodoArbol(ADA[pos].arbolDeAnimales, NN);
    ADA[pos].idEspecie = pos;


    return validos;
}


nodoArbol* agregarNodoArbol(nodoArbol* raiz, nodoArbol* NN)
{

    if (raiz == NULL)
    {

        raiz = NN;
    }
    else
    {

        if (NN->dato.cantidad > raiz->dato.cantidad)
        {

            raiz->der = agregarNodoArbol(raiz->der, NN);

        }
        else
        {

            raiz->izq = agregarNodoArbol(raiz->izq, NN);
        }
    }


    return raiz;
}

int agregarMateria(celdaEspecie ADA[], int validos, char especie[])
{


    strcpy(ADA[validos].especie, especie);
    ADA[validos].arbolDeAnimales = NULL;
    validos++;

    return validos;
}

int buscarPosArreglo(celdaEspecie ADA[], int validos, char especie[])
{

    int pos = -1;

    int i = 0;

    while (i < validos && pos == -1)
    {
        if (strcmpi(ADA[i].especie, especie) == 0)
        {
            pos = i;
        }
        i++;
    }
    return pos;
}

nodoArbol* crearNodoArbol(animal ani)
{

    nodoArbol* aux = (nodoArbol*)malloc(sizeof(nodoArbol));

    aux->dato = ani;
    aux->der =NULL;
    aux->izq =NULL;


    return aux;
}

animal pasarDeRegistroToAnimal(registroArchivo registro)
{


    animal aux;

    aux.cantidad = registro.cant;
    aux.habitat = registro.habitat;
    strcpy(aux.nombreAnimal, registro.animal);


    return aux;
}


void mostrarArchivo()
{
    FILE* archi = fopen(ARCHI_ANIMALES, "rb");

    registroArchivo aux;

    while (fread(&aux, sizeof(registroArchivo),1, archi) > 0)
    {


        mostrarRegistroArchivo(aux);

    }
    fclose(archi);
}

void mostrarRegistroArchivo(registroArchivo aux)
{


    printf("\n*******************");
    printf("\n Animal..........%s", aux.animal);
    printf("\n Cantidad........%i", aux.cant);
    printf("\n Habitat.........%i", aux.habitat);
    printf("\n Id Especie......%i", aux.idEspecie);
    printf("\n Especie.........%s", aux.especie);

}

void recorrerYmostrar(celdaEspecie ADA[], int validos)
{


    for (int i = 0; i< validos; i++)
    {
        printf("\n\n*************************\n");
        printf("\n Especie.......: %s", ADA[i].especie);
        printf("\n IdEspecie.....: %i", ADA[i].idEspecie);
        printf("\n\n*************************\n");
        mostrarArbolInorder(ADA[i].arbolDeAnimales);

    }
}


void mostrarArbolInorder(nodoArbol* arbol)
{

    if(arbol != NULL)
    {


        mostrarArbolInorder(arbol->izq);
        mostrarAnimal(arbol->dato);
        mostrarArbolInorder(arbol->der);
    }


}

void mostrarAnimal(animal ani)
{


    printf("\n*****************");
    printf("\n Animal..........%s", ani.nombreAnimal);
    printf("\n Cantidad........%i", ani.cantidad);
    printf("\n Habitat.........%i", ani.habitat);

}

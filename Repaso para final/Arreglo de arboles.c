#include <stdio.h>
#include <stdlib.h>
#include "string.h"
/*
typedef struct
{
    char nombre[20];
    int edad;

} stPersona;

typedef struct
{
    stPersona persona;
    struct nodoArbol* izq;
    struct nodoArbol* der;
} nodoArbol;

typedef struct
{
    char genero[10];
    nodoArbol *raiz;
} Celda;

int cargarArregloArboles(Celda ada[], int dimension);
int alta(Celda ada[], char genero[], stPersona persona, int validos);
nodoArbol* agregarNodoArbol(nodoArbol* raiz, nodoArbol* NN);
int agregarElementoArreglo(Celda ada[], char genero[], int validos);
int agregarElementoArreglo(Celda ada[], char genero[], int validos);
int buscarPosArreglo(Celda ada[], char genero[], int validos);
nodoArbol* crearNodoArbol(stPersona per);
stPersona cargarPersona();
void mostrarPersona(stPersona aux);


int main()
{


    Celda ada[10];

    int validos = cargarArregloArboles(ada, 10);
    printf("%i", validos);

    mostrarArregloDeArbol(ada, validos);
    return 0;
}


int cargarArregloArboles(Celda ada[], int dimension)
{

    int validos = 0;
    char rta = 's';
    stPersona person;
    char genero[20];


    while (validos < dimension && rta == 's')
    {

        fflush(stdin);
        printf("ingrese el genero\n");
        gets(genero);

        person = cargarPersona();

        validos = alta(ada, genero, person, validos);

        printf("Para continuar presione 's' \n");
        fflush(stdin);
        scanf("%c", &rta);
    }

    return validos;
}


int alta(Celda ada[], char genero[], stPersona persona, int validos)
{

    nodoArbol* NN = crearNodoArbol(persona);


    int pos = buscarPosArreglo(ada, genero, validos);

    if (pos == -1)
    {
        validos = agregarElementoArreglo(ada, genero, validos);
        pos = validos -1;
    }

    ada[pos].raiz = agregarNodoArbol(ada[pos].raiz, NN);


    return validos;
}

nodoArbol* agregarNodoArbol(nodoArbol* raiz, nodoArbol* NN)
{


    if(raiz == NULL)
    {
        raiz = NN;
    }
    else if( NN->persona.edad < raiz->persona.edad )
    {
        raiz->izq = agregarNodoArbol(raiz->izq, NN);
    }
    else
    {
        raiz->der = agregarNodoArbol(raiz->der, NN);
    }

    return raiz;
}


int agregarElementoArreglo(Celda ada[], char genero[], int validos)
{


    strcpy(ada[validos].genero, genero);
    ada[validos].raiz = NULL;
    validos++;
    return validos;
}


int buscarPosArreglo(Celda ada[], char genero[], int validos)
{
    int i = 0;
    int pos = -1;


    while (i < validos && pos == -1)
    {
        if (strcmpi(ada[i].genero, genero) == 0)
        {
            pos = i;
        }
        i++;
    }

    return pos;
}

nodoArbol* crearNodoArbol(stPersona per)
{
    nodoArbol* aux = (nodoArbol*)malloc(sizeof(nodoArbol));

    aux->persona = per;
    aux->der = NULL;
    aux->izq = NULL;

    return aux;

}


stPersona cargarPersona()
{
    stPersona perso;

    printf("Ingrese el nombre\n");
    char nombre[20];
    fflush(stdin);
    gets(nombre);
    strcpy(perso.nombre, nombre);

    printf("Ingrese la edad\n");
    fflush(stdin);
    scanf("%i", &perso.edad);


    return perso;
}

void mostrarPersona(stPersona aux)
{

    printf("\n****************************************");
    printf("\nNombre..........: %s", aux.nombre);
    printf("\nEdad............: %i", aux.edad);
    printf("\n****************************************");

}


void mostrarArregloDeArbol( Celda ada[], int validos){

for (int i = 0; i < validos; i++){

    printf("\n==========================");
    printf("\n Genero.........: %s", ada[i].genero);
    printf("\n==========================");

    inorder(ada[i].raiz);

}


}

void inorder(nodoArbol* raiz){

if(raiz != NULL){

    inorder(raiz->izq);
    mostrarPersona(raiz->persona);
    inorder(raiz->der);
}

}

*/

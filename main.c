#include <stdio.h>
#include <stdlib.h>
#include "string.h"


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
    char genero[20];
    nodoArbol* raiz;
    struct Celda* sig;
} Celda;

stPersona cargarPersona();
stPersona cargarPersona();
Celda* CargarLista(Celda* lista);
Celda* alta(Celda* lista, char genero[], stPersona per);
nodoArbol* agregarNodoArbol(nodoArbol* raiz, nodoArbol* NN);
Celda* agregarElementoCelda(Celda* lista, char genero[]);
Celda* agregarFinalCelda(Celda* lista, Celda* NN);
Celda* buscarUltimoCelda(Celda* lista);
Celda* crearNodoCelda(char genero[]);
Celda* buscarPosCelda(Celda* lista, char genero[]);
nodoArbol* crearNodoArbol(stPersona per);
void mostrarPersona(stPersona aux);
void recorrerYmostrar(Celda* lista);


int main()
{

    Celda* lista = NULL;

    lista = CargarLista(lista);

    recorrerYmostrar(lista);

    return 0;
}


Celda* CargarLista(Celda* lista)
{
    char rta = 's';

    while (rta == 's')
    {

        char genero[20];
        printf("ingrese el genero\n");
        fflush(stdin);
        gets(genero);

        stPersona persona = cargarPersona();

        lista = alta(lista, genero, persona);

        printf("Para seguir presione 's'\n");
        fflush(stdin);
        scanf("%c", &rta);
    }

    return lista;
}


Celda* alta(Celda* lista, char genero[], stPersona per)
{

    nodoArbol* NN = crearNodoArbol(per);

    Celda* pos = buscarPosCelda(lista, genero);

    if(pos == NULL)
    {
        lista = agregarElementoCelda(lista, genero);
        pos = buscarUltimoCelda(lista);
    }

    pos->raiz = agregarNodoArbol(pos->raiz, NN);
    inorder(pos->raiz);

    return lista;
}


nodoArbol* agregarNodoArbol(nodoArbol* raiz, nodoArbol* NN)
{

    if(raiz == NULL)
    {
        raiz = NN;
    }

    else if(NN->persona.edad < raiz->persona.edad)
        raiz->izq = agregarNodoArbol(raiz->izq, NN);
    else
        raiz->der = agregarNodoArbol(raiz->der, NN);

    return raiz;
}


Celda* agregarElementoCelda(Celda* lista, char genero[])
{

    Celda* aux = crearNodoCelda(genero);

    lista = agregarFinalCelda(lista, aux);

    return lista;

}

Celda* agregarFinalCelda(Celda* lista, Celda* NN)
{


    if (lista == NULL)
        lista = NN;

    else
    {
        Celda* ultimo = buscarUltimoCelda(lista);

        ultimo->sig = NN;
    }

    return lista;


}

Celda* buscarUltimoCelda(Celda* lista)
{
    Celda* aux = lista;
    while (aux->sig != NULL)
    {
        aux = aux->sig;
    }

    return aux;

}

Celda* crearNodoCelda(char genero[])
{

    Celda* NN = (Celda*)malloc(sizeof(Celda));

    strcpy(NN->genero, genero);
    NN->raiz = NULL;
    NN->sig = NULL;

    return NN;
}


Celda* buscarPosCelda(Celda* lista, char genero[])
{
    Celda* pos = NULL;

    while (pos == NULL && lista != NULL)
    {
        if(strcmpi(lista->genero, genero) == 0)
            pos = lista;

        lista = lista->sig;
    }


    return pos;
}


nodoArbol* crearNodoArbol(stPersona per)
{

    nodoArbol* aux = (nodoArbol*)malloc(sizeof(nodoArbol));

    aux->der = NULL;
    aux->izq = NULL;
    aux->persona = per;


    return aux;
}


stPersona cargarPersona()
{
    stPersona perso;

    printf("Ingrese el nombre\n");
    fflush(stdin);
    char nombre[20];
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
void inorder(nodoArbol* raiz)
{

    if(raiz != NULL)
    {
        inorder(raiz->izq);
        mostrarPersona(raiz->persona);
        inorder(raiz->der);
    }
}


void recorrerYmostrar(Celda* lista)
{

    while (lista != NULL)
    {

        printf("\nGenero.....: %s", lista->genero);
        lista = lista->sig;

    }


}

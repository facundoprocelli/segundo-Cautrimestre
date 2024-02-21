#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct
{
    int dato;
    struct nodo* sig;
} nodo;

typedef struct
{
    nodo* tope;
} Pila;


nodo* agregarPpio(nodo* lista, nodo* NN);
nodo* crearNodo(int dato);
nodo* borrarPrimerNodo(nodo* lista);


int main()
{
    Pila pilita;

    inicPila(&pilita);
    apilar(&pilita, 5);
    apilar(&pilita, 6);
    apilar(&pilita, 7);

    mostrar(&pilita);

    desapilar(&pilita);

    mostrar(&pilita);
    return 0;
}

void inicPila(Pila* pilita)
{
    pilita->tope = NULL;
}

void apilar(Pila* pilita, int dato)
{

    nodo* aux = crearNodo(dato);
    pilita->tope = agregarPpio(pilita->tope, aux);


}


nodo* crearNodo(int dato)
{
    nodo* aux = (nodo*)malloc(sizeof(nodo));
    aux->dato = dato;
    aux->sig = NULL;
    return aux;
}


nodo* agregarPpio(nodo* lista, nodo* NN)
{

    if(lista == NULL)
    {
        lista = NN;
    }
    else
    {
        NN->sig = lista;
        lista = NN;
    }

    return lista;
}


void mostrar(Pila* pilita)
{
    recorrerYmostrar(pilita->tope);
}


void recorrerYmostrar(nodo* lista)
{
    nodo* aux = lista;
    puts("\nTope..........................Fin");
    while (aux != NULL)
    {
        printf("[%i]", aux->dato);
        aux = aux->sig;
    }
    puts("\nTope..........................Fin\n");
}


void desapilar(Pila* pilita)
{
    pilita->tope = borrarPrimerNodo(pilita->tope);
}

nodo* borrarPrimerNodo(nodo* lista)
{

    if(lista)
    {
        nodo* aux = lista;
        lista = lista->sig;
        free(aux);
    }

    return lista;
}



#include <stdio.h>
#include <stdlib.h>
#include "string.h"


//agregar
//Extraer
//inicFila
// mostrar
// vaciar



typedef struct
{
    int dato;
    struct nodo* sig;
    struct nodo* ante;

}nodo2;


typedef struct
{
    nodo2* inicio;
    nodo2* fin;
}Fila;

nodo2* iniclista();
nodo2* agregarFinalFila(nodo2* ultimo, nodo2* NN);
nodo2* crearNodo2(int dato);
nodo2* borrarPrimerNodo(nodo2* lista);
void inicFila(Fila* filita);
void agregar(Fila* filita, int dato);
void recorrerYmostrar(nodo2* lista);
int vaciar(Fila** filita);
void extraer(Fila* filita);




int main()
{

    Fila* filita;
    inicFila(&filita);

    agregar(&filita, 5);
    agregar(&filita, 12);
    agregar(&filita, 32);
    agregar(&filita, 43);

    mostrar(&filita);

    extraer(&filita);

    mostrar(&filita);

    int cantidad = vaciar(&filita);

    printf("\n [%i]", cantidad);
    return 0;
}

nodo2* iniclista2()
{
    return NULL;
}


void inicFila(Fila* filita)
{
    filita->inicio= iniclista2();
    filita->fin = iniclista2();
}


void agregar(Fila* filita, int dato)
{
    nodo2* NN = crearNodo2(dato);


    filita->fin = agregarFinalFila(filita->fin, NN);

    if(!filita->inicio)
    {
        filita->inicio = filita->fin;
    }
}

nodo2* agregarFinalFila(nodo2* ultimo, nodo2* NN)
{
    if (!ultimo)
    {
        ultimo = NN;
    }
    else
    {
        ultimo->sig = NN;
        NN->ante = ultimo;
        ultimo = NN;
    }

    return ultimo;
}


nodo2* crearNodo2(int dato)
{
    nodo2* aux = (nodo2*)malloc(sizeof(nodo2));
    aux->ante = NULL;
    aux->sig= NULL;
    aux->dato = dato;

    return aux;

}

void mostrar(Fila* filita)
{
    recorrerYmostrar(filita->inicio);
}


void recorrerYmostrar(nodo2* lista)
{
    nodo2* aux = lista;

    while (aux)
    {
        printf("[%i]", aux->dato);
        aux= aux->sig;
    }
}

void extraer(Fila* filita)
{

    if(filita->inicio)
    {
        filita->inicio = borrarPrimerNodo(filita->inicio);
    }
    if(!filita->inicio)
    {
        filita->fin = filita->inicio;
    }

}

nodo2* borrarPrimerNodo(nodo2* lista)
{

    if(lista)
    {
        nodo2* aux = lista;
        lista = lista->sig;
        free(aux);
    }

    return lista;
}


int vaciar(Fila** filita)
{
    int i = 0;
    while (*filita)
    {
        extraer(filita);
        i++;
    }

    return i;
}


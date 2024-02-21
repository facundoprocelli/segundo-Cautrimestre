#include <stdio.h>
#include <stdlib.h>
#include "string.h"


int main()
{
    return 0;
}


nodo* borrarNodo(nodo* lista, int dato)
{
    int i = 0;
    if(lista)
    {
        if (lista->dato == dato)
        {
            nodo* aux = lista;
            lista = lista->sig;
            free(aux);
            int i = 1;
        }
        if(i == 0)
            lista = borrarNodo(lista->sig, dato);
    }

    return lista;
}


nodo2* borrarNodo2(nodo2* lista, int dato)
{

    int i = NULL;
    if(lista)
    {
        if(lista->dato == dato)
        {
            nodo2* aux = lista;
            lista = lista->sig;

            if(lista)
                lista->ante = NULL;

            free(aux);
            i = 1;
        }

        if (!i)
            lista = borrarNodo2(lista->sig, dato);
    }
    return lista;
}





nodoArbol* borrarNodoArbol(nodoArbol* raiz, int dato)
{

    if (raiz)
    {
        if (raiz->dato == dato)
        {
            if (raiz->izq)
            {
                nodoArbol* masDer = NMD(raiz->izq);
                raiz->dato = masDer->dato;
               raiz->izq = borrarNodoArbol(raiz->izq, masDer->dato);
            }
            else if(raiz->der)
            {
                nodoArbol* masIzq = NMI(raiz->der);
                raiz->dato = masIzq->dato;
                raiz->der = borrarNodoArbol(raiz->der, masIzq->dato)
            }
            else
            {
                free(raiz);
                raiz = NULL;
            }
        }
        else if(dato < raiz->dato)
        {
            raiz->izq = borrarNodoArbol(raiz->izq, dato);
        }
        else
        {
            raiz->der = borrarNodoArbol(raiz->der, dato);
        }
    }
    return raiz;
}


void extraerFila(Fila* filita)
{

    if(filita->inicio)
    {
        filita->inicio = borrarPrimerNodo(filita->inicio)
    }
    if(!filita->inicio)
    {
        filita->fin = filita->incio;
    }
}

nodo2* borrarPrimerNodo(nodo2* lista)
{
    if(lista)
    {
        nodo2* aux = lista;
        lista = lista->sig;

        if(lista)
        {
            lista->ante = NULL;
        }
        free(aux);
    }
    return lista;
}

int vaciar(Fila** filita)
{
    int i = 0;
    while (*filita)
    {
        extraerFila(filita);
        i++;
    }

    return i;
}


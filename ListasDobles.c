#include <stdio.h>
#include <stdlib.h>
#include "ListasDobles.h"


/*
nodo2* iniclista2()
{
    return NULL;
}



nodo2* crearNodo2(int dato)
{
    nodo2* aux = (nodo2*)malloc(sizeof(nodo2));
    aux->dato = dato;
    aux->ante = iniclista2();
    aux->sig = iniclista2();

    return aux;
}



nodo2* agregarPpio2 (nodo2* lista, nodo2* NN)
{

    NN->sig = lista;

    if(lista != NULL)
    {

        lista->ante = NN;
    }
    return NN;
}

nodo2* agregarOrdenado2(nodo2* lista, nodo2* NN)
{
    if(lista == NULL)
    {
        lista == NN;
    }

    else
    {

        nodo2* seg = iniclista2();
        nodo2* anterior = iniclista2();

        while ((seg != NULL) && (seg->dato < NN->dato))
        {
            anterior = seg;
            seg = seg->sig;
        }

        NN->sig = seg;
        NN->ante = anterior;

        anterior->sig = NN;


        if( seg != NULL)
        {

            seg->ante = NN;
        }
    }

    return lista;
}

nodo2* buscarUltimo2(nodo2* lista)
{
    nodo2* seg = lista;

    if(seg != NULL)
    {

        while (seg->sig != NULL)
        {
            seg = seg->sig;
        }

    }
    return seg;
}

nodo2* agregarAlFinal2(nodo2* lista, nodo2* NN)
{

    if (lista == NULL)
    {
        lista = NN;
    }

    else
    {

        nodo2* ultimo = buscarUltimo2(lista);

        NN->ante = ultimo;
        ultimo->sig = NN;
    }



    return lista;
}




void mostrarListaRecursivaInversa2(nodo2* lista)
{


    nodo2* aux = lista;

    while (aux->sig != NULL)
    {


        aux = aux->sig;
    }

    mostrarListaRecursivaInversa2auxiliar(aux);

}

void mostrarListaRecursivaInversa2auxiliar(nodo2* aux)
{


    if(aux != NULL)
    {
        printf("[%i]->", aux->dato);
        mostrarListaRecursivaInversa2auxiliar(aux->ante);
    }


}





nodo2* borrarNodo2(nodo2* lista, int dato)
{

    if(lista != NULL)
    {
        if(lista->dato == dato)
        {

            nodo2* aux = lista;

            lista = lista->sig;

            if(lista != NULL)
            {
                lista->ante = iniclista2();
            }
            free(aux);
        }
    }

    else
    {
        nodo2* seg = lista;

        while ((seg != NULL )&& (seg->dato < dato))
        {

            seg = seg->sig;
        }

        if ( seg != NULL)
        {
            nodo2* ante = seg->ante;

            ante->sig = seg->sig;

            if(seg->sig)
            {
                nodo2* sig = seg->sig;
                sig->ante = ante;
            }

            free(seg);
        }
    }
}



nodo2* borrarNodo2Recursivo(nodo2* lista, int dato)
{
    if(lista != NULL)
    {
        if(lista->dato == dato)
        {
            nodo2* aux = lista;
            lista = lista->sig;

            if(lista != NULL)
            {
                lista->ante = NULL;
            }
            free(aux);
        }
        else
        {
            lista->sig = borrarNodo2Recursivo(lista->sig, dato);

            if(lista->sig != NULL)
            {
                nodo2* seg = lista->sig;
                seg->ante = lista;
            }
        }
    }
    return lista;
}

nodo2* agregarOrdenadoRecursivo2(nodo2* lista, nodo2* NN)
{
    if (lista != NULL)
    {
        if (lista->dato > NN->dato)
        {
           lista = agregarPpio2(lista, NN);
        }
        else
        {
            lista ->sig = agregarOrdenadoRecursivo2(lista->sig, NN);
            if(lista->sig != NULL)
            {
                nodo2* ste = lista->sig;
                ste->ante = lista;

            }

        }
    }
    else
        lista = NN;

    return lista;
}


*/

#include <stdio.h>
#include <stdlib.h>

#include "string.h"
#include "Arboles.h"


nodoArbol* inicarbol()
{
    return NULL;
}



void mostrarNodo(nodoArbol* raiz)
{

    printf("---\n");

    printf("Legajo: %i\n", raiz->dato.legajo);
    printf("Nombre: %s\n", raiz->dato.nombre);
    printf("Edad: %i\n", raiz->dato.edad);

}
/*
nodoArbol* buscarNodo(nodoArbol* arbol, int dato)
{

    nodoArbol* rta = inicarbol();
    if (arbol != NULL)
    {
        if (dato  ==  arbol->dato)
        {
            rta = arbol;
        }
        else
        {

            if(dato > arbol->dato)
            {
                // primer acercamiento al corte
                rta = buscarNodo(arbol->der, dato);
            }
            else
            {
                // segundo acercamiento al corte
                rta = buscarNodo(arbol->izq, dato);
            }
        }
    }
    return rta;
}

*/
/*
nodoArbol* insertarNodo(nodoArbol* raiz, nodoArbol* NN)
{

    if(raiz == NULL)
    {
        raiz = NN;
    }

    else
    {

        if(NN->dato > raiz->dato)
        {
            // Pongo ese = ya que el dato se va a linkear a esa parte
            raiz->der = insertarNodo(raiz->der, NN);
        }
        else
        {
            // Pongo ese = ya que el dato se va a linkear a esa parte
            raiz->izq = insertarNodo(raiz->izq, NN);
        }
    }

    return raiz;
}

*/



int cantidadNodosHoja(nodoArbol * raiz)
{

    int rta = 0;

    if (raiz != NULL)
    {

        if (raiz->izq == NULL && raiz->der == NULL)
        {
            rta = 1;
        }



        rta += cantidadNodosHoja(raiz->izq) + cantidadNodosHoja(raiz->der);
    }
    return  rta;

}



int cantidadNodosGradoUno(nodoArbol* raiz)
{


    int rta = 0;

    if(raiz != NULL)
    {

        if ((raiz->izq == NULL && raiz->der != NULL) || (raiz->izq != NULL && raiz->der == NULL))
        {

            rta = 1;
        }

        rta += cantidadNodosGradoUno(raiz->izq) + cantidadNodosGradoUno(raiz->der);
    }


    return rta;
}

/*

int calcularAltura(nodoArbol* raiz)
{

int rtaI = 0;
int rtaD = 0;

    if (raiz != NULL)
    {


       int rtaI = calcularAltura(raiz->izq);
       int rtaD = calcularAltura(raiz->der);


     return  (rtaI > rtaD) ? (rtaI + 1) : (rtaD + 1);
    }
}
*/


/*

/// Borrar un nodo

nodoArbol* borrarNodo(nodoArbol* raiz, int dato)
{
    if(raiz != NULL)
    {

        if(raiz->dato == dato)
        {

            if(raiz->izq != NULL)
            {

                nodoArbol* masDerecha = nodoMasDerecho(raiz->izq);
                raiz->dato = masDerecha->dato;
                raiz->izq = borrarNodo(raiz->izq, masDerecha->dato);
            }
            else if(raiz->der != NULL)
            {
                nodoArbol* masIzquierda = nodoMasIzquierdo(raiz->der);
                raiz->dato = masIzquierda->dato;
                raiz->der = borrarNodo(raiz->der, masIzquierda->dato);

            }

            if (esHoja(raiz) == 1)
            {
                free(raiz);
                raiz = NULL;
            }

        }
        else if(dato < raiz->dato)
        {
            raiz->izq =  borrarNodo(raiz->izq, dato);
        }

        else
        {
            raiz->der = borrarNodo(raiz->der, dato);

        }
    }

    return raiz;
}



int esHoja(nodoArbol* raiz)
{

    if(raiz->der == NULL && raiz->izq == NULL)
    {

        return 1;
    }
    else
    {
        return 0;
    }

}




nodoArbol* nodoMasDerecha(nodoArbol* raiz){

if(raiz->der != NULL)
    {
     raiz = nodoMasDerecha(nodoArbol* raiz->der);
    }

return raiz;
}


nodoArbol* nodoMasIzquierda(nodoArbol* raiz){

if(raiz->izq != NULL)
    {
     raiz = nodoMasIzquierda(nodoArbol* raiz->izq);
    }

return raiz;
}

*/





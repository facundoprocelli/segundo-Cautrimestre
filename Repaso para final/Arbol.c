#include <stdio.h>
#include <stdlib.h>

/**

estructura
inicArbol
crearNodoArbol
insertarNodoArbol
buscarNodoArbol
mostrarNodoArbol
borrarNodoArol
NMI
MND

**/

/// Todo lo necesario para el manejo de los arboles

// Estructura
/*
typedef struct
{

    int dato;

    struct nodoArbol* izq;
    struct nodoArbol* der;

} nodoArbol;




nodoArbol* inicArbol()
{
    return NULL;
}


nodoArbol* crearNodoArbol(int dato)
{
    nodoArbol* raiz = (nodoArbol*)malloc(sizeof(nodoArbol));
    raiz->dato = dato;
    raiz->der = inicArbol();
    raiz->izq = inicArbol();


    return raiz;
}

nodoArbol* insertarNodoArbol(nodoArbol* raiz, nodoArbol* NN)
{

    if (raiz == NULL)
    {

        raiz = NN;
    }
    else
    {
        if (NN->dato > raiz->dato)
        {
            raiz->der = insertarNodoArbol(raiz->der, NN);
        }
        else
        {
            raiz->izq= insertarNodoArbol(raiz->izq, NN);
        }
    }


    return raiz;
}

nodoArbol* buscarNodo(nodoArbol* raiz, int dato)
{
    nodoArbol* rta = inicArbol();

    if(raiz != NULL)
    {
        if(raiz->dato == dato)
        {
            rta = raiz;
        }
        else
        {
            if(raiz->dato > dato)
            {
                buscarNodo(raiz->izq, dato);

            }
            else
            {
                buscarNodo(raiz->der, dato);
            }
        }
    }
    return rta;
}


void mostrarArbol(nodoArbol* raiz)
{

    if(raiz != NULL)
    {
        printf("    %i    ", raiz->dato);
    }
}


void preorder(nodoArbol*raiz)
{

    if(raiz != NULL)
    {
        mostrarArbol(raiz);
        preorder(raiz->izq);
        preorder(raiz->der);

    }
}

void inorder(nodoArbol* raiz)
{

    if(raiz != NULL)
    {
        inorder(raiz->izq);
        mostrarArbol(raiz);
        inorder(raiz->der);
    }
}


void postorder(nodoArbol* raiz)
{

    if ( raiz != NULL)
    {

        postorder(raiz->izq);
        postorder(raiz->der);
        mostrarArbol(raiz);
    }
}

nodoArbol* NMD(nodoArbol* raiz)
{

    if(raiz->der != NULL)
    {
        raiz = NMD(raiz->der);
    }

    return raiz;

}

nodoArbol* NMI(nodoArbol* raiz)
{

    if(raiz->izq != NULL)
    {
        raiz = NMI(raiz->izq);
    }

    return raiz;
}


nodoArbol* borrar (nodoArbol* raiz, int dato)
{
    if (raiz != NULL)
    {
        if(dato == raiz->dato)
        {
            if(raiz->izq != NULL)
            {
                nodoArbol* masDer = NMD(raiz->izq);
                raiz->dato = masDer->dato;
                raiz->izq = borrar(raiz->izq, masDer->dato);
            }
            else if(raiz->der != NULL)
            {
                nodoArbol* masIzq = NMI(raiz->der);
                raiz->dato = masIzq->dato;
                raiz->der = borrar(raiz->der, masIzq->dato);
            }
            else
            {
                free(raiz);
                raiz = NULL;
            }
        }
        else if(dato > raiz->dato)
        {
            raiz->der = borrar(raiz->der, dato);
        }
        else
        {
            raiz->izq = borrar(raiz->izq, dato);
        }
    }

    return raiz;
}


int contarNodosHoja(nodoArbol* raiz)
{
    int rta = 0;

    if (raiz != NULL)
    {

        if (raiz->izq == NULL && raiz->der == NULL)
        {
            rta = 1;
        }

        rta += contarNodosHoja(raiz->izq) + contarNodosHoja(raiz->der);
    }

    return rta;
}

int contarNodosGradoUno(nodoArbol* raiz)
{
    int rta = 0;

    if (raiz != NULL)
    {
        if((raiz->izq != NULL && raiz->der == NULL) ||  (raiz->izq == NULL && raiz->der != NULL))
        {
            rta = 1;
        }

        rta += contarNodosGradoUno(raiz->izq) + contarNodosGradoUno(raiz->der);
    }

    return rta;
}
*/





#include <stdio.h>
#include <stdlib.h>



typedef struct
{

    int dato;
    struct nodoArbol * izq;
    struct nodoArbol * der;
} nodoArbol;

nodoArbol* inicarbol();
nodoArbol* crearNodoArbol(int dato);
nodoArbol* buscarNodo(nodoArbol* raiz, int dato);
nodoArbol* insertarNodo(nodoArbol* raiz, nodoArbol* NN);


int main()
{

    int a[9] = {8,3,1,6,4,7,10,14,13};
    nodoArbol* arbol = inicarbol();

    for(int i=0; i < 9; i++)
    {
        nodoArbol* NN = crearNodoArbol(a[i]);
        arbol = insertarNodo(arbol, NN);

    }

    printf("preorden\n");
    preorden(arbol);

    printf("\n\n");
    printf("postOrden\n");
    postorder(arbol);

    printf("\n\n");
    printf("inorden\n");
    inorder(arbol);

/*
        printf("\nQue elemento desea buscar?");
        int op;
        scanf("%i", &op);

        nodoArbol* aux = buscarNodo(arbol, op);
        mostrarNodo(aux);
*/

    /*
    int cantidad = cantidadNodosHoja(arbol);
    printf("\n\n cantidad %i", cantidad);
    */


    int cantodad = cantidadNodosGradoUno(arbol);
    printf("\n\n cantidad %i", cantodad);


}


/// Inicar un arbol
nodoArbol* inicarbol()
{
    return NULL;
}


///Crear el nodo del arbol





nodoArbol* crearNodoArbol(int dato)
{

    nodoArbol* aux = (nodoArbol*)malloc(sizeof(nodoArbol));

    aux->dato = dato;
    aux->izq = inicarbol();
    aux->der = inicarbol();


    return aux;
}


///Buscar un nodo en un arbol

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



/// Insertar un nodo en un arbol


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


void mostrarNodo(nodoArbol* raiz)
{

    if (raiz != NULL)
    {

        printf("    %i    ", raiz->dato);

    }
}

void preorden(nodoArbol* raiz)
{

    if(raiz!= NULL)
    {

        mostrarNodo(raiz);
        preorden(raiz->izq);
        preorden(raiz->der);
    }
}


void inorder(nodoArbol* raiz)
{

    if(raiz != NULL)
    {

        inorder(raiz->izq);
        mostrarNodo(raiz);
        inorder(raiz->der);
    }

}

void postorder(nodoArbol* raiz)
{

    if(raiz != NULL)
    {

        postorder(raiz->izq);
        postorder(raiz->der);
        mostrarNodo(raiz);
    }
}



/** Punto 1

a- preorden

8-3-1-6-4-7-10-14-13

inorden

3-1-6-4-7-8-10-14-13

posorden

3-1-6-4-7-10-14-13-8



B-

Nivel 0 : 8
Nivel 1 : 3- 10
Nivel 2 : 1 - 6- 14
Nivel 3 : 4 - 7- 13

Altura 1 : 8
Altura 2 :3-10
Altura 3 : 1-6-14
Altura 4 : 4- 7- 13

**/


/// Desarrollar Funciones
//Punto 2;


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



int cantidadNodosGradoUno(nodoArbol* raiz){


int rta = 0;

if(raiz != NULL){

    if ((raiz->izq == NULL && raiz->der != NULL) || (raiz->izq != NULL && raiz->der == NULL)){

        rta = 1;
    }

    rta += cantidadNodosGradoUno(raiz->izq) + cantidadNodosGradoUno(raiz->der);
}


return rta;
}







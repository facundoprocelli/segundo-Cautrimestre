#include <stdio.h>
#include <stdlib.h>

/// Un arbol es una lista de nodos que en lugar de tener dos enlaces al siguiente y al anteiror,
/// tiene un nodo a su izuqierda y a su derecha.

///Como se ordena un arbol


/**
La información la vamos a ordenar con un criterio :
                        -En el lado izquierdo van los datos menores al arbol.
                        -En el lado derecho van los datos mayores al arbol.



            (10)
       --------------
    (8)             (15)
  -------          -------
(5)   (NULL)   (NULL)    (NULL)

**/

//La forma de recorrida de arboles no puede ser secuencial, tiene que ser recursiva.

// Todas las funciones van a ser recursivas

/**
/// ARBOLES BINARIOS

    - El arbol binario esta Vacio si no tiene ningun elemento
    - Se denomina arbol binario al tipo de arbol que contiene un nodos raiz y dos nodos
        que aprten del él, llamamos Nodo izquierdo y nodo Derecho ( que tambien son arboles).
    -Un arbol binario es un arbol en el que ningun nodo puede tener más de dos súbarboles.
    - En un arbol binario, cada nodo puede tener 0,1 o 2 hijos.
    - El arbol binario binario completo, es una arbol lleno, completo y balanceado.

/// Cosas a tener en cuenta

- Nodo raiz absoluta ( main)
- Nodo raiz:
Es aquel que tiene hijos pero no padre
- Nodo Rama:
Es aquel que tiene padre e hijos.
- Nodo hoja:
Tiene padre pero no hijos.
- Nivel:
Aumenta cuando se aleja de la raiz, el nivel de la raiz es 0 ( No cuenta la raiz)
- Altura:
Parte desde la raiz ( Cuenta la raiz);
- Grado:
Es la cantidad de descendientes de cada nodo.




1 Cargar un arbol
2 mostrar el arbol X3
3 buscar un elemento
*/

///   Estructura

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

    int a[10] = {1,6,9,3,5,12,2,90,34};
    nodoArbol* arbol = inicarbol();

    for(int i=0; i < 10; i++)
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


    printf("\nQue elemento desea buscar?");
    int op;
    scanf("%i", &op);

    nodoArbol* aux = buscarNodo(arbol, op);
    mostrarNodo(aux);

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

/*
/// MOSTRAR ARBOLES

// existen tres algoritmos par amostrar un arbol

-Preorden = 10 - 5 - 15
-Inorden = 5 - 10 - 15
-Postorden = 5 - 15 - 10

/*

            (10)
        -----------
    (5)            (15)

*/



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

        preorden(raiz->izq);
        mostrarNodo(raiz);
        preorden(raiz->der);
    }

}

void postorder(nodoArbol* raiz)
{

    if(raiz != NULL)
    {

        preorden(raiz->izq);
        preorden(raiz->der);
        mostrarNodo(raiz);
    }
}



//va  apreguntar como es la logica de cada una, como es que se dibuja pre, in y post order

// El arbol sirve solo para buscar cuando el criterio de busqueda es el mismoo que con el que se organiza el arbol













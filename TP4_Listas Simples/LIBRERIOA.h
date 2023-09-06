#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED


typedef struct
{
    int edad;
    char nombre[20];
    struct nodo* siguiente;
} nodo;

//Iniciar una lista
nodo* inicLista();

//       AGREGAR NODOS
//-------------------------------------------------------------------------
//agregar nodo al principio

nodo* agregarPpio ( nodo* lista, nodo* nuevoNodo);

// Agregar nodo ordenado

nodo * agregarOrdenado(nodo* lista, nodo* nuevoNodo);

// Agregar Nodo al Final
nodo * agregarFinal(nodo* lista, nodo* nuevoNodo);

//-------------------------------------------------------------------------


//       MOSTRAR NODOS
//-------------------------------------------------------------------------
// Mostrar lista no recursiva

void mostrarLista(nodo* lista);

//Mostrar Lista de forma recursiva

void mostrarListaRecursiva(nodo* lista);

//-------------------------------------------------------------------------



//         BUSCAR NODOS
//-------------------------------------------------------------------------
//Buscar Ultimo Nodo
nodo * buscarUltimo(nodo* lista);


//-------------------------------------------------------------------------



//       BORAR NODOs
//-------------------------------------------------------------------------
// Borrar un Nodo con Int

nodo * borrarNodo(nodo* lista, int dato);

//-------------------------------------------------------------------------

#endif // LIB_H_INCLUDED

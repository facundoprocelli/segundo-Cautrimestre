#ifndef LIB2_H_INCLUDED
#define LIB2_H_INCLUDED






// Declarar estructura

typedef struct
{
//info
    int dato;
    struct nodo2* sig;
    struct nodo2* ante;

} nodo2;



// Inciializar lista

nodo2* iniclista2();

// Crear Nodo

nodo2 * crearNodo(int dato);

// Agregar al principio

nodo2* agregarPpio2(nodo2* lista, nodo2* NN);

// Agreagr En orden

nodo2* agregarEnOrden(nodo2* lista, nodo2* NN);

// Agregar al final

nodo2* agregarFinal(nodo2* lista, nodo2* NN);

// Mostrar Lista

void mostrarLista(nodo2* lista);

//Mostrar Nodo

void mostrarNodo(nodo2* lista);

// Mostrar Nodo inverso

void mostrarListaInversa(nodo2* lista);

// Buscar Ultimo

nodo2* buscarUltimo ( nodo2* lista);

//Borrar Nodo

nodo2 * borrarNodo(nodo2* lista, int dato);



#endif // LIB2_H_INCLUDED

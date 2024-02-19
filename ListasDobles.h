#ifndef LISTASDOBLES_H_INCLUDED
#define LISTASDOBLES_H_INCLUDED


typedef struct
{
    int dato;
    struct nodo2* ante;
    struct nodo2* sig;
} nodo2;

nodo2* iniclista2();
nodo2* crearNodo2(int dato);
nodo2* agregarPpio2(nodo2* lista, nodo2* NN);
nodo2* agregarOrdenado2(nodo2* lista, nodo2* NN);
nodo2* buscarUltimo2(nodo2* lista);
nodo2* agregarAlFinal2(nodo2* lista, nodo2* NN);
void mostrarListaRecursivaInversa2(nodo2* lista);
void mostrarListaRecursivaInversa2auxiliar(nodo2* aux);
nodo2* borrarNodo2(nodo2* lista, int dato);
nodo2* borrarNodo2Recursivo(nodo2* lista, int dato);
nodo2* agregarOrdenadoRecursivo2(nodo2* lista, nodo2* NN);


#endif // LISTASDOBLES_H_INCLUDED

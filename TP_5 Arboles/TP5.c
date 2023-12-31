#include <stdio.h>
#include <stdlib.h>
#include "Arboles.h"

typedef struct
{

    persona dato;
    struct nodo* sig;


} nodo;

nodo* iniclista();
nodo* crearNodo(persona per);
nodo* agregarPpio(nodo* lista, nodo* NN);
nodo* copiarLista( nodoArbol* raiz,  nodo* lista);

nodoArbol* buscarLegajo(nodoArbol* raiz, int legajoBuscado);
nodoArbol* buscarNombre(nodoArbol* raiz, char nombre[]);

nodoArbol* borrarNodo(nodoArbol* raiz, int dato);
nodoArbol* nodoMasIzquierda(nodoArbol* raiz);
nodoArbol* nodoMasDerecha(nodoArbol* raiz);





int main()
{


    nodoArbol* arbol = inicarbol();

    persona per1 = cargarPersona(10, "facu", 20);
    persona per2= cargarPersona(15, "juan", 19);
    persona per3= cargarPersona(6, "Santi", 22);
    persona per4= cargarPersona(13, "lucas", 56);
    persona per5= cargarPersona(3, "emma", 21);
    persona per6= cargarPersona(7, "gonza", 23);
    persona per7= cargarPersona(17, "juli", 31);
    persona per8= cargarPersona(19, "shuli", 31);
    persona per9= cargarPersona(16, "shuli", 31);

    nodoArbol* NN1 = cargarNodo(per1);
    nodoArbol* NN2 = cargarNodo(per2);
    nodoArbol* NN3= cargarNodo(per3);
    nodoArbol* NN4 = cargarNodo(per4);
    nodoArbol* NN5= cargarNodo(per5);
    nodoArbol* NN6= cargarNodo(per6);
    nodoArbol* NN7= cargarNodo(per7);
    nodoArbol* NN8= cargarNodo(per8);
    nodoArbol* NN9= cargarNodo(per9);

    arbol = insertarNodo(arbol, NN1);
    arbol = insertarNodo(arbol, NN2);
    arbol = insertarNodo(arbol, NN3);
    arbol = insertarNodo(arbol, NN4);
    arbol = insertarNodo(arbol, NN5);
    arbol = insertarNodo(arbol, NN6);
    arbol = insertarNodo(arbol, NN7);
    arbol = insertarNodo(arbol, NN8);
    arbol = insertarNodo(arbol, NN9);

    //printf("\n ------------PREORDER-----------");
    //preorder(arbol);
       printf("\n ------------INORDER-----------");
      inorder(arbol);
    //printf("\n ------------POSTORDER-----------");
    //postorder(arbol);


    //nodo* lista = iniclista();

    //lista = copiarLista(arbol, lista);

    //mostrarLista(lista);

    //nodoArbol* buscado = buscarLegajo(arbol, 13);

    //mostrarNombreBuscado(arbol);


    /*
    int elementos = contarElementos(arbol);
    printf("\n Cantidad de elemntos:   %i", elementos);
    */
/*
    int altura = calcularAltura(arbol);
    printf("\n Altura: %i", altura);

    int nodosHoja = contarNodosHoja(arbol);
    printf("\n Nodos Hoja:  %i", nodosHoja);
*/

arbol = borrarNodo(arbol, 13);

printf("\nborro el 13");

 printf("\n ------------INORDER-----------");
      inorder(arbol);

    return 0;
}

/// Aca van todas las funciones que son de listas

nodo* iniclista()
{
    return NULL;
}


nodo* crearNodo(persona per)
{

    nodo* aux = (nodo*)malloc(sizeof(nodo));
    aux->dato = per;
    aux->sig = iniclista();


    return aux;
}


nodo* agregarPpio(nodo* lista, nodo* NN)
{


    if(lista == NULL)
    {
        lista = NN;
    }
    else
    {

        NN->sig  = lista;
        lista = NN;
    }

    return lista;
}

void mostrarLista(nodo* lista)
{

    while(lista != NULL)
    {


        mostrarPersona(lista->dato);
        lista = lista->sig;
    }
}

/// Copiar arbol en una lista simple

nodo* copiarLista(nodoArbol* raiz, nodo* lista)
{


    if(raiz != NULL)
    {

        lista = copiarLista(raiz->izq, lista);
        nodo* NN = crearNodo(raiz->dato);
        lista =  agregarPpio(lista, NN);
        lista = copiarLista(raiz->der, lista);

    }


    return lista;
}






persona cargarPersona(int legajo, char nombre[20], int edad)
{

    persona aux;

    aux.edad = edad;
    aux.legajo = legajo;
    strcpy(aux.nombre, nombre);

    return aux;
}

void mostrarPersona(persona per)
{
    printf("\n------------\n");
    printf("Legajo: %d\n", per.legajo);
    printf("Nombre: %s\n", per.nombre);
    printf("Edad: %d\n", per.edad);
    printf("\n------------\n");

}

// Cargar un nodo

nodoArbol* cargarNodo(persona per)
{

    nodoArbol* aux = (nodoArbol*)malloc(sizeof(nodoArbol));

    aux->dato = per;
    aux->der = inicarbol();
    aux->izq = inicarbol();

    return aux;
}

//Insertar un nodo

nodoArbol* insertarNodo(nodoArbol* raiz, nodoArbol* NN)
{

    if (raiz == NULL)
    {
        raiz = NN;
    }

    else
    {

        if(NN->dato.legajo > raiz->dato.legajo)
        {
            // Esto es para no perder el rastro de donde viene el nodo
            raiz->der = insertarNodo(raiz->der, NN);

        }
        else
        {
            // Esto es para no perder el rastro de donde viene el nodo
            //Ademas de que se queda enlazado el nodo de la izquierda con el que corresponde
            raiz->izq = insertarNodo(raiz->izq, NN);
        }
    }


    return raiz;
}


// Mostrar el arbol de diferentes formas
void inorder(nodoArbol* raiz)
{

    if(raiz != NULL)
    {
        inorder(raiz->izq);
        mostrarPersona(raiz->dato);
        inorder(raiz->der);

    }

}

void preorder(nodoArbol* raiz)
{

    if(raiz != NULL)
    {
        mostrarPersona(raiz->dato);
        preorder(raiz->izq);
        preorder(raiz->der);

    }

}

void postorder(nodoArbol* raiz)
{

    if(raiz != NULL)
    {
        postorder(raiz->izq);
        postorder(raiz->der);
        mostrarPersona(raiz->dato);
    }
}



// Buscar un alumno por legajo
nodoArbol* buscarLegajo(nodoArbol* raiz, int legajoBuscado)
{

    nodoArbol* rta = inicarbol();

    if(raiz != NULL)
    {


        if (raiz->dato.legajo == legajoBuscado)
        {

            rta = raiz;
        }
        else
        {

            if (raiz->dato.legajo > legajoBuscado)
            {

                rta = buscarLegajo(raiz->izq, legajoBuscado);
            }
            else
            {

                rta = buscarLegajo(raiz->der, legajoBuscado);
            }
        }
    }
    return rta;
}

/// Buscar un alumno por nombre

nodoArbol* buscarNombre(nodoArbol* raiz, char nombre[])
{

    nodoArbol* rta = inicarbol();



    if(raiz != NULL)
    {

        if(strcmpi(raiz->dato.nombre, nombre) == 0)
        {

            rta = raiz;
        }

        else
        {

            rta = buscarNombre(raiz->izq, nombre);

            if(rta == NULL)
            {

                rta = buscarNombre(raiz->der, nombre);
            }

        }

    }


    return rta;
}



void mostrarNombreBuscado(nodoArbol*raiz)
{

    char persona[20];
    printf("\nIngrese el nombre que desea buscar: ");

    gets(persona);


    nodoArbol* buscado = buscarNombre(raiz, persona);

    if( buscado != NULL)
    {
        mostrarNodo(buscado);
    }
    else
    {
        printf("\nNo se encontr el elemento");
    }

}




//  Contar los elementos del arbol



int contarElementos(nodoArbol* raiz)
{

    int rta = 0;



    if (raiz != NULL)
    {
        rta = 1;
        rta += contarElementos(raiz->der) + contarElementos(raiz->izq);

    }
    return rta;
}





int calcularAltura(nodoArbol* raiz)
{
    int rta = 0;

    if (raiz != NULL)
    {


        int rtaI = calcularAltura(raiz->izq);
        int rtaD = calcularAltura(raiz->der);

        if(rtaI > rtaD)
        {

            rta = rtaI + 1;
        }
        else
        {
            rta = rtaD + 1;
        }

    }

    return rta;
}



int contarNodosHoja(nodoArbol* raiz)
{

    int rta = 0;


    if(raiz != NULL)
    {

        if(raiz->izq == NULL && raiz->der == NULL)
        {
            rta = 1;
        }

            rta += contarNodosHoja(raiz->izq) + contarNodosHoja(raiz->der);
    }
    return rta;
}




nodoArbol* borrarNodo(nodoArbol* raiz, int dato)
{
    if(raiz != NULL)
    {

        if(raiz->dato.legajo == dato)
        {

            if(raiz->izq != NULL)
            {

                nodoArbol* masDerecha = nodoMasDerecha(raiz->izq);
                raiz->dato.legajo = masDerecha->dato.legajo;
                raiz->izq = borrarNodo(raiz->izq, masDerecha->dato.legajo);
            }
            else if(raiz->der != NULL)
            {
                nodoArbol* masIzquierda = nodoMasIzquierda(raiz->der);
                raiz->dato.legajo = masIzquierda->dato.legajo;
                raiz->der = borrarNodo(raiz->der, masIzquierda->dato.legajo);

            }

            if (esHoja(raiz) == 1)
            {
                free(raiz);
                raiz = NULL;
            }

        }
        else if(dato < raiz->dato.legajo)
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
     raiz = nodoMasDerecha(raiz->der);
    }

return raiz;
}


nodoArbol* nodoMasIzquierda(nodoArbol* raiz){

if(raiz->izq != NULL)
    {
     raiz = nodoMasIzquierda( raiz->izq);
    }

return raiz;
}











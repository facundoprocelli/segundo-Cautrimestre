#include <stdlib.h>
#include <stdio.h>
#include "Lib2.h"


/*Definir la estructura de la lista DE*/





//Inicializar lista

nodo2* iniclista2()
{

    return NULL;
}


// Crear un nuevo nodo;


nodo2 * crearNodo(int dato)
{


    nodo2 * nuevoNodo = (nodo2*)malloc(sizeof(nodo2));


    nuevoNodo->dato = dato;

    nuevoNodo->sig = NULL;
    return nuevoNodo;
}



// Agregar nodo al principio


nodo2* agregarPpio2(nodo2* lista, nodo2* NN)
{


    NN->sig = lista; // Enlazo la salida de el nodo nuevo a lista
    //sirve para casos de NULL y de nodo Valido


    if ( lista!= NULL)  // si no es NULL
    {
        lista-> ante = NN; // anterior es == a nuevo nodo, enlazando la entrada
    }

    return NN;
}
//--------------------------------------------------------------------------------------



//agregar en orden
//--------------------------------------------------------------------------------------

nodo2* agregarEnOrden(nodo2* lista, nodo2* NN)
{

    nodo2* seg = iniclista2();
    nodo2* ante = iniclista2();
    if ( lista == NULL)
    {
        lista = NN;
    }

    else if(NN-> dato < lista->dato)
    {
        lista == agregarPpio2 (lista, NN);
    }

    else
    {

        seg = lista->sig;

        ante = lista;

        while ((seg != NULL) && (seg->dato < NN->dato))
        {

            ante = seg;  // avanza una posicion ante
            seg = seg->sig; // avanza una posicion seg

        }

        NN->sig = seg; // Enlazo el nuevo nodo a seg, que es una posiicon mas grande
        NN->ante = ante; // Enlazo el nuevonodo ante, al ante que es una posicion menor

        ante->sig = NN;// conecto la vuelta de el siguinete a NN

        if(seg != NULL)  // Esta sentecia es para que no se romap cuando el NN es el ,mayor de todos
        {
            // Porque sino conectariamos el NODO a Nada y se rompe
            seg-> ante =NN; // conecto el ante de seguidor a la NN
        }
    }

    return lista;
}

//--------------------------------------------------------------------------------------



// agregar al final

//--------------------------------------------------------------------------------------


nodo2* agregarFinal(nodo2* lista, nodo2* NN)
{


    if (lista == NULL)
    {

        lista = NN; // Si esta vacia, el ginal es el nuevo nodo
    }

    else
    {


        nodo2* ultimo = buscarUltimo(lista); // buscamosel ultimo

        ultimo->sig = NN;   // Enlazo el final, a NN
        NN->ante = ultimo; // enlazo el anteiror al ultimo
    }




    return lista;
}

// Mostrar Lista

void mostrarLista(nodo2* lista)
{

    nodo2* seg = lista; // trabajo con una copia para no moficar el original

    while (seg!= NULL)  // Mientras no este en el final
    {

        mostrarNodo(seg); // llamo a la funcion mostrar nodo
        seg = seg ->sig; // avanzo una posicion
    }
}


// Mostrar Nodo

void mostrarNodo(nodo2* lista)
{

    printf("%i\n", lista->dato);

}



// Mostrar lista inversa

void mostrarListaInversa(nodo2* lista)
{

    nodo2* seg = lista;
    if (seg =! NULL)
    {

        nodo2* ultimo = buscarUltimo(seg);

        while (ultimo->ante != NULL)
        {

            mostrarNodo(ultimo);
            ultimo = ultimo-> ante;

        }
    }
}




// Buscar ultimo
nodo2* buscarUltimo ( nodo2* lista)
{

    nodo2* seg = lista;

    if (seg != NULL)
    {
        while (seg->sig!= NULL)
        {

            seg = seg-> sig;
        }


    }
    return seg;
}




// Borrar Nodo



nodo2 * borrarNodo(nodo2* lista, int dato)
{

    if (lista!= NULL)   // si la lista no esta vacia
    {
        if (lista->dato == dato)   // si el primero coincide
        {

            nodo2 * aux = lista;  // el nodo aux es igual a lista
            lista = lista->sig; // enlazo lista al proximo puntero

            if (lista != NULL) // si lista no es NULL
            {
                lista->ante= NULL;  // Hago que ante sean NULL
            }
            free(aux); // borro aux
        }

        else
        {

            nodo2* seg = lista-> sig; // creo seg, para usarlo de auxiliar
            nodo2* ante = lista; // crea ante, para ser un valor anterior al seguidor

            while ((seg != NULL) && (seg->dato != dato)) // mientras seg no este vacio y el dato sea difrente al dato
            {

                ante = seg; // avanzo ante
                seg = seg-> sig; // avanzo seg

            }

            if (seg!= NULL)
            {

                ante->sig = seg-> sig;  // Enlazo ante a la proxima posicion de seguidor

                free(seg); // Limpio seguidor
            }
        }

    }

    return lista; // retorno lista
}


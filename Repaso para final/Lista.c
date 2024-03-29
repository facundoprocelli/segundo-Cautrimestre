#include <stdlib.h>
#include <stdio.h>
#include "Lista.h"
/*
//Inciar una lista

nodo* inicLista()
{
    return NULL;
}


//agregar nodo al principio

nodo* agregarPpio ( nodo* lista, nodo* nuevoNodo)
{

    if(lista == NULL)
    {

        lista = nuevoNodo; // Si esta vacia agrego el nodo de una
    }
    else
    {
        //en caso de que noe ste vacia

        nuevoNodo->siguiente = lista; // el neuvo nodo apunta a lista
        lista = nuevoNodo; // El puntero lista, apunta al nuevo nodo
    }
    return lista;
}

// Agregar nodo ordenado

nodo * agregarOrdenado(nodo* lista, nodo* nuevoNodo)
{


    if (lista == NULL)
    {

        lista = nuevoNodo;
    }       // Los valores a los ue apunta tales como edad, tienen que ser modificado dependiendo d ela necesidad de la funcion
    /*--------------
    else if(nuevoNodo->edad < lista -> edad)
    {

        lista = agregarPpio(lista, nuevoNodo);
    }

    else
    {

        nodo* ante = lista;
        nodo* seg = lista -> siguiente;
        /*-------------
        while ((seg!= NULL) && (seg-> edad < nuevoNodo-> edad  ))
        {


            ante =seg;

            seg = seg->siguiente;
        }
        nuevoNodo->siguiente = seg;
        ante-> siguiente = nuevoNodo;
    }

    return lista;

}







// Agregar nodo al final

nodo * agregarFinal(nodo* lista, nodo* nuevoNodo)
{

    if (lista == NULL)   // si la lista esta vacia
    {
        lista = nuevoNodo; // El nuevo nodo, se convierte en la lista
    }

    else
    {

        nodo * ultimo = buscarUltimo(lista);  // llamamos a una funcion apra buscar al ultimo
        ultimo->siguiente = nuevoNodo; //la posicion siguiente del ultimo, es el nuevo elemento
    }

    return lista;// retornamos lista en caso de que s ehaya creado en el primer if

}

// Mostrar lista no recursiva

void mostrarLista(nodo* lista)
{

    nodo* seg = lista; // trabajo con una copia para no moficar el original

    while (seg!= NULL)  // Mientras no este en el final
    {

        mostrarNodo(seg); // llamo a la funcion mostrar nodo
        seg = seg -> siguiente; // avanzo una posicion
    }
}




void mostrarNodo(nodo * lista)
{


    printf("%i\n", lista->edad);


}



// Buscar el fianl de una lista

nodo * buscarUltimo(nodo* lista)
{

    nodo* seg = lista; // Creo una copia para no modifcar nada

    if (seg != NULL)  // mientras no este al final
    {

        while (seg -> siguiente != NULL)   // mientras el siguinete no sea NULL
        {

            seg = seg -> siguiente; // avanzamos la posicion de seg
        }

    }

return seg;
}


// Borrar un Nodo con Int

nodo * borrarNodo(nodo* lista, int dato)
{

    if (lista!= NULL)   // si la lista no esta vacia
    {

        if (lista -> edad == dato)   // si el primer coincide
        {

            nodo * aux = lista;  // el nodo aux es igual a lista
            lista = lista -> siguiente; // enlazo lista al proximo puntero
            free(aux); // borro aux
        }

        else
        {

            nodo * seg = lista -> siguiente; // creo seg, para usarlo de auxiliar
            nodo* ante = lista; // crea ante, para ser un valor anterior al seguidor

            while ((seg != NULL) && (seg->edad != dato)) // mientras seg no este vacio y el dato sea difrente al dato
            {

                ante = seg; // avanzo ante
                seg = seg-> siguiente; // avanzo seg
            }

            ante->siguiente = seg-> siguiente;  // Enlazo ante a la proxima posicion de seguidor
            free(seg); // Limpio seguidor
        }

        return lista; // retorno lista
    }
}
*/

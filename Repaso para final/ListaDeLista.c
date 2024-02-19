#include <stdio.h>
#include <stdlib.h>
#include "string.h"

/*
typedef struct
{
    char nombre[20];
    int edad;
}stPersona;

typedef struct
{
    stPersona persona;
    struct nodo* sig;
} nodo;

typedef struct
{
    char genero[20];
    nodo* lista;
    struct Celda* sig;
}Celda;

stPersona cargarPersona();
Celda* alta(Celda* lista, char genero[], stPersona perso);
nodo* crearNodo(stPersona perso);
Celda* buscarPosCelda(Celda* lista, char genero[]);
nodo* agregarPpioLista( nodo* lista, nodo* NN);
Celda* agregarElementosCelda(Celda* lista, char genero[]);
Celda* agregarFinalCelda(Celda* lista, Celda* NN);
Celda* buscarUltimoCelda(Celda* lista);
Celda* crearNodoCelda(char genero[]);
Celda* cargarCelda(Celda* lista);



int main()
{

    Celda* lista = NULL;
    lista = cargarCelda(lista);
    recorrerYmostrar(lista );

    return 0;
}

Celda* cargarCelda(Celda* lista)
{

    char rta = 's';
    char genero[20];


    while (rta == 's')
    {

        printf("Ingrese el genero\n");
        fflush(stdin);
        gets(genero);

        stPersona perso;
        perso = cargarPersona();

        lista = alta(lista, genero, perso);

        printf("Para seguir presione 's'\n");
        fflush(stdin);
        scanf("%c", &rta);
    }

    return lista;
}


Celda* alta(Celda* lista, char genero[], stPersona perso)
{

    nodo* NN = crearNodo(perso);

    Celda* pos = buscarPosCelda(lista, genero);
    if(pos == NULL)
    {
        lista = agregarElementosCelda(lista, genero);
       pos = buscarUltimoCelda(lista);
    }

    pos->lista = agregarPpioLista(pos->lista, NN);



return lista;
}


nodo* agregarPpioLista( nodo* lista, nodo* NN)
{

    if (lista == NULL)
        lista = NN;
    else
    {
        NN->sig = lista;
        lista = NN;
    }

    return lista;
}

Celda* agregarElementosCelda(Celda* lista, char genero[])
{
    Celda* NN = crearNodoCelda(genero);

    lista = agregarFinalCelda(lista, NN);

    return lista;

}

Celda* agregarFinalCelda(Celda* lista, Celda* NN)
{

    if (lista == NULL)
        lista = NN;
    else
    {
        Celda* ultimo = buscarUltimoCelda(lista);

        ultimo->sig = NN;
    }

    return lista;
}


Celda* buscarUltimoCelda(Celda* lista)
{
    Celda* aux = lista;

    while (aux->sig != NULL)
    {

        aux = aux->sig;
    }

    return aux;
}

Celda* crearNodoCelda(char genero[])
{
    Celda* aux = (Celda*)malloc(sizeof(Celda));
    aux->lista = NULL;
    aux->sig = NULL;
    strcpy(aux->genero, genero);

    return aux;
}

Celda* buscarPosCelda(Celda*  lista, char genero[])
{
    Celda* pos = NULL;

    while (lista != NULL && pos == NULL)
    {

        if(strcasecmp(lista->genero, genero) == 0)
        {
            pos = lista;
        }
        lista= lista->sig;
    }

return pos;
}

nodo* crearNodo(stPersona perso)
{

    nodo* aux = (nodo*)malloc(sizeof(nodo));
    aux->persona = perso;
    aux->sig = NULL;

    return aux;
}


stPersona cargarPersona()
{
    stPersona perso;

    printf("Ingrese el nombre\n");
    fflush(stdin);
    char nombre[20];
    gets(nombre);
    strcpy(perso.nombre, nombre);

    printf("Ingrese la edad\n");
    fflush(stdin);
    scanf("%i", &perso.edad);


    return perso;
}

void mostrarPersona(stPersona aux)
{

    printf("\n****************************************");
    printf("\nNombre..........: %s", aux.nombre);
    printf("\nEdad............: %i", aux.edad);
    printf("\n****************************************");

}
void mostrarLista(nodo* lista)
{

    while (lista != NULL)
    {

        mostrarPersona(lista->persona);

        lista = lista->sig;
    }



}
void recorrerYmostrar(Celda* lista)
{

    while (lista != NULL)
    {

        printf("\nGenero.....: %s", lista->genero);

        mostrarLista(lista->lista);

        lista = lista->sig;

    }


}
*/

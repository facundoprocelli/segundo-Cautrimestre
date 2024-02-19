#include <stdio.h>
#include <stdlib.h>
#include "string.h"

/*
typedef struct
{
    char nombre[20];
    int edad;

} stPersona;

typedef struct
{
    stPersona persona;
    struct nodo* sig;
} nodo;

typedef struct
{
    char genero[10];
    nodo *lista;
} Celda;


stPersona cargarPersona();
int cargarArreglo(Celda adl[], int dimension);
int alta(Celda adl[], char genero[], stPersona persona, int validos);
nodo* agregarPpio(nodo* lista, nodo* NN);
int agregarElementosArreglo(Celda adl[], int validos, char genero[]);
int buscarPosArreglo(Celda adl[], char genero[], int validos);
nodo* crearNodo(stPersona persona);


int main()
{

    Celda adl[10];

    int validos = cargarArreglo(adl, 10);

    recorrerYmostrar(adl, validos);

    return 0;
}


int cargarArreglo(Celda adl[], int dimension)
{
    int validos = 0;
    char rta = 's';


    while (rta == 's' && validos < dimension)
    {
        char genero[10];
        printf("Ingrese el genero\n");
        fflush(stdin);
        gets(genero);

        stPersona persona;
        persona = cargarPersona();


        validos = alta(adl, genero, persona, validos);

        printf("para seguir presione 's'\n");
        fflush(stdin);
        scanf("%c", &rta);
    }


    return validos;
}

int alta(Celda adl[], char genero[], stPersona persona, int validos)
{
    nodo* NN = crearNodo(persona);
    int pos = buscarPosArreglo(adl, genero, validos);

    if(pos == -1)
    {
        validos = agregarElementosArreglo(adl, validos, genero);
        pos = validos -1;
    }

    adl[pos].lista = agregarPpio(adl[pos].lista, NN);


    return validos;
}

nodo* agregarPpio(nodo* lista, nodo* NN)
{

    if(lista == NULL)
    {
        lista = NN;
    }

    else
    {
        NN->sig = lista;
        lista = NN;
    }

    return lista;
}

int agregarElementosArreglo(Celda adl[], int validos, char genero[])
{


    strcpy(adl[validos].genero, genero);
    adl[validos].lista = NULL;
    validos++;


    return validos;
}

int buscarPosArreglo(Celda adl[], char genero[], int validos)
{
    int pos = -1;
    int i = 0;

    while (i < validos && pos == -1)
    {
        if (strcmpi(adl[i].genero, genero) == 0)
        {
            pos = i;
        }

        i++;
    }



    return pos;
}

nodo* crearNodo(stPersona persona)
{

    nodo* aux = (nodo*)malloc(sizeof(nodo));

    aux->persona = persona;
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
void recorrerYmostrar(Celda adl[], int validos)
{

    for(int i = 0; i < validos; i++)
    {

        printf("\nGenero.....: %s", adl[i].genero);

        mostrarLista(adl[i].lista);

    }


}
*/

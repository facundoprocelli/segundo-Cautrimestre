/// Arreglo de listas


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_DIM 20



typedef struct
{

    int edad;
    char nombre[MAX_DIM];

} stPersona;

typedef struct
{

    stPersona dato;
    struct nodo* sig;
} nodo;

typedef struct
{

    char genero[MAX_DIM];
    nodo* lista;
} celda;


nodo* agregarPpio(nodo* lista, nodo* NN);
nodo* iniclista();
nodo* crearNodo(stPersona persona);

stPersona cargarPersona();


int main()
{

    celda adl[MAX_DIM];


    int validos = cargarArreglo(adl, MAX_DIM);

    recorrerYmostrar(adl, validos);
    return 0;
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

        mostrarPersona(lista->dato);

        lista = lista->sig;
    }



}
void recorrerYmostrar(celda adl[], int validos)
{

    for(int i = 0; i < validos; i++)
    {

        printf("\nGenero.....: %s", adl[i].genero);

        mostrarLista(adl[i].lista);

    }


}



int cargarArreglo(celda adl[], int dimension)
{

    int validos = 0;
    char rta = 's';
    int i = 0;



    while (i < dimension && rta == 's')
    {

        char genero[MAX_DIM];
        printf("\nIngrese el genero");
        fflush(stdin);
        gets(genero);

        stPersona persona;
        persona = cargarPersona();


        validos = alta(adl, validos, genero, persona);

        printf("\nPara seguir presione 's'");
        fflush(stdin);
        scanf("%c", &rta);

    }


    return validos;
}

int alta(celda adl[], int validos, char genero[], stPersona persona)
{

    nodo* NN = crearNodo(persona);
    int pos = buscarPosArreglo(adl, validos, genero);

    if(pos == -1)
    {
        validos = agregarElementoArreglo(adl, validos, genero);
        pos = validos -1;

    }

    adl[pos].lista = agregarPpio(adl[pos].lista, NN);

    return validos;
}

nodo* agregarPpio(nodo* lista, nodo* NN)
{

    if (lista == NULL)
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

int agregarElementoArreglo(celda adl[], int validos, char genero[])
{

    strcpy(adl[validos].genero, genero);
    adl[validos].lista = iniclista();
    validos++;


    return validos;
}

int buscarPosArreglo(celda adl[], int validos, char genero[])
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


nodo* iniclista()
{
    return NULL;
}

nodo* crearNodo(stPersona persona)
{
    nodo* aux = (nodo*)malloc(sizeof(nodo));
    aux->dato = persona;
    aux->sig = iniclista();

    return aux;

}

stPersona cargarPersona()
{

    stPersona aux;

    printf("\nIngrese el nombre de la persona");
    fflush(stdin);
    gets(aux.nombre);


    printf("\n Ingrese la edad de la persona");
    fflush(stdin);
    scanf("%i", &aux.edad);

    return aux;
}

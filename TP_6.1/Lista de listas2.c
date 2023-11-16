/// Arreglo de arboles


#include <stdio.h>
#include <stdlib.h>
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
    struct celda* sig;

} celda;



stPersona cargarPersona();

celda* cargarListaDeListas(celda* ldl);
celda* alta(celda ldl[], char genero[], stPersona persona);
celda* agregarCeldaPpio(celda* ldl, celda* NN);
celda* crearCelda(char genero[]);
celda* buscarCelda(celda* ldl, char genero[]);


nodo* agregarPpio(nodo* lista, nodo* NN);
nodo* crearNodo(stPersona aux);


int main()
{


    celda* ldl = NULL;

    ldl = cargarListaDeListas(ldl);

    recorrerYmostrar(ldl);

    return 0;
}


void recorrerYmostrar(celda* ldl)
{


    celda* aux = ldl;
    while (aux!= NULL)
    {


        printf("\n========================");
        printf("\n Genero....: %s", aux->genero);
        printf("\n========================");

        mostrarLista(aux->lista);

        aux = aux->sig;

    }


}

void mostrarPersona(stPersona aux)
{

    printf("\n**********************");
    printf("\n Nombre.........: %s", aux.nombre);
    printf("\n Edad...........: %i", aux.edad);
    printf("\n**********************");



}

void mostrarLista(nodo* lista)
{

    while (lista != NULL)
    {

        mostrarPersona(lista->dato);

        lista = lista->sig;
    }


}

celda* cargarListaDeListas(celda* ldl)
{
    char rta = 's';
    int validos = 0;
    char genero[MAX_DIM];
    stPersona persona;


    while (rta == 's')
    {

        printf("\n Ingrese el genero de la persona");
        fflush(stdin);
        gets(genero);

        persona = cargarPersona();


        ldl = alta(ldl, genero, persona);

        printf("\n Para seguir presione 's'");
        fflush(stdin);
        scanf("%c", &rta);
    }

    return ldl;
}

celda* alta(celda ldl[], char genero[], stPersona persona)
{
    nodo* NN = crearNodo(persona);
    celda* celdaEncontrada = buscarCelda(ldl, genero);

    if(celdaEncontrada == NULL)
    {

        celda* nuevaCelda = crearCelda(genero);
        ldl = agregarCeldaPpio(ldl, nuevaCelda);
        celdaEncontrada = ldl;

    }

    celdaEncontrada->lista = agregarPpio(celdaEncontrada->lista, NN);



    return ldl;
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
        lista =NN;

    }


    return lista;
}

celda* agregarCeldaPpio(celda* ldl, celda* NN)
{


    if(ldl == NULL)
    {

        ldl = NN;
    }
    else
    {

        NN->sig = ldl;
        ldl = NN;

    }


    return ldl;
}

celda* crearCelda(char genero[])
{

    celda* aux = (celda*)malloc(sizeof(celda));

    strcpy(aux->genero, genero);
    aux->sig = NULL;
    aux->lista = NULL;


    return aux;
}

celda* buscarCelda(celda* ldl, char genero[])
{

    celda* seg = ldl;
    celda* encontrada = NULL;


    while (seg != NULL && encontrada == NULL)
    {

        if (strcmpi(seg->genero, genero) == 0)
        {

            encontrada = seg;
        }
        seg = seg->sig;

    }


    return encontrada;
}
nodo* crearNodo(stPersona aux)
{

    nodo* NN = (nodo*)malloc(sizeof(nodo));

    NN->dato = aux;
    NN->sig = NULL;


    return NN;
}



stPersona cargarPersona()
{

    stPersona aux;

    printf("\n Ingrese el nombre de la persona:  ");
    fflush(stdin);
    gets(aux.nombre);

    printf("\nIngrese la edad de la persona: ");
    fflush(stdin);
    scanf("%i", &aux.edad);

    return aux;

}

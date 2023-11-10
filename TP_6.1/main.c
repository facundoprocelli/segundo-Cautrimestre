#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARCHIVO_MEZCLADO "archivo_mezclado.bin"

#define MAX_DIM 40
#define MAX_CHAR_DNI 9
#define MAX_DIM_ALTURA 5



typedef struct
{
    int nota;
    int legajo;
    char nombreApe[40];
    char materia[40];
    int idMateria;
} registroArchivo;

typedef struct
{
    int nota;
    int legajo;
    char nombreApe[40];
} notaAlumno;

typedef struct nodo
{
    notaAlumno dato;
    struct nodo *sig;
} nodo;

typedef struct
{
    int idMateria;
    char materia[40];
    nodo * listaDeNotas;
} celda;

registroArchivo cargarRegistro();

nodo* cargarListaDesdeArchivo(nodo* lista);



nodo* iniclista();
nodo* agregarPpio(nodo* lista, nodo* NN);
nodo* crearNodo(notaAlumno dato);



int main()
{

    //registroArchivo reg = cargarRegistro();

       // mostrarRegistroArchivo(cargarRegistro());


       cargarArchivo();
       mostrarArchivo();

       nodo* lista = iniclista();

       lista = cargarListaDesdeArchivo(lista);

       mostrarListaSimple(lista);
    return 0;
}

nodo* iniclista()
{
    return NULL;
}

registroArchivo cargarRegistro()
{

    registroArchivo aux;


    printf("Nombre y Apellido: \n");
    fflush(stdin);
    fgets(aux.nombreApe, MAX_DIM, stdin);

    printf("Materia: \n");
    fflush(stdin);
    fgets(aux.materia, MAX_DIM, stdin);

    printf("ID materia: \n");
    fflush(stdin);
    scanf("%i", &aux.idMateria);

    printf("Nota: \n");
    fflush(stdin);
    scanf("%i", &aux.nota);

    printf("Legajo: \n");
    fflush(stdin);
    scanf("%i", &aux.legajo);

    return aux;
}


void mostrarRegistroArchivo(registroArchivo aux)
{
    printf("\n............................\n");
    printf("Nombre y apellido...:  %s", aux.nombreApe);
    printf("Materia.............:  %s", aux.materia);
    printf("Id Materia..........:  %i\n", aux.idMateria);
    printf("Nota................:  %i\n", aux.nota);
    printf("Legajo..............:  %i\n", aux.legajo);
}



nodo* cargarListaDesdeArchivo(nodo* lista) {
    FILE* archi = fopen(ARCHIVO_MEZCLADO, "rb");
    notaAlumno nuevaNota;
     registroArchivo aux;

    while (fread(&aux, sizeof(registroArchivo), 1, archi) == 1) {
        strcpy(nuevaNota.nombreApe, aux.nombreApe);
        nuevaNota.legajo = aux.legajo;
        nuevaNota.nota = aux.nota;

        nodo* NN = crearNodo(nuevaNota);
        lista = agregarPpio(lista, NN); // Asigna el resultado de agregarPpio a la lista
    }

    fclose(archi);

    return lista;
}







void cargarArchivo(){

FILE* archi = fopen(ARCHIVO_MEZCLADO, "wb");

for (int i = 0; i < 15; i++){

registroArchivo dato = cargarRegistro();
fwrite(&dato, sizeof(registroArchivo), 1, archi);


}

fclose(archi);

}

void mostrarArchivo(){

FILE* archi = fopen(ARCHIVO_MEZCLADO, "rb");
registroArchivo aux;

while(fread(&aux, sizeof(registroArchivo), 1, archi) == 1){

mostrarRegistroArchivo(aux);

}


fclose(archi);
}







nodo* crearNodo(notaAlumno dato)
{

    nodo* aux = (nodo*)malloc(sizeof(nodo));

    aux->dato = dato;
    aux->sig = iniclista();


    return aux;
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


void mostrarListaSimple(nodo* lista){

while (lista != NULL){

    mostrarNotaAlumno(lista->dato);
    lista = lista->sig;
}

}

void mostrarNotaAlumno(notaAlumno aux){

printf("\n................\n");
printf("Nombre......: %s", aux.nombreApe);
printf("Nota........: %i\n", aux.nota);
printf("Legajo......: %i\n", aux.legajo);


}



/*

typedef struct
{

    char nombre[MAX_DIM];
    char apellido[MAX_DIM];
    char DNI [MAX_CHAR_DNI];
    int edad;
    char direcicon[MAX_DIM];
    char altura[MAX_DIM_ALTURA];
    char genero[MAX_DIM];

} stPersona;
/// ------------------Cargar una persona-----------------------

stPersona cargarPersona()
{

    stPersona aux;

    printf("Ingrese el Nombre\n");
    fflush(stdin);
    gets(aux.nombre);

    printf("Ingrese el Apellido\n");
    fflush(stdin);
    gets(aux.apellido);


    printf("Ingrese el DNI\n");
    fflush(stdin);
    gets(aux.DNI);

    printf("Ingrese la edad\n");
    fflush(stdin);
    scanf("%i", &aux.edad);

    printf("Ingrese la Direccion\n");
    fflush(stdin);
    gets(aux.direcicon);


    printf("Ingrese la altura\n");
    fflush(stdin);
    gets(aux.altura);
    printf("Ingrese el Genero\n");
    fflush(stdin);
    gets(aux.genero);


    return aux;
}



void mostrarPersona(stPersona aux)
{
printf("\n............................\n");
    printf("Nombre.......: %s\n",aux.nombre);
    printf("Apellido.....: %s\n",aux.apellido);
    printf("DNI..........: %s\n",aux.DNI);
    printf("Edad.........: %i\n",aux.edad);
    printf("Direccion....: %s\n",aux.direcicon);
    printf("Altura.......: %s\n",aux.altura);
    printf("Genero.......: %s\n",aux.genero);
}


///-------------------------------------------------------------------------
*/


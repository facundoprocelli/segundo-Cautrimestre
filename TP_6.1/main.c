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

celda cargarCelda(registroArchivo dato, nodo* NN);
notaAlumno cargarNotaAlumnoDesdeArchivo(registroArchivo dato);




int main()
{

    celda adl[MAX_DIM];


    cargarArchivo();
    mostrarArchivo();

    nodo* lista = iniclista();

    lista = cargarListaDesdeArchivo(lista);

    int validos = cargarArregloDeListas(adl, MAX_DIM);

    mostrarListaSimple(lista);
    return 0;
}



nodo* iniclista()
{
    return NULL;
}



int cargarArregloDeListas(celda adl[], int dimension)
{

int validos = 0;
printf("ingres0\n");

    FILE* archi = fopen(ARCHIVO_MEZCLADO, "rb");

    registroArchivo dato;
    notaAlumno alumno;

    printf("declaro cosas\n");
    while(fread(&dato, sizeof(registroArchivo), 1, archi) == 1 && validos < dimension)
    {
puts("entro al bucle\n");

        alumno = cargarNotaAlumnoDesdeArchivo(dato);
        nodo* NN = crearNodo(alumno);
        printf("cree el nodo\n");


        int pos = buscarPosMateria(adl, dato.materia, validos);
        printf("Pase la buscar materia\n");

        if (pos == -1)
        {
            printf("agrego materia\n");
            validos  = agregarMateria(adl, dato.materia, validos);
            pos = validos -1;
        }

        printf("agrego listas a el arreglo\n");
        adl[pos].listaDeNotas = agregarPpio(adl[pos].listaDeNotas, NN);

        mostrarListaSimple(adl[pos].listaDeNotas);
        printf("\n Materia: %S\n", adl[pos].materia);
    }
    printf("retorno\n");

    return validos;
}

int agregarMateria(celda adl[], char materia[], int validos)
{

    strcpy(adl[validos].materia, materia);
    adl[validos].listaDeNotas = iniclista();
    validos++;



    return validos;
}

int buscarPosMateria(celda adl[], char materia[], int validos)
{


    int rta = -1;

    int i = 0;

    while (1 < validos && rta == -1)
    {

        if (strcmpi(adl[i].materia, materia) == 0)
        {

            rta = 1;
        }
        i++;
    }

    return rta;
}













celda cargarCelda(registroArchivo dato, nodo* NN)
{

    celda aux;

    aux.idMateria = dato.idMateria;
    strcpy(aux.materia, dato.materia);
    aux.listaDeNotas = NN;

    return aux;
}

notaAlumno cargarNotaAlumnoDesdeArchivo(registroArchivo dato)
{

printf("cargo notas\n");
    notaAlumno aux;

    aux.legajo = dato.legajo;
    aux.nota =dato.nota;
    strcpy(aux.nombreApe, dato.nombreApe);

    return aux;
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



nodo* cargarListaDesdeArchivo(nodo* lista)
{

    FILE* archi = fopen(ARCHIVO_MEZCLADO, "rb");
    notaAlumno nuevaNota;
    registroArchivo aux;

    while (fread(&aux, sizeof(registroArchivo), 1, archi) == 1)
    {
        strcpy(nuevaNota.nombreApe, aux.nombreApe);
        nuevaNota.legajo = aux.legajo;
        nuevaNota.nota = aux.nota;

        nodo* NN = crearNodo(nuevaNota);
        lista = agregarPpio(lista, NN); // Asigna el resultado de agregarPpio a la lista
    }

    fclose(archi);

    return lista;
}





















void cargarArchivo()
{

    FILE* archi = fopen(ARCHIVO_MEZCLADO, "wb");

    for (int i = 0; i < 15; i++)
    {

        registroArchivo dato = cargarRegistro();
        fwrite(&dato, sizeof(registroArchivo), 1, archi);


    }

    fclose(archi);

}













void mostrarArchivo()
{

    FILE* archi = fopen(ARCHIVO_MEZCLADO, "rb");
    registroArchivo aux;

    while(fread(&aux, sizeof(registroArchivo), 1, archi) == 1)
    {

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





void mostrarListaSimple(nodo* lista)
{

    while (lista != NULL)
    {

        mostrarNotaAlumno(lista->dato);
        lista = lista->sig;
    }

}

void mostrarNotaAlumno(notaAlumno aux)
{

    printf("\n................\n");
    printf("Nombre......: %s", aux.nombreApe);
    printf("Nota........: %i\n", aux.nota);
    printf("Legajo......: %i\n", aux.legajo);


}




#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_DIM 20

#define ARCHIVO_REGISTRO "archivo.bin"
#define ARCHIVO_REGISTRO_APROBADOS "archivoAprobados.bin"



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

typedef struct
{
    notaAlumno dato;
    struct nodo *siguiente;
} nodo;

typedef struct
{
    int idMateria;
    char materia[40];
    nodo * listaDeNotas;
} celda;

nodo* crearNodo(notaAlumno nota);
nodo* agregarPpio(nodo* lista, nodo* NN);

notaAlumno cargarNotaAlumno();
int alta(celda adl[], char materia[], notaAlumno nota, int validos);
int agregarMateria(celda adl[], char materia[], int validos);

registroArchivo cargarRegistro(celda adl[], int pos, nodo* lista);


int cargarArreglo(celda arregloDeLista[], int dimension);

int pasarDeArchivoToADL (celda adl[], int validos);
nodo* cargarListaDesdeArchivo(registroArchivo registro);

notaAlumno cargarNotaDesdeArchivo(registroArchivo registro);


/// MAIN
int main()
{

    int dimension = 20;

    // celda arregloDeLista[dimension];
    // int validos = cargarArreglo(arregloDeLista, dimension);


    //mostrarArregloDeLista(arregloDeLista, validos);

    //recorrerYmostrar(arregloDeLista, validos);



    //pasarDeADLtoArchivo(arregloDeLista, validos);
    // mostrarArchivo();

    //pasarDeADLtoArchivoAprobados(arregloDeLista, validos);
    mostrarArchivoAprobados();



    celda arregloDeAprobados[dimension];
    int validosAprobados =  pasarDeArchivoToADL(arregloDeAprobados, dimension);
    printf("\n\nValidos aprobados  %i", validosAprobados);

    recorrerYmostrar(arregloDeAprobados, validosAprobados);
    //mostrarArregloDeLista(arregloDeAprobados, validosAprobados);

    return 0;
}



int pasarDeArchivoToADL (celda adl[], int dimension)
{

    FILE* archi = fopen (ARCHIVO_REGISTRO_APROBADOS, "rb");

    registroArchivo aux;
    int i = 0;
    int validos  = 0;

    while ((fread(&aux, sizeof(registroArchivo), 1, archi) > 0) && (validos < dimension) )
    {

        char materia[20];
        strcpy(materia, aux.materia);

        notaAlumno nota;
        nota = cargarNotaDesdeArchivo(aux);


         validos = alta(adl,materia,nota, validos);


    }

    fclose(archi);

    return validos;
}





notaAlumno cargarNotaDesdeArchivo(registroArchivo registro)
{

    notaAlumno aux;

    aux.legajo = registro.legajo;
    aux.nota = registro.nota;
    strcpy(aux.nombreApe, registro.nombreApe);


    return aux;
}






void mostrarArregloDeLista(celda adl[], int validos)
{


    for (int i = 0; i < validos; i++)
    {


        printf("\nMateria... %s", adl[i].materia);
    }
}


/// Funciones de archivo

void mostrarArchivo()
{
    FILE* archi = fopen(ARCHIVO_REGISTRO, "rb");

    registroArchivo aux;


    while (fread(&aux, sizeof(registroArchivo), 1, archi) > 0)
    {


        mostrarRegistroArchivo(aux);
    }
}


void mostrarArchivoAprobados()
{
    FILE* archi = fopen(ARCHIVO_REGISTRO_APROBADOS, "rb");

    registroArchivo aux;


    while (fread(&aux, sizeof(registroArchivo), 1, archi) > 0)
    {

        mostrarRegistroArchivo(aux);
    }
}

void mostrarRegistroArchivo(registroArchivo aux)
{


    printf("\n*******************");
    printf("\n Materia..............: %s", aux.materia);
    printf("\n Id Materia...........: %i", aux.idMateria);
    printf("\n Nombre y Apellido....: %s", aux.nombreApe);
    printf(" Legajo...............: %i", aux.legajo);
    printf("\n Nota.................: %i", aux.nota);

}


///De arreglo a archivo

void pasarDeADLtoArchivo(celda adl[], int validos)
{

    FILE* archi = fopen(ARCHIVO_REGISTRO, "ab");

    for (int i = 0; i < validos; i++)
    {

        nodo* aux = adl[i].listaDeNotas;

        while (aux != NULL)
        {

            registroArchivo registro;
            registro = cargarRegistro(adl, i, aux);

            fwrite(&registro, sizeof(registroArchivo), 1, archi);

            aux = aux->siguiente;
        }
    }

    fclose(archi);
}

void pasarDeADLtoArchivoAprobados(celda adl[], int validos)
{

    FILE* archi = fopen(ARCHIVO_REGISTRO_APROBADOS, "wb");

    for (int i = 0; i < validos; i++)
    {

        nodo* aux = adl[i].listaDeNotas;

        while (aux != NULL)
        {

            registroArchivo registro;
            registro = cargarRegistro(adl, i, aux);



            if(registro.nota >= 6)
            {

                fwrite(&registro, sizeof(registroArchivo),1, archi);
            }
            aux = aux->siguiente;
        }
    }

    fclose(archi);
}


/// De arreglo a arhcivo aprobados

///Cargar estructura archivo
registroArchivo cargarRegistro(celda adl[], int pos, nodo* lista)
{

    registroArchivo aux;

    aux.idMateria = adl[pos].idMateria;
    aux.legajo = lista->dato.legajo;
    aux.nota = lista->dato.nota;
    strcpy(aux.materia, adl[pos].materia);
    strcpy(aux.nombreApe, lista->dato.nombreApe);


    return aux;
}

/// Mostrar arreglo de lista

void recorrerYmostrar(celda adl[], int validos )
{

    int i = 0;

    for (i = 0; i < validos; i++)
    {

        printf("\n\nMateria:  %s", adl[i].materia);
        printf("\nId Materia: %i", adl[i].idMateria);


        mostrarLista(adl[i].listaDeNotas);

    }

}


void mostrarLista(nodo* aux)
{

    while (aux != NULL)
    {

        mostrarNotasAlumno(aux->dato);

        aux = aux->siguiente;
    }

}

void mostrarNotasAlumno(notaAlumno aux)
{

    printf("\n **************************");
    printf("\n Nombre y Apellido.....%s", aux.nombreApe);
    printf("  Nota..................%i", aux.nota);
    printf("\n Legajo................%i", aux.legajo);

}

///Cargar Arreglo de listas

int cargarArreglo(celda arregloDeLista[], int dimension)
{

    char salir = 's';
    int validos = 0;

    char materia[MAX_DIM];


    while (salir == 's' && validos < dimension)
    {


        printf("\nIngrese el nombre de la materia: ");
        fflush(stdin);
        gets(materia);


        notaAlumno nota;
        nota = cargarNotaAlumno();


        validos = alta(arregloDeLista, materia, nota, validos);



        printf("\nPara seguir presione s");
        fflush(stdin);
        scanf("%c", &salir);
    }




    return validos;
}


/// Dar de alta materias en el arreglo
int alta(celda adl[], char materia[], notaAlumno nota, int validos)
{


    nodo* NN = crearNodo(nota);

    int pos = buscarPosMateria(adl, materia, validos);

    if (pos == -1)
    {
        validos = agregarMateria(adl, materia, validos);
        pos = validos -1;
    }

    adl[pos].listaDeNotas = agregarPpio(adl[pos].listaDeNotas, NN);
    adl[pos].idMateria = pos;



    return validos;
}

/// agregar una materia al arreglo
int agregarMateria(celda adl[], char materia[], int validos)
{

    strcpy(adl[validos].materia, materia);
    adl[validos].idMateria = validos;
    adl[validos].listaDeNotas = NULL;
    validos++;

    return validos;
}


//Buscar posicion en el arreglo

int buscarPosMateria(celda arregloDeLista[], char mat[], int validos)
{

    int i = 0;
    int pos = -1;
    while (i < validos && pos == -1)
    {

        if(strcmpi(arregloDeLista[i].materia, mat) == 0)
        {

            pos = i;
        }
        i++;

    }

    return pos;
}


///agregar nodo
nodo* agregarPpio(nodo* lista, nodo* NN)
{

    if(lista == NULL)
    {

        lista = NN;

    }
    else
    {


        NN->siguiente = lista;
        lista = NN;
    }

    return lista;
}

/// Crear un nodo

nodo* crearNodo(notaAlumno nota)
{

    nodo* aux = (nodo*)malloc(sizeof(nodo));

    aux->dato = nota;
    aux->siguiente = NULL;


    return aux;
}


///Cargar estructura alumno
notaAlumno cargarNotaAlumno()
{

    notaAlumno aux;

    printf("\nIngrese el Nombre y Apellido del alumno:  ");
    fflush(stdin);
    fgets(aux.nombreApe,40, stdin);
    printf("\n Ingrese la nota del alumno: ");
    fflush(stdin);
    scanf("%i", &aux.nota);

    printf("\n Ingrese El legajo del alumno: ");
    fflush(stdin);
    scanf("%i", &aux.legajo);


    return aux;
}




/// Datos para cargar Rapido


Estadistica
Facundo Gonzalez
9
1234
s
Progra
Lorena Rodriguez
4
5678
s
Arqui
Juan Perez
7
9012
s
Estadistica
Maria Garcia
10
3456
s
Progra
Alejandro Martinez
6
7890
s
Arqui
Ana Fernandez
2
2345
s
Estadistica
Martin Lopez
5
6789
s
Progra
Carla Silva
8
1234
s
Arqui
Pablo Rodriguez
7
5678
s
Estadistica
Camila Gonzalez
6
9012
s
Progra
Mateo Perez
9
3456
s
Arqui
Julia Martinez
10
7890
s
Estadistica
Nicolas Fernandez
8
2345
s
Progra
Valentina Lopez
3
6789
s
Arqui
Santiago Silva
9
1234
s

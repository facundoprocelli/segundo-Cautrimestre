/// Arreglo de arboles


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIM 20


typedef struct{

int edad;
char nombre[MAX_DIM];
} stPersona;

typedef struct{

stPersona dato;
struct nodoArbol* izq;
struct nodoArbol* der;

}nodoArbol;


typedef struct{

char genero[MAX_DIM];
nodoArbol* raiz;

}celda;


nodoArbol* agregarNodoArbol(nodoArbol* raiz, nodoArbol* NN);
nodoArbol* inicArbol();
nodoArbol* crearNodoArbol(stPersona persona);
stPersona cargarPersona();




int main(){


celda ada[MAX_DIM];

int validos = cargarArregloDeArboles(ada, MAX_DIM);

printf("validos : %i", validos);


mostrarArregloDeArbol(ada, validos);

return 0;
}

void mostrarArregloDeArbol( celda ada[], int validos){

for (int i = 0; i < validos; i++){

    printf("\n==========================");
    printf("\n Genero.........: %s", ada[i].genero);
    printf("\n==========================");

    inorder(ada[i].raiz);

}


}

void inorder(nodoArbol* raiz){

if(raiz != NULL){

    inorder(raiz->izq);
    mostrarPersona(raiz->dato);
    inorder(raiz->der);
}

}

void mostrarPersona(stPersona aux){


printf("\n**********************");
printf("\n Nombre........: %s", aux.nombre);
printf("\n Edad...........: %i", aux.edad);
printf("\n**********************");

}


int cargarArregloDeArboles(celda ada[], int dimension)
{
    char rta = 's';
    int validos = 0;
    char genero[MAX_DIM];
    stPersona persona;


    while (validos < dimension && rta == 's'){

        printf("\n Ingrese el genero de la persona");
        fflush(stdin);
        gets(genero);

        persona = cargarPersona();


        validos = alta(ada, validos, genero, persona);

        printf("\n Para seguir presione 's'");
        fflush(stdin);
        scanf("%c", &rta);
    }

    return validos;
}

int alta(celda ada[], int validos, char genero[], stPersona persona)
{
    nodoArbol* NN = crearNodoArbol(persona);

    int pos = -1;
    pos = buscarPosArreglo(ada, validos, genero);

    if(pos == -1){

        validos = agregarGeneroArreglo(ada, validos, genero);

        pos = validos -1;
    }

    ada[pos].raiz = agregarNodoArbol(ada[pos].raiz, NN);

return validos;
}

nodoArbol* agregarNodoArbol(nodoArbol* raiz, nodoArbol* NN)
{
    if (raiz == NULL){
        raiz = NN;
    }
    else{

        if (NN->dato.edad > raiz->dato.edad){

            raiz->der = agregarNodoArbol(raiz->der, NN);
        }
        else{

            raiz->izq = agregarNodoArbol(raiz->izq, NN);
        }
    }



    return raiz;
}

int agregarGeneroArreglo(celda ada[], int validos, char genero[])
{
    strcpy(ada[validos].genero, genero);
    ada[validos].raiz = inicArbol();
    validos++;

    return validos;
}


int buscarPosArreglo(celda ada[], int validos, char genero[])
{
    int i = 0;
    int pos = -1;

    while ((i < validos) &&(pos == -1)){

        if (strcmpi(ada[i].genero, genero) == 0){

            pos = i;
        }
        i++;

    }

    return pos;

}


nodoArbol* inicArbol(){
return NULL;
}

nodoArbol* crearNodoArbol(stPersona persona){

nodoArbol* aux = (nodoArbol*)malloc(sizeof(nodoArbol));

aux->dato = persona;
aux->der = inicArbol();
aux->izq = inicArbol();


return aux;
}


stPersona cargarPersona(){

stPersona aux;

printf("\n Ingrese el nombre de la persona:  ");
fflush(stdin);
gets(aux.nombre);

printf("\nIngrese la edad de la persona: ");
fflush(stdin);
scanf("%i", &aux.edad);

return aux;

}

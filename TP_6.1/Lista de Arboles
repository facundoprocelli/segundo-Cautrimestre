#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define MAX_DIM 20

typedef struct{

char titulo[MAX_DIM];
char autor[MAX_DIM];
int anioDeLanz;


}stLibro;


typedef struct {

stLibro dato;

struct nodoArbol* izq;
struct nodoArbol* der;

}nodoArbol;

typedef struct{

char genero[MAX_DIM];
nodoArbol* raiz;
struct listaDeArbol* sig;
}listaDeArbol;

listaDeArbol* iniclista();
listaDeArbol* cargarGeneros(listaDeArbol* listaPrincipal);
listaDeArbol * alta ( listaDeArbol* lista, char genero[], stLibro libro);
listaDeArbol* agregarListaPpio(listaDeArbol* lista, listaDeArbol* NN);
listaDeArbol* crearNodoLista(char genero[]);
listaDeArbol* buscarNodo(listaDeArbol* lista, char genero[]);


nodoArbol* agregarNodoArbol(nodoArbol* raiz, nodoArbol* NN);
nodoArbol* crearNodoArbol(stLibro libro);

stLibro cargarLibro();


int main(){


listaDeArbol* listaPrincipal = iniclista();

listaPrincipal = cargarGeneros(listaPrincipal);
mostrarLista(listaPrincipal);

return 0;
}


void mostrarLista(listaDeArbol* listaPrincipal){


while (listaPrincipal != NULL){


    printf("\nGenero: %s", listaPrincipal->genero);
    inorder(listaPrincipal->raiz);
    listaPrincipal = listaPrincipal->sig;
}


}

void inorder(nodoArbol* raiz){

if(raiz != NULL){

    inorder(raiz->izq);
    mostrarLibro(raiz->dato);
    inorder(raiz->der);

}

}


void mostrarLibro(stLibro dato){
printf("\n**********************\n");
printf("\nTitulo........%s", dato.titulo);
printf("\nAutor.........%s", dato.autor);
printf("\nAnio..........%i", dato.anioDeLanz);

}


listaDeArbol* cargarGeneros(listaDeArbol* listaPrincipal){

char resp = 's';
char genero[MAX_DIM];


while (resp == 's'){

printf("\n Ingrese el Genero: ");
fflush(stdin);
gets(genero);

stLibro libro;
libro = cargarLibro();


listaPrincipal = alta(listaPrincipal, genero, libro);

printf("\n Presione 's' para seguir\n ");
fflush(stdin);
scanf("%c", &resp);

}

return listaPrincipal;
}



listaDeArbol * alta ( listaDeArbol* lista, char genero[], stLibro libro){

nodoArbol* NN = crearNodoArbol(libro);

listaDeArbol* nodoBuscado = buscarNodo(lista, genero);


if(nodoBuscado == NULL){

    listaDeArbol* NN = crearNodoLista(genero);
    lista = agregarListaPpio(lista, NN);
    nodoBuscado = lista;

}

    nodoBuscado->raiz = agregarNodoArbol(nodoBuscado->raiz, NN);



return lista;
}

nodoArbol* agregarNodoArbol(nodoArbol* raiz, nodoArbol* NN){

if (raiz == NULL){

        raiz =NN;
}
else{


    if (strcmpi(raiz->dato.titulo, NN->dato.titulo) >0){

        raiz->der = agregarNodoArbol(raiz->der, NN);
    }
    else{


        raiz->izq = agregarNodoArbol(raiz->izq, NN);
    }

}


return raiz;
}


listaDeArbol* agregarListaPpio(listaDeArbol* lista, listaDeArbol* NN){

if (lista == NULL){

    lista = NN;
}
else{


    NN->sig = lista;
    lista = NN;
}

return lista;
}

listaDeArbol* crearNodoLista(char genero[]){

listaDeArbol* NN = (listaDeArbol*)malloc(sizeof(listaDeArbol));

strcpy(NN->genero,genero);
NN->raiz = NULL;
NN->sig = iniclista();


return NN;

}

listaDeArbol* buscarNodo(listaDeArbol* lista, char genero[]){

listaDeArbol* buscado = NULL;
listaDeArbol* seg = lista;

while (seg != NULL){


    if (strcmpi(seg->genero, genero) == 0){

        buscado = seg;
    }
    seg = seg->sig;

}


return buscado;
}

nodoArbol* crearNodoArbol(stLibro libro){

nodoArbol* aux = (nodoArbol*)malloc(sizeof(nodoArbol));

aux->dato = libro;
aux->der = NULL;
aux->izq = NULL;

return aux;
}


stLibro cargarLibro(){
stLibro aux;

printf("\n Ingrese el Titulo: ");
fflush(stdin);
gets(aux.titulo);

printf("\n Ingrese el Autor: ");
fflush(stdin);
gets(aux.autor);

printf("\n Ingrese el Anio de lanzamiento: ");
fflush(stdin);
scanf("%i", &aux.anioDeLanz);



return aux;
}


listaDeArbol* iniclista(){
return NULL;
}

#include <stdio.h>
#include <stdlib.h>

/*


//Todo lo necesario para poder usar las filas


// Definicion de las estructuras de
// Lista doblemente enlaada

typedef struct
{
    int dato;
    struct nodo2* ste;
    struct nodo2* ante;
} nodo2;

// Filas

typedef struct
{
    struct nodo2* inicio;
    struct nodo2* fin;

} Fila;





/// Inicializar las estructuras

// Inicilaizar una lista;

nodo2* iniclista2()
{
    return NULL;
}

// Inicializar una Fila

void inicFila(Fila* filita)
{
    filita->inicio= iniclista2();
    filita->fin = iniclista2();
}


/// Crear un nodo

nodo2* crearNodo2(int dato)
{

    nodo2* aux = (nodo2*)malloc(sizeof(nodo2));
    aux->dato = dato;
    aux->ste = iniclista2();
    aux->ante = iniclista2();

    return aux;
}

/// Agregar nodo a la fila
nodo2* agregarFinalFila(nodo2* ultimo, nodo2* NN)
{
    if(ultimo == NULL)
    {
        ultimo = NN;
    }
    else{

        ultimo->ste = NN;
        NN->ante = ultimo;
        ultimo = NN;
    }

    return ultimo;
}

void agregar(Fila* filita, int dato)
{

    nodo2* NN = crearNodo2(dato);

    filita->fin = agregarFinalFila( filita->fin,  NN);

    if(filita->inicio == NULL)
    {
        filita->inicio = filita->fin;
    }

}



/// Mostrar la fila


void recorrerYmostrar(nodo2* lista)
{
    nodo2* aux = lista;

    while (aux!= NULL)
    {
        printf("[%i]", aux->dato);
        aux= aux->ste;
    }
}
void mostrar(Fila* filita)
{
    recorrerYmostrar(filita->inicio);
}


/// Eliminar elementos de la fila
nodo2* borrarPrimerNodo(nodo2* lista)
{

    nodo2* aux = lista;
    lista = lista->ste;

    free(aux);


    return lista;
}

void extraer(Fila* filita)
{

    if(filita->inicio != NULL)
    {
        filita->inicio = borrarPrimerNodo(filita->inicio);
    }

    if(filita->inicio == NULL)
    {
        filita->fin == NULL;
    }
}


/// Vaciar una fila por completo y devolver el resultado
int vaciarFila(Fila** filita)
{
    int i = 0;
    while (*filita != NULL)
    {
        extraer(filita);
        i++;

    }
    return i;
}




*/

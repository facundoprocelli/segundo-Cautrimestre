#ifndef ARBOLES_H_INCLUDED
#define ARBOLES_H_INCLUDED


typedef struct {
     int legajo;
     char nombre[20];
     int edad;
} persona;


typedef struct nodoArbol {
     persona dato;
     struct nodoArbol * izq;
     struct nodoArbol * der;
} nodoArbol;


nodoArbol* buscarNodo(nodoArbol* arbol, int dato);
nodoArbol* insertarNodo(nodoArbol* raiz, nodoArbol* NN);
nodoArbol* inicarbol();
persona cargarPersona(int legajo, char nombre[20], int edad);
void inorder(nodoArbol* raiz);
void preorder(nodoArbol* raiz);
void postorder(nodoArbol* raiz);
persona cargarPersona(int legajo, char nombre[20], int edad);
int esHoja(nodoArbol* raiz);



nodoArbol* cargarNodo(persona per);





#endif // ARBOLES_H_INCLUDED

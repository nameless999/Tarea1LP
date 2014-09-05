#ifndef _LISTA_H_INCLUDED_
#define _LISTA_H_INCLUDED_

typedef struct nodo
{
        void *info;
        char label; // S si es un switch, E si es un enemigo
        struct nodo *siguiente;
}tNodo;

typedef struct Lista {
        tNodo *head;
        tNodo *tail;
        tNodo *curr;
        unsigned int listSize;
        unsigned int pos;
}tLista;

tLista* inicializacion ();
void printA(tLista *lista);
 
 #endif
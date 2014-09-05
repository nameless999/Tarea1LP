#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
 
tLista* inicializacion ()
{
        tLista *lista;
        lista = (tLista *)malloc(sizeof(tLista));
        lista->head = NULL;
        lista->tail = NULL;
        lista->curr = NULL;
        lista->listSize = 0;
        lista->pos = 0;
        return lista;
}
 
void moveToStart(tLista *lista) 
{
    lista->curr = lista->head; 
    lista->pos = 0;
}

void moveToEnd(tLista *lista) 
{
    lista->curr = lista->tail; 
    lista->pos = lista->listSize;
}

void moveToNext(tLista *lista) 
{
    if (lista->curr != NULL)
    {
        lista->curr = lista->curr->siguiente;
        lista->pos++;
    }
}
 
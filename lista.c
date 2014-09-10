#include "lista.h"

tLista *inicializacion()
{
        tLista *lista;
        lista = (tLista *)malloc(sizeof(tLista));
        lista->head =  NULL;
        lista->curr =  NULL;
        lista->tail = NULL;
        lista->listSize = 0;
        lista->pos = 0;
        return lista;
}
 
void moveToStart(tLista *lista) 
{    
    lista->curr = lista->head;
    lista->pos = 0;
}


void moveToNext(tLista *lista) 
{
    if (lista->curr != lista->tail)
    {
        lista->curr = lista->curr->siguiente;   
    }
    lista->pos++;
}
 
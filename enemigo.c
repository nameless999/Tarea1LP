#include "lista.c"

#include "enemigo.h"

tEnemigo* crearEnemigo( char tipo, int maxmov, int pasos, char direccion, int x, int y)
{
        tEnemigo *enemigo;
        enemigo = (tEnemigo *)malloc(sizeof(tEnemigo));
        enemigo->tipo = tipo;
        enemigo->siguiente_movimiento = siguiente_movimiento;
        enemigo->maxmov = maxmov;
        enemigo->pasos = pasos;
        enemigo->direccion = direccion;
        enemigo->x = x;
        enemigo->y = y;
        return enemigo;
}
 
void agregarEnemigo(tLista *lista, tEnemigo *enemigo)
{
        if(lista->curr == NULL)
        {
                lista->curr = (tNodo *)malloc(sizeof(tNodo));
                lista->curr->info = enemigo;
                lista->tail = lista->curr;
                lista->head = lista->curr;
                lista->curr->label = 'E';
                lista->listSize++;
        }
 
        else
        {
                tNodo *aux = lista->curr->siguiente;
                lista->curr->siguiente = (tNodo *)malloc(sizeof(tNodo));
                lista->curr->siguiente->info = (void*) enemigo;
                lista->curr->siguiente->siguiente = aux;
                lista->curr->label = 'E';

                if (lista->curr == lista->tail) lista->tail = lista->curr->siguiente;
                lista->listSize++;
        }
}

tLista *crearListaEnemigos(char **map, int largo, int ancho) 
{
    tLista *enemigos;
    enemigos = inicializacion();
    int y,x;
    for (y = 0; y < largo; ++y)
    {   
        for (x = 0; x < ancho; ++x)
        {
            if(map[y][x] == '2')
            {
                agregarEnemigo(enemigos, crearEnemigo('H',2,0,'R',x,y)); //Horizontal, derecha
            }
            else if (map[y][x] == '3')
            {
                agregarEnemigo(enemigos,crearEnemigo('V',2,0,'U',x,y)); //Vertical, arriba 
            }

            else if (map[y][x] == '4')
            {
                agregarEnemigo(enemigos, crearEnemigo('H',3,0,'L',x,y)); //Horizontal, left
                
            }

            else if (map[y][x] == '5')
            {
                agregarEnemigo(enemigos,  crearEnemigo('V',3,0,'D',x,y)); //Vertical, abajo
               
            }   

            else if (map[y][x] == '6')
            {
                agregarEnemigo(enemigos, crearEnemigo('H',4,0,'R',x,y));
                
            }

            else if (map[y][x] == '7')
            {
                agregarEnemigo(enemigos, crearEnemigo('V',4,0,'U',x,y));
                
            }

            else if (map[y][x] == '8')
            {
                agregarEnemigo(enemigos, crearEnemigo('H',5,0,'L',x,y));
            }

            else if (map[y][x] == '9')
            {
                agregarEnemigo(enemigos,crearEnemigo('V',5,0,'D',x,y));
            }
        }
    }
    return enemigos;
}

char siguiente_movimiento(void *general, char **map, int x, int y)
{
    tEnemigo *enemigo;
    enemigo = (tEnemigo *)general;
    printf("%c\n", enemigo->tipo );
    if(enemigo->tipo == 'H')
    {
        if(enemigo->direccion =='D')
        {
            if (map[y][x+2] == '0')
            {
                if(enemigo->maxmov != enemigo->pasos)
                {
                    map[y][x] = '0';
                    map[y][x+2] = '1';
                    enemigo->maxmov--;
                    enemigo->pasos++;
                    return '1';
                }
            }

            else if(map[y][x+2] == '*')
            {
                return '2'; 
            }

            else 
            {
                enemigo->direccion == 'I';
                siguiente_movimiento(enemigo,map,x,y);
            }
        }

        else if(enemigo->direccion == 'I')
        {
            if(map[y][x-2] == '0')
            {
                if(enemigo->maxmov != enemigo->pasos)
                {
                    map[y][x] = '0';
                    map[y][x+2] = '1';
                    enemigo->maxmov--;
                    enemigo->pasos++;
                    return '1';
                }
            }

            else if(map[y][x+2] == '*')
            {
                return '2'; 
            }

            else 
            {
                enemigo->direccion == 'I';
                siguiente_movimiento(enemigo,map,x,y);
            }
        }
    }

    else if (enemigo->tipo == 'V')
    {
        if(enemigo->direccion =='U')
        {
            if (map[y-1][x] == '0')
            {
                if(enemigo->maxmov != enemigo->pasos)
                {
                    map[y][x] = '0';
                    map[y-1][x] = '1';
                    enemigo->maxmov--;
                    enemigo->pasos++;
                    return '1';
                }
            }

            else if(map[y-1][x] == '*')
            {
                return '2'; 
            }

            else 
            {
                enemigo->direccion == 'D';
                siguiente_movimiento(enemigo,map,x,y);
            }
        }

        else if(enemigo->direccion == 'D')
        {
            if(map[y+1][x] == '0')
            {
                if(enemigo->maxmov != enemigo->pasos)
                {
                    map[y][x] = '0';
                    map[y+1][x] = '1';
                    enemigo->maxmov--;
                    enemigo->pasos++;
                    return '1';
                }
            }

            else if(map[y+1][x] == '*')
            {
                return '2'; 
            }

            else 
            {
                enemigo->direccion == 'U';
                siguiente_movimiento(enemigo,map,x,y);
            }
        }
    }
}

char movEnemigos(tLista *listaEnemigos, char **map)
{
    void *general;
    tEnemigo *enemigo;
    char a;
    int x,y;
    moveToStart(listaEnemigos);
    while(listaEnemigos->listSize != listaEnemigos->pos || a == '2')
    {   
        enemigo = (tEnemigo *)listaEnemigos->curr->info;
        x = enemigo->x;
        y = enemigo->y;
        general = &listaEnemigos->curr->info;
        a = enemigo->siguiente_movimiento(general, map , x, y);   
        moveToNext(listaEnemigos);        
    }
    return a;

}

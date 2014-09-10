#include "lista.c"
#include "enemigo.h"

tEnemigo* crearEnemigo( char tipo, int maxmov, int pasos, char direccion, int x, int y, char nombre)
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
        enemigo->nombre= nombre;
        return enemigo;
}
 
void agregarEnemigo(tLista *lista, tEnemigo *enemigo)
{

    if(lista->listSize == 0)
    {
        lista->head = lista->curr =  lista->tail = (tNodo*)malloc(sizeof(tNodo));
        lista->head->info  = enemigo;
        lista->head->label = 'E';
        lista->listSize++;
    }

    else
    {
        lista->tail->siguiente = (tNodo*)malloc(sizeof(tNodo));
        lista->tail = lista->tail->siguiente;
        lista->tail->info = enemigo;
        lista->tail->label = 'E';
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
                agregarEnemigo(enemigos, crearEnemigo('H',2,0,'R',x,y,'2')); //Horizontal, right
            }
            else if (map[y][x] == '3')
            {
                agregarEnemigo(enemigos,crearEnemigo('V',2,0,'U',x,y,'3')); //Vertical, arriba 
            }

            else if (map[y][x] == '4')
            {
                agregarEnemigo(enemigos, crearEnemigo('H',3,0,'L',x,y,'4')); //Horizontal, left
                
            }

            else if (map[y][x] == '5')
            {
                agregarEnemigo(enemigos,  crearEnemigo('V',3,0,'D',x,y,'5')); //Vertical, abajo
            }   

            else if (map[y][x] == '6')
            {
                agregarEnemigo(enemigos, crearEnemigo('H',4,0,'R',x,y,'6'));
            }

            else if (map[y][x] == '7')
            {
                agregarEnemigo(enemigos, crearEnemigo('V',4,0,'U',x,y,'7'));
            }

            else if (map[y][x] == '8')
            {
                agregarEnemigo(enemigos, crearEnemigo('H',5,0,'L',x,y,'8'));
            }

            else if (map[y][x] == '9')
            {
                agregarEnemigo(enemigos,crearEnemigo('V',5,0,'D',x,y,'9'));
            }
        }
    }

    return enemigos;
}

char siguiente_movimiento(void *general, char **map, int x, int y)
{

    tEnemigo *enemigo;
    enemigo = (tEnemigo *)general;

    if(enemigo->tipo == 'H')
    {
        if(enemigo->direccion =='R')
        {
            if (map[y][x+2] == '0')
            {
                if(enemigo->maxmov != enemigo->pasos)
                {
                    map[y][x] = '0';
                    map[y][x+2] = enemigo->nombre;
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
                enemigo->direccion = 'L';
                return '1';
            }
        }

        else if(enemigo->direccion == 'L')
        {
            if(map[y][x-2] == '0')
            {
                if(enemigo->maxmov != enemigo->pasos)
                {
                    map[y][x] = '0';
                    map[y][x+2] = enemigo->nombre;
                    enemigo->maxmov--;
                    enemigo->pasos++;
                    return '1';
                }
            }

            else if(map[y][x-2] == '*')
            {
                return '2'; 
            }

            else 
            {
                enemigo->direccion = 'R';
                map[y][x] = '0';
                map[y][x+2] = enemigo->nombre;
                enemigo->maxmov--;
                enemigo->pasos++;
                return '1';
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
                    map[y-1][x] = enemigo->nombre;
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
                enemigo->direccion = 'D';
                return '1';
            }
        }

        else if(enemigo->direccion == 'D')
        {
            if(map[y+1][x] == '0')
            {
                if(enemigo->maxmov != enemigo->pasos)
                {
                    map[y][x] = '0';
                    map[y+1][x] = enemigo->nombre;
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
                enemigo->direccion = 'U';
                return '1';
            }
        }
    }

    return '2';
}

char movEnemigos(tLista *listaEnemigos, char **map)
{
    void *general;
    tEnemigo *enemigo;
    char a;
    int x1,y1,i;
    moveToStart(listaEnemigos);   
    i = 0;
    while(listaEnemigos->listSize != listaEnemigos->pos || a == '2')
    {   
        general = listaEnemigos->curr->info;
        enemigo = (tEnemigo*)listaEnemigos->curr->info;
        x1 = enemigo->x;
        y1 = enemigo->y;
        a = enemigo->siguiente_movimiento(general, map ,x1,y1);
        moveToNext(listaEnemigos); 
    }
    return a;
}

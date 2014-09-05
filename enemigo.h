#ifndef _ENEMIGO_H_INCLUDED_
#define _ENEMIGO_H_INCLUDED_

typedef struct
{
        char(*siguiente_movimiento)(void *,char **,int,int);
        char tipo;
        int maxmov;
        int pasos;
        char direccion;
        int y;
        int x;
}tEnemigo;


tEnemigo* crearEnemigo( char tipo, int maxmov, int pasos, char direccion, int x,int y);
void printEnemigo(tEnemigo *enemigo);
char siguiente_movimiento(void *, char **map, int x, int y);


 
#endif
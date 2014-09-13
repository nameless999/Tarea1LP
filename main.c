#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaElementos.c"
#include "enemigos.c"
#include "interruptores.c"
#include "listapuertas.c"

void Switch(char **map, tLista *lista, char label)
{
   void *general;
   tSwitch* Switch;
   moveToStart(lista);
   while(lista->listSize != lista->pos)
   {

      if(lista->curr->label == 'S')
      {
         Switch = (tSwitch*)lista->curr->info;
         if(Switch->label == label)
         {
            general = Switch;
            activar_switch(general,map);
         }
      }
      moveToNext(lista);
   }
}

/******** Función: dontMove ********
Descripción: jugador selecciona mantenerse en posición actual
Parametros: string literal (entrada), posición actual
Retorno: entero característico de la función (label)
****************************************/
int dontMove(char **map, int *pos,tLista *listaEnemigosSwitch) // X
{
      

   if(map[pos[0]][pos[1]] == 'a') //Si la casilla actual es == a (Switch)...
   {
      printf ("\033[2J\033[1;1H"); 
      printf("Te has quedado quieto en la posición (%d,%d) y has activado el Switch 'a' <('o'<).\n\n\n\n", pos[0], pos[2]);
      Switch(map,listaEnemigosSwitch,'a');
      return '1';
   }

   else if(map[pos[0]][pos[1]] == 'b') //Si la casilla de la derecha es == a (Switch)...
   {
      printf ("\033[2J\033[1;1H"); 
      printf("Te has quedado quieto en la posición (%d,%d) y has activado el Switch 'b' <('o'<).\n\n\n\n", pos[0], pos[2]);
      Switch(map,listaEnemigosSwitch,'b');
      return '1';
   }

   else if(map[pos[0]][pos[1]] == 'c') //Si la casilla de la derecha es == a (Switch)...
   {
      printf ("\033[2J\033[1;1H"); 
      printf("Te has quedado quieto en la posición (%d,%d) y has activado el Switch 'c' <('o'<).\n\n\n\n", pos[0], pos[2]);
      Switch(map,listaEnemigosSwitch,'c');
      return '1';
   }

   else
   {
      printf ("\033[2J\033[1;1H"); 
      printf("Te has quedado quieto en la posición (%d,%d) <('o'<).\n\n\n\n", pos[0], pos[2]);
      return '1';
   }

}

/******** Función: movDown ********
Descripción: jugador ejecuta movimiento hacia abajo desde su posición actual
Parámetros: string literal (entrada), posición actual
Retorno: entero característico de la función (label)
****************************************/
int movDown(char **map, int *pos, tLista *listaEnemigosSwitch) // W
{
   char nombreEnemigo;
   if(map[pos[0]+1][pos[1]] == '0') //Si la casilla de abajo es == 0 (válida)...
   {
      printf ("\033[2J\033[1;1H");
      if(map[pos[0]][pos[1]] == '*' || map[pos[0]][pos[1]] == 'I' )
      {
         map[pos[0]][pos[1]] = '0'; //Dejamos la posición I como 0 para que sea válida otra vez.
      }  
      map[pos[0]+1][pos[1]] = '*'; //Nos movemos a la casilla de abjao
      pos[0] += 1; //Dejamos nuestra fila como 0
      pos[1] = pos[1]; //Dejamos nuestra columna como 2, es decir, una casilla a la derecha de la pos actual
      printf("Te has movido a la posición (%d,%d).\n\n\n\n", pos[0], pos[2]);
      return '1';
   }

   else if(map[pos[0]+1][pos[1]] == 'F')
   {
      return '2';
   }   

   else if(map[pos[0]+1][pos[1]] == '1')
   {
      printf ("\033[2J\033[1;1H");
      printf("┬┴┬┴┤(･_├┬┴┬┴ UPS! Hay una gran muralla delante tuyo, debes buscar otro camino.\n\n\n\n");
      return '5';
   }

   else if(map[pos[0]+1][pos[1]] == 'A')
   {
      printf ("\033[2J\033[1;1H");   
      printf("La puerta está cerrada, busca el switch 'a' para abrirla. ¯_(ツ)_/¯ \n\n\n\n");
      return '5';
   }


   else if(map[pos[0]+1][pos[1]] == 'a') //Si la casilla de la derecha es == a (Switch)...
   {
      printf ("\033[2J\033[1;1H");  
      map[pos[0]][pos[1]] = '0'; //Dejamos la posición I como 0 para que sea válida otra vez.  
      pos[0] += 1; //Dejamos nuestra fila como 0
      pos[1] = pos[1]; //Dejamos nuestra columna como 2, es decir, una casilla a la derecha de la pos actual
      printf("Te has movido a la posición (%d,%d) sobre el Switch a y has abierto la puerta A.\n\n\n\n", pos[0], pos[2]);
      Switch(map, listaEnemigosSwitch, 'a');
      return '1';
   }

   else if(map[pos[0]+1][pos[1]] == 'B')
   {
      printf ("\033[2J\033[1;1H");   
      printf("La puerta está cerrada, busca el switch 'b' para abrirla.\n");
      return '5';
   }

   else if(map[pos[0]+1][pos[1]] == 'b') //Si la casilla de la derecha es == a (Switch)...
   {  
      printf ("\033[2J\033[1;1H");
      map[pos[0]][pos[1]] = '0'; //Dejamos la posición I como 0 para que sea válida otra vez.  
      pos[0] += 1; //Dejamos nuestra fila como 0
      pos[1] = pos[1]; //Dejamos nuestra columna como 2, es decir, una casilla a la derecha de la pos actual
      printf("Te has movido a la posición (%d,%d) sobre el Switch b y has abierto la puerta B.\n\n\n\n", pos[0], pos[2]);
      Switch(map, listaEnemigosSwitch, 'b');
      return '1';
   }

   else if(map[pos[0]+1][pos[1]] == 'C')
   {
      printf ("\033[2J\033[1;1H");   
      printf("La puerta está cerrada, busca el switch 'c' para abrirla.\n");
      return '5';
   }


   else if(map[pos[0]+1][pos[1]] == 'c') //Si la casilla de la derecha es == a (Switch)...
   {
      printf ("\033[2J\033[1;1H");
      map[pos[0]][pos[1]] = '0'; //Dejamos la posición I como 0 para que sea válida otra vez.  
      pos[0] += 1; //Dejamos nuestra fila como 0
      pos[1] = pos[1]; //Dejamos nuestra columna como 2, es decir, una casilla a la derecha de la pos actual
      printf("Te has movido a la posición (%d,%d) sobre el Switch c y has abierto la puerta C.\n\n\n\n", pos[0], pos[2]);
      Switch(map, listaEnemigosSwitch, 'c');
      return '1';
   }

   else
   {
      return '0';
   }
   
}

/******** Función: movUp ********
Descripción: jugador ejecuta movimiento hacia arriba desde su posición actual
Parámetros: string literal (entrada), posición actual
Retorno: entero característico de la función (label)
****************************************/
int movUp(char **map, int *pos, tLista *listaEnemigosSwitch) // S
{
   char nombreEnemigo;
   if(map[pos[0]-1][pos[1]] == '0') //Si la casilla de abajo es == 0 (válida)...
   {
      printf ("\033[2J\033[1;1H");
      if(map[pos[0]][pos[1]] == '*' || map[pos[0]][pos[1]] == 'I' )
      {
         map[pos[0]][pos[1]] = '0'; //Dejamos la posición I como 0 para que sea válida otra vez.
      }  
      map[pos[0]-1][pos[1]] = '*'; //Nos movemos a la casilla de abjao
      pos[0] -= 1; //Dejamos nuestra fila como 0
      pos[1] = pos[1]; //Dejamos nuestra columna como 2, es decir, una casilla a la derecha de la pos actual
      printf("Te has movido a la posición (%d,%d).\n\n\n\n", pos[0], pos[2]);
      return '1';
   }

   else if(map[pos[0]-1][pos[1]] == 'F')
   {
      return '2';
   }

   else if(map[pos[0]-1][pos[1]] == '1')
   {
      printf ("\033[2J\033[1;1H");
      printf("┬┴┬┴┤(･_├┬┴┬┴ UPS! Hay una gran muralla delante tuyo, debes buscar otro camino.\n\n\n\n");
      return '5';
   }

   else if(map[pos[0]-1][pos[1]] == 'A')
   {
      printf ("\033[2J\033[1;1H");   
      printf("La puerta está cerrada, busca el switch 'a' para abrirla. ¯_(ツ)_/¯ \n\n\n\n");
      return '5';
   }


   else if(map[pos[0]-1][pos[1]] == 'a') //Si la casilla de la derecha es == a (Switch)...
   {  
      printf ("\033[2J\033[1;1H");
      map[pos[0]][pos[1]] = '0'; //Dejamos la posición I como 0 para que sea válida otra vez.  
      pos[0] -= 1; //Dejamos nuestra fila como 0
      pos[1] = pos[1]; //Dejamos nuestra columna como 2, es decir, una casilla a la derecha de la pos actual
      printf("Te has movido a la posición (%d,%d) sobre el Switch a y has abierto la puerta A.\n\n\n\n", pos[0], pos[2]);
      Switch(map, listaEnemigosSwitch, 'a');
      return '1';
   }

   else if(map[pos[0]-1][pos[1]] == 'B')
   {
      printf ("\033[2J\033[1;1H");   
      printf("La puerta está cerrada, busca el switch 'b' para abrirla.\n\n\n\n");
      return '5';
   }

   else if(map[pos[0]-1][pos[1]] == 'b') //Si la casilla de la derecha es == a (Switch)...
   {
      printf ("\033[2J\033[1;1H");
      map[pos[0]][pos[1]] = '0'; //Dejamos la posición I como 0 para que sea válida otra vez.  
      pos[0] -= 1; //Dejamos nuestra fila como 0
      pos[1] = pos[1]; //Dejamos nuestra columna como 2, es decir, una casilla a la derecha de la pos actual
      printf("Te has movido a la posición (%d,%d) sobre el Switch b y has abierto la puerta B.\n\n\n\n", pos[0], pos[2]);
      Switch(map, listaEnemigosSwitch, 'b');
      return '1';
   }

   else if(map[pos[0]-1][pos[1]] == 'C')
   {
      printf ("\033[2J\033[1;1H");   
      printf("La puerta está cerrada, busca el switch 'c' para abrirla.\n\n\n\n");
      return '5';
   }


   else if(map[pos[0]-1][pos[1]] == 'c') //Si la casilla de la derecha es == a (Switch)...
   {
      printf ("\033[2J\033[1;1H");
      map[pos[0]][pos[1]] = '0'; //Dejamos la posición I como 0 para que sea válida otra vez.  
      pos[0] -= 1; //Dejamos nuestra fila como 0
      pos[1] = pos[1]; //Dejamos nuestra columna como 2, es decir, una casilla a la derecha de la pos actual
      printf("Te has movido a la posición (%d,%d) sobre el Switch c y has abierto la puerta C.\n\n\n\n", pos[0], pos[2]);
      Switch(map, listaEnemigosSwitch, 'c');
      return '1';
   }
   else
   {
      return '0';
   }
}

/******** Función: movLeft ********
Descripción: jugador ejecuta movimiento hacia la izquierda desde su posición actual
Parámetros: string literal (entrada), posición actual
Retorno: entero característico de la función (label)
****************************************/
int movLeft(char **map, int *pos, tLista *listaEnemigosSwitch) // A
{
      if(map[pos[0]][pos[1]-2] == '0') //Si la casilla que está a la derecha es == 0 (válida)...
      {
         printf ("\033[2J\033[1;1H"); 
         if(map[pos[0]][pos[1]] == '*' || map[pos[0]][pos[1]] == 'I' )
         {
            map[pos[0]][pos[1]] = '0'; //Dejamos la posición I como 0 para que sea válida otra vez.
         }    
         map[pos[0]][pos[1]-2] = '*'; //Nos movemos a la casilla de la derecha map[pos[0][pos[1]-2] == (0,2).
         pos[0] = pos[0]; //Dejamos nuestra fila como 0
         pos[1] -= 2; //Dejamos nuestra columna como 2, es decir, una casilla a la derecha de la pos actual
         pos[2] -= 1;
         printf("Te has movido a la posición (%d,%d).\n\n\n\n", pos[0], pos[2]);
         return '1';
      }

      else if(map[pos[0]][pos[1]-2] == 'F')
      {
         return '2';
      }

      else if(map[pos[0]][pos[1]-2] == '1') //Si la casilla de la derecha es == 1 (muralla)...
      {
         printf ("\033[2J\033[1;1H");               
         printf("┬┴┬┴┤(･_├┬┴┬┴ UPS! Hay una gran muralla delante tuyo, debes buscar otro camino.\n\n\n\n");
         return '5';
      }

      else if(map[pos[0]][pos[1]-2] == 'A') //Si la casilla de la derecha es == A (Puerta)...  
      {
         printf ("\033[2J\033[1;1H");
         printf("La puerta está cerrada, busca el switch 'a' para abrirla. ¯_(ツ)_/¯ \n\n\n\n");
         return '5';
      }

      else if(map[pos[0]][pos[1]-2] == 'a') //Si la casilla de la derecha es == a (Switch)...
      {
         printf ("\033[2J\033[1;1H"); 
         map[pos[0]][pos[1]] = '0'; //Dejamos la posición I como 0 para que sea válida otra vez.   
         pos[0] = pos[0]; //Dejamos nuestra fila como 0
         pos[1] -= 2; //Dejamos nuestra columna como 2, es decir, una casilla a la derecha de la pos actual
         pos[2] -= 1;
         printf("Te has movido a la posición (%d,%d) sobre el Switch a y has abierto la puerta A.\n\n\n\n", pos[0], pos[2]);
         Switch(map, listaEnemigosSwitch, 'a');
         return '1';
      }

      else if(map[pos[0]][pos[1]-2] == 'B')
      {
         printf ("\033[2J\033[1;1H");   
         printf("La puerta está cerrada, busca el switch 'b' para abrirla.\n\n\n\n");
         return '5';
      }


      else if(map[pos[0]][pos[1]-2] == 'b') //Si la casilla de la derecha es == a (Switch)...
      {
         printf ("\033[2J\033[1;1H"); 
         map[pos[0]][pos[1]] = '0'; //Dejamos la posición I como 0 para que sea válida otra vez.   
         pos[0] = pos[0]; //Dejamos nuestra fila como 0
         pos[1] -= 2; //Dejamos nuestra columna como 2, es decir, una casilla a la derecha de la pos actual
         pos[2] -= 1;
         printf("Te has movido a la posición (%d,%d) sobre el Switch a y has abierto la puerta A.\n\n\n\n", pos[0], pos[2]);
         Switch(map, listaEnemigosSwitch, 'b');
         return '1';
      }

      else if(map[pos[0]][pos[1]-2] == 'C')
      {
         printf ("\033[2J\033[1;1H");   
         printf("La puerta está cerrada, busca el switch 'c' para abrirla.\n\n\n\n");
         return '5';
      }

      else if(map[pos[0]][pos[1]-2] == 'c') //Si la casilla de la derecha es == a (Switch)...
      {
         printf ("\033[2J\033[1;1H"); 
         map[pos[0]][pos[1]] = '0'; //Dejamos la posición I como 0 para que sea válida otra vez.   
         pos[0] = pos[0]; //Dejamos nuestra fila como 0
         pos[1] -= 2; //Dejamos nuestra columna como 2, es decir, una casilla a la derecha de la pos actual
         pos[2] -= 1;
         printf("Te has movido a la posición (%d,%d) sobre el Switch a y has abierto la puerta A.\n\n\n\n", pos[0], pos[2]);
         Switch(map, listaEnemigosSwitch, 'c');
         return '1';
      }

      else
      {
         return '0';
      }
}

/******** Función: movRight ********
Descripción: jugador ejecuta movimiento hacia la derecha desde su posición actual
Parámetros: string literal (entrada), posición actual
Retorno: entero característico de la función (label)
****************************************/
int movRight(char **map, int *pos, tLista *listaEnemigosSwitch) // D
{
   if(map[pos[0]][pos[1]+2] == '0') //Si la casilla que está a la derecha es == 0 (válida)...
      {
         printf ("\033[2J\033[1;1H"); 
         if(map[pos[0]][pos[1]] == '*' || map[pos[0]][pos[1]] == 'I' )
         {
            map[pos[0]][pos[1]] = '0'; //Dejamos la posición I como 0 para que sea válida otra vez.
         }     
         map[pos[0]][pos[1]+2] = '*'; //Nos movemos a la casilla de la derecha map[pos[0][pos[1]+2] == (0,2).
         pos[0] = pos[0]; //Dejamos nuestra fila como 0
         pos[1] += 2; //Dejamos nuestra columna como 2, es decir, una casilla a la derecha de la pos actual
         pos[2] += 1;
         printf("Te has movido a la posición (%d,%d).\n\n\n\n", pos[0], pos[2]);
         return '1';
      }

      else if(map[pos[0]][pos[1]+2] == 'F')
      {
         return '2';
      }          

      else if(map[pos[0]][pos[1]+2] == '1') //Si la casilla de la derecha es == 1 (muralla)...
      {
         printf ("\033[2J\033[1;1H");               
         printf("┬┴┬┴┤(･_├┬┴┬┴ UPS! Hay una gran muralla delante tuyo, debes buscar otro camino.\n\n\n\n");
         return '5';
      }

      else if(map[pos[0]][pos[1]+2] == 'A') //Si la casilla de la derecha es == A (Puerta)...  
      {
         printf ("\033[2J\033[1;1H");
         printf("La puerta está cerrada, busca el switch 'a' para abrirla. ¯_(ツ)_/¯ \n\n\n\n");
         return '5';
      }

      else if(map[pos[0]][pos[1]+2] == 'a') //Si la casilla de la derecha es == a (Switch)...
      {
         printf ("\033[2J\033[1;1H"); 
         map[pos[0]][pos[1]] = '0'; //Dejamos la posición I como 0 para que sea válida otra vez.   
         pos[0] = pos[0]; //Dejamos nuestra fila como 0
         pos[1] += 2; //Dejamos nuestra columna como 2, es decir, una casilla a la derecha de la pos actual
         pos[2] += 1;
         printf("Te has movido a la posición (%d,%d) sobre el Switch a y has abierto la puerta A.\n\n\n\n", pos[0], pos[2]);
         Switch(map, listaEnemigosSwitch, 'a');
         return '1';
      }

      else if(map[pos[0]][pos[1]+2] == 'B')
      {
         printf ("\033[2J\033[1;1H");   
         printf("La puerta está cerrada, busca el switch 'b' para abrirla.\n\n\n\n");
         return '5';
      }


      else if(map[pos[0]][pos[1]+2] == 'b') //Si la casilla de la derecha es == a (Switch)...
      {
         printf ("\033[2J\033[1;1H"); 
         map[pos[0]][pos[1]] = '0'; //Dejamos la posición I como 0 para que sea válida otra vez.   
         pos[0] = pos[0]; //Dejamos nuestra fila como 0
         pos[1] += 2; //Dejamos nuestra columna como 2, es decir, una casilla a la derecha de la pos actual
         pos[2] += 1;
         printf("Te has movido a la posición (%d,%d) sobre el Switch b y has abierto la puerta B.\n\n\n\n", pos[0], pos[2]);
         Switch(map, listaEnemigosSwitch, 'b');
         return '1';
      }

      else if(map[pos[0]][pos[1]+2] == 'C')
      {
         printf ("\033[2J\033[1;1H");   
         printf("La puerta está cerrada, busca el switch 'c' para abrirla.\n\n\n\n");
         return '5';
      }


      else if(map[pos[0]][pos[1]+2] == 'c') //Si la casilla de la derecha es == a (Switch)...
      {
         printf ("\033[2J\033[1;1H"); 
         map[pos[0]][pos[1]] = '0'; //Dejamos la posición I como 0 para que sea válida otra vez.   
         pos[0] = pos[0]; //Dejamos nuestra fila como 0
         pos[1] += 2; //Dejamos nuestra columna como 2, es decir, una casilla a la derecha de la pos actual
         pos[2] += 1;
         printf("Te has movido a la posición (%d,%d) sobre el Switch c y has abierto la puerta C.\n\n\n\n", pos[0], pos[2]);
         Switch(map, listaEnemigosSwitch, 'c');
         return '1';
      }

      else
      {
         return '0';
      }
}

   /******** Función: movUsuario ********
Descripción: ejecuta función según la tecla ingresada por el jugador (movimiento) 
Parámetros: string literal (entrada), posición actual, largo y ancho del mapa
Retorno:  
****************************************/
int movUsuario(tLista *listaEnemigosSwitch,char **map, int *pos, int largo, int ancho)
{
   int x,y;
   char tecla;
   tecla = getchar(); //Pedimos un movimiento al usuario (ASWD)   

   if (pos[0] == largo-1 && pos[1] == ancho-2) // Esquina inferior derecha
   {

      if (tecla == 'x' || tecla == 'X') //Es decir, me quedo quieto.
      {
         return dontMove(map,pos,listaEnemigosSwitch);
      }

      else if (tecla == 'd' || tecla == 'D') //Si presionamos la tecla D, es decir a la derecha...
      {
         printf ("\033[2J\033[1;1H"); 
         printf("Aquí no hay nada de nada, vuelva a intentarlo. (ﾉ◕ ヮ◕ )ﾉ*:･ﾟ✧\n\n\n\n");
         return '5';   
      }

      else if (tecla == 'w' || tecla == 'W')
      {
         return movUp(map,pos,listaEnemigosSwitch); 
      }

      else if (tecla == 's' || tecla == 'S') //Si presion la tecla S, es decir abajo....
      {
         printf ("\033[2J\033[1;1H"); 
         printf("Aquí no hay nada de nada, vuelva a intentarlo. (ﾉ◕ ヮ◕ )ﾉ*:･ﾟ✧\n\n\n\n");
         return '5';   
      }

      else if (tecla == 'a' || tecla =='A')
      {
        return movLeft(map,pos,listaEnemigosSwitch);
      }
   }
   else if (pos[0] == 0 && pos[1] == 0) //Esquina superior izquierda
   {
         if (tecla == 'x' || tecla == 'X')
         {
            return dontMove(map,pos,listaEnemigosSwitch);
         }

         else if (tecla == 'd' || tecla == 'D') //Si presionamos la tecla D, es decir a la derecha...
         {
            return movRight(map,pos,listaEnemigosSwitch);
         }

         else if (tecla == 's' || tecla == 'S') //Si presion la tecla S, es decir abajo....
         {
            return movDown(map,pos,listaEnemigosSwitch);
         }

         else if(tecla == 'w' || tecla == 'W')
         {
            printf ("\033[2J\033[1;1H"); 
            printf("Aquí no hay nada de nada, vuelva a intentarlo. (ﾉ◕ ヮ◕ )ﾉ*:･ﾟ✧\n\n\n\n");
            return '5';   
         }

         else if (tecla == 'a' || tecla == 'A')
         {
            printf ("\033[2J\033[1;1H"); 
            printf("Aquí no hay nada de nada, vuelva a intentarlo. (ﾉ◕ ヮ◕ )ﾉ*:･ﾟ✧\n\n\n\n");
            return '5';
         }     
   }
   else if(pos[0] == 0 && pos[1] == ancho-2 ) // Esquina superior derecha
   {
      if (tecla == 'x' || tecla == 'X') //Es decir, me quedo quieto.
      {
         return dontMove(map,pos,listaEnemigosSwitch);
      }

      else if (tecla == 'd' || tecla == 'D') //Si presionamos la tecla D, es decir a la derecha...
      {
         printf ("\033[2J\033[1;1H"); 
         printf("Aquí no hay nada de nada, vuelva a intentarlo. (ﾉ◕ ヮ◕ )ﾉ*:･ﾟ✧\n\n\n\n");
         return '5';   
      }

      else if (tecla == 'w' || tecla == 'W')
      {
         printf ("\033[2J\033[1;1H"); 
         printf("Aquí no hay nada de nada, vuelva a intentarlo. (ﾉ◕ ヮ◕ )ﾉ*:･ﾟ✧\n\n\n\n");
         return '5';  
      }

      else if (tecla == 's' || tecla == 'S') //Si presion la tecla S, es decir abajo....
      {
         return movDown(map,pos,listaEnemigosSwitch);   
      }

      else if (tecla == 'a' || tecla =='A')
      {
        return movLeft(map,pos,listaEnemigosSwitch);
      }  
   }
   else if(pos[0] == largo-1 && pos[1] == 0) // Esquina inferior izquierda
   {
      if (tecla == 'x' || tecla == 'X') //Es decir, me quedo quieto.
      {
         return dontMove(map,pos,listaEnemigosSwitch);
      }

      else if (tecla == 'd' || tecla == 'D') //Si presionamos la tecla D, es decir a la derecha...
      {
         return movRight(map,pos,listaEnemigosSwitch);   
      }  

      else if (tecla == 'w' || tecla == 'W')
      {
         return movUp(map,pos,listaEnemigosSwitch); 
      }

      else if (tecla == 's' || tecla == 'S') //Si presion la tecla S, es decir abajo....
      {
         printf ("\033[2J\033[1;1H"); 
         printf("Aquí no hay nada de nada, vuelva a intentarlo. (ﾉ◕ ヮ◕ )ﾉ*:･ﾟ✧\n\n\n\n");
         return '5';      
      }

      else if (tecla == 'a' || tecla =='A')
      {
         printf ("\033[2J\033[1;1H"); 
         printf("Aquí no hay nada de nada, vuelva a intentarlo. (ﾉ◕ ヮ◕ )ﾉ*:･ﾟ✧\n\n\n\n");
         return '5';   
      }  
   }
   else if (pos[0] != 0 && pos[1] == 0) //Cuando estoy en el (x,0)
   {
      
      if (tecla == 'x' || tecla == 'X') //Es decir, me quedo quieto.
      {
         return dontMove(map,pos,listaEnemigosSwitch);
      }

      else if (tecla == 'd' || tecla == 'D') //Si presionamos la tecla D, es decir a la derecha...
      {
         return movRight(map,pos,listaEnemigosSwitch);
      }
      
      else if (tecla == 's' || tecla == 'S') //Si presion la tecla S, es decir abajo....
      {
         return movDown(map,pos,listaEnemigosSwitch);
      }   

      else if (tecla == 'w' || tecla == 'W') //Si presion la tecla W, es decir arriba....
      {
         return movUp(map,pos,listaEnemigosSwitch);
      }   

      else if (tecla == 'a' || tecla == 'A')
      {
            printf ("\033[2J\033[1;1H");   
            printf("Aquí no hay nada de nada, vuelva a intentarlo. (ﾉ◕ ヮ◕ )ﾉ*:･ﾟ✧\n\n\n\n");
            return '5';
      } 
   }
   else if (pos[0] == largo-1 && pos[1] != 0) //Cuando estoy en el (9,x)
   {
      
      if (tecla == 'x' || tecla == 'X') //Es decir, me quedo quieto.
      {
         return dontMove(map,pos,listaEnemigosSwitch);
      }

      else if (tecla == 'd' || tecla == 'D') //Si presionamos la tecla D, es decir a la derecha...
      {
         return movRight(map,pos,listaEnemigosSwitch);
      }
      
      else if (tecla == 's' || tecla == 'S') //Si presion la tecla S, es decir abajo....
      {
         printf ("\033[2J\033[1;1H");   
         printf("Aquí no hay nada de nada, vuelva a intentarlo. (ﾉ◕ ヮ◕ )ﾉ*:･ﾟ✧\n\n\n\n");
         return '5';
      }   

      else if (tecla == 'w' || tecla == 'W') //Si presion la tecla W, es decir arriba....
      {
         return movUp(map,pos,listaEnemigosSwitch);
      }   

      else if (tecla == 'a' || tecla == 'A')
      {
         return movLeft(map,pos,listaEnemigosSwitch);
      } 
   }
   else if (pos[0] != 0 && pos[1] == ancho-2) //Cuando estoy en el (x, 18)
   {
      
      if (tecla == 'x' || tecla == 'X') //Es decir, me quedo quieto.
      {
         return dontMove(map,pos,listaEnemigosSwitch);
      }

      else if (tecla == 'd' || tecla == 'D') //Si presionamos la tecla D, es decir a la derecha...
      {
         printf ("\033[2J\033[1;1H");   
         printf("Aquí no hay nada de nada, vuelva a intentarlo. (ﾉ◕ ヮ◕ )ﾉ*:･ﾟ✧\n\n\n\n");
         return '5';
      }
      
      else if (tecla == 's' || tecla == 'S') //Si presion la tecla S, es decir abajo....
      {
         return movDown(map,pos,listaEnemigosSwitch);
      }   

      else if (tecla == 'w' || tecla == 'W') //Si presion la tecla W, es decir arriba....
      {
         return movUp(map,pos,listaEnemigosSwitch);
      }   

      else if (tecla == 'a' || tecla == 'A')
      {
         return movLeft(map,pos,listaEnemigosSwitch);
      } 
   }
   else if (pos[0] == 0 && pos[1] != 0) //En el caso cuando I está en el (0,x) x = cualquier número.
   {

      if (tecla == 'x' || tecla == 'X') //Es decir, me quedo quieto.
      {
         return dontMove(map,pos,listaEnemigosSwitch);
      }

      else if (tecla == 'd' || tecla == 'D') //Si presionamos la tecla D, es decir a la derecha...
      {

         return movRight(map,pos,listaEnemigosSwitch);
      }

      else if (tecla == 's' || tecla == 'S') //Si presion la tecla S, es decir abajo....
      {
         return movDown(map,pos,listaEnemigosSwitch);
      }

      else if (tecla == 'w' || tecla == 'W')
      {
         printf ("\033[2J\033[1;1H"); 
         printf("Aquí no hay nada de nada, vuelva a intentarlo. (ﾉ◕ ヮ◕ )ﾉ*:･ﾟ✧\n\n\n\n");
         return '5';   
      }

      else if (tecla == 'a' || tecla =='A')
      {
        return movLeft(map,pos,listaEnemigosSwitch);
      }
   }   
   else if (pos[0] != 0 && pos[1] != 0 ) //Cuando estoy en el (x,y)
   {
      
      if (tecla == 'x' || tecla == 'X') //Es decir, me quedo quieto.
      {
         return dontMove(map,pos,listaEnemigosSwitch);
      }

      else if (tecla == 'd' || tecla == 'D') //Si presionamos la tecla D, es decir a la derecha...
      {
         return movRight(map,pos,listaEnemigosSwitch);
      }
         
      else if (tecla == 's' || tecla == 'S') //Si presion la tecla S, es decir abajo....
      {
         return movDown(map,pos,listaEnemigosSwitch);
      }   

      else if (tecla == 'w' || tecla == 'W') //Si presion la tecla W, es decir arriba....
      {
         return movUp(map,pos,listaEnemigosSwitch);
      }   

      else if (tecla == 'a' || tecla =='A')
      {
         return movLeft(map,pos,listaEnemigosSwitch);
      }
   }
   else
   {
      //
      return '1';   
   }
}

/******** Función: movEnemigos ********
Descripción: 
Parámetros: 
Retorno: 
****************************************/
char movEnemigos(tLista *lista, char **map, int largo,int ancho)
{
    void *general;
    tEnemigo *enemigo;
    char a;
    int x,y;
    moveToStart(lista);   
    while(lista->listSize != lista->pos)
    {   
        if(lista->curr->label == 'E')
        {
            general = lista->curr->info;
            enemigo = (tEnemigo*)lista->curr->info;
            x = enemigo->x;
            y = enemigo->y;
            a = enemigo->siguiente_movimiento(general,map,x,y,largo,ancho);
            if(a == '0')
            {
                break;
            }
        }
            moveToNext(lista); 
    }
    return a;
}

/******** Función: Map ********
Descripción: genera la matriz de tamaño largo x ancho entregado en el .txt
Parámetros: NumMapa para saber el mapa a ejecutar, tamaño es el tamaño del mapa (ancho x largo) y pos del punto inicial.
Retorno: arreglo de chars, es decir, la matriz.  
****************************************/
char **Map(int NumMapa, int *tamano, int *pos)
{
   int x,y,largo,ancho,i,j;
   char anchochar[10],largochar[10], mapa[40];
   char **matriz;
   FILE *entrada;
   char entradachar[8] ="entrada";
   char txt[6] =".txt";
   char NumMapaChar[2];
   sprintf(NumMapaChar,"%d", NumMapa);
   strcpy(mapa,entradachar);
   strcat(mapa,NumMapaChar);
   strcat(mapa,txt);

   if(NumMapa == 0)
   {
      entrada = fopen("entrada.txt","r");
      if (entrada == NULL)
         exit(1);  
   }

   else
   {
      entrada = fopen(mapa,"r");    
      if (entrada == NULL)
      exit(1);  
   }

   fgets(anchochar,10,entrada);
   fgets(largochar,10,entrada);
   largo = atoi(largochar);
   ancho = atoi(anchochar)*2;
   tamano[0] = largo;
   tamano[1] = ancho;

	matriz = (char **)malloc(sizeof(char *)*largo); 
	for(i = 0; i < largo; ++i)
	{
		matriz[i]= (char *)malloc(sizeof(char *)*ancho);
	}

	for(i = 0; i < largo; i++)
	{
		for(j = 0; j < ancho; j++)
		{
			matriz[i][j] = fgetc(entrada);
		}
	}

   fclose(entrada);


   for(y = 0; y < largo; y++)
   {
      for (x = 0; x < ancho; x++)
      {
         if (matriz[y][x] == 'I')
         {
            pos[0] = y;  //largo
            pos[1] = x; //ancho
            pos[2] = pos[1]/2;
         }
      }
   }

	return matriz;
}  

/******** Función: printMap ********
Descripción: Imprime el mapa en consola.
Parámetros: arreglo de chars con el mapa, el largo y ancho del mapa.
Retorno: Nada.
****************************************/
void printMap(char **map,int largo,int ancho)
{
   int x,y;
   if(ancho <= 20)
   {
      for(y = 0; y < largo; y++)
      {
         printf("\033[30C");
         for (x = 0; x < ancho; x++)
         {
            printf("%c",map[y][x]);
         }
      }
   }

   else if(ancho > 20 && ancho <= 30)
   {
      for(y = 0; y < largo; y++)
      {
         printf("\033[25C");
         for (x = 0; x < ancho; x++)
         {
            printf("%c",map[y][x]);
         }
      }
   }

   else if(ancho > 30 && ancho <= 40)
   {
      for(y = 0; y < largo; y++)
      {
         printf("\033[20C");
         for (x = 0; x < ancho; x++)
         {
            printf("%c",map[y][x]);
         }
      }
   }

   else if(ancho > 40 && ancho <= 50)
   {
      for(y = 0; y < largo; y++)
      {
         printf("\033[15C");
         for (x = 0; x < ancho; x++)
         {
            printf("%c",map[y][x]);
         }
      }
   }

   else if(ancho > 50 && ancho <= 60)
   {
      for(y = 0; y < largo; y++)
      {
         printf("\033[10C");
         for (x = 0; x < ancho; x++)
         {
            printf("%c",map[y][x]);
         }
      }
   }

   if (largo > 15)
   {
      printf("\n");
   }

   else{
      printf("\n\n\n\n");
   }
}

int main()
{

	//Declaración de variables
 	int x,y,largo,ancho,NumMapa;
 	char **map, anchochar[10],largochar[10],tecla,accion;
 	int pos[3], tamano[2];
   tEnemigo* enemy;
   tLista *listaEnemigosSwitch;
 	//Termina declaración de variables

   printf ("\033[2J\033[1;1H");
   printf("▄︻̷̿┻̿═━一  Bienvenido a Death Dungeon V.1.0\n\n");
   printf("Instrucciones del juego: \n\n");
   printf("    1. Su misión es llegar desde el punto inicial I, a el punto final F.\n" );
   printf("    2. Para moverse utilizar: A (Izquierda), S (Abajo), D (Derecha), W (Arriba).\n" );
   printf("    3. El número '0' en el mapa significa que usted puede moverse a esa\n       posición.\n" );
   printf("    4. El número '1' en el mapa significa que hay una muralla, es decir, no se\n       puede pasar.\n" );
   printf("    5. Los enemigos están listados del 2 al 9.\n\n" );
   
   tecla = 0;
   while((int)tecla != 10)
   {
      printf("(☞ﾟヮﾟ)☞ ¡Presiona Enter para comenzar el juego! ☜(ﾟヮﾟ☜)");
      tecla = getchar();
   }

   NumMapa = 0;
   //Genera el mapa
   printf ("\033[2J\033[1;1H");  
   printf("El juego ha comenzado...no mueras ♪└|∵|┐♪└|∵|┘♪┌|∵|┘♪ ♪└|∵┌|└| ∵ |┘|┐∵|┘\n\n\n\n");
   map = Map(NumMapa, tamano, pos);
   largo = tamano[0];
   ancho = tamano[1];

   listaEnemigosSwitch = crearListaEnemigosSwitch(map,largo,ancho);
   printMap(map,largo,ancho);
   printf("Es su turno, por favor haga un movimiento.\n");

   while(1)
   {
    	//Termina de generar el mapa
      accion = movUsuario(listaEnemigosSwitch ,map, pos, largo, ancho); 
      if(accion == '5')
      {
         printMap(map,largo,ancho); 
         printf("Es su turno, por favor haga un movimiento.\n");

         continue;   
      }

      if(accion == '1')
      {
         accion = movEnemigos(listaEnemigosSwitch, map, largo, ancho); 
      }

      if (accion == '2' && NumMapa >= 2)
      {
         accion = '3';
      }

      switch(accion)
      {
            case '0':
               printf ("\033[2J\033[1;1H");  
               printf("Juego terminado, más suerte para la próxima.\n");
               free(listaEnemigosSwitch);
               exit(0);
               break;
            case '1':
               printMap(map,largo,ancho);
               printf("Es su turno, por favor haga un movimiento.\n");
   
               break;

            case '2':
                  NumMapa += 1;
                  map = Map(NumMapa, tamano, pos);
                  largo = tamano[0];
                  ancho = tamano[1];
                  listaEnemigosSwitch = crearListaEnemigosSwitch(map,largo,ancho);
                  printf ("\033[2J\033[1;1H");  
                  printf("Nivel %d superado, felicitaciones!.\n\n\n\n", NumMapa);
                  printMap(map,largo,ancho);
                  printf("Es su turno, por favor haga un movimiento.\n");  
               break;

            case '3':
               printf ("\033[2J\033[1;1H");  
               printf("Has completado los %d niveles, Felicitaciones!.\n", NumMapa);
               exit(0);
               break;
            default:
               break;
      }   
   }
}
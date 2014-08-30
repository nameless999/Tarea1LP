#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//pos[0] es la fila
//pos[1] es la columna
//pos[2] es fila sin sumar 2t m

int dontMove(char **map, int *pos) // X
{
   printf ("\033[2J\033[1;1H"); 
   printf("Te has quedado quieto en la posición (%d,%d) <('o'<).\n\n\n\n", pos[0], pos[2]);

   if(map[pos[0]][pos[1]] == 'a') //Si la casilla actual es == a (Switch)...
   {
      //implementar
      return '1';
   }

   else if(map[pos[0]][pos[1]] == 'b') //Si la casilla de la derecha es == a (Switch)...
   {
      //implementar
      return '1';
   }

   else if(map[pos[0]][pos[1]] == 'c') //Si la casilla de la derecha es == a (Switch)...
   {
     //implementar
      return '1';
   }

   return '1';
}

int movDown(char **map, int *pos) // W
{
   if(map[pos[0]+1][pos[1]] == '0') //Si la casilla de abajo es == 0 (válida)...
   {
      printf ("\033[2J\033[1;1H");
      map[pos[0]+1][pos[1]] = '*'; //Nos movemos a la casilla de abjao
      map[pos[0]][pos[1]] = '0'; //Dejamos la posición inicial como 0, es decir, válida.
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
      return '1';
   }

   else if(map[pos[0]+1][pos[1]] == 'A')
   {
      printf ("\033[2J\033[1;1H");   
      printf("La puerta está cerrada, busca el switch 'a' para abrirla. ¯_(ツ)_/¯ \n\n\n\n");
      return '1';
   }


   else if(map[pos[0]+1][pos[1]] == 'a') //Si la casilla de la derecha es == a (Switch)...
   {
      return '1';
   }

   else if(map[pos[0]+1][pos[1]] == 'B')
   {
      printf ("\033[2J\033[1;1H");   
      printf("La puerta está cerrada, busca el switch 'b' para abrirla.\n");
      return '1';
   }

   else if(map[pos[0]+1][pos[1]] == 'b') //Si la casilla de la derecha es == a (Switch)...
   {
      return '1';
   }

   else if(map[pos[0]+1][pos[1]] == 'C')
   {
      printf ("\033[2J\033[1;1H");   
      printf("La puerta está cerrada, busca el switch 'c' para abrirla.\n");
      return '1';
   }


   else if(map[pos[0]+1][pos[1]] == 'c') //Si la casilla de la derecha es == a (Switch)...
   {
      return '1';
   }
}

int movUp(char **map, int *pos) // S
{
   if(map[pos[0]-1][pos[1]] == '0') //Si la casilla de abajo es == 0 (válida)...
   {
      printf ("\033[2J\033[1;1H");

      map[pos[0]-1][pos[1]] = '*'; //Nos movemos a la casilla de abjao
      map[pos[0]][pos[1]] = '0'; //Dejamos la posición inicial como 0, es decir, válida.
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
      return '1';
   }

   else if(map[pos[0]-1][pos[1]] == 'A')
   {
      printf ("\033[2J\033[1;1H");   
      printf("La puerta está cerrada, busca el switch 'a' para abrirla. ¯_(ツ)_/¯ \n\n\n\n");
      return '1';
   }


   else if(map[pos[0]-1][pos[1]] == 'a') //Si la casilla de la derecha es == a (Switch)...
   {
      return '1';
   }

   else if(map[pos[0]-1][pos[1]] == 'B')
   {
      printf ("\033[2J\033[1;1H");   
      printf("La puerta está cerrada, busca el switch 'b' para abrirla.\n\n\n\n");
      return '1';
   }

   else if(map[pos[0]-1][pos[1]] == 'b') //Si la casilla de la derecha es == a (Switch)...
   {
      return '1';
   }

   else if(map[pos[0]-1][pos[1]] == 'C')
   {
      printf ("\033[2J\033[1;1H");   
      printf("La puerta está cerrada, busca el switch 'c' para abrirla.\n\n\n\n");
      return '1';
   }


   else if(map[pos[0]-1][pos[1]] == 'c') //Si la casilla de la derecha es == a (Switch)...
   {
      return '1';
   }
}

int movLeft(char **map, int *pos) // A
{
         if(map[pos[0]][pos[1]-2] == '0') //Si la casilla que está a la derecha es == 0 (válida)...
         {
            printf ("\033[2J\033[1;1H"); 
            map[pos[0]][pos[1]] = '0'; //Dejamos la posición I como 0 para que sea válida otra vez.   
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
            return '1';
         }

         else if(map[pos[0]][pos[1]-2] == 'A') //Si la casilla de la derecha es == A (Puerta)...  
         {
            printf ("\033[2J\033[1;1H");
            printf("La puerta está cerrada, busca el switch 'a' para abrirla. ¯_(ツ)_/¯ \n\n\n\n");
            return '1';
         }

         else if(map[pos[0]][pos[1]-2] == 'a') //Si la casilla de la derecha es == a (Switch)...
         {
             return '1';
         }

         else if(map[pos[0]][pos[1]-2] == 'B')
         {
            printf ("\033[2J\033[1;1H");   
            printf("La puerta está cerrada, busca el switch 'b' para abrirla.\n\n\n\n");
            return '1';
         }


         else if(map[pos[0]][pos[1]-2] == 'b') //Si la casilla de la derecha es == a (Switch)...
         {
            return '1';
         }

         else if(map[pos[0]][pos[1]-2] == 'C')
         {
            printf ("\033[2J\033[1;1H");   
            printf("La puerta está cerrada, busca el switch 'c' para abrirla.\n\n\n\n");
            return '1';
         }

         else if(map[pos[0]][pos[1]-2] == 'c') //Si la casilla de la derecha es == a (Switch)...
         {
            return '1';
         }
}

int movRight(char **map, int *pos) // D
{
   if(map[pos[0]][pos[1]+2] == '0') //Si la casilla que está a la derecha es == 0 (válida)...
         {
            printf ("\033[2J\033[1;1H"); 
            map[pos[0]][pos[1]] = '0'; //Dejamos la posición I como 0 para que sea válida otra vez.   
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
            return '1';
         }

         else if(map[pos[0]][pos[1]+2] == 'A') //Si la casilla de la derecha es == A (Puerta)...  
         {
            printf ("\033[2J\033[1;1H");
            printf("La puerta está cerrada, busca el switch 'a' para abrirla. ¯_(ツ)_/¯ \n\n\n\n");
            return '1';
         }

         else if(map[pos[0]][pos[1]+2] == 'a') //Si la casilla de la derecha es == a (Switch)...
         {

            return '1';
         }

         else if(map[pos[0]][pos[1]+2] == 'B')
         {
            printf ("\033[2J\033[1;1H");   
            printf("La puerta está cerrada, busca el switch 'b' para abrirla.\n\n\n\n");
            return '1';
         }


         else if(map[pos[0]][pos[1]+2] == 'b') //Si la casilla de la derecha es == a (Switch)...
         {
            return '1';
         }

         else if(map[pos[0]][pos[1]+2] == 'C')
         {
            printf ("\033[2J\033[1;1H");   
            printf("La puerta está cerrada, busca el switch 'c' para abrirla.\n\n\n\n");
            return '1';
         }


         else if(map[pos[0]][pos[1]+2] == 'c') //Si la casilla de la derecha es == a (Switch)...
         {
            return '1';
         }
}

int movUsuario(char **map, int *pos, int largo, int ancho)
{
   int x,y;
   char tecla;
   tecla = getchar(); //Pedimos un movimiento al usuario (ASWD)
   printf("Es su turno, por favor haga un movimiento.\n");
   

   if (pos[0] == largo-1 && pos[1] == ancho-2) // Esquina inferior derecha
   {

      if (tecla == 'x' || tecla == 'X') //Es decir, me quedo quieto.
      {
         return dontMove(map,pos);
      }

      else if (tecla == 'd' || tecla == 'D') //Si presionamos la tecla D, es decir a la derecha...
      {
         printf ("\033[2J\033[1;1H"); 
         printf("Aquí no hay nada de nada, vuelva a intentarlo. (ﾉ◕ ヮ◕ )ﾉ*:･ﾟ✧\n\n\n\n");
         return '1';   
      }

      else if (tecla == 'w' || tecla == 'W')
      {
         return movUp(map,pos); 
      }

      else if (tecla == 's' || tecla == 'S') //Si presion la tecla S, es decir abajo....
      {
         printf ("\033[2J\033[1;1H"); 
         printf("Aquí no hay nada de nada, vuelva a intentarlo. (ﾉ◕ ヮ◕ )ﾉ*:･ﾟ✧\n\n\n\n");
         return '1';   
      }

      else if (tecla == 'a' || tecla =='A')
      {
        return movLeft(map,pos);
      }
   }
   else if (pos[0] == 0 && pos[1] == 0) //Esquina superior izquierda
   {
         if (tecla == 'x' || tecla == 'X')
         {
            return dontMove(map,pos);
         }

         else if (tecla == 'd' || tecla == 'D') //Si presionamos la tecla D, es decir a la derecha...
         {
            return movRight(map,pos);
         }

         else if (tecla == 's' || tecla == 'S') //Si presion la tecla S, es decir abajo....
         {
            return movDown(map,pos);
         }

         else if(tecla == 'w' || tecla == 'W')
         {
            printf ("\033[2J\033[1;1H"); 
            printf("Aquí no hay nada de nada, vuelva a intentarlo. (ﾉ◕ ヮ◕ )ﾉ*:･ﾟ✧\n\n\n\n");
            return '1';   
         }

         else if (tecla == 'a' || tecla == 'A')
         {
            printf ("\033[2J\033[1;1H"); 
            printf("Aquí no hay nada de nada, vuelva a intentarlo. (ﾉ◕ ヮ◕ )ﾉ*:･ﾟ✧\n\n\n\n");
            return '1';
         }     
   }
   else if(pos[0] == 0 && pos[1] == ancho-2 ) // Esquina superior derecha
   {
      if (tecla == 'x' || tecla == 'X') //Es decir, me quedo quieto.
      {
         return dontMove(map,pos);
      }

      else if (tecla == 'd' || tecla == 'D') //Si presionamos la tecla D, es decir a la derecha...
      {
         printf ("\033[2J\033[1;1H"); 
         printf("Aquí no hay nada de nada, vuelva a intentarlo. (ﾉ◕ ヮ◕ )ﾉ*:･ﾟ✧\n\n\n\n");
         return '1';   
      }

      else if (tecla == 'w' || tecla == 'W')
      {
         printf ("\033[2J\033[1;1H"); 
         printf("Aquí no hay nada de nada, vuelva a intentarlo. (ﾉ◕ ヮ◕ )ﾉ*:･ﾟ✧\n\n\n\n");
         return '1';  
      }

      else if (tecla == 's' || tecla == 'S') //Si presion la tecla S, es decir abajo....
      {
         return movDown(map,pos);   
      }

      else if (tecla == 'a' || tecla =='A')
      {
        return movLeft(map,pos);
      }  
   }
   else if(pos[0] == largo-1 && pos[1] == 0) // Esquina inferior izquierda
   {
      if (tecla == 'x' || tecla == 'X') //Es decir, me quedo quieto.
      {
         return dontMove(map,pos);
      }

      else if (tecla == 'd' || tecla == 'D') //Si presionamos la tecla D, es decir a la derecha...
      {
         return movRight(map,pos);   
      }  

      else if (tecla == 'w' || tecla == 'W')
      {
         return movUp(map,pos); 
      }

      else if (tecla == 's' || tecla == 'S') //Si presion la tecla S, es decir abajo....
      {
         printf ("\033[2J\033[1;1H"); 
         printf("Aquí no hay nada de nada, vuelva a intentarlo. (ﾉ◕ ヮ◕ )ﾉ*:･ﾟ✧\n\n\n\n");
         return '1';      
      }

      else if (tecla == 'a' || tecla =='A')
      {
         printf ("\033[2J\033[1;1H"); 
         printf("Aquí no hay nada de nada, vuelva a intentarlo. (ﾉ◕ ヮ◕ )ﾉ*:･ﾟ✧\n\n\n\n");
         return '1';   
      }  
   }
   else if (pos[0] != 0 && pos[1] == 0) //Cuando estoy en el (x,0)
   {
      
      if (tecla == 'x' || tecla == 'X') //Es decir, me quedo quieto.
      {
         return dontMove(map,pos);
      }

      else if (tecla == 'd' || tecla == 'D') //Si presionamos la tecla D, es decir a la derecha...
      {
         return movRight(map,pos);
      }
      
      else if (tecla == 's' || tecla == 'S') //Si presion la tecla S, es decir abajo....
      {
         return movDown(map,pos);
      }   

      else if (tecla == 'w' || tecla == 'W') //Si presion la tecla W, es decir arriba....
      {
         return movUp(map,pos);
      }   

      else if (tecla == 'a' || tecla == 'A')
      {
            printf ("\033[2J\033[1;1H");   
            printf("Aquí no hay nada de nada, vuelva a intentarlo. (ﾉ◕ ヮ◕ )ﾉ*:･ﾟ✧\n\n\n\n");
            return '1';
      } 
   }
   else if (pos[0] == largo-1 && pos[1] != 0) //Cuando estoy en el (9,x)
   {
      
      if (tecla == 'x' || tecla == 'X') //Es decir, me quedo quieto.
      {
         return dontMove(map,pos);
      }

      else if (tecla == 'd' || tecla == 'D') //Si presionamos la tecla D, es decir a la derecha...
      {
         return movRight(map,pos);
      }
      
      else if (tecla == 's' || tecla == 'S') //Si presion la tecla S, es decir abajo....
      {
         printf ("\033[2J\033[1;1H");   
         printf("Aquí no hay nada de nada, vuelva a intentarlo. (ﾉ◕ ヮ◕ )ﾉ*:･ﾟ✧\n\n\n\n");
         return '1';
      }   

      else if (tecla == 'w' || tecla == 'W') //Si presion la tecla W, es decir arriba....
      {
         return movUp(map,pos);
      }   

      else if (tecla == 'a' || tecla == 'A')
      {
         return movLeft(map,pos);
      } 
   }
   else if (pos[0] != 0 && pos[1] == ancho-2) //Cuando estoy en el (x, 18)
   {
      
      if (tecla == 'x' || tecla == 'X') //Es decir, me quedo quieto.
      {
         return dontMove(map,pos);
      }

      else if (tecla == 'd' || tecla == 'D') //Si presionamos la tecla D, es decir a la derecha...
      {
         printf ("\033[2J\033[1;1H");   
         printf("Aquí no hay nada de nada, vuelva a intentarlo. (ﾉ◕ ヮ◕ )ﾉ*:･ﾟ✧\n\n\n\n");
         return '1';
      }
      
      else if (tecla == 's' || tecla == 'S') //Si presion la tecla S, es decir abajo....
      {
         return movDown(map,pos);
      }   

      else if (tecla == 'w' || tecla == 'W') //Si presion la tecla W, es decir arriba....
      {
         return movUp(map,pos);
      }   

      else if (tecla == 'a' || tecla == 'A')
      {
         return movLeft(map,pos);
      } 
   }
   else if (pos[0] == 0 && pos[1] != 0) //En el caso cuando I está en el (0,x) x = cualquier número.
   {

      if (tecla == 'x' || tecla == 'X') //Es decir, me quedo quieto.
      {
         return dontMove(map,pos);
      }

      else if (tecla == 'd' || tecla == 'D') //Si presionamos la tecla D, es decir a la derecha...
      {

         return movRight(map,pos);
      }

      else if (tecla == 's' || tecla == 'S') //Si presion la tecla S, es decir abajo....
      {
         return movDown(map,pos);
      }

      else if (tecla == 'w' || tecla == 'W')
      {
         printf ("\033[2J\033[1;1H"); 
         printf("Aquí no hay nada de nada, vuelva a intentarlo. (ﾉ◕ ヮ◕ )ﾉ*:･ﾟ✧\n\n\n\n");
         return '1';   
      }

      else if (tecla == 'a' || tecla =='A')
      {
        return movLeft(map,pos);
      }
   }   
   else if (pos[0] != 0 && pos[1] != 0 ) //Cuando estoy en el (x,y)
   {
      
      if (tecla == 'x' || tecla == 'X') //Es decir, me quedo quieto.
      {
         return dontMove(map,pos);
      }

      else if (tecla == 'd' || tecla == 'D') //Si presionamos la tecla D, es decir a la derecha...
      {
         return movRight(map,pos);
      }
         
      else if (tecla == 's' || tecla == 'S') //Si presion la tecla S, es decir abajo....
      {
         return movDown(map,pos);
      }   

      else if (tecla == 'w' || tecla == 'W') //Si presion la tecla W, es decir arriba....
      {
         return movUp(map,pos);
      }   

      else if (tecla == 'a' || tecla =='A')
      {
         return movLeft(map,pos);
      }
   }
   else
   {
      //
      return '1';   
   }
}

char **Map(int NumMapa, int *tamano, int *pos)
{
   //Declaración de variables
   int x,y,largo,ancho,i,j;
   char anchochar[10],largochar[10], mapa[40];
   char **matriz;
   FILE *entrada;
   //FILE *entrada;
   char entradachar[8] ="entrada";
   char txt[6] =".txt";
   char NumMapaChar[2];
   sprintf(NumMapaChar,"%d", NumMapa);
   //char trash[10]; //Sólo para no volver a tomar el tamaño
   //Termina declaración de variables
   strcpy(mapa,entradachar);
   strcat(mapa,NumMapaChar);
   strcat(mapa,txt);
   
   //Se abre el archivo
   //entrada = fopen("entrada1.txt","r");    
   //if (entrada == NULL)
   //   exit(1);
   //Termina de abrir archivo

   //Obtiene largo y ancho, luego transforma a int
   //fgets(trash,10,entrada);
   //fgets(trash,10,entrada);
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
   //Se abre el archivo

   //Termina de abrir archivo

   //Obtiene largo y ancho, luego transforma a int
   fgets(anchochar,10,entrada);
   fgets(largochar,10,entrada);
   largo = atoi(largochar);
   ancho = atoi(anchochar)*2;
    //Termina
   tamano[0] = largo;
   tamano[1] = ancho;

    //Asigna memoria a la matriz
	matriz = (char **)malloc(sizeof(char *)*largo); 
	for(i = 0; i < largo; ++i)
	{
		matriz[i]= (char *)malloc(sizeof(char *)*ancho);
	}
   //Termina

   //Los datos en entrada.txt son copiados a la matriz
	for(i = 0; i < largo; i++)
	{
		for(j = 0; j < ancho; j++)
		{
			matriz[i][j] = fgetc(entrada);
		}
	}
   //Termina
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

   if (largo >= 15)
   {
      printf("\n");
   }

   else{
      printf("\n\n\n");
   }
}

int main()
{

	//Declaración de variables
 	int x,y,largo,ancho,NumMapa;
 	char **map, anchochar[10],largochar[10],tecla,accion;
 	int pos[3], tamano[2];
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

   printMap(map,largo,ancho);
   printf("Es su turno, por favor haga un movimiento.\n");
   while(1)
   {
 	//Termina de generar el mapa
   	accion = movUsuario(map, pos, largo, ancho);   
      if (accion == '2' && NumMapa >= 2)
         {
            accion = '3';
         }
      switch(accion)
      {
         case '1':
            printMap(map,largo,ancho);   
            printf("Debug: Pos[0] = %d, Pos[1] = %d\n", pos[0],pos[1] );
            break;

         case '2':
               NumMapa += 1;
               map = Map(NumMapa, tamano, pos);
               printf ("\033[2J\033[1;1H");  
               printf("Nivel %d superado, felicitaciones!.\n\n\n\n", NumMapa);
               printMap(map,largo,ancho);  
            break;

         case '0':
            printf("GAME OVER\n");
            break;
            break;

         case '3':
            printf ("\033[2J\033[1;1H");  
            printf("Has completado los %d niveles, eres bkn.\n", NumMapa);
            exit(0);
            break;
         default:
            break;
     }
   }   
}
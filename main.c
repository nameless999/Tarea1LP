#include <stdio.h>
#include <stdlib.h>

char **movUsuario(char **map, int *pos)
{
   char tecla;
   printf( "Haga su siguiente movimiento: " );
   scanf( "%c", &tecla);

   if (pos[0] == 0 and pos[1] == 0)
   {
   		if(tecla == 'w')
   		{
    		printf("Movimiento inválido\n");  	
   		}

   		
   }
   
}

char **mapInicial()
{
	char **matriz;
	FILE *entrada;
 	int i,j,largo,ancho;
 	char anchochar[10],largochar[10];
 	//Termina declaración de variables

 	//Se abre el archivo
 	entrada = fopen("entrada.txt","r"); 	
 	if (entrada == NULL)
 		exit(1);
 	//Termina de abrir archivo

 	//Obtiene largo y ancho, luego transforma a int
 	fgets(anchochar,10,entrada);
 	fgets(largochar,10,entrada);
 	largo = atoi(largochar);
    ancho = atoi(anchochar)*2;
    //Termina

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

	return matriz;
}  

int main(){

	//Declaración de variables
 	int x,y;
 	char **map;
 	int pos[2];
 	//Termina declaración de variables

    //Genera el mapa
 	map = mapInicial();


 	for(x = 0; x < 10; x++)
	{
		for (y = 0; y < 20; y++)
		{
			if (map[x][y] == 'I')
			{
				pos[0] = x;
				pos[1] = y;
			}
		}
	}

	printf("%d\n", inicio[0]);
	printf("%d\n", inicio[1]);

 	for(i = 0; i < 10; i++)
	{
		for (j = 0; j < 20; j++)
		{
			printf("%c",map[i][j]);
		}
	}

 	//Termina de generar el mapa

	movUsuario(map);

}
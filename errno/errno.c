/*
* 
* Programa para listar todos los posibles errores que un programa puede generar.
* Estos mensajes son los que retornan cuando se hace una llamada al sistema
* 
*/

#include <stdio.h>


int main(){
	int i;
	/* En el array  sys_errlist hay una descripcion corta asociada a cada numero de 
	 Error, sys_nerr es el total de elementos del array sys_errlist*/	
	for(i=0; i < sys_nerr; i++)
	{
		printf("%d: %s\n", i,sys_errlist [i]);
	}
 return 0;
}

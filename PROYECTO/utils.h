#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/* Función para leer cadenas de forma dinámica 
(strdynread => String Dynamic Read)
/* La función se llama y usa de este modo: variable = strdynread()
con variable siendo un tipo (char *) */
char *strdynread(){
	char *cad=NULL;
	int ind=0,c=EOF;
	// Seguir leyendo caracteres hasta que el usuario presione "EOF" o salto de línea
	while(c){
		c=getc(stdin);
		if(c==EOF || c=='\n')
			c=0;
		// Cambiar el tamaño del bloque de memoria;
		cad=realloc(cad,ind+1);
		// Guardar en cad[ind] con ind que es el largo actual de la cadena
		cad[ind++]=c;
		// Al usar '++' con notación postfija en ind, primero se hace la asignación y luego se hace el incremento en ind
	}
	return cad;
}

char *concatenar(char *c1,char *c2){
	int i,j;
	char *nueva_cadena=(char *)malloc(sizeof(strlen(c1)+strlen(c2)));
	for(i=0;c1[i];i++)
		nueva_cadena[i]=c1[i];
	for(j=i;c2[j-i];j++)
		nueva_cadena[j]=c2[j-i];
	return nueva_cadena;
}
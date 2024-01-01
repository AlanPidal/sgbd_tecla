#include<stdio.h>
#include<stdlib.h>
#include "tablas.h"
#include "disco.h"
// Sistema gestor de bases de datos


void debug(){
	Tabla **espacio=generarEspacioTablas(2);
	redimEspacioTablas(espacio,5);
	espacio[0]=asistCreacionTablas();
	espacio[1]=asistCreacionTablas();
	printf("%d",getSizeEspacioTablas(espacio));
	guardarEspacioTablas(espacio);
	/*printf("Inicializando el asistente creador de tablas\n");
	Tabla *nueva=asistCreacionTablas();
	guardarTabla(nueva);*/
}
void main(){
	debug();
}

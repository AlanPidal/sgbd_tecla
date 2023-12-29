#include<stdio.h>
#include<stdlib.h>
#include "tablas.h"
#include "disco.h"
// Sistema gestor de bases de datos



void debug(){
	printf("Inicializando el asistente creador de tablas\n");
	Tabla *nueva=asistCreacionTablas();
	guardarTabla(nueva);
}
void main(){
	debug();
}

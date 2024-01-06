#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "utils.h"
#include "tablas.h"
//#include "disco.h"
//#include "crud.h"
// Sistema gestor de bases de datos


void debug(){

	//Auxiliar debug
	int u;

	Tabla **espacio=generarEspacioTablas(10);
	redimEspacioTablas(espacio,11);
	char **nombres_metadatos=(char **)malloc(sizeof(char *)*10);
	for(u=0;u<20;u++)
		nombres_metadatos[u]=(char *)malloc(10);
	strcpy(nombres_metadatos[0],"nombre");
	strcpy(nombres_metadatos[1],"ID");
	strcpy(nombres_metadatos[2],"apellido");
	char **nombres_tipos=(char **)malloc(sizeof(char *)*10);
	for(u=0;u<20;u++)
		nombres_tipos[u]=(char *)malloc(10);
	strcpy(nombres_tipos[0],"char[20]");
	strcpy(nombres_tipos[1],"int");
	strcpy(nombres_tipos[2],"char[20]");
	espacio[0]=crearTabla("Tabla1",3,nombres_metadatos,nombres_tipos);
	debugPrintDataTabla(espacio[0]);
	/*
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

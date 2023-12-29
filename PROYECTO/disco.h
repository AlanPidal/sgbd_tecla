#include<stdio.h>
#include<stdlib.h>
// Colección de funciones para hacer operaciones en disco
// Incluye escribir o leer disco

// Programa para guardar tablas en un archivo
void guardarTabla(Tabla *tabla){
	FILE *f=fopen("tablas.dat","at");
	fprintf(f,"==== TABLE ====\n");
	fprintf(f,"%s\n",tabla->nombre);
	fprintf(f,"%d\n",tabla->nCampos);
	for(int u=0;u<tabla->nCampos;u++)
		fprintf(f,"%s\n",tabla->metadatos[u]);
	fclose(f);
}
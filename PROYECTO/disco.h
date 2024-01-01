#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// Colección de funciones para hacer operaciones en disco
// Incluye escribir o leer disco

// Programa para guardar tablas en un archivo

char *dynFileread(FILE *f){
	char *cad=NULL;
	int ind=0,c=EOF;
	while(c){
		c=fgetc(f);
		if(c=='\n' || c==EOF) c=0;
		cad=realloc(cad,ind+1);
		cad[ind++]=c;
	}
	return cad;
}
void guardarTabla(Tabla *tabla){
	FILE *f=fopen("tablas.dat","at");
	fprintf(f,"==== TABLE ====\n");
	fprintf(f,"%s\n",tabla->nombre);
	fprintf(f,"%d\n",tabla->nCampos);
	for(int u=0;u<tabla->nCampos;u++)
		fprintf(f,"%s\n",tabla->metadatos[u]);
	fputc('&',f);
	fputs('\n',f);
	fclose(f);
}

void guardarEspacioTablas(Tabla **espacio){
	int u;
	for(u=0;espacio[u];u++)
		guardarTabla(espacio[u]);
}

Tabla *leerTabla(){
	int ind,c;
	char **metadatos,*nombre;
	int nCampos;
	FILE *f=fopen("tablas.dat","rt");
	nombre=dynFileread(f);
	fscanf(f,"%d\n",&nCampos);
	while(c!='&'){
		metadatos=realloc(metadatos,sizeof(char **)*(ind+1));
		metadatos[ind]=dynFileread(f);
		ind++;
	}
	Tabla *tabla=crearTabla(nombre,nCampos,metadatos);
	return tabla;
}
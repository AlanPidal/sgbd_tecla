#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// EStructura tabla consta de metadatos y registros

struct metadato{
	char *nombre;
	char *tipo;
};
typedef struct metadato Metadato;
struct tabla{
	char *nombre;
	int nCampos;
	Metadato **campos;
	void ***registros;
};

// Establecemos un sinónimo para struct tabla
typedef struct tabla Tabla;

// Función para obtener el tamaño del espacio del conjunto de tablas
int getSizeEspacioTablas(Tabla **espacio){
	int u;
	for(u=0;espacio[u];u++);
	return u;
}

// Función para generar un espacio para todo el conjutno de tablas
Tabla **generarEspacioTablas(int m){
	Tabla **espacio=(Tabla **)malloc(sizeof(Tabla *)*m);
	return espacio;
}

// Redimensionar/Cambiar tamaño de conjunto de tablas
void redimEspacioTablas(Tabla **espacio,int m){
	espacio=(Tabla **)realloc(espacio,m+1);
}

// Función para crear una nueva tabla
Tabla *crearTabla(char *nombre,int nCampos,char **nombres_metadatos,char **tipos){
	int u;
	Tabla *tabla=(Tabla *)malloc(sizeof(Tabla));
	tabla->nombre=(char *)malloc(sizeof(char)*strlen(nombre));
	strcpy(tabla->nombre,nombre);
	tabla->nCampos=nCampos;
	tabla->campos=(Metadato **)malloc(sizeof(Metadato *)*nCampos);
	for(u=0;u<=nCampos;u++){
		tabla->campos[u]=(Metadato *)malloc(sizeof(Metadato));
		tabla->campos[u]->nombre=(char *)malloc(strlen(nombres_metadatos[u]));
		strcpy(tabla->campos[u]->nombre,nombres_metadatos[u]);
		printf("%s\n",tabla->campos[u]->nombre);
		tabla->campos[u]->tipo=(char *)malloc(strlen(tipos[u]));
		strcpy(tabla->campos[u]->tipo,tipos[u]);
	}
	return tabla;
}

char **definirCampos(int nCampos,char **tipos){
	int u=0,opc;
	char *tipo;
	char *cantidad;
	char **nombres=(char **)malloc(sizeof(char *)*nCampos);
	for(u=0;u<nCampos;u++){
		printf("Nombre del campo %d:\n",u+1);
		nombres[u]=strdynread();
		printf("Define el tipo del campo %s",nombres[u]);
		printf("0)char\t1)int");
		scanf("%d",&opc);
		getchar();
		switch(opc){
		case 0:
			printf("Cantidad de caracteres:\n");
				cantidad=strdynread();
				tipo=concatenar("char[",cantidad);
				tipo=concatenar(tipo,"]");
		}
	}
	return nombres;
}

Tabla *asistenteCreacionTablas(){
	int u,nCampos;
	char *nombre,**nombres_metadatos;
	printf("Nombre de la tabla:\n");
	nombre=strdynread();
	printf("Número de campos de la tabla:\n");
	scanf("%d",&nCampos);
	char **contenedor_tipos=(char **)malloc(sizeof(nCampos));
	// 	getchar permite consumir un salto de línea que queda atorado en el buffer en la anterior ejecución de scanf
	getchar();
	nombres_metadatos=definirCampos(nCampos,contenedor_tipos);
	Tabla *nueva_tabla=crearTabla(nombre,nCampos,nombres_metadatos,contenedor_tipos);
	return nueva_tabla;
}

void debugPrintDataTabla(Tabla *tabla){
	int u;
	printf("Nombre: %s\n",tabla->nombre);
	printf("# de campos: %d\n",tabla->nCampos);
	for(u=0;u<tabla->nCampos;u++){
		printf("%s",tabla->campos[u]->nombre);
	}
}
/*
// Función para nombrar los campos de una tabla
char **nombrarCampos(int nCampos){
	int u=0;
	char **metadatos=(char **)malloc(sizeof(char *)*nCampos);
	for(u=0;u<nCampos;u++){
		printf("Nombre del campo %d:\n",u+1);
		metadatos[u]=strdynread();
	}
	return metadatos;
}

// Función asistente de creación de tablas en la GUI del usuario
Tabla *asistCreacionTablas(){
	int u,nCampos;
	char *nombre,**metadatos;
	printf("Nombre de la tabla: \n");
	nombre=strdynread();
	fflush(stdin);
	printf("Elija el número de campos en la nueva tabla: \n");
	scanf("%d",&nCampos);
	// 	getchar permite consumir un salto de línea que queda atorado en el buffer en la anterior ejecución de scanf
	getchar();
	metadatos=nombrarCampos(nCampos);
	Tabla *newTabla=crearTabla(nombre,nCampos,metadatos);
	return newTabla;
}
*/
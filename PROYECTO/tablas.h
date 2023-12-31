#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// EStructura tabla consta de metadatos y registros

struct tabla{
	char *nombre;
	int nCampos;
	char **metadatos;
	void ***registros;
};

// Establecemos un sinónimo para struct tabla
typedef struct tabla Tabla;

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

// Función para obtener el tamaño del espacio del conjunto de tablas
int getSizeEspacioTablas(Tabla **conj){
	int u;
	for(u=0;conj[u];u++);
	return u;
}

// Función para generar un espacio para todo el conjutno de tablas
Tabla **generarEspacioTablas(int m){
	Tabla **conj=(Tabla **)malloc(sizeof(Tabla *)*m);
	return conj;
}

// Redimensionar/Cambiar tamaño de conjunto de tablas
Tabla **redimEspacioTablas(Tabla **conj,int m){
	conj=(Tabla **)realloc(conj,m+1);
	return conj;
}

// Función para crear una nueva tabla
Tabla *crearTabla(char *nombre,int nCampos,char **metadatos){
	Tabla *tabla=(Tabla *)malloc(sizeof(Tabla));
	tabla->nombre=(char *)malloc(sizeof(char)*strlen(nombre));
	strcpy(tabla->nombre,nombre);
	tabla->nCampos=nCampos;
	tabla->metadatos=(char **)malloc(sizeof(char *)*nCampos);
	for(int u=0;u<nCampos;u++){
		tabla->metadatos[u]=(char *)malloc(sizeof(char)*strlen(metadatos[u]));
		strcpy(tabla->metadatos[u],metadatos[u]);
	}
	return tabla;
}

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

// Función asistente para nombrar campos en la GUI del usuario
void asistNombrarCampos(){
	char **nombres;
	int u=0,seguir;
	char *nombre;
	do{
		printf("Escribe a continuación");
		nombre=strdynread();
		nombres=realloc(nombres,u+1);
		strcpy(nombres[u],nombre);
		printf("¿Otro valor más? Presiona 0 para terminar u otra tecla para continuar\n");
		scanf("%d",&seguir);
		u++;
	}while(seguir);
}

char **metadatosRealloc(char **metadatos,int tama){
	return realloc(metadatos,sizeof(char **)*tama);
}
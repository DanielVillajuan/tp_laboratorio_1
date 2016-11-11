#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct{
    int id;
    int estado;
    int duracion;
    int puntaje;
    char titulo[30];
    char genero[25];
    char descripcion[50];
    char linkImagen[60];
}EMovie;
int espacioLibre(EMovie*,int CANT);
int agregarPelicula(EMovie*, int);
int borrarPelicula(EMovie* ,int);
int modificarPelicula(EMovie* ,int );
void generarPagina(EMovie lista[], char nombre[]);
void start(EMovie*,int);
void peliculasCargadas(EMovie*,int);
void ordenadoMayuscula(char[]);
void validarNombre( char []);
void archivo(EMovie*,int,char*);
void archivoModificado(EMovie*,int,char*);

#endif // FUNCIONES_H_INCLUDED

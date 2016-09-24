#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    long int dni;
    int estado;
}EPersona;

char validarNombre(char nombre[]);
long int validardni(char dni[]);
int validaredad(char edad[]);
void ordenadoMayuscula(char []);
void agregar(EPersona [],int);
void inicializacion(EPersona [] ,int );
void mostrar(EPersona [],int);
void borrarRegistro(EPersona [],int);
void ordenamiento(EPersona [],int,EPersona);
void grafico(int,int,int);
int obtenerEspacioLibre(EPersona lista[], int);
long int buscarPorDni(EPersona lista[],long int);

#endif // FUNCIONES_H_INCLUDED

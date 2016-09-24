#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>
#include <windows.h>
#include <ctype.h>
#define CANTIDAD 3

/**
*@brief Mayuscula en la inicial de cada Nombre
*@param nombre la cadena nombre se pasa como parametro
*/

void ordenadoMayuscula(char nombre[]){
    int i;

    strlwr(nombre);
    nombre[0]=toupper(nombre[0]);
    for(i=0;i<strlen(nombre);i++){
        if(nombre[i]==' '){
            i++;
            nombre[i]=toupper(nombre[i]);
        }
    }

} /* fin de funcion ordenadoMayuscula */

/**
*@brief valida dni de tipo caracater que no contenga una letra o signo de puntuacion y tenga la cantidad correcta
*@param dni cadena que se le pasa como parametro
*@return entero largo dni ya validado
*/

long int validardni(char dni[]) {

int i;

 while(strlen(dni)<7 || strlen(dni)>8)
        {
            printf("\nERROR!INGRESE CANTIDAD CORRECTA DE DIGITOS DEL DNI:");
            fflush(stdin);
            gets(dni);
        }

        for(i=0;i<strlen(dni);i++){
            while(isdigit(dni[i])==0 || ispunct(dni[i]!=0)){
                printf("\nIngreso una letra o signo de puntuacion!\n Reingrese DNI: ");
                gets(dni);

                while(strlen(dni)<7 || strlen(dni)>8)
                    {
                    printf("\nERROR!INGRESE CANTIDAD CORRECTA DE DIGITOS DEL DNI:");
                    fflush(stdin);
                    gets(dni);
                    }

                i=0;
                break;
            }
        }

        dni=atol(dni);

    return dni;
} /* fin de funcion validardni*/

/**
*@brief Valida la edad que no tenga letra o signo de puntuacion y la cantidad correcta
*@param edad cadena que se le pasa como parametro
*@return entero la edad ya validada
*/

int validaredad(char edad[]){

int i;

        while(strlen(edad)==0 || strlen(edad)>3){
             printf("\nERROR!INGRESE EDAD CORRECTA:");
            fflush(stdin);
            gets(edad);
        }

        for(i=0;i<strlen(edad);i++){
            while(isdigit(edad[i])==0 || ispunct(edad[i]!=0)){
                printf("\nIngreso una letra o signo de puntuacion!\n Reingrese edad: ");
                fflush(stdin);
                gets(edad);

                while(strlen(edad)==0 || strlen(edad)>3)
                    {
                    printf("\nERROR!INGRESE EDAD CORRECTA:");
                    fflush(stdin);
                    gets(edad);
                    }

                i=0;
                break;
            }
        }

        edad=atoi(edad);

        return edad;
} /* fin de funcion validaredad */

/**
*@brief Valida la cadena Nombre que no tenga un numero o puntuacion
*@param nombre cadena que se le pasa como unico parametro
*@return cadena de caracteres ya validada
*/

char validarNombre( char nombre[]){

int i;

for(i=0;i<strlen(nombre);i++){
    while(isdigit(nombre[i])!=0 || ispunct(nombre[i])!=0){
        printf("ERROR! INGRESO NUMERO o SIGNO DE PUNTUACION!\n REINGRESE NOMBRE:");
        gets(nombre);
        i=0;
        break;
    }
}

return nombre;
}/* fin de funcion validar nombre */


/**
*@brief Agrega a la lista a una persona completando los campos de la estructura validando si el DNI ya fue registrado
*@param Lista el array se pasa como parametro
*@param i indice a guardar que se le pasa como parametro
*/

void agregar(EPersona a[],int i){

int flag=0,j,auxEdad;
long int auxDni;
char dni[10],edad[5];


        printf("\nIngrese Nombre:");
        fflush(stdin);
        gets(a[i].nombre);
        validarNombre(a[i].nombre);
        ordenadoMayuscula(a[i].nombre);


        printf("Ingrese edad:");
        gets(edad);
        auxEdad=validaredad(edad);
        while(auxEdad<0 || auxEdad >110){
            printf("\nIngrese una edad Correcta:");
            gets(edad);
            auxEdad=validaredad(edad);
        }
        a[i].edad=auxEdad;

        printf("Ingrese DNI:");
        fflush(stdin);
        gets(dni);
        auxDni=validardni(dni);
        while(auxDni<1000000){
            printf("\nIngrese DNI VALIDO:");
            gets(dni);
            auxDni=validardni(dni);
        }

        for(j=0;j<CANTIDAD;j++){
            if(a[j].dni==auxDni){
                    system("cls");
                printf("\t \t\n ***DNI YA REGISTRADO!!***\n");
                printf("\t***DATOS DEL DNI YA REGISTRADO***\n \n");
                mostrar(a,j);
                getch();
                flag=1;
                break;
            }
        }
        a[i].dni=auxDni;

        if(flag==0){
                (a[i].estado=1);
                    }
            else{
                if(flag==1){
                    (a[i].estado=0);
                        }
            }
}/* fin de funcion agregar */

/**
*@brief Inicializa en "0" todos los campos de la estructura para poder ser completadas
*@param Lista array que se le pasa como parametro
*@param cant numero de cantidad de array de Lista
*/

void inicializacion(EPersona a[], int cant){

    int i;

    for(i=0;i<cant;i++){
        strcpy(a[i].nombre,"\0");
        a[i].edad=0;
        a[i].dni=0;
        a[i].estado=0;

        }
    return;
}/* fin de funcion inicializacion */

/**
*@brief Busca en el array de estructura un indice libre con el estado en "0"
*@param Lista array que se le pasa como parametro
*@param cant numero de cantidad de array de Lista
*@return i retorna el indice libre con el estado en "0"
*/

int obtenerEspacioLibre(EPersona a[], int cant){

int i;

for(i=0;i<cant;i++){

    if(a[i].estado==0){
            system("cls");
     printf("\t *** Hay espacio disponible!***");
     return i;
     break;
        }
}
    if(i==cant){
            system("cls");
            printf("No queda espacio para guardar!!!! \a");
                return -1;
           }
}/* fin de la funcion obtenerEspacioLibre */

/**
*@brief Muestra los campos con su respectivo indice
*@param Lista array que se le pasa como parametro
*@param i indice de ubicacion
*/


void mostrar(EPersona a[],int i){

      printf("\n \t Nombre:%s \n \t Edad:%d \n \t Estado:%d \n \t DNI:%ld \n \n",a[i].nombre,a[i].edad,a[i].estado,a[i].dni);

return;
} /* fin de funcion mostrar*/

/**
*@brief  Busqueda por DNI para mostrar datos si esta registrado
*@param Lista array que se le pasa como parametro
*@param dni dni ya validado que se le pasa como parametro
*@return dni si fue registrado o -1 en caso contrario
*/

long int buscarPorDni(EPersona a[],long int dni){

int i;

    for(i=0;i<CANTIDAD;i++){
        if(a[i].dni==dni){
                system("cls");
            printf("\n \n \t ------ DATOS: ------\n");
            mostrar(a,i);
            return dni;
            break;
        }
    }
    if(i==CANTIDAD){
            system("cls");
        printf("\n \n \n \t*******  DNI NO REGISTRADO! ******" );
        getch();
        return -1;
        }
}/* fin de funcion buscarPorDni */

/**
*@brief Borra Registro (Inicializa en 0 todos los campos de estructura) encontrado por DNI
*@param Lista array que se le pasa como parametro
*@param dni a borrar como parametro
*/

void borrarRegistro(EPersona a[], int dni){

    int i;

    for(i=0;i<CANTIDAD;i++){

        if(a[i].dni==dni){
        strcpy(a[i].nombre,"\0");
        a[i].edad=0;
        a[i].dni=0;
        a[i].estado=0;
        system("cls");
        printf("\n \n \n \t *** REGISTRO BORRADO ***");
        break;
        }
    }


}/* fin de funcion borrarRegistro */

/**
*@brief Ordena por nombre de A - Z todos los registros cargados(estado = 1 )
*@param Lista array que se le pasa como parametro
*@param cant numero de cantidad de array de Lista
*@param aux variable auxiliar de estructura que se le pasa como parametro
*/

void ordenamiento(EPersona a[],int cant,EPersona aux){
    int i,j,auxPrintf=0;

    for(i=0;i<cant-1;i++){
        for(j=i+1;j<cant;j++){
                if(stricmp(a[i].nombre,a[j].nombre)>0){

                    aux=a[i];
                    a[i]=a[j];
                    a[j]=aux;       }
                else    {
                        if(stricmp(a[i].nombre,a[j].nombre)==0) {
                            if(a[i].dni>a[j].dni) {
                                aux=a[i];
                                a[i]=a[j];
                                a[j]=aux;
                        }
                    }
                }
            }
        }

            for(i=0;i<cant;i++){


                    if(a[i].estado==1){
                            if(auxPrintf==0){
                                    printf("\n \t***Lista ordenada de  A-Z*** \n");
                                    auxPrintf=1;
                        }
                        mostrar(a,i);
                }
            }
    getch();

}/* fin de funcion ordenamiento */

/**
*@brief Grafico para mostrar la cantidad de gente registrada con respectivas edades
*@param menora18 contador que se le pasa como parametro
*@param entre19y35 contador que se le pasa como parametro
*@param mayora35 contador que se le pasa como parametro
*/


void grafico(int menora18,int entre19y35, int mayora35){

int i,band=0,grande;

    if(menora18>=entre19y35 && menora18>=mayora35){
        grande=menora18;
    }
    else{
        if(entre19y35>=menora18 && entre19y35>=mayora35){
            grande=entre19y35;
        }
        else{
            grande=mayora35;
        }
    }

    system("cls");
    printf("\n \n \n \n \n");

for(i=grande;i>0;i--){
        printf("    |");
        if(i<= menora18){
            printf(" *");
        }
        if(i<= entre19y35){
            band=1;
            printf("\t   *");
        }
        if(i<= mayora35){
            if(band==0)
                printf("  \t    \t*");
            if(band==1)
                printf("  \t*");

        }
        printf("\n");
    }

    printf("----+-----------------");
    printf("\nEDAD|<18 19-35 >35");
    printf("\n     %d\t  %d\t%d", menora18, entre19y35, mayora35);
    printf("\n \n La Cantidad de Personas:\n Hasta 18 anios: %d  \nEntre 19 y 35 años: %d  \nMayor a 35: %d  ",menora18,entre19y35,mayora35);
    getch();
}/* fin de funcion grafico */

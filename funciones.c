#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

/**
*@brief Inicializa en "0" todos los campos de la estructura para poder ser completadas
*@param plista puntero a array que se le pasa como parametro
*@param cant numero de cantidad de array de Lista
*/

void start(EMovie* plista,int CANT){

int i;
for(i=0;i<CANT;i++){
        (*(plista+i)).id=0;
        (*(plista+i)).duracion=0;
        (*(plista+i)).puntaje=0;
        (*(plista+i)).estado=0;
}

}//fin de funcion Start

/**
*@brief Busca en el array de estructura un indice libre con el estado en "0"
*@param pLista puntero a array que se le pasa como parametro
*@param cant numero de cantidad de array de Lista
*@return i retorna el indice libre con el estado en "0"
*/

int espacioLibre(EMovie* plista,int CANT){
    int i,retorno=-1;

    for(i=0;i<CANT;i++){
        if((plista+i)->estado==0){
            return i;
            break;
        }
    }
   return retorno;
}//fin de funcion espacioLibre
/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */

int agregarPelicula(EMovie* plista, int indice){

    int retorno=0;
    char confirmacion=0;

    printf("Ingrese Titulo:");
    fflush(stdin);
    gets((plista+indice)->titulo);
    validarNombre((plista+indice)->titulo);
    ordenadoMayuscula((plista+indice)->titulo);


    printf("Puntaje MAX|10:");
    scanf("%d",&(plista+indice)->puntaje);

    printf("Duracion (Minutos):");
    scanf("%d",&(plista+indice)->duracion);

    printf("Genero:");
    fflush(stdin);
    gets((plista+indice)->genero);
    validarNombre((plista+indice)->genero);
    ordenadoMayuscula((plista+indice)->genero);

    printf("Descripcion:");
    fflush(stdin);
    gets((plista+indice)->descripcion);
    validarNombre((plista+indice)->descripcion);
    ordenadoMayuscula((plista+indice)->descripcion);

    printf("Link de imagen:");
    fflush(stdin);
    gets((plista+indice)->linkImagen);

    printf("GUARDAR DATOS?! [s|n]");
    fflush(stdin);
    scanf("%c",&confirmacion);
    while(isdigit(confirmacion)!=0 || ispunct(confirmacion)!=0){
    printf("\nINGRESE S(si) o N(no):");
    fflush(stdin);
    scanf("%c",&confirmacion);
    }
    confirmacion=tolower(confirmacion);
    while(confirmacion!='s' && confirmacion!='n'){
    printf("\nINGRESE S(si) o N(no):");
    fflush(stdin);
    scanf("%c",&confirmacion);
    }

    if(confirmacion=='s'){

        (plista+indice)->estado=1;
        (plista+indice)->id=indice+1;
        retorno=1;
    }
    else{
        system("cls");
        printf("\n\n\t\t***DATOS CANCELADO, NO GUARDADOS***");
        getch();
    }


    return retorno;
}//Fin de funcion AgregarPelicula

/**
*@brief Muestra todas las peliculas de la Lista
*@param plista puntero array que se le pasa como parametro
*@param CANT cantidad de elementos del array
*/

void mostrarAll(EMovie* plista,int CANT){
 int i;
    for(i=0;i<CANT;i++){
            if((plista+i)->estado==1){
                printf("Titulo:%s\n",(plista+i)->titulo);
                printf("Genero:%s\n",(plista+i)->genero);
                printf("ID:%d\n",(plista+i)->id);
                printf("Duracion:%d\n",(plista+i)->duracion);
                printf("Puntaje:%d\n",(plista+i)->puntaje);
                printf("Descripcion:%s\n",(plista+i)->descripcion);
                printf("Link Imagen:%s\n",(plista+i)->linkImagen);
            }
    }

}// fin de funcion MostrarAll
/**
 *  Borra una pelicula del archivo binario
 *  @param plista elemento de la estructura a ser eliminada al archivo
 *  @param CANT cantidad de elementos de la estructura
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */

int borrarPelicula(EMovie* plista, int CANT){

int i,retorno=0,opcion;
char confirmacion;

        mostrarAll(plista,CANT);

        printf("\nEliga ID de Pelicula a borrar:");
        fflush(stdin);
        scanf("%d",&opcion);

        for(i=0;i<CANT;i++){
            if((plista+i)->id==opcion && (plista+i)->estado== 1){
                printf("\nSeguro de borrar pelicula?[s|n]=");
                fflush(stdin);
                scanf("%c",&confirmacion);
                while(isdigit(confirmacion)!=0 || ispunct(confirmacion)!=0){
                            printf("\nINGRESE S(si) o N(no):");
                            fflush(stdin);
                            scanf("%c",&confirmacion);
                        }
                        confirmacion=tolower(confirmacion);
                        while(confirmacion!='s' && confirmacion!='n'){
                            printf("\nINGRESE S(si) o N(no):");
                            fflush(stdin);
                            scanf("%c",&confirmacion);
                        }
                if(confirmacion=='s'){
                    (plista+i)->estado=0;
                    (plista+i)->id=0;
                    retorno=1;
                    break;
                }
                else{
                    printf("\nAccion Cancelada!");
                    break;
                }

            }
        }
        if(i==CANT){
            printf("\n ID NO ENCONTRADO!");
            retorno=0;
        }
        return retorno;
}//fin de funcion BorrarPelicula

/**
 *  Modifica una pelicula del archivo binario
 *  @param plista puntero a elemento de la estructura a ser eliminada
 *  @param CANT cantidad de elementos del array
 *  @return retorna 1 o 0 de acuerdo a si pudo modificar la pelicula o no
 */

int modificarPelicula(EMovie* plista,int CANT){

int i,retorno=0,opcion;
char confirmacion;
int duracion;
int puntaje;
char titulo[30];
char genero[25];
char descripcion[50];
char linkImagen[60];

        mostrarAll(plista,CANT);

        printf("\nEliga ID de Pelicula a Modificar:");
        fflush(stdin);
        scanf("%d",&opcion);

        for(i=0;i<CANT;i++){
            if((plista+i)->id==opcion && (plista+i)->estado== 1){
               printf("\nNuevo Titulo:");
               fflush(stdin);
               gets(titulo);
               validarNombre(titulo);
               ordenadoMayuscula(titulo);
               printf("\nPuntaje MAX|10:");
               scanf("%d",&puntaje);
               printf("\nDuracion (Minutos):");
               scanf("%d",&duracion);
               printf("\nGenero:");
               fflush(stdin);
               gets(genero);
               validarNombre(genero);
               ordenadoMayuscula(genero);
               printf("\nDescripcion:");
               fflush(stdin);
               gets(descripcion);
               validarNombre(descripcion);
               ordenadoMayuscula(descripcion);
               printf("\nLink de Imagen:");
               fflush(stdin);
               gets(linkImagen);

                printf("\nSeguro de modificar Pelicula?[s|n]:");
                fflush(stdin);
                scanf("%c",&confirmacion);

                if(confirmacion=='s' || confirmacion=='S'){
                    strcpy((plista+i)->titulo,titulo);
                    (plista+i)->puntaje=puntaje;
                    (plista+i)->duracion=duracion;
                    strcpy((plista+i)->genero,genero);
                    strcpy((plista+i)->descripcion,descripcion);
                    strcpy((plista+i)->linkImagen,linkImagen);
                    retorno=1;
                    break;
                }
                else{
                    printf("\nAccion Cancelada!");
                    break;
                }
            }
        }
        if(i==CANT){
            printf("\n ID NO ENCONTRADO!");
            retorno=0;
        }
        return retorno;

}//fin de funcion ModificarPelicula
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

}//fin de funcion OrdenadoMayuscula

/**
*@brief Valida la cadena Nombre que no tenga un numero o puntuacion
*@param nombre cadena que se le pasa como unico parametro
*@return cadena de caracteres ya validada
*/

void validarNombre( char nombre[]){

int i;

for(i=0;i<strlen(nombre);i++){
    while(isdigit(nombre[i])!=0 || ispunct(nombre[i])!=0){
        printf("ERROR! INGRESO NUMERO o SIGNO DE PUNTUACION!\n REINGRESE NOMBRE:");
        gets(nombre);
        i=0;
        break;
    }
}
}//fin de funcion validarNombre

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie lista[], char nombre[]){


}

/**
 *  Genera un archivo binario a partir de las peliculas cargadas
 *  @param plista puntero que se le pasa como parametro para el archivo
 *  @param cant cantidad de peliculas cargadas
 *  @param nombreArchivo nombre del archivo binario a crear
 */

void archivo(EMovie* plista,int cant,char* nombreArchivo){

FILE *archi=fopen(nombreArchivo,"ab");



if(archi==NULL){
    printf("\nNo se pudo generar el archivo");
    getch();
}
else{
        fwrite(plista,sizeof(EMovie),cant,archi);
        printf("\n\n\tSe pudo crear El archivo con peliculas!");
        fclose(archi);
}

}//fin de funcion archivo

/**
 *  Modifica/SobreEscribe archivo binario a partir de las peliculas modificadas
 *  @param plista puntero que se le pasa como parametro para el archivo
 *  @param cant cantidad de peliculas cargadas
 *  @param nombreArchivo nombre del archivo binario a modificar
 */

void archivoModificado(EMovie* plista,int cant,char* nombreArchivo){

FILE *archi=fopen(nombreArchivo,"wb");



if(archi==NULL){
    printf("\nNo se pudo generar el archivo Modificado");
    getch();
}
else{
        fwrite(plista,sizeof(EMovie),cant,archi);
        printf("\n\n\tArchivo Modificado!");
        fclose(archi);
}

}//fin de funcion modificarArchivo

/*
    Trabajo Practico Incompleto de Archivos

AMB:Completo.
No tuvimos tiempo de practicar archivos por la fecha de entrega del TP3
Motivos:por falta de clases,feriados,etc.

 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define CANT 5


int main()
{
    char seguir='s',nombreArchivo[15]="prueba.bin";
    int opcion=0,eL,retorno,borrado,modificado,cantAlta=0,salvavidas=0;

    EMovie lista[CANT];
    EMovie *plista;
    plista=lista;

    start(plista,CANT);

    while(seguir=='s')
    {   system("cls");

        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:     system("cls");
                        eL = espacioLibre(plista,CANT);

                            if(eL!=-1){
                                retorno=agregarPelicula(plista,eL);
                                if(retorno==1){
                                    printf("\n\n\t\t***DATOS GUARDADOS!***");
                                    cantAlta++;
                                    archivo(plista,CANT,nombreArchivo);
                                    salvavidas=1;
                                    getch();
                                }
                            }
                            else{
                                system("cls");
                                printf("\n\n\t\t***NO HAY ESPACIO EN MEMORIA!***");
                                getch();
                            }
                break;
            case 2:
                        if(salvavidas==0){
                                system("cls");
                            printf("LISTA VACIA! INGRESE UNA PELICULA PRIMERO!");
                            getch();
                            break;
                        }

                        borrado = borrarPelicula(plista,CANT);

                        if(borrado==1){
                            printf("\nDatos Borrado Correctamente!");
                            cantAlta--;
                            archivoModificado(plista,CANT,nombreArchivo);
                            getch();
                        }

                break;
            case 3:
                        if(salvavidas==0){
                            system("cls");
                            printf("LISTA VACIA! INGRESE UNA PELICULA PRIMERO!");
                            getch();
                            break;
                        }

                        modificado = modificarPelicula(plista,CANT);

                        if(modificado==1){
                            printf("\nDatos Modificado Correctamente!");
                            archivoModificado(plista,CANT,nombreArchivo);
                            getch();
                        }
                break;
            case 4:
                seguir = 'n';
                break;
            default:
                printf("\nIngrese Opcion correcta! \n");
                        system("pause");
                break;
        }
    }
    return 0;
}

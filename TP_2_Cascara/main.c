#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>
#include <ctype.h>
#include <windows.h>
#define CANTIDAD 3


int main()
{
    char seguir='s',cancel,dni[10];
    int opcion,e,i,menora18=0,entre19y35=0,mayora35=0;
    long int d,auxDni;

    EPersona lista[CANTIDAD];
    EPersona aux;

    inicializacion(lista,CANTIDAD);

    while(seguir=='s')
    {


        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");
        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                        e=obtenerEspacioLibre(lista,CANTIDAD);
                        if(e>=0){
                        agregar(lista,e);
                        break;
                        }
                        getch();
                        break;
            case 2:
                    system("cls");
                        printf("Ingrese DNI a eliminar:");
                        scanf("%s",&dni);
                        auxDni=validardni(dni);
                        d=buscarPorDni(lista,auxDni);

                        if(d>0){
                        printf("Desea eliminar registro: [S|N]");
                        fflush(stdin);
                        scanf("%c",&cancel);
                        while(isdigit(cancel)!=0 || ispunct(cancel)!=0){
                            printf("\nINGRESE S(si) o N(no):");
                            fflush(stdin);
                            scanf("%c",&cancel);
                        }
                        cancel=tolower(cancel);
                        while(cancel!='s' && cancel!='n'){
                            printf("\nINGRESE S(si) o N(no):");
                            fflush(stdin);
                            scanf("%c",&cancel);
                        }
                        if(cancel=='s'){
                            borrarRegistro(lista,d);
                        }
                        getch();
                        }

                break;
            case 3:     system("cls");
                        ordenamiento(lista,CANTIDAD,aux);
                break;
            case 4:
                        for(i=0;i<CANTIDAD;i++){
                            if(lista[i].estado==1){
                                if(lista[i].edad<=18){
                                    menora18++;
                                        }
                                else{
                                    if(lista[i].edad>=19 && lista[i].edad<=35){
                                        entre19y35++;
                                    }
                                    else{
                                        mayora35++;
                                    }
                                }
                            }
                        }

                        grafico(menora18,entre19y35,mayora35);

                break;
            case 5:
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

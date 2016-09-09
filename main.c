#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
#include "funciones.h"
int main()
{
    char seguir='s';
    int opcion=0,flag1=0,flag2=0;
    float num1=0,num2=0;

    while(seguir=='s')
    {   system("cls");

        printf("1- Cargar 1er operando (A=%.3f)\n",num1);
        printf("2- Cargar 2do operando (B=%.3f)\n",num2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (Solo de A)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n \n");
        scanf("%d" , &opcion);

        if(opcion>=1 && opcion<=9){
        switch(opcion)
        {
            case 1:     system("cls");
                                printf("Ingrese numero(A): \n");
                                scanf("%f",&num1);
                                    cero(num1);
                        flag1=1;
                break;

            case 2:     system("cls");
                                printf("Ingrese numero(B): \n");
                        scanf("%f",&num2);
                                    cero(num2);
                        flag2=1;

                break;

            case 3: system("cls");

                        validar_ingreso(flag1,flag2);
                        if(flag1!=0 || flag2!=0){
                            printf("Numero A: %.3f y Numero B: %.3f \n \n",num1,num2);
                                suma(num1,num2);
                            getch();
                                                }
                    break;

            case 4:
                    system("cls");

                        validar_ingreso(flag1,flag2);

                        if(flag1!=0 || flag2!=0){
                            printf("Numero A: %.3f y Numero B: %.3f \n \n",num1,num2);
                                resta(num1,num2);
                            getch();
                                                }

                break;

            case 5:
                    system("cls");

                        validar_ingreso(flag1,flag2);
                        if(flag1!=0 || flag2!=0){
                                printf("Numero A: %.3f y Numero B: %.3f \n \n",num1,num2);
                                division(num1,num2);
                                getch();        }
                break;
            case 6:
                    system("cls");

                        validar_ingreso(flag1,flag2);

                        if(flag1!=0 || flag2!=0){
                                printf("Numero A: %.3f y Numero B: %.3f \n \n",num1,num2);
                                multiplicacion(num1,num2);
                                getch();
                                                }
                break;

            case 7:
                    system("cls");
                        if(flag1==0){
                            printf("No ingreso el Operando A!!! \a");
                            getch();
                        }else{
                            printf("Numero A= %.3f  \n \n",num1);
                            factorial(num1);
                    getch();    }
                break;

            case 8:
                system("cls");
                    validar_ingreso(flag1,flag2);

                    if(flag1!=0 || flag2!=0){
                        printf("Numero A: %.3f Numero B: %.3f \n \n",num1,num2);
                           suma(num1,num2);
                           resta(num1,num2);
                           division(num1,num2);
                           multiplicacion(num1,num2);
                           factorial(num1);
                        getch();
                        }

                    break;

            case 9:
                system("cls");
                printf("\n \n \n \n *** Hasta Luego! *** \n \n \n \n \n \n");
                seguir = 'n';
                break;

            default:{}
                break;

            }  /* FIN DEL SWITCH */
        }  /* FIN DEL IF DE VALIDACION DE OPCION*/
    }  /* FIN DEL BUCLE DE LA CALCULADORA */

 return 0;

} /* FIN DEL CODIGO */

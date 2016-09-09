/**
* @brief Librerias!
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <windows.h>



/**
*@brief Muestra un mensaje por ingresar CERO como operando
*@param A Variable(bandera) a comparar el ingreso a CERO
*/

void cero(int a){
if(a==0){
        system("cls");
    printf("Usted a Ingresado CERO!!");
    getch();
        }
}  /* FIN DE LA FUNCION "CERO" */


/**
*   @brief Valida el ingreso de un operando y devuelve mensaje
*   @param A Variable(bandera 1) para comparar el primer ingreso
*   @param B Variable(bandera 2) para comparar el segundo ingreso
*/
void validar_ingreso(int a,int b){
if(a==0 && b==0){
                printf("NO INGRESO NI UN OPERANDO!!! \a \n \n Resultado: 0.000 \n \n");
                getch();
                }
else{
        if(a==0 || b==0){
                printf("Le falto ingresar un Operando!.Se reemplazara automaticamente por CERO! \n \n");
                        }
    }

                                 } /* FIN DE FUNCION "Validar_ingreso" */

 /**
 *@brief Suma dos numeros y devuelve el resultado
 *@param A Primera variable a sumar
 *@param B Segundo numero a sumar
 *@return Devuelve la suma en una 3ra variable
 */

float suma(float a,float b){

float resultado;
    resultado=a+b;
    printf("El resultado de la suma es: %.3f \n",resultado);
return resultado;
}   /* FIN DE LA FUNCION "SUMA" */

/**
 *@brief Resta dos numeros y devuelve el resultado
 *@param A Primera variable a restar
 *@param B Segundo numero a restar
 *@return Devuelve la resta en una 3ra variable
 */
float resta(float a,float b){

float resultado;
    resultado=a-b;
    printf("El resultado de la resta es: %.3f \n",resultado);
return resultado;
}   /* FIN DE FUNCION "RESTA" */

 /**
 *@brief Multiplica dos numeros,devuelve el resultado y valida el cero por un resultado "-0"
 *@param A Primera variable a multiplicar
 *@param B Segunda variable a multiplicar
 *@return Devuelve el resultado en una 3ra variable
 */

float multiplicacion(float a,float b){

float resultado;
    if(a==0 || b==0){
            printf("El resultado de la Multiplicacion es: 0.000");
    }
    else{
    resultado=a*b;
    printf("El resultado de la Multiplicacion es: %.3f \n",resultado);
    }
return resultado;
}/* FIN DE FUNCION "MULTIPLICACION" */

/**
*@brief Divide dos numeros,devuelve el resultado y valida que se divida por 0
*@param A Primera variable a dividir
*@param B Segunda variable para dividir
*@return Devuelve resultado en una 3ra variable
*/

float division(float a, float b){

float resultado;

    if (b==0){
        printf("No se puede dividir por 0 \a\n");
             }
    else{
        resultado=a/b;
        printf("el resultado de la division es: %.3f \n",resultado);
        }
return resultado;
}   /* FIN DE FUNCION DIVISION Y VALIDACION */

/**
*@brief Factorea un numero ingresado y la devuelve.
*@brief Tambien, valida si es un negativo ,o decimal(devuelve el factorial del entero).
*@param A Variable a Factorial
*@return Devuelve el resultado en una 3ra variable
*/

int factorial(float a){

    int i;
    int acum=1;
    int e;
    float b;
    e=(int)a;  //TOMAR EL ENTERO DEL NUMERO FLOTANTE
    b=ceil(a); // COMANDO "CEIL" PARA REDONDEAR UN DECIMAL

        if(e<0){
            printf("no se puede factoriar NEGATIVO \a \n");
                }
        else{
                        if(a<b) {
                                printf("Ingresaste numero decimal! : %.3f \n",a);
                                for(i=1;i<=e;i++)
                                {
                        acum=i*acum;   // BUCLE DE INICIO "1" HASTA EL NUMERO INGRESADO E IR ACUMULANDO EL NUMERO MULTIPLICADO.
                                }
                            printf("(***NO SE PUEDE CON DECIMALES***)\a \n Pero si la parte entera,el factorial del entero(A) es: %d \n",acum);
                                }
                        else{

                                for(i=1;i<=e;i++)
                                {
                                acum=i*acum;
                                }
                                printf("El factorial es : %d \n",acum);

                                }

                    }

    return acum;
} /* FIN DE FUNCION FACTORIAL */

/* 
ENUNCIADO DEL EJERCICIO:
-------------------------------------------------------------------------------------------------------------------------
Ed, Edd y Eddy tienen una máquina de golosinas donde fueron guardando todos los caramelos rompemuelas que tienen.
Ésta misma sólo saca un caramelo cuando se ingresa el código correcto, que consiste en la suma de las edades de los tres. 
Ed quiere comer uno antes de irse a dormir, pero no es muy bueno con las sumas.
Ayudalo implementando un procedimiento que le diga el código a ingresar.
Implementar el procedimiento imprimir_codigo, el cual reciba tres números e imprima por pantalla el 
resultado de la suma de estos.

Ejemplos:
Si se recibe 15, 18 y 17, debe imprimirse "50".
Si se recibe 21, 20 y 24, debe imprimirse "65".
-------------------------------------------------------------------------------------------------------------------------
*/

// RESOLUCION 
#include <stdio.h>

void imprimir_codigo(int numero_1,int numero_2, int numero_3){
    int suma = numero_1 + numero_2 + numero_3;
    printf("%i",suma);
}

int main(){
    int edad_ed;
    scanf("%i", &edad_ed);
    int edad_edd;
    scanf("%i", &edad_edd);
    int edad_eddy;
    scanf("%i", &edad_eddy);

    imprimir_codigo(edad_ed,edad_edd,edad_eddy);

    return 0;
}
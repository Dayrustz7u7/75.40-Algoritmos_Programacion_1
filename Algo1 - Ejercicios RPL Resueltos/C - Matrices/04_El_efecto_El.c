/* 
ENUNCIADO DEL EJERCICIO:
-------------------------------------------------------------------------------------------------------------------------
Él, el enemigo de las chicas superpoderosas, tiene poderes psicológicos con los que puede volver locas a sus enemigas.

En esta oportunidad, se le ocurrió hacer que las chicas superpoderosas vean a distintos grupos de personas personificados
en Él.

Para tener registradas cuántas personas tiene en cada grupo, hizo una matriz donde cada posición equivale a la cantidad
de personas que le quedan con ese efecto, y a medida que fueron pasando los dias, se agregó una nuevo valor con la 
cantidad de personas nuevas que fueron afectadas, o las que fueron curadas. Si en el grupo lograron volver a la 
normalidad, se encontrará representada la cantidad con un número negativo.

Implementar una función que devuelva el total de las personas que todavía tienen el efecto de Él.
Ejemplo:

Si se recibe la matriz de 3x4:
 5 4 -2  1
-4 5  2  2
-2 -5 3  7
El total que se deberá devolver será 5+4-2+1-4+5+2+2-2-5+3+7 = 16
-------------------------------------------------------------------------------------------------------------------------
*/

// RESOLUCION 
#include <stdio.h>
#define MAX_FILAS 5
#define MAX_COLUMNAS 5

int personas_bajo_efecto(int grupos[MAX_FILAS][MAX_COLUMNAS], int tope_fila, int tope_columna) {
    int total=0;
    for(int i =0; i< tope_fila; i++){
        for(int j =0; j< tope_columna; j++){
            total += grupos[i][j];
        }
    }
    return total;
}
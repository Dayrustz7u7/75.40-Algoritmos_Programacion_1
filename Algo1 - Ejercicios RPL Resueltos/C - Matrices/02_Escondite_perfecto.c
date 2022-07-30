/* 
ENUNCIADO DEL EJERCICIO:
-------------------------------------------------------------------------------------------------------------------------
Coraje hace poco cumplió años y le regalaron un montón de huesos para que coma. Pero como quiere que le duren para que 
el disfrute sea mayor, decidió esconder un hueso en cada árbol de un parque. El problema es que al haber tantos, siempre 
pierde la cuenta.

Implementar una función que recorra el parque como si fuera una matriz, donde cada casillero va a estar representado 
por una A si hay un árbol, o una V si está vacío, y devuelva la cantidad total de árboles encontrados.
-------------------------------------------------------------------------------------------------------------------------
*/

// RESOLUCION 
#include <stdio.h>
#define MAX_FILAS 5
#define MAX_COLUMNAS 5
#define ARBOL 'A'
#define VACIO 'V'

int cantidad_arboles(char parque[MAX_FILAS][MAX_COLUMNAS]) {
    int contador=0;
    for(int i=0;i<MAX_FILAS;i++){
        for(int j= 0; j<MAX_COLUMNAS;j++){
            if( parque[i][j]== ARBOL){
                contador++;
            }
        }
    }
    return contador;
}
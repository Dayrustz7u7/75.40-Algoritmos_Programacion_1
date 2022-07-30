/* 
ENUNCIADO DEL EJERCICIO:
-------------------------------------------------------------------------------------------------------------------------
El profesor Utonio, libre de trabajo, decidió ponerse a sembrar unas flores en su patio. Como sus favoritas son 
las rosas, plantó rosas en todo el terreno disponible que tenía.

Implementar un procedimiento que inicialice todo el terreno con las rosas (R).
-------------------------------------------------------------------------------------------------------------------------
*/

// RESOLUCION 
#include <stdio.h>
#define MAX_TERRENO 10
#define ROSAS 'R'

void cantidad_arboles(char patio[MAX_TERRENO][MAX_TERRENO]) {
    for(int i =0;i<MAX_TERRENO;i++){
        for(int j = 0;j<MAX_TERRENO;j++){
            patio[i][j] = ROSAS;
        }
    }
}
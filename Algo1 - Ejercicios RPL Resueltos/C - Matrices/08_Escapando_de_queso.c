/* 
ENUNCIADO DEL EJERCICIO:
-------------------------------------------------------------------------------------------------------------------------
Blue se está escondiendo de Queso, ya no soporta escucharlo hablar sobre lo genial que son los sándwiches de manteca de 
maní y mermelada. Para su desgracia, Queso tiene un gran instinto como para buscarlo, así que Blue tiene que estar 
moviéndose y cambiando de escondite a cada rato.

Implementar una función que dada una matriz que representa a la mansión Foster, y la posición siguiente de Blue, realice 
el movimiento y devuelva true si esto es posible. En caso contrario debe devolver false y no realizar el movimiento.
El movimiento no se puede hacer si la posición está ocupada por Queso o queda por fuera de los límites de la matriz.
A tener en cuenta:

La matriz puede no ser cuadrada y tiene sus respectivos topes.
Siempre va a haber un Blue en la matriz! Aunque puede que no haya un Queso.
La matriz es de caracteres, donde en cada posición puede haber:
Blue (B).
Queso (Q).
Vacío (-).
Ejemplo:

Teniendo una matriz de 3x3:

- B -
- - -
Q - -
Y teniendo como nueva posición:

fila = 3
columna = 0
No se debe mover a Blue, quedando la matriz sin modificar, y se debe devolver false.
-------------------------------------------------------------------------------------------------------------------------
*/

// RESOLUCION 
#include <stdbool.h>
#define MAX_FILAS 30
#define MAX_COLUMNAS 25
#define BLUE 'B'
#define QUESO 'Q'
#define VACIO '-'


bool mover(char mansion[MAX_FILAS][MAX_COLUMNAS], int tope_filas, int tope_columnas, int nueva_fila, int nueva_columna) {
    bool movimiento_valido = false;
    if(nueva_fila>tope_filas || nueva_columna>tope_columnas){
        movimiento_valido = false;
        return movimiento_valido;
    }
    if(mansion[nueva_fila][nueva_columna]==QUESO){
        movimiento_valido = false;
        return movimiento_valido;
    }
    else if(mansion[nueva_fila][nueva_columna]!= QUESO){
        for(int i=0;i<tope_filas;i++){
            for(int j = 0; j<tope_columnas;j++){
                if(mansion[i][j]==BLUE){
                    mansion[i][j] = VACIO;
                }
            }
        }
        mansion[nueva_fila][nueva_columna] = BLUE;
        movimiento_valido = true;
    }
    return movimiento_valido;
}
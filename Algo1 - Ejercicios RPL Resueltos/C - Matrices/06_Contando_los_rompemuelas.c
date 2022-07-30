/* 
ENUNCIADO DEL EJERCICIO:
-------------------------------------------------------------------------------------------------------------------------
Ed, Edd y Eddy se vieron con ganas de comer rompemuelas, pero se dieron cuenta que estaban todos desparramados por el 
cajón, y no podían saber si iban a alcanzar para los tres.

Se tiene una matriz que representa al cajón, y en cada posición se encuentra el caracter R si se encuentra un rompemuelas
rojo, A si hay un rompemuelas azul, V si hay un rompemuelas verde o - si no hay ningún caramelo.

Implementar una función que dada la cantidad de caramelos pedidos y el color, devuelva true si los caramelos alcanzan o 
false en caso contrario. Además, se pide que se actualice la matriz debiendo quedar la posición en la que se encuentran dichos caramelos, vacía.

Tener en cuenta:

Si los caramelos no son suficientes, la matriz debe quedar como está dada originalmente.
Si los caramelos son suficientes se debe actualizar la matriz vaciando los caramelos pedidos recorriendo de arriba hacia 
abajo, de izquierda a derecha.
Ejemplo:

Se quieren 5 caramelos rojos, y la matriz recibida es:

R A V -
V A A -
- R R V
La cantidad de caramelos rojos es insuficiente, por lo que se debe devolver false y la matriz quedar como estaba.

Otro ejemplo:

Se quieren 2 caramelos verdes, y la matriz recibida es:

V A -
- V V
- V R
La cantidad de verdes es suficiente, por lo que se debe devolver true y la matriz se debe actualizar a:

- A -
- - V
- V R
-------------------------------------------------------------------------------------------------------------------------
*/

// RESOLUCION 
#include <stdbool.h>
#define MAX_FILAS 5
#define MAX_COLUMNAS 5
#define C_ROJO 'R'
#define C_AZUL 'A'
#define C_VERDE 'V'
#define VACIO '-'

bool caramelos_suficientes(char cajon[MAX_FILAS][MAX_COLUMNAS], int tope_filas, int tope_columnas, int cantidad_caramelos, char color_caramelo) {
    int cantidad_esperada = 0;
    int cantidad_eliminados = 0;
    bool alcanzo;
    for(int i =0; i< tope_filas; i++){
        for(int j =0; j< tope_columnas; j++){
            if( cajon[i][j] == color_caramelo ){
                cantidad_esperada++;
            }
        }
    }
    if (cantidad_esperada >= cantidad_caramelos){
        for(int i =0; i< tope_filas; i++){
            for(int j =0; j< tope_columnas; j++){
                if( cajon[i][j] == color_caramelo && cantidad_eliminados < cantidad_caramelos){
                    cajon[i][j] = VACIO;
                    cantidad_eliminados++;
                }
            }
        }
        alcanzo = true;
    }else{
        alcanzo = false;
    }
    return alcanzo;
}
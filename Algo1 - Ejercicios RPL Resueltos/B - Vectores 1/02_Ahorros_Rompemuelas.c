/* 
ENUNCIADO DEL EJERCICIO:
-------------------------------------------------------------------------------------------------------------------------
Ed, Edd y Eddy están ahorrando arduamente para poder comprarse uno de los deliciosos rompemuelas sabor chocotorta que
salió como edición limitada. Llevan cuenta de sus ahorros diariamente y van anotándolos en un vector.

Implementar una función que dado un vector de sus ahorros y su tope devuelva la cantidad total de ahorros que 
lograron juntar hasta el momento.
Ejemplos:

Si se recibe el vector [50,120,43,300], se debe devolver 513.
Si se recibe el vector [400,120,80], se debe devolver 600.
-------------------------------------------------------------------------------------------------------------------------
*/

// RESOLUCION 
#include <stdio.h>
#define MAX_AHORROS 256

int calcular_ahorros_totales(int ahorros[MAX_AHORROS], int tope_ahorros) {
	int ahorros_totales = 0;
	for(int i = 0; i<tope_ahorros; i++){
		ahorros_totales += ahorros[i];
	}
	return ahorros_totales;
}
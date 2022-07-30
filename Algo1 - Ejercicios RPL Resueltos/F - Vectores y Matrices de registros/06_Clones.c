/*	ENUNCIADO
-------------------------------------------------------------------------------------------------------------------------
Dexter está experimentando para poder crear un propio ejército de clones de él mismo, con el cual cree que la velocidad de sus experimentos va a 
crecer linealmente con la cantidad de clones que haga. Pero como nunca trabajó en equipo, no entiende mucho cómo funciona, asi que lo vamos a ayudar. 
Nos informó que ya generó todos los clones y que solo falta copiar en éstos los datos del Dexter original. Pero no exactamente lo mismo a todos, quiere 
ver de variar un poco el nivel de paciencia que maneja cada clon.

    Realizar una función que dada una matriz de clones, sus respectivos topes y la información del Dexter original, rellene toda la matriz con 
    la información del original. Solo se pide cambiar la paciencia, la cual debe ser calculada como fila * columna para cada clon.

Notas:

    La matriz puede NO ser cuadrada.
    Cada clon o Dexter tiene los siguientes datos:
        Imaginación (entero).
        Paciencia (entero).
        Conocimiento (entero).
        Es clon (booleano).
    Tener en cuenta que el dexter que se pasa por parámetro es el original, por lo tanto su booleano de si es clon va a estar en false, pero todos 
    los de las matriz son clones, por lo que su booleano debe este en true.
-------------------------------------------------------------------------------------------------------------------------
    */

//	RESOLUCION

#include <stdio.h>
#include <stdbool.h>
#define MAX_FILAS 50
#define MAX_COLUMNAS 50

typedef struct dexter {
    int imaginacion;
    int paciencia;
    int conocimiento;
    bool es_clon;
} dexter_t;

void inicializar_clones(dexter_t clones[MAX_FILAS][MAX_COLUMNAS], int tope_filas, int tope_columnas, dexter_t original){
    
    for(int i =0; i < tope_filas; i++){
        for(int j =0; j < tope_columnas; j++){
            clones[i][j] = original;
            clones[i][j].paciencia = i*j;
            clones[i][j].es_clon = true;
        }
    }
}

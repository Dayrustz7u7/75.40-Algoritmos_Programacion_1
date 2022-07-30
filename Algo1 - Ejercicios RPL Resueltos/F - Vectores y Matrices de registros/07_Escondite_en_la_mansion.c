/*	ENUNCIADO
-------------------------------------------------------------------------------------------------------------------------
Los amigos imaginarios están todos jugando a un gran escondite en la mansión. Blue resulta ser muy malo al encontrar gente, y 
ya se está empezando a frustrar. Sabe que hacer trampa está mal, pero espera que nadie lo descubra y te pide ayuda para encontrar a los demás amigos.

    Implementar una función que a partir de una matriz que representa la mansión, sus respectivos topes y una posición que eligió Blue, 
    devuelva true si hay un amigo en esa posición o false en caso contrario.

Notas:

    La matriz que representa la mansión tiene en cada posición suya un registro con los siguientes datos:
        Ocupado (booleano).
        Nombre de amigo (string).
        Nombre de escondite (string).
    La matriz puede NO ser cuadrada.
-------------------------------------------------------------------------------------------------------------------------
*/

//	RESOLUCION

#include <stdio.h>
#include <stdbool.h>
#define MAX_FILAS 100
#define MAX_COLUMNAS 100
#define MAX_NOMBRE 60
// Acá deberían ir las constantes.

typedef struct escondite {
    bool ocupado;
    char nombre_amigo[MAX_NOMBRE];
    char nombre_escondite[MAX_NOMBRE];
} escondite_t;

typedef struct posicion {
    int fila;
    int columna;
} posicion_t;

bool hay_amigo(escondite_t mansion[MAX_FILAS][MAX_COLUMNAS], int tope_filas, int tope_columnas, posicion_t posicion){
   bool encontrado = false;
   int i=0;
   int j=0;
   while(!encontrado && i <posicion.fila){
       while(!encontrado && j<posicion.columna){
           if(mansion[i][j].ocupado){
               encontrado = true;
           }
            j++;
       }
       i++;
   }
   return encontrado;
}
/* 
ENUNCIADO DEL EJERCICIO:
-------------------------------------------------------------------------------------------------------------------------
Conejo lleva registro de todos los amigos imaginarios que se encuentran en la mansión Foster, y como es súper 
ordenado los tiene en un vector donde a cada amigo imaginario lo representa con un id que es un entero.
Últimamente están entrando muchos amigos nuevos y a Conejo se le complica un poco estar agregándolos a mano a 
este vector, por lo que nos pidió ayuda para que creemos un algoritmo que lo haga por él. Pero como nosotros nos 
dormimos en esas clases, te lo pedimos a vos.

Implementar una función que dado un vector, su tope y un id agregue al nuevo amigo al vector.
Además, si no es posible agregarlo porque el vector ya está al máximo de su capacidad, se pide que devuelva false y 
en caso contrario devolver true.
-------------------------------------------------------------------------------------------------------------------------
*/

// RESOLUCION 
#include <stdbool.h>
#define MAX_AMIGOS 5

bool registrar_amigo(int amigos[MAX_AMIGOS], int* tope_amigos, int id_amigo) {
    bool no_esta_lleno;
    if( (*tope_amigos) < MAX_AMIGOS){
        amigos[(*tope_amigos)] = id_amigo;
        (*tope_amigos)++;
        no_esta_lleno = true; 
    }
    else {
        no_esta_lleno = false;
    }
    return no_esta_lleno;
}
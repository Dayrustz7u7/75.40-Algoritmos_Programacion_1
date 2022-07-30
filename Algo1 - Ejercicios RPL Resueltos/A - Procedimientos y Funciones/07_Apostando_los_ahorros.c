/* 
ENUNCIADO DEL EJERCICIO:
-------------------------------------------------------------------------------------------------------------------------
Blue y Mac están apostando parte de sus ahorros a adivinar cuántos huevos pone Coco en el día. El que gana, se lleva 10
pesos del que pierde, y si hay empate los ahorros de ambos están a salvo.

Implementar una función que dados los ahorros de Mac, los ahorros de Blue y la cantidad de huevos que puso Coco en 
el día, modifique ambos ahorros según corresponda. Tener en cuenta que:

Si Coco puso más de 10 huevos, Blue le da 10 pesos a Mac.
Si Coco puso menos de 10 huevos, Mac le da 10 pesos a Blue.
Si puso exactamente 10 huevos, entonces no pasa nada.

Si el que pierde no posee el dinero necesario, le dará todo lo que pueda hasta quedar en 0.
-------------------------------------------------------------------------------------------------------------------------
*/

// RESOLUCION
#include <stdio.h>
#define HUEVOS 10
#define VACIO 0
#define PESOS 10

void realizar_apuesta(int* ahorros_mac, int* ahorros_blue, int huevos_puestos) {

    if (huevos_puestos > HUEVOS ){
        (*ahorros_blue) -= PESOS;
        (*ahorros_mac) += PESOS;
    }
    else if ( huevos_puestos < HUEVOS){
        (*ahorros_mac) -= PESOS;
        (*ahorros_blue) += PESOS;
    }
    if (*ahorros_blue < PESOS){
        (*ahorros_mac) += (*ahorros_blue);
        (*ahorros_blue) = VACIO;
    }    
    else if ( *ahorros_mac < PESOS){
        (*ahorros_blue) += (*ahorros_mac);
        (*ahorros_mac) = VACIO;
    }    
}
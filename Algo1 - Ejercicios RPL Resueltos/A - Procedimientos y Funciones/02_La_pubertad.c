/*
ENUNCIADO DEL EJERCICIO:
-------------------------------------------------------------------------------------------------------------------------
El invierno es la peor época para los chicos del barrio, ya que junto con las gripes,
llega una enfermedad mucho más dañina, la pubertad, la cual se lleva cientos de soldados cada año. 
Para poder distinguir si un agente tiene gripe o se está volviendo un adulto, 
se hace una simple prueba: se le pide que diga el primer número que le viene a la mente. 
Como todo el mundo sabe, los chicos solo saben contar del 1 al 10 (inclusive), por lo que si su número 
cae por fuera de este rango, significa que le agarró la enfermedad de la pubertad.

Implementar la función tiene_pubertad la cual dado un número entero devuelva true si este está por fuera del rango 1-10 (tanto el 1 como el 10 cuentan como dentro del rango), o false en caso contrario.
Ejemplos:

Si se recibe 9, la función debe devolver false.
Si se recibe 15, la función debe devolver true.
-------------------------------------------------------------------------------------------------------------------------
*/

// RESOLUCION
#include <stdio.h>
#include <stdbool.h>

bool tiene_pubertad(int numero) {
    return numero<1 || numero> 10;
}
int main(){

    bool prueba1 = tiene_pubertad(9);
    bool prueba2 = tiene_pubertad(15);

    return 0;
}
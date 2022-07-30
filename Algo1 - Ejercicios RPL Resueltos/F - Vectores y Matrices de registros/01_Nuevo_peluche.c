/*	ENUNCIADO
-------------------------------------------------------------------------------------------------------------------------
Burbuja ama las cosas suavecitas, y como consecuencia, ama los peluches. Tanto que cada día que pasa su grupo de amigos 
inanimados crece más y más. 
Al ser tantos, el profesor Utonio pierde la cuenta, y esto es muy importante, para así cuando los limpie no se olvide 
ninguno en el lavarropas por accidente. 
Ya pasó una vez y no se quiere arriesgar nuevamente.

    Implementar un procedimiento que dado un vector de peluches, junto con su tope, y los datos de un nuevo peluche, 
    sume a este último al final del vector.

Notas:

    Los peluches están representados por un registro que contiene los siguientes datos:
        Nombre (string).
        Limpio (booleano).
    Los nuevos peluches siempre están limpios. Como consecuencia, no es necesario que te pasen este dato en la función, 
    deberías inicializarlo vos.
    Recordar que el nuevo peluche se agrega al final del vector.

Ejemplo:
Teniendo un vector con un elemento (tope = 1), y pasando el nombre “Wasabi”, al finalizar de ejecutar nuestra 
función el vector debe haber quedado 
con dos elementos (tope = 2) y en su última posición tener el peluche de nombre “Wasabi”, el cual se encuentra 
limpio (limpio = true). 
-------------------------------------------------------------------------------------------------------------------------

*/

//	RESOLUCION

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_PELUCHES 200
#define MAX_NOMBRE 144

typedef struct peluche {
    char nombre[MAX_NOMBRE];
    bool limpio;
} peluche_t;

void agregar_peluche(peluche_t peluches[MAX_PELUCHES], int* tope, char nombre[MAX_NOMBRE]){

   strcpy(peluches[*tope].nombre, nombre);
   peluches[*tope].limpio = true;
   (*tope)++;

}
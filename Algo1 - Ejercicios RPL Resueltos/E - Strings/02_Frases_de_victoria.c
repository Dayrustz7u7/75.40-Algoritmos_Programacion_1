/* 
ENUNCIADO DEL EJERCICIO:
-------------------------------------------------------------------------------------------------------------------------
Robin, de los Jóvenes Titanes, está haciendo una lista de todas las frases que se le ocurren para decirle a Slade cuando
lo derrote. Ya anotó varias y ahora las está repasando para ver cuáles son dignas del momento. Como regla, decidió que 
la frase sí o sí debería ser de menos de 19 letras porque tiene miedo de no terminar la frase antes de que se le escape 
Slade.

Implementar una función que dada una frase de Robin devuelva true si esta es digna, o false en caso contrario.
-------------------------------------------------------------------------------------------------------------------------
*/

// RESOLUCION 
#include <string.h>
#include <stdbool.h>
#define MAX_FRASE 50
#define FRASE_DIGNA 19

bool frase_digna(char frase[MAX_FRASE]) {
	if(strlen(frase)<FRASE_DIGNA){
		return true;
	}else{
		return false;
	}
}
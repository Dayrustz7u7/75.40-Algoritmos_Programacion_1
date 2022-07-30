/* 
ENUNCIADO DEL EJERCICIO:
-------------------------------------------------------------------------------------------------------------------------
Queso está persiguiendo a Blue por toda la Mansión Foster y repitiendo cada cosa que dice. Ya cansado de esto, 
lue decidió optar por otra estrategia, además de intentar esconderse en el baño. Su estrategia se basa en decir frases 
sin sentido alguno y esperar a que Queso se confunda y no pueda repetir más lo que dice.

Implementar una función que dado lo que dijo Blue y lo que dijo Queso devuelva true si su estrategia falló y Queso logró 
repetir la frase, o false en caso contrario.
-------------------------------------------------------------------------------------------------------------------------
*/

// RESOLUCION 
#include <string.h>
#include <stdbool.h>
#define MAX_FRASE 40
#define IGUAL 0


bool frase_repetida(char frase_blue[MAX_FRASE], char frase_queso[MAX_FRASE]) {
	if(strcmp(frase_blue,frase_queso) == IGUAL){
		return true;
	}
	else{
		return false;
	}
}
/* 
ENUNCIADO DEL EJERCICIO:
-------------------------------------------------------------------------------------------------------------------------
Se sumó un nuevo amigo imaginario a la Mansión Foster, Kiki, y con él un nuevo idioma. Kiki, en lo único que sabe 
hablar es en kikiano, y como Blue quiere acercarse a él para formar una amistad, decide aprender a hablarlo. Luego de 
un par de observaciones, obtuvo la siguiente información:

No se recibirán mayúsculas ni letras con tilde.

En cada vocal, se agrega un sufijo dependiendo de qué vocal sea.

Si la vocal es a: se agrega ka.
Si la vocal es e: se agrega ke.
Si la vocal es i: se agrega ki.
Si la vocal es o: se agrega ko.
Si la vocal es u: se agrega ku.
Implementar un procedimiento que a partir de una frase dicha por Blue, la traduzca al kikiano.

Ejemplo:

Si la frase dicha por Blue es "alejate de mi, queso”, esta quedará “akalekejakateke deke miki, qukuekesoko”.
-------------------------------------------------------------------------------------------------------------------------
*/

// RESOLUCION 
#include <string.h>
#define MAX_FRASE 50
#define VOCAL_A 'a'
#define VOCAL_E 'e'
#define VOCAL_I 'i'
#define VOCAL_O 'o'
#define VOCAL_U 'u'
#define CONSONANTE 'k'

void traducir_frase(char frase_blue[MAX_FRASE]) {
	char kikiano[MAX_FRASE*2];
	int j = 0;
	int len = (int)strlen(frase_blue);
	for(int i=0; i<= len;i++){
		if(frase_blue[i]== VOCAL_A|| frase_blue[i]== VOCAL_E || frase_blue[i]== VOCAL_I || frase_blue[i]== VOCAL_O || frase_blue[i]== VOCAL_U){
			kikiano[j] = frase_blue[i];
			j++;
			kikiano[j] = CONSONANTE;
			j++;
			kikiano[j] = frase_blue[i];
			j++;
		}
		else{
			kikiano[j] = frase_blue[i];
			j++;
		}
	}
	strcpy(frase_blue,kikiano);
}
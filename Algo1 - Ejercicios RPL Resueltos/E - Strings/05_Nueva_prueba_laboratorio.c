/* 
ENUNCIADO DEL EJERCICIO:
-------------------------------------------------------------------------------------------------------------------------
Dee Dee tenía planeado entrar al laboratorio de su hermano, pero se dió cuenta que hay una nueva prueba antes de 
poder pasar. Esta prueba consiste en escuchar un código, descifrar qué es lo que dice, y dar una respuesta correcta. 
Dee dee, inmediatamente notó que el código es una frase que está dicha de derecha a izquierda, pero le cuesta mucho darla
vuelta para poder identificar qué es lo que dice.

Implementar un procedimiento que invierta la frase escuchada para ayudar a Dee Dee.
Ejemplo:

Si se escucha la frase “odavirp oirotarobaL”, debe quedar “Laboratorio privado”
-------------------------------------------------------------------------------------------------------------------------
*/

// RESOLUCION 
#include <string.h>
#define MAX_FRASE 40

void intercambiar_frase(char frase[MAX_FRASE]) {
	char aux;
	int len = (int)strlen(frase);
	for(int i = 0;i<len;i++){
		aux=frase[i];
		frase[i]=frase[len-1];
		frase[len-1] = aux;
		len--;
	}
}
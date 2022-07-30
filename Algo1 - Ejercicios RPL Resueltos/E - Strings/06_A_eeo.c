/* 
ENUNCIADO DEL EJERCICIO:
-------------------------------------------------------------------------------------------------------------------------
Las chicas superpoderosas estaban planeando su último ataque hacia Mojojojo, hasta que se dieron cuenta que el teléfono 
por donde se comunica el alcalde, estaba pinchado, por lo que todos sus enemigos estaban escuchando su plan.
Para evitar que tengan más información, decidieron comenzar a hablar sólo con las vocales. De esta forma, el plan sería 
secreto y sólo ellas podrían entenderlo.
Se sabe que el plan recibido no contendrá mayúsculas.

Implementar un procedimiento que, dado un plan, elimine todas las consonantes existentes en él.
Ejemplo:

Si el plan es “entrar de incognito”, debe quedar “ea e ioio”
-------------------------------------------------------------------------------------------------------------------------
*/

// RESOLUCION 
#include <string.h>
#define MAX_PLAN 50
#define VOCAL_A 'a'
#define VOCAL_E 'e'
#define VOCAL_I 'i'
#define VOCAL_O 'o'
#define VOCAL_U 'u'


void cifrar_plan(char plan[MAX_PLAN]) {
	int len= (int)strlen(plan);
	int j = 0;
    char nuevo[len];
	int tope_nuevo = 0;
	for (int i =0;i<len;i++){
		if(plan[i]==VOCAL_A ||plan[i]== VOCAL_E || plan[i] == VOCAL_I ||plan[i] == VOCAL_O ||plan[i] == VOCAL_U ||plan[i]==' '){
			nuevo[j]= plan[i];
			j++;
			tope_nuevo++;
		}
	}
    strcpy(plan,nuevo);
	plan[tope_nuevo]= '\0';
}
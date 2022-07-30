/* 
ENUNCIADO DEL EJERCICIO:
-------------------------------------------------------------------------------------------------------------------------
Burbuja llegó a tener una gran familia de peluches, tiene 53 en total, y decidió que todos tengan nombres que terminen en 
“lindi”.

Implementar un procedimiento que dado el nombre de un peluche le agregue “lindi” al final. Considerar que el nombre va 
a tener suficiente espacio para el agregado.
Ejemplo:

Si nos viene de nombre "nao", el resultado de llamar a nuestro procedimiento va a ser "naolindi".
-------------------------------------------------------------------------------------------------------------------------
*/

// RESOLUCION 
#include <string.h>
#define MAX_NOMBRE 30
#define nombre "lindi"

void nombrar_peluche(char peluche[MAX_NOMBRE]) {
	strcat(peluche,nombre);
}
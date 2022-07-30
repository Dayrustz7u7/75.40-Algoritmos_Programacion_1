/* 
ENUNCIADO DEL EJERCICIO:
-------------------------------------------------------------------------------------------------------------------------
Los enemigos de Cartoon Network, siguiendo con su idea de derrotar a los enemigos, decidieron que iba a ser más práctico 
si se ordenaban según sus habilidades. Para esto, necesitan de alguna forma tener un registro de cada uno con sus 
respectivas características.

Implementar un registro donde se puedan guardar los siguientes datos de los enemigos:
Nombre. (máx 50 caracteres)

Edad.

Fuerza Que puede ser F, M o D ((F)uerte, (M)edia, (D)ebil).

Si tiene_poderes o no.

Información_adicional importante, en forma de texto que almacene hasta 50 caracteres.

Aclaración:

Respetá el orden dado
No utilices tíldes ni mayusculas
-------------------------------------------------------------------------------------------------------------------------
*/

// RESOLUCION 
#include <stdbool.h>
#include <stdio.h>
typedef struct enemigo{
	char nombre[50];
	int edad;
	char fuerza;
	bool tiene_poderes;
	char informacion_adicional[50];
} enemigo_t;
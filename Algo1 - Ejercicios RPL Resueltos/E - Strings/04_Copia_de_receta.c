/* 
ENUNCIADO DEL EJERCICIO:
-------------------------------------------------------------------------------------------------------------------------
Tom y Jerry se inscribieron a un curso de cocina en el que en la etapa final cada uno tiene que cocinar lo que quiera,
siempre y cuando se luzcan y demuestren todo lo que fueron aprendiendo a lo largo del curso. Pero como Tom es muy 
distraído, no anotó ninguna receta, por lo que no se le ocurre qué puede cocinar. Su única salvación, es copiar la receta 
que tiene Jerry en la mesa de al lado.

Implementar un procedimiento que copie la receta de Jerry en el recetario de Tom.
-------------------------------------------------------------------------------------------------------------------------
*/

// RESOLUCION 
#include <string.h>
#define MAX_RECETA 250

void copiar_receta(char receta_jerry[MAX_RECETA], char recetario_tom[MAX_RECETA]) {
	strcpy(recetario_tom,receta_jerry);
}
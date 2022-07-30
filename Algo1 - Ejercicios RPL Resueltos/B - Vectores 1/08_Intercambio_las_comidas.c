/* 
ENUNCIADO DEL EJERCICIO:
-------------------------------------------------------------------------------------------------------------------------
Scooby se dió cuenta que Velma tiene anotado en un vector la cantidad de comida que le da por día en toda la semana, 
y quiere alterar un poco los números, ya que se dio cuenta que los días que más hambre tiene, son los días que menos 
recibe.

Implementar un procedimiento que cree un nuevo vector para reemplazar el anterior, intercambiando la cantidad de comida 
que recibe los lunes, por los viernes, y la cantidad de comida que recibe los domingos, por los miércoles.
Tener en cuenta:

Las posiciones del vector representan los días de semana comenzando por el domingo en la posición 0.
Ambos vectores tienen de tope el MAX_DIAS siempre. Es decir, siempre vienen con 7 elementos, ni más ni menos.
Ejemplo:

Teniendo el vector de comidas originales [1, 4, 6, 2, 5, 1, 7] el vector de comidas intercambiadas 
debe quedar [2, 1, 6, 1, 5, 4, 7].
-------------------------------------------------------------------------------------------------------------------------
*/

// RESOLUCION 
#include <stdio.h>
#define MAX_DIAS  7

void intercambiar_comidas(int comidas_original[MAX_DIAS], int comidas_intercambiadas[MAX_DIAS]){
    int aux_1 = comidas_original[1];
    comidas_intercambiadas[1] = comidas_original[5];
    comidas_intercambiadas[5] = aux_1;
    int aux_2 = comidas_original[0];
    comidas_intercambiadas[0] = comidas_original[3];
    comidas_intercambiadas[3] = aux_2;

}
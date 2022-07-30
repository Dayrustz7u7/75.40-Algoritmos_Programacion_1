/*	ENUNCIADO
-------------------------------------------------------------------------------------------------------------------------
El guardarropas de Mandy ya se está volviendo un desastre, no le entra nada más de las cosas que toma de Puro Hueso. Como no soporta esto, 
obliga a Billy y Puro Hueso a ordenar su guardarropas. El tema es que a ambos le da mucho miedo, con solo mirarlo ya se ponen nerviosos. 
Pero no saben si es peor el peligro que corren al ordenar el guardarropas o al desobedecer a Mandy.

    Crear una función que dada una matriz que representa el guardarropas de Mandy (cada posición es un cajón), sus respectivos topes y 
    el nivel de miedo que le tienen a Mandy, devuelva true si pueden ordenarlo (esto es, si el miedo que le tienen a este es menor o 
    igual al miedo que le tienen a Mandy) o false en caso contrario.

Notas:

    La matriz que representa al guardarropas puede NO ser cuadrada.
    Cada cajon tiene los siguientes datos:
        Cantidad de objetos que guarda (entero).
        Cantidad de miedo por objeto guardado (entero).
    Para calcular el miedo total del guardarropas se deben sumar los miedos dados por cada cajón. Estos últimos se calculan como 
    cantidad_objetos * miedo_por_objeto.
    Si el guardarropas está vacío entonces se toma como que pueden ordenarlo.
-------------------------------------------------------------------------------------------------------------------------
*/
//	RESOLUCION

#include <stdio.h>
#include <stdbool.h>
#define MAX_FILAS 50
#define MAX_COLUMNAS 50

typedef struct cajon {
    int cantidad_objetos;
    int miedo_por_objeto;
} cajon_t;

bool pueden_ordenar_guardarropas(cajon_t guardarropas[MAX_FILAS][MAX_COLUMNAS], int tope_filas, int tope_columnas, int miedo_a_mandy){
    int miedo_guardaropas = 0;

    for(int i=0; i<tope_filas;i++){
        for(int j =0; j< tope_columnas; j++){
            miedo_guardaropas += guardarropas[i][j].cantidad_objetos * guardarropas[i][j].miedo_por_objeto;
        }
    }

    if(miedo_guardaropas <= miedo_a_mandy){
        return true;
    }
    return false;
}
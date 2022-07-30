/* 
ENUNCIADO DEL EJERCICIO:
-------------------------------------------------------------------------------------------------------------------------
Los tres queridos osos atraviesan varios cambios de humor a lo largo de un año según la estación. 
Por lo que los expertos en osos nos dijeron (osea, lo que nos dijo Chloe) que por cada estación del año, cada oso pasa 
por un humor diferente.
Los humores por lo que pueden pasar son los siguientes:

Contento (C)
Meh (M)
Triste (T)
Y estos son lo cambios que logramos anotar:

-Primavera (P): Panda y Pardo están contentos, mientras que Polar está meh.
-Verano (V): Polar está triste, Panda está meh y Pardo está contento.
-Otoño (O): los tres osos están contentos (obvio, si es la mejor estación).
-Invierno (I): Polar está contento, Panda está meh y Pardo está triste.

Implementar una función que dada la estación del año, modifique el humor de cada oso al correspondiente, y 
devuelva la cantidad de osos que están contentos.
-------------------------------------------------------------------------------------------------------------------------
*/

// RESOLUCION 
#include <stdio.h>
#define CONTENTO 'C'
#define MEH 'M'
#define TRISTE 'T'
#define PRIMAVERA 'P'
#define VERANO 'V'
#define OTONIO 'O'
#define INVIERNO 'I'

int definir_humor_osos(char* humor_panda, char* humor_pardo, char* humor_polar, char estacion){
    int cantidad_osos_contentos = 0;
    if ( estacion == PRIMAVERA ){
        (*humor_panda) = CONTENTO;
        (*humor_pardo) = CONTENTO;
        (*humor_polar) = MEH;
        cantidad_osos_contentos = 2;    
    }
    else if ( estacion == VERANO){
        (*humor_panda) = MEH;
        (*humor_pardo) = CONTENTO;
        (*humor_polar) = TRISTE;
        cantidad_osos_contentos = 1;
    }
    else if ( estacion == OTONIO){
        (*humor_panda) = CONTENTO;
        (*humor_pardo) = CONTENTO;
        (*humor_polar) = CONTENTO;
        cantidad_osos_contentos = 3;
    }
    else if ( estacion == INVIERNO){
        (*humor_panda) = MEH;
        (*humor_pardo) = TRISTE;
        (*humor_polar) = CONTENTO;
        cantidad_osos_contentos = 1;
    }
    return cantidad_osos_contentos;
}

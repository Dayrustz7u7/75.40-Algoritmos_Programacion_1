/* 
ENUNCIADO DEL EJERCICIO:
-------------------------------------------------------------------------------------------------------------------------
Shaggy está jugando con Scooby al típico juego de los magos de esconder una pelota debajo de un vaso y mezclarlo junto 
con otros vasos. Solo que su versión del juego es mucho más rica, ya que esconden una hamburguesa en vez de una pelota 
y usan cajas en vez de vasos (porque las hamburguesas no entran en los vasos).
Si el que elige encuentra la hamburguesa se la puede comer, sino, se la queda el que la mezcló.
Después de un par de rondas están un poco demasiado llenos como para mezclar, así que te pidieron implementar un 
algoritmo que la realice.

Implementar un procedimiento que dadas tres cajas realice la mezcla. La caja que tenga la hamburguesa será representada
por una H y las que están vacías con una V. El algoritmo para mezclar sigue las siguientes reglas:

Si la hamburguesa estaba en la primera caja, esta pasa a estar en la tercera.
Si la hamburguesa estaba en la segunda caja esta pasa a estar en la primera.
Y si la hamburguesa estaba en la tercera caja, esta pasa a estar en la segunda.

Ejemplo:

Si se recibe VHV, debe cambiarse a HVV.
Si se recibe VVH, debe cambiarse a VHV.
-------------------------------------------------------------------------------------------------------------------------
*/

// RESOLUCION
#include <stdio.h>
#define CAJA_CON_HAMBURGUESA 'H'
#define CAJA_VACIA 'V'

void mezclar_cajas(char* primer_caja, char* segunda_caja, char* tercera_caja) {
    if (CAJA_CON_HAMBURGUESA == (*primer_caja)) {
        (*tercera_caja) = CAJA_CON_HAMBURGUESA;
        (*segunda_caja) = CAJA_VACIA;
        (*primer_caja) = CAJA_VACIA;
    }
    else if (CAJA_CON_HAMBURGUESA == (*segunda_caja)){
        (*primer_caja) = CAJA_CON_HAMBURGUESA;
        (*segunda_caja) = CAJA_VACIA;
        (*tercera_caja) = CAJA_VACIA;
    }    
    else if (CAJA_CON_HAMBURGUESA == (*tercera_caja)){
        (*segunda_caja) = CAJA_CON_HAMBURGUESA;
        (*primer_caja) = CAJA_VACIA;
        (*tercera_caja) = CAJA_VACIA;        
    }    
    
}
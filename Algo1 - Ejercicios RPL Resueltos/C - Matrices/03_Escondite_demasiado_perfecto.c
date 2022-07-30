/* 
ENUNCIADO DEL EJERCICIO:
-------------------------------------------------------------------------------------------------------------------------
Coraje había escondido todos sus huesos, uno en cada árbol, para no comérselos todos de una. Este plan no le salió 
muy bien porque ni bien los escondió, fue a sacar y comérselos todos. El problema es que perdió la cuenta y no sabe si 
le quedan huesos, o si ya se los terminó.

Implementar una función que dada una matriz que representa al parque, donde cada posición de ésta es un árbol 
representado por una A, busque si hay algún hueso faltante representado por una H. La función debe devolver true si se 
encontró al menos un hueso o false en caso contrario.

Tener en cuenta:
La matriz está llena (topes iguales a sus máximos).
-------------------------------------------------------------------------------------------------------------------------
*/

// RESOLUCION
#include <stdbool.h>
#define MAX_FILAS 5
#define MAX_COLUMNAS 5
#define ARBOL 'A'
#define HUESO 'H'

bool quedan_huesos(char parque[MAX_FILAS][MAX_COLUMNAS]) {
    bool encontro = false;
    for(int i=0;i<MAX_FILAS;i++){
        for(int j=0;j<MAX_COLUMNAS;j++){
            if(parque[i][j]== HUESO){
                encontro = true;    
            }
        }
    }
    return encontro;
} 
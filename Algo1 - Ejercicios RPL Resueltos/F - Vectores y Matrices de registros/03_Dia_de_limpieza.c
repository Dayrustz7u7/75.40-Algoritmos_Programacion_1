/*	ENUNCIADO
-------------------------------------------------------------------------------------------------------------------------
Ha llegado ese día, el día más temido por el profesor Utonio… El día de limpieza. Este día, toca la responsabilidad de limpiar los peluches de Burbuja, 
y debe ser muy cuidadoso. Si lava un peluche que ya está limpio se arriesga a que este se arruine, y que Burbuja se enoje mucho mucho. Además, 
debe asegurarse de contar bien la cantidad de peluches que lavó y sacó del lavarropas, para no arriesgarse a olvidarse alguno en el solitario lavarropas, 
y que Burbuja se enoje mucho mucho :(

    Implementar una función que dado un vector de peluches, junto con su tope, limpie los peluches que lo necesiten (esto es modificar el booleano limpio) 
    y devuelva la cantidad de peluches que se limpiaron.

Notas:

    Los peluches están representados por un registro que contiene los siguientes datos:
        Nombre (string).
        Limpio (booleano).

-------------------------------------------------------------------------------------------------------------------------

*/

//	RESOLUCION
#include <stdio.h>
#include <stdbool.h>
#define MAX_PELUCHES 200
#define MAX_NOMBRE 144

typedef struct peluche {
    char nombre[MAX_NOMBRE];
    bool limpio;
} peluche_t;

int limpiar_peluches(peluche_t peluches[MAX_PELUCHES], int tope){
    int peluches_limpios =0;
    for(int i=0;i < tope ;i++){
        if(!peluches[i].limpio){
            peluches_limpios++;
            peluches[i].limpio =true;
        }
    }
    return peluches_limpios;
}
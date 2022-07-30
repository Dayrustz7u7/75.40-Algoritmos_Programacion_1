/*	ENUNCIADO
-------------------------------------------------------------------------------------------------------------------------
Las Crueles son tres hermanas que viven en un parque de casas rodantes y son muy temidas en el callejón por los niños debido a su personalidad cruel. 
Todas están enamoradas de un Ed y semanalmente le dedican cartas de amor que nunca envían.

    Dado un vector de registros correspondientes a cartas de amor, determinar cuál es la arrugada que tiene mayor cantidad de palabras románticas y 
    devolver su ID.

En caso de empate, devolver la primera encontrada (la mas cercana al indice 0).
-------------------------------------------------------------------------------------------------------------------------
*/

//	RESOLUCION

#include <stdio.h>
#include <stdbool.h>
#define MAX_CARTAS 50
//Aca deberian ir las constantes.

typedef struct carta{
	int id;
	int cantidad_palabras_de_amor;
	bool esta_arrugada;
}carta_t;

int id_carta_mas_palabras_de_amor(carta_t cartas[MAX_CARTAS], int tope){
	carta_t carta;
	carta.cantidad_palabras_de_amor = 0;
	for(int i=0; i<tope; i++){
		if(cartas[i].esta_arrugada && cartas[i].cantidad_palabras_de_amor > carta.cantidad_palabras_de_amor){
			carta = cartas[i];
		}
	}
	return carta.id;
}
/*	ENUNCIADO
-------------------------------------------------------------------------------------------------------------------------
Habiendo desarrollado la función para determinar la distancia entre puntos, los chicos del barrio están cada vez más cerca de derrotar a Barba Pegajosa.

Ahora necesitarán una función que determine, dado un vector de puntos, cuál es el más cercano al punto central. En caso de haber un empate, devolver 
el punto más débil(menor fortaleza) entre los empatados. Tienes a tu disposición la función distancia_entre_puntos(primero, segundo)

Aclaración: El vector de puntos siempre va a tener al menos 1 elemento.
-------------------------------------------------------------------------------------------------------------------------
*/

//	RESOLUCION

#include <stdio.h>
#include "funcion.h"//aqui esta la funcion distancia_entre_puntos
#define MAX_PUNTOS 20
//Aca deberian ir las constantes.

typedef struct punto{
	int x;
	int y;
	int fortaleza;
}punto_t;

punto_t punto_mas_cercano(punto_t centro, punto_t puntos[MAX_PUNTOS], int tope){
    punto_t punto_cercano = puntos[0];
	int distancia_entre_punto = distancia_entre_puntos(puntos[0],centro);
	for(int i=0; i< tope; i++){
		if(distancia_entre_puntos(centro, puntos[i])< distancia_entre_punto){
            punto_cercano= puntos[i];
			distancia_entre_punto = distancia_entre_puntos(centro, puntos[i]);
		}else if(distancia_entre_puntos(centro, puntos[i]) == distancia_entre_punto ){
			if(puntos[i].fortaleza < punto_cercano.fortaleza){
				punto_cercano = puntos[i];
			}
		}
	}
	return punto_cercano;
}
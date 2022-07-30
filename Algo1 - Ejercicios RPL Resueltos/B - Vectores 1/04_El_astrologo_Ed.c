/* 
ENUNCIADO DEL EJERCICIO:
-------------------------------------------------------------------------------------------------------------------------
Ed se volvió fanático de la astrología, por lo que empezó a leer libros y buscar información de cada signo. Para probar
sus conocimientos, quiso hacerles unas preguntas a Edd y Eddy y tratar de adivinar de qué signo son. Para facilitarse 
el trabajo, les hizo las preguntas a los dos al mismo tiempo y en cada posición de un vector fue marcando S si ambos 
respondieron que sí, N si ambos respondieron que no, E si sólo Edd respondió que sí, y D Si sólo Eddy respondió que sí.

Tiene como información adicional que los signos de ambos solamente pueden ser piscis, libra, acuario o cáncer.

Implementar una función que calcule cuántas respuestas positivas tuvieron tanto Edd como Eddy, y a partir de este 
resultado, retorne true si son del mismo signo, o false en caso contrario.
-Entre 0 y 2: Libra (L).
-Entre 3 y 5: Piscis(P).
-Entre 6 y 8: Acuario(A).
-Más de 8: Cáncer(C).
-------------------------------------------------------------------------------------------------------------------------
*/

// RESOLUCION 
#include <stdio.h>
#include <stdbool.h>
#define MAX_RESPUESTAS 300
#define EDD_EDDY_POSITIVO 'S'
#define EDD_EDDY_NEGATIVO 'N'
#define EDD_POSITIVO 'E'
#define EDDY_POSITIVO 'D'

bool tienen_mismo_signo(char respuestas[MAX_RESPUESTAS], int tope_respuestas) {
	int contador_positivo_EDD = 0;
	int contador_positivo_EDDY = 0;
	bool son_iguales;
	for(int i = 0; i<tope_respuestas; i++){
		if (respuestas[i] == EDD_EDDY_POSITIVO){
			contador_positivo_EDD++;
			contador_positivo_EDDY++;
		}
		else if (respuestas[i]== EDD_POSITIVO){
			contador_positivo_EDD++;
		}
		else if (respuestas[i]== EDDY_POSITIVO){
			contador_positivo_EDDY++;
		}
	}
	if (contador_positivo_EDD == contador_positivo_EDDY){
		son_iguales = true;
	}
	else{
		son_iguales = false;
	}
	return son_iguales;

}
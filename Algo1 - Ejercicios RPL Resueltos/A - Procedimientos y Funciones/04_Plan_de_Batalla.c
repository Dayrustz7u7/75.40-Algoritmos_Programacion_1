/* 
ENUNCIADO DEL EJERCICIO:
-------------------------------------------------------------------------------------------------------------------------
Luego de varias batallas perdidas, Mojo Jojo ideó un nuevo plan para atacar a las chicas super poderosas, 
el cual se basa en atacarlas los días en donde están más cansadas, para así aumentar sus oportunidades de ganar. 
Él sabe que están cansadas siempre los días lunes, miércoles y domingo. Además Mojo Jojo tiene que estar bien descansado 
para poder atacar, y para eso tiene que haber dormído un mínimo de 9 horas (inclusive).
Para este ejercicio, se pide implementar tanto la función estan_cansadas como la función puede_atacar:

Implementar la función estan_cansadas, que según un caracter devuelva true si ese día están cansadas o false en caso 
contrario.
Los días están representados con los siguientes caracteres:
-Lunes (L).
-Martes (M).
-Miércoles (X).
-Jueves (J).
-Viernes (V).
-Sábado (S).
-Domingo (D).

Implementar la función puede_atacar, el cual recibe un caracter que representa el día de la semana y las horas dormidas 
por Mojo Jojo, y devuelva true si pueden atacar o false en caso contrario.
-------------------------------------------------------------------------------------------------------------------------
*/

// RESOLUCION 
#include <stdio.h>
#include <stdbool.h>
#define  LUNES 'L'
#define MIERCOLES 'X'
#define DOMINGO 'D'
#define HORAS 9
bool estan_cansadas(char dia) {
	return (dia == LUNES) || (dia ==  MIERCOLES) || (dia == DOMINGO);
}

bool puede_atacar(char dia, int horas_que_durmio) {
	
	return (estan_cansadas(dia)) && (horas_que_durmio >= HORAS); 
 
}
/*	ENUNCIADO
-------------------------------------------------------------------------------------------------------------------------
Los chicos del barrio están organizando una reunión secreta (aka: una festichola) para celebrar la derrota de Catarro Común. Para esto necesitan 
tener varios snacks, así la gente tiene para elegir y comer hasta el cansancio. De alguna manera se olvidaron que tenían varios dulces y snacks 
escondidos en un baúl, así que parte de ellos están bien lejos de su fecha de vencimiento, y ni hablar de los que necesitaban refrigeración. 
Número uno dijo que deberían contar la cantidad de alimentos echados a perder, para saber cuánta pérdida sufrieron al esconder las cosas en ese baúl.

    Implementar una función que dado un vector de alimentos, junto con su tope, cuente aquellos que se hayan echado a perder y devuelva la 
    cantidad total de estos.

Notas:

    Los alimentos están representados por un registro el cual contiene la siguiente información:
        Nombre (string).
        Venció (booleano).
        Puntos mal olor (int).
    Se considera que un alimento está echado a perder si venció y tiene más (estricto) de 3 puntos en mal olor.
-------------------------------------------------------------------------------------------------------------------------
    */

//	 RESOLUCION

#include <stdio.h>
#include <stdbool.h>
#define MAX_ALIMENTOS 400
#define MAX_NOMBRE 144
int mal_olor =3;

typedef struct alimento {
    char nombre[MAX_NOMBRE];
    bool vencio;
    int puntos_mal_olor;
} alimento_t;

bool alimentos_daniado(bool vencio,int puntos_mal_olor){
    return (vencio==true && puntos_mal_olor > mal_olor);
}

int cantidad_alimentos_echados_a_perder(alimento_t alimentos[MAX_ALIMENTOS], int tope){
   int alimentos_daniados=0;
   for(int i=0; i<tope;i++){
       if(alimentos_daniado(alimentos[i].vencio,alimentos[i].puntos_mal_olor)){
           alimentos_daniados++;
       }
   }
   return alimentos_daniados;
}

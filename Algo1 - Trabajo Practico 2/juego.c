#include "la_sombra_de_mac.h"
#include "utiles.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
#define ESTA_JUGANDO 0
#define ESTA_PERDIDO -1
#define ESTA_GANADO 1
int main (){
    
    srand (( unsigned)time(NULL)); 


    juego_t juego;
    inicializar_juego(&juego);
    int partida = estado_juego(juego);
    while(partida == ESTA_JUGANDO ){
        imprimir_terreno(juego);
        realizar_jugada(&juego);
        partida = estado_juego(juego);
    }  
    printf("SE TERMINO EL JUEGO\n");

    return 0;
}






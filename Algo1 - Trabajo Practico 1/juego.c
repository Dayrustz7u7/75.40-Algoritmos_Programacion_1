#include "la_sombra_de_mac_primero.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
// Para obtener una semilla desde el reloj
int main (){
    
    srand (( unsigned)time(NULL)); // Genera la semilla aleatoria.
//---------------------------------------------------------------------------------------------------------------------    
    coordenada_t primera_coord;
    primera_coord.fila = 2;
    primera_coord.col = 3;
    coordenada_t segunda_coord;
    segunda_coord.fila = 2;
    segunda_coord.col = 3;

    if (coordenadas_iguales(primera_coord,segunda_coord)){
        printf("Son iguales \n");
    }else {
        printf("No son iguales\n");
    }

//---------------------------------------------------------------------------------------------------------------------    
    coordenada_t coord_aleatorio = coordenada_aleatoria(MAX_FILAS,MAX_COLUMNAS);
    printf("Se genero una coordenada aleatoria: (%i , %i) \n", coord_aleatorio.fila,coord_aleatorio.col);

//---------------------------------------------------------------------------------------------------------------------    
    personaje_t mac;
    inicializar_personaje(&mac,coord_aleatorio);
    printf("La vida de Mac es: %i\n",mac.vida);
    printf("La posicion inicial de Mac es: (%i,%i)\n",mac.posicion.fila,mac.posicion.col);
    printf("Mac comienza con puntos:  %i\n",mac.puntos);
    if (mac.tiene_llave){
        printf("Consiguio la llave!!\n");
    } else {
        printf("Todavia no encontro la llave :c\n");
    }
    
//---------------------------------------------------------------------------------------------------------------------    
    sombra_t bloo;
    inicializar_sombra(&bloo,coord_aleatorio);
    bloo.posicion.col = MAX_COLUMNAS - mac.posicion.col - 1;
    printf("La posicion de Bloo es: (%i,%i)\n",bloo.posicion.fila,bloo.posicion.col);
    if (bloo.esta_viva){
        printf("Comienza Vivo!!\n");
    }
    
//---------------------------------------------------------------------------------------------------------------------    
    juego_t juego;
    juego.personaje = mac;
    juego.sombra =bloo;

//---------------------------------------------------------------------------------------------------------------------    
    coordenada_t fuera_de_rango;
    fuera_de_rango.fila = 0;
    fuera_de_rango.col = 19;

    if(esta_dentro_rango(fuera_de_rango,MAX_FILAS,MAX_COLUMNAS)){
        printf("Esta dentro del rango! \n");
    }else{
        printf("Coordenada invalida. \n");
    }
    
//----------------------------------------------------------------------------------------------------------------------
    elemento_t elementos[MAX_ELEMENTOS];
    int tope_elementos = 0;
    elementos[0].posicion = coordenada_aleatoria(MAX_FILAS,MAX_COLUMNAS);
    tope_elementos++;
    elementos[1].posicion = coordenada_aleatoria(MAX_FILAS,MAX_COLUMNAS);
    tope_elementos++;
    elementos[2].posicion = coordenada_aleatoria(MAX_FILAS,MAX_COLUMNAS);
    tope_elementos++;
    elementos[3].posicion = coordenada_aleatoria(MAX_FILAS,MAX_COLUMNAS);
    tope_elementos++;
    elementos[4].posicion.fila = 0;
    elementos[4].posicion.col = 19;
    tope_elementos++;
    int posicion_elemento = buscar_elemento( elementos, tope_elementos, fuera_de_rango);
    printf ("La posicion donde se encuentra la coordenada igual es: [%i]\n",posicion_elemento);
    
//---------------------------------------------------------------------------------------------------------------------    
  
    while (esta_dentro_rango(bloo.posicion,MAX_FILAS,MAX_COLUMNAS) == true){
        char movimiento;
        printf("Mueve el personaje con W,A,S,D: ");
        scanf(" %c",&movimiento);
        pedir_movimiento(&movimiento);
        mover_personaje(&juego.personaje,&juego.sombra,movimiento);
        imprimir_terreno(juego);
        printf("La posicion ahora de Mac es: (%i,%i)\n",juego.personaje.posicion.fila,juego.personaje.posicion.col);
        printf("La posicion ahora de Bloo es: (%i,%i)\n",juego.sombra.posicion.fila,juego.sombra.posicion.col);
    }

    return 0;
}




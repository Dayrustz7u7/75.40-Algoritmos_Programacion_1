#include "la_sombra_de_mac_primero.h"
#include <stdio.h>
#include <stdlib.h> // Para usar rand
const char MOV_ARRIBA = 'W';
const char MOV_ABAJO = 'S';
const char MOV_IZQUIERDA = 'A';
const char MOV_DERECHA = 'D';
const int VIDA_MAC = 3;
const int PUNTOS_MAC = 0;
const char MAC = 'M';
const char BLOO = 'B'; 

bool coordenadas_iguales(coordenada_t a, coordenada_t b){
    return a.fila == b.fila && a.col == b.col;
}

coordenada_t coordenada_aleatoria(int max_alto, int max_ancho){
    
    coordenada_t aleatorio;
    aleatorio.fila = rand () % max_alto;
    aleatorio.col = rand () % max_ancho;

    return aleatorio;

}

void inicializar_personaje(personaje_t* ref_personaje, coordenada_t arranque_personaje){
    (*ref_personaje).vida = VIDA_MAC;
    (*ref_personaje).puntos = PUNTOS_MAC;
    (*ref_personaje).interruptor_apretado = false;
    (*ref_personaje).tiene_llave = false;
    (*ref_personaje).posicion.col = arranque_personaje.col;
    (*ref_personaje).posicion.fila = arranque_personaje.fila;
}

void inicializar_sombra(sombra_t* ref_sombra, coordenada_t arranque_sombra){
    (*ref_sombra).posicion.fila = arranque_sombra.fila;
    (*ref_sombra).posicion.col = arranque_sombra.col;
    (*ref_sombra).esta_viva = true ;
   
}

bool es_movimiento_valido(char movimiento){
    return movimiento == MOV_ARRIBA || movimiento == MOV_ABAJO || movimiento == MOV_IZQUIERDA || movimiento == MOV_DERECHA;

}

void pedir_movimiento(char* ref_movimiento){
    char auxiliar_1 = (*ref_movimiento);
    bool auxiliar_2 = es_movimiento_valido(auxiliar_1);
    while (auxiliar_2 != true){
        printf("Por favor, ingrese un movimiento valido: ");
        scanf(" %c",ref_movimiento);
        auxiliar_1 = (*ref_movimiento);
        auxiliar_2 = es_movimiento_valido(auxiliar_1);
    }
}

bool esta_dentro_rango(coordenada_t posicion, int max_alto, int max_ancho){
    return posicion.fila < max_alto && posicion.fila >= 0 && posicion.col < max_ancho && posicion.col >= 0;
}
/*
  PRE:Recibe una coordena_t si o si de "MAC" y un movimiento valido si solo si es "W,S,A,D".
  POST: Resta o Suma la coordenada recibida por parametro si solo si cumple el if.
*/
void evaluar_coord_mac(coordenada_t* ref_personaje,char movimiento){    
    if (esta_dentro_rango((*ref_personaje),MAX_FILAS,MAX_COLUMNAS)!=true && movimiento == MOV_ARRIBA){
        (*ref_personaje).fila++;
    }
    else if (esta_dentro_rango((*ref_personaje),MAX_FILAS,MAX_COLUMNAS)!=true && movimiento == MOV_ABAJO){
        (*ref_personaje).fila--;
    }
    else if ((esta_dentro_rango((*ref_personaje),MAX_FILAS,MAX_COLUMNAS)!=true && movimiento == MOV_IZQUIERDA)){
        (*ref_personaje).col++;
    }
    else if ((esta_dentro_rango((*ref_personaje),MAX_FILAS,MAX_COLUMNAS)!=true && movimiento == MOV_DERECHA)){
        (*ref_personaje).col--;
    }   
}
/*
  PRE:Recibe una coordena_t si o si de "BLOO" y un movimiento valido si solo si es "W,S,A,D".
  POST: Resta o Suma la coordenada recibida por parametro si solo si cumple el if.
*/
void evaluar_coord_sombra(coordenada_t* ref_sombra,char movimiento){    
    if (esta_dentro_rango((*ref_sombra),MAX_FILAS,MAX_COLUMNAS)!=true && movimiento == MOV_ARRIBA){
        (*ref_sombra).fila++;
    }
    else if (esta_dentro_rango((*ref_sombra),MAX_FILAS,MAX_COLUMNAS)!=true && movimiento == MOV_ABAJO){
        (*ref_sombra).fila--;
    }
    else if ((esta_dentro_rango((*ref_sombra),MAX_FILAS,MAX_COLUMNAS)!=true && movimiento == MOV_IZQUIERDA)){
        (*ref_sombra).col--;
    }
    else if ((esta_dentro_rango((*ref_sombra),MAX_FILAS,MAX_COLUMNAS)!=true && movimiento == MOV_DERECHA)){
        (*ref_sombra).col++;
    }   
}


void mover_personaje(personaje_t* ref_personaje, sombra_t* ref_sombra, char movimiento){
    if (movimiento == MOV_ARRIBA ){
        (*ref_personaje).posicion.fila--;
        (*ref_sombra).posicion.fila--;
    }

    else if (movimiento == MOV_ABAJO ){
        (*ref_personaje).posicion.fila++;
        (*ref_sombra).posicion.fila++;        
    }
    else if (movimiento == MOV_IZQUIERDA ){
        (*ref_personaje).posicion.col--;
        (*ref_sombra).posicion.col++;
    }
    else if (movimiento == MOV_DERECHA ){
        (*ref_personaje).posicion.col++;
        (*ref_sombra).posicion.col--;
    }
    evaluar_coord_mac(&((*ref_personaje).posicion),movimiento);
    evaluar_coord_sombra(&((*ref_sombra).posicion),movimiento);
}

int buscar_elemento(elemento_t elementos[MAX_ELEMENTOS], int tope, coordenada_t posicion){
    int i = 0;
    int posicion_elemento = -1;
    bool coord_iguales = false;
    while((i<tope)&&(coord_iguales==false)){
        if( coordenadas_iguales(elementos[i].posicion,posicion)){
            posicion_elemento = i;
            coord_iguales = true;        
        }
        i++;
    }
    return posicion_elemento;
}

void imprimir_terreno(juego_t juego){
    char terreno[MAX_FILAS][MAX_COLUMNAS];
    
    for (int i=0; i < MAX_FILAS;i++){
        for (int j=0;j< MAX_COLUMNAS;j++){
            terreno[i][j] = '-';
        }
    }
    terreno[juego.personaje.posicion.fila][juego.personaje.posicion.col]= MAC;
    terreno[juego.sombra.posicion.fila][juego.sombra.posicion.col]= BLOO;
    printf("   00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19\n");
    
    for (int i=0; i < MAX_FILAS;i++){
        if (i<10){
            printf("0%i|",i);
        }
        else{
            printf("%i|",i);
        }
        for (int j=0;j< MAX_COLUMNAS;j++){
            printf(" %c ",terreno[i][j]);
        }
        printf("\n");
    }    
}

void llenar_nivel(elemento_t obstaculos[MAX_ELEMENTOS],int tope_obstaculos,elemento_t herramientas[MAX_ELEMENTOS],int tope_herramientas,int num_nivel){
    int tope_velas_pozo;
    int tope_escalera_moneda;
    if(num_nivel == 1){
        tope_velas_pozo = tope_obstaculos - 1;
        tope_escalera_moneda = tope_herramientas - 1;
        llenar_obstaculos(obstaculos,tope_velas_pozo,tope_obstaculos,4,20);
        llenar_herramientas(herramientas,tope_herramientas,tope_escalera_moneda,9,20);
    }
    else if(num_nivel == 2){
        tope_velas_pozo = tope_obstaculos - 4;
        tope_escalera_moneda = tope_herramientas -2;
        llenar_obstaculos(obstaculos,tope_velas_pozo,tope_obstaculos,9,31);
        llenar_herramientas(herramientas,tope_herramientas,tope_escalera_moneda,14,30);
    }
    else if (num_nivel == 3){
        tope_velas_pozo = tope_obstaculos - 8;
        tope_escalera_moneda = tope_herramientas -2;
        llenar_obstaculos(obstaculos,tope_velas_pozo,tope_obstaculos,11,45);
        llenar_herramientas(herramientas,tope_herramientas,tope_escalera_moneda,14,30);
    }
    
}
/*void verificacion_coord(elemento_t obs_herra[MAX_ELEMENTOS],int c){
    int comparar;
    for(int i = c;i>=0;i--){
        comparar=i;
        for(int j = c-1;j>=0;j--){
            if(coordenadas_iguales(obs_herra[comparar].coordenada,obs_herra[j].coordenada)){
                obs_herra[j].coordenada = coordenada_aleatoria(MAX_FILAS,MAX_COLUMNAS);
            }
        }
    }
}
*/


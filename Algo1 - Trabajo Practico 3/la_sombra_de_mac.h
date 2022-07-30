#ifndef __LA_SOMBRA_DE_MAC__
#define __LA_SOMBRA_DE_MAC__

#include <stdbool.h>

#define MAX_FILAS 20
#define MAX_COLUMNAS 25
#define MAX_ELEMENTOS 500
#define MAX_NIVELES 3
#define MAX_PAREDES 200
#define MAX_NOMBRE 100
#define N1_POZOS_DEFAULT 15
#define N1_VELAS_DEFAULT 5
#define N1_INTERRUPTORES_DEFAULT 1
#define N1_PORTALES_DEFAULT 0
#define N1_MONEDAS_DEFAULT 10
#define N1_ESCALERAS_DEFAULT 10
#define N1_LLAVES_DEFAULT 10
#define N2_POZOS_DEFAULT 20
#define N2_VELAS_DEFAULT 10
#define N2_INTERRUPTORES_DEFAULT 2
#define N2_PORTALES_DEFAULT 2
#define N2_MONEDAS_DEFAULT 15
#define N2_ESCALERAS_DEFAULT 15
#define N2_LLAVES_DEFAULT 1
#define N3_POZOS_DEFAULT 12
#define N3_VELAS_DEFAULT 30
#define N3_INTERRUPTORES_DEFAULT 4
#define N3_PORTALES_DEFAULT 4
#define N3_MONEDAS_DEFAULT 15
#define N3_ESCALERAS_DEFAULT 15
#define N3_LLAVES_DEFAULT 1


typedef struct coordenada {
    int fila;
    int col;
}coordenada_t;

typedef struct personaje {
    coordenada_t posicion;
    int vida;
    int puntos;
    bool tiene_llave;
    bool interruptor_apretado;
}personaje_t;

typedef struct sombra {
    coordenada_t posicion;
    bool esta_viva;
}sombra_t;

typedef struct elemento {
    char tipo;
    coordenada_t coordenada;
}elemento_t;

typedef struct nivel {
    int numero_nivel;
    coordenada_t paredes[MAX_PAREDES];
    int tope_paredes;
    elemento_t obstaculos[MAX_ELEMENTOS];
    int tope_obstaculos;
    elemento_t herramientas[MAX_ELEMENTOS];
    int tope_herramientas;
}nivel_t;

typedef struct juego {
    personaje_t personaje;
    sombra_t sombra;
    nivel_t niveles[MAX_NIVELES];
    int nivel_actual;
}juego_t;

typedef struct partida {
    char jugador[MAX_NOMBRE];
    int nivel_llegado;
    int puntos;
    int vidas_restantes;
    bool gano;
}partida_t;

typedef struct config{
    int pozos;
    int velas;
    int interruptores;
    int portales;
    int monedas;
    int escaleras;
    int llaves;
}config_t;


/*
 * Procedimiento que recibe el juego e imprime toda su información por pantalla.
 */
void imprimir_terreno(juego_t juego);

/* 
 *Inicializará el juego, cargando toda la información inicial, los datos del personaje, y los 3 niveles.
 */
void inicializar_juego(juego_t* juego,config_t configuraciones[MAX_NIVELES]);

/*
 * Recibe un juego con todas sus estructuras válidas.
 *
 * El juego se dará por ganado, si terminó todos los niveles. O perdido, si el personaje queda
 * sin vida. 
 * Devolverá:
 * -> 0 si el estado es jugando. 
 * -> -1 si el estado es perdido.
 * -> 1 si el estado es ganado.
 */
int estado_juego(juego_t juego);

/*
 * El nivel se dará por terminado, si ambos personajes pasaron por la puerta teniendo la 
 * llave correspondiente.
 * Devolverá:
 * -> 0 si el estado es jugando.
 * -> 1 si el estado es ganado.
 */
int estado_nivel(juego_t juego);

/*
 * Moverá el personaje, y realizará la acción necesaria en caso de chocar con un elemento
 */
void realizar_jugada(juego_t* juego);

#endif
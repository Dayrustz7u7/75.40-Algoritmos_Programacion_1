/* 
ENUNCIADO DEL EJERCICIO:
-------------------------------------------------------------------------------------------------------------------------
Las chicas superpoderosas en su tiempo libre se pusieron a practicar tirar con arco y flecha, y se volvieron tan buenas 
que decidieron entrar a un torneo local.
Mojo Jojo al escuchar esto vió su oportunidad perfecta para humillarlas, ya que después de todo, él se cree un genio en 
el manejo del arco y flecha. La realidad es que nunca tocó un arco, pero dejémoslo soñar y ayudémoslo a ir practicando 
para el torneo.

Implementar una función que dada una matriz que representa un blanco, devuelva el puntaje de ese tiro. El puntaje está 
dado dependiendo de en qué posición de éste fue el tiro:
Amarillo: 10 puntos.
Rojo: 5 puntos.
Negro: 2 puntos.
Por afuera del blanco: 0 puntos.
Tener en cuenta:

La matriz es de caracteres, donde cada posición puede representar un color:

Amarillo (A).
Rojo (R).
Negro (N).
La matriz no es necesariamente cuadrada y tiene sus respectivos topes. Por lo que se toma al tiro por fuera del blanco 
cuando éste está por fuera de los límites definidos por los topes de la matriz.

Ejemplo:

Con la matriz de 5x5:

N N R N N
N R A R N
N R N R N
N R A R N
N N R N N
Y el tiro:

fila = 2
columna = 1
El resultado esperado de la función es 5 ya que da en uno rojo.
-------------------------------------------------------------------------------------------------------------------------
*/

// RESOLUCION 
#include <stdio.h>
#define MAX_FILAS 10
#define MAX_COLUMNAS 23
#define AMARILLO 'A'
#define ROJO 'R'
#define NEGRO 'N'

int calcular_puntaje_tiro(char blanco[MAX_FILAS][MAX_COLUMNAS], int tope_filas, int tope_columnas, int fila_tiro, int columna_tiro) {
    int puntos=0;
    if( fila_tiro > tope_filas || columna_tiro > tope_columnas  ){
        return puntos;
    }
    if (blanco[fila_tiro][columna_tiro] == AMARILLO ){
        puntos += 10;
    }
    else if (blanco[fila_tiro][columna_tiro] == ROJO ){
        puntos +=5;
    }
    else if (blanco[fila_tiro][columna_tiro] == NEGRO){
        puntos +=2;
    }
    return puntos; 

}
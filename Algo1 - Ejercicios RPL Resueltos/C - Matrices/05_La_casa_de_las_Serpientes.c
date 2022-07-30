/* 
ENUNCIADO DEL EJERCICIO:
-------------------------------------------------------------------------------------------------------------------------
Charly, el ruidoso amigo de los osos, hizo una casita para sus amigas serpientes. Y ahora que son muchas tuvo que 
poner un poco de orden para que entren todas. Para organizarlas pensó la casa como una matriz, donde cada serpiente está 
representada por un entero (su id) y puede ocupar más de un casillero de forma horizontal, los lugares vacíos están 
representados con un 0 (cero).

Implementar una función que dada la matriz, el id de una serpiente, su largo y la fila donde Charly piensa posicionarla 
agregue a esta misma a la matriz.
Tener en cuenta:

Las serpientes se agregan solo a lo largo de una fila, pensémoslo como que se acuestan de forma recta en horizontal.
El id que nos pasen es un id válido, esto quiere decir que no va a ser negativo ni 0 (cero).
La fila donde nos van a pedir posicionar la serpiente siempre va a estar completamente vacía.

Por otra parte la fila que nos pidan puede no estar disponible dentro de los limites de la matriz, en estos casos no se 
debe hacer nada.

La serpiente puede no entrar en la fila que se nos pide, esto es cuando el largo de la serpiente es mayor al límite de 
columnas. En estos casos hay que posicionar todo lo que se pueda de la serpiente, a fines practicos esto quiere decir que 
toda la fila queda ocupada por la serpiente.
Las serpientes siempre empiezan desde la columna 0. Esto quiere decir que si una serpiente es de largo 3, entonces va 
a ocupar los casilleros 0, 1 y 2 de la fila pedida.
Ejemplo:

Teniendo una matriz vacía de 4x4:

0000
0000
0000
Y teniendo que posicionar la serpiente de id 3, de largo 2 en la fila 1, tendríamos que tener como resultado una matriz:

0000
3300
0000
-------------------------------------------------------------------------------------------------------------------------
*/

// RESOLUCION
#include <stdio.h>
#define MAX_FILAS 10
#define MAX_COLUMNAS 10

void posicionar_serpiente(int casa[MAX_FILAS][MAX_COLUMNAS],int tope_filas,int tope_columnas,int id,int largo, int fila){
  for(int i = 0; i<tope_filas; i++){
        if( i == fila ){
            for(int j =0; j< tope_columnas; j++){
                if(j<largo){
                    casa[i][j] = id;
                }
            }
        }
    }
}
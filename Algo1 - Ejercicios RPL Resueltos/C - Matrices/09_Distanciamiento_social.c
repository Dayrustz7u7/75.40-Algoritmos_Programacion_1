/* 
ENUNCIADO DEL EJERCICIO:
-------------------------------------------------------------------------------------------------------------------------
Todos los enemigos de Cartoon Network se juntaron para finalmente derrotar a sus oponentes.
Ya tenían hasta formaciones hechas y todo, el tema es que ahora con la pandemia tienen que redistribuirse en sus formaciones para así lograr respetar el distanciamiento social.
Para poder organizarse pusieron sus formaciones en una matriz, donde en cada posición puede haber un enemigo (E) o un espacio vacío (-). Ahora solo necesitan reacomodarse, pero como no tienen mucho tiempo decidieron respetar el distanciamiento solo en las filas, por lo que no les importará si quedan dos enemigos aledaños en alguna columna (no entendieron nada me parece, pero bueno).

Implementar una función que por fila separe a los enemigos. Esto quiere decir agregar un espacio vacío (-) entre cada par de enemigos que se encuentren aledaños. Por lo que si se tiene EE se debe distanciar dejandolos E-E. Es posible que el distanciamento agrande la matriz de la formación, por lo que también hay que actualizar los topes según corresponda.
Tener en cuenta:

Si es necesario hay que actualizar los topes de la matriz, siempre respetando los máximos.
Si no es posible respetar el distanciamiento social porque se va de los máximos de la matriz, entonces todos los enemigos que al distanciar queden por afuera de los máximos son matados. Eehh… Digo… Se los saca de la formación.
Si un par de enemigos ya está distanciado con uno o más lugares vacíos entre ellos, no hace falta agregar distancia.
Si sobran lugares en una fila se rellena con vacíos al final de esta misma.
Ejemplo:

Teniendo una matriz de topes 3x4 con máximos 3x5:

EE-E
--E-
EEEE
Al aplicar el distanciamiento debería quedar una matriz de 3x5:

E-E-E
--E--
E-E-E
Notar que:

A la segunda fila se la rellenó con un vacío al final.
En la última fila se "mató" al ultimo enemigo porque no entraba, ups.
-------------------------------------------------------------------------------------------------------------------------
*/

// RESOLUCION
#define MAX_FILAS 3
#define MAX_COLUMNAS 5
#define ENEMIGO 'E'
#define VACIO '-'

void distanciar_formacion(char formacion[MAX_FILAS][MAX_COLUMNAS], int* tope_filas, int* tope_columnas) {
    int contador_enemigos_muertos;
    
    for(int i =0; i< *tope_filas; i++){
        contador_enemigos_muertos=0;
        for(int j=0; j< *tope_columnas; j++){
            if(formacion[i][j-1]== ENEMIGO &&formacion[i][j] == ENEMIGO && j>0){
                formacion[i][j] = VACIO;
                contador_enemigos_muertos ++;
            }
            if(formacion[i][j-1]== VACIO &&formacion[i][j] == VACIO && contador_enemigos_muertos >0 ){
                formacion[i][j] = ENEMIGO;
                contador_enemigos_muertos--;
            }
            if(j == (*tope_columnas)-1 && j<MAX_COLUMNAS-1 && contador_enemigos_muertos > 0){ 
              (*tope_columnas)++;
              for(int h=0; h <*tope_filas;h++){
                  formacion[h][j+1] = VACIO;
              }
            }                     
        }
    }
}
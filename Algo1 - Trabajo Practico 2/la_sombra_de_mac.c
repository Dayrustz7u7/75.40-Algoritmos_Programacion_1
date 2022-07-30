#include "la_sombra_de_mac.h"
#include "utiles.h"
#include <stdio.h>
#include <stdlib.h> // Para usar rand
const char MOV_ARRIBA = 'W';
const char MOV_ABAJO = 'S';
const char MOV_IZQUIERDA = 'A';
const char MOV_DERECHA = 'D';
const char MOV_VIDA = 'V';
const int  CANJEAR_VIDA = 200;
const int VIDA_MAC = 3;
const int PUNTOS_MAC = 0;
const char MAC = 'M';
const char BLOO = 'B';
const char PUERTA = 'D';
const char ESCALERAS = 'E';
const char LLAVE =  'L';
const char MONEDAS = 'C';
const char POZOS = 'W';
const char INTERRUPTORES = 'O';
const char PORTALES = 'P';
const char VELAS = 'V';
const char PARED = '#';
const int NIVEL_1 = 1;
const int NIVEL_2 = 2;
const int NIVEL_3 = 3;
const int SALTO_MAC = 1;
const int REVIVIR_BLOO = 50;
const int ELEMENTO_NO_ENCONTRADO = -1;
const int ESTA_JUGANDO = 0;
const int ESTA_PERDIDO = -1;
const int ESTA_GANADO = 1;
const int DISTANCIA_PUERTA = 1;
const int POS_INTERRUP_NV1 = 20;
const int POS_INTERRUP_NV2 = 31;
const int POS_INTERRUP_NV3 = 45;
const int POS_PUERTA_NV1 = 20;
const int POS_PUERTA_NV2 = 30;
const int POS_PUERTA_NV3 = 30;
const int CANT_OBS_NIVEL_1 = 21;
const int CANT_OBS_NIVEL_2 = 34;
const int CANT_OBS_NIVEL_3 = 50;
const int CANT_HERRA_NIVEL_1 = 21;
const int CANT_HERRA_NIVEL_2 = 32;
const int CANT_HERRA_NIVEL_3 = 32;
const int CANT_VELAS_NIVEL_1 = 5;
const int CANT_VELAS_NIVEL_2 = 10;
const int CANT_VELAS_NIVEL_3 = 12;
const int CANT_POZOS_NIVEL_1 = 15;
const int CANT_POZOS_NIVEL_2 = 20;
const int CANT_POZOS_NIVEL_3 = 30;
const int CANT_ESCALERA_NIVEL_1 = 10;
const int CANT_ESCALERA_NIVEL_2 = 15;
const int CANT_ESCALERA_NIVEL_3 = 15;
const int CANT_PUERTA = 1;
const int CANT_LLAVE = 1;

/*
*  Función que recibe dos coordenadas, devuelve true si las
*  coordenadas son iguales, sino false.
*/
bool coordenadas_iguales(coordenada_t a, coordenada_t b){
    return a.fila == b.fila && a.col == b.col;
}
/*
*  Función que dados una altura máxima y un ancho máximo
*  devuelve una coordenada aleatoria. Una posición nunca podrá
*  tener un valor negativo, ni ser mayor a sus máximos.
*/
coordenada_t coordenada_aleatoria(int max_alto, int max_ancho){
    
    coordenada_t aleatorio;
    aleatorio.fila = rand() % max_alto;
    aleatorio.col = rand() % max_ancho;

    return aleatorio;
}
/*
*  Procedimiento que dejará la estructura personaje_t en un
*  estado válido para iniciar el juego.
*  'arranque_personaje' es un parámetro que representa la posición 
*  en la arrancará el personaje.
*/
void inicializar_personaje(personaje_t* ref_personaje, coordenada_t arranque_personaje){
    (*ref_personaje).vida = VIDA_MAC;
    (*ref_personaje).puntos = PUNTOS_MAC;
    (*ref_personaje).interruptor_apretado = false;
    (*ref_personaje).tiene_llave = false;
    (*ref_personaje).posicion.col = arranque_personaje.col;
    (*ref_personaje).posicion.fila = arranque_personaje.fila;
}
/*
*  Procedimiento que dejará una estructura elemento_t que
*  represente a la sombra, en un estado válido para iniciar el juego. 
*  'arranque_sombra' es un parámetro que representa la posición 
*  en la arrancará la sombra.
*/
void inicializar_sombra(sombra_t* ref_sombra, coordenada_t arranque_sombra){
    (*ref_sombra).posicion.fila = arranque_sombra.fila;
    (*ref_sombra).posicion.col =MAX_COLUMNAS-arranque_sombra.col-1;
    (*ref_sombra).esta_viva = true ;
   
}
/*
*  La función recibe un caracter y devuelve true
*  si el movimiento recibido concuerda con la convención
*  propuesta, sino false.
*  -> W: Si el personaje debe moverse para la arriba. 
*  -> A: Si el personaje debe moverse para la izquierda.
*  -> S: Si el personaje debe moverse para la abajo.
*  -> D: Si el personaje debe moverse para la derecha.
*  -> V: Si el personaje canjea 200pts para 1 VIDA EXTRA.
*/
bool es_movimiento_valido(char movimiento){
    return movimiento == MOV_ARRIBA || movimiento == MOV_ABAJO || movimiento == MOV_IZQUIERDA || movimiento == MOV_DERECHA || movimiento == MOV_VIDA;
}
/*
*  Procedimineto que se encargará de pedirle al usuario
*  que ingrese un movimiento hasta que sea válido.
*/
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
/*
*  La función recibe una coordenada, devuelve true
*  si la posición dentro de las dimensiones dadas, sino false.
*  Una posición nunca podrá tener un valor negativo y no tendrá un 
*  valor más alto que los máximos.
*/
bool esta_dentro_rango(coordenada_t posicion, int max_alto, int max_ancho){
    return posicion.fila < max_alto && posicion.fila >= 0 && posicion.col < max_ancho && posicion.col >= 0;
}
/*
*   La funcion se encargar de evaluar si una coordenada estra dentro
*   del vector dado por parametro, devuelve true si esta, sino false.
*   El vector dado por parametro debe ser de tipo struct "coordena_t"
*   y el tope no debe de exceder al MAX_ELEMENTOS ni ser negativo.
*/
bool esta_dentro_pared(coordenada_t coord_diferentes[MAX_ELEMENTOS],int tope_coord_dif,coordenada_t coord_agregar){
    bool posicion_repetida = false;
    for(int i = 0; i < tope_coord_dif; i++){
        if(coordenadas_iguales(coord_diferentes[i],coord_agregar)){
            posicion_repetida  = true;
        }
    }
    return posicion_repetida ;
}
/*
*   La funcion se encarga de evaluar si una coordenada esta dentro
*   del vector dado por parametro, devuelve true si esta, sino false.
*   El vector dado por parametro debe ser de tipo struct "elemento_t"
*   y el tope no debe de exceder al MAX_ELEMENTOS ni ser negativo.
*/
bool esta_dentro_elemento(elemento_t elementos[MAX_ELEMENTOS],int tope_elementos,coordenada_t coord_verificar){
    bool posicion_repetida = false;
    for(int i = 0; i < tope_elementos; i++){
        if(coordenadas_iguales(elementos[i].coordenada,coord_verificar)){
            posicion_repetida = true;
        }
    }
    return posicion_repetida;
}
/*
*   Procedimiento que se encarga en verificar si la posicion actual
*   de mac y bloo no sean las mismas que las paredes, si lo son se
*   mantiene la posicion de mac y bloo antes del cambio de la jugada
*   recibida por parametro "posicicon_correcta_mac" y "posicion_correc_bloo"
*/
void bloqueo_paredes(juego_t* ref_juego,coordenada_t posicion_correcta_mac,coordenada_t posicion_correcta_bloo,int nivel_actual){

    if(esta_dentro_pared((*ref_juego).niveles[nivel_actual].paredes,(*ref_juego).niveles[nivel_actual].tope_paredes,(*ref_juego).personaje.posicion)){
        (*ref_juego).personaje.posicion = posicion_correcta_mac;
    }
    if(esta_dentro_pared((*ref_juego).niveles[nivel_actual].paredes,(*ref_juego).niveles[nivel_actual].tope_paredes,(*ref_juego).sombra.posicion)){
        (*ref_juego).sombra.posicion = posicion_correcta_bloo;
    }
}
/*
*  La función recibe un vector de elementos, su respectivo tope y una coordenada,
*  devuelve la posición del elemento del vector, que coincida con la coordenada pasada 'posicion',
*  si no se encuentra ningún elemento, se devolverá -1. 
*/
int buscar_elemento(elemento_t elementos[MAX_ELEMENTOS], int tope, coordenada_t posicion){
    int i = 0;
    int posicion_elemento = -1;
    bool coord_iguales = false;
    while((i<tope)&&(coord_iguales==false)){
        if( coordenadas_iguales(elementos[i].coordenada,posicion)){
            posicion_elemento = i;
            coord_iguales = true;        
        }
        i++;
    }
    return posicion_elemento;
}
/*
*  Procedimiento que evalua si la nueva posicion generada para MAC
*  no se repetia con las posiciones de los demas elementos y paredes;
*  de ser asi se cambiara por la nueva posicion evaluada.
*  nivel_actual no debe de pasar de MAX_NIVELES ni ser negativo.
*/
void nueva_posicion_mac(juego_t* ref_juego,int nivel_actual){
    bool son_iguales = true;
    while(son_iguales){
        coordenada_t nuevo_posicion_mac = coordenada_aleatoria(MAX_FILAS,MAX_COLUMNAS);
        bool igual_posicion_pared = esta_dentro_pared((*ref_juego).niveles[nivel_actual].paredes,(*ref_juego).niveles[nivel_actual].tope_paredes,nuevo_posicion_mac);
        bool igual_posicion_herra = esta_dentro_elemento((*ref_juego).niveles[nivel_actual].herramientas,(*ref_juego).niveles[nivel_actual].tope_herramientas,nuevo_posicion_mac);
        bool igual_posicion_obs =  esta_dentro_elemento((*ref_juego).niveles[nivel_actual].obstaculos,(*ref_juego).niveles[nivel_actual].tope_obstaculos,nuevo_posicion_mac);
        
        if(igual_posicion_pared == false && igual_posicion_herra == false && igual_posicion_obs == false){
            (*ref_juego).personaje.posicion = nuevo_posicion_mac;
            (*ref_juego).sombra.posicion.fila =  (*ref_juego).personaje.posicion.fila;
            (*ref_juego).sombra.posicion.col = MAX_COLUMNAS - (*ref_juego).personaje.posicion.col - 1;
            son_iguales = false;
        }
    }
}
/*
*  Funcion que evalua si en la posicion que cae Mac, se encuentra con una escalera,
*  -> Si cae se realizara la modificacion de la posicion de acuerdo al movimiento dado por parametro
*     y se evaluara si dicha modificacion no se sobrepone con una paredo o se sale de rango. y devolvera
*     la "posicion del vector" que concuerda con la posicion de mac.
*  -> Si no coincide con alguna posicion de escalera o dicho cambio esta por fuera de rango o en la pared
*     se devolvera "-1" y la posicion de mac vuelve hacer el mismo antes del cambio.
*/
int hay_escalera(nivel_t niveles[MAX_NIVELES],int nivel_actual,personaje_t* ref_mac,char movimiento){
    coordenada_t posicion_mac = (*ref_mac).posicion;
    int posicion_escalera = buscar_elemento(niveles[nivel_actual].herramientas,niveles[nivel_actual].tope_herramientas,(*ref_mac).posicion);
    if(posicion_escalera != ELEMENTO_NO_ENCONTRADO){
        if(niveles[nivel_actual].herramientas[posicion_escalera].tipo == ESCALERAS){
            if(movimiento == MOV_ARRIBA){
                (*ref_mac).posicion.fila -= SALTO_MAC;
            }
            else if(movimiento ==MOV_ABAJO){
                (*ref_mac).posicion.fila += SALTO_MAC;
            }
            else if(movimiento == MOV_DERECHA){
                (*ref_mac).posicion.col += SALTO_MAC;
            }
            else if(movimiento == MOV_IZQUIERDA){
                (*ref_mac).posicion.col -= SALTO_MAC;
            }
        }
        if(esta_dentro_rango((*ref_mac).posicion,MAX_FILAS,MAX_COLUMNAS) == false){
            (*ref_mac).posicion =  posicion_mac;
            posicion_escalera = ELEMENTO_NO_ENCONTRADO;
        }
        else if(esta_dentro_pared(niveles[nivel_actual].paredes,niveles[nivel_actual].tope_paredes,(*ref_mac).posicion)){
            (*ref_mac).posicion = posicion_mac;
            posicion_escalera = ELEMENTO_NO_ENCONTRADO;
        }
    }
    return posicion_escalera;
}    
/*
*  Procedimiento que recibe a juego_t por referencia, movimiento y su nivel_actual
*  De acuerdo el Movimiento dado por parametro, se cambiara la posicion a distancia 2
*  y se evaluara si dicha posicion cambiada no se sobrepone con alguno de las paredes o
*  o se salga del rango.
*  -> Devolvera true -> Si se realizo el salto. 
*  -> Devolvera false -> Si la posicion es igual a una pared o se sale de rango.
*  nivel_actual no debe ser negativo ni ser mayor a MAX_NIVEL.
*/
bool movimiento_escalera(juego_t* ref_juego,char movimiento,int nivel_actual){
    coordenada_t posicion_mac = (*ref_juego).personaje.posicion;
    bool realizo_salto = true;
    bool piso_pared;
    bool esta_adentro;
    bool hay_escalera;
    if(movimiento == MOV_ARRIBA){
        (*ref_juego).personaje.posicion.fila -= SALTO_MAC;
    }
    else if ( movimiento == MOV_ABAJO){
        (*ref_juego).personaje.posicion.fila += SALTO_MAC;
    }
    else if ( movimiento ==  MOV_DERECHA){
        (*ref_juego).personaje.posicion.col += SALTO_MAC;
    }
    else if ( movimiento ==  MOV_IZQUIERDA){
        (*ref_juego).personaje.posicion.col -= SALTO_MAC;
    }
    esta_adentro =esta_dentro_rango((*ref_juego).personaje.posicion,MAX_FILAS,MAX_COLUMNAS);
    piso_pared = esta_dentro_pared((*ref_juego).niveles[nivel_actual].paredes,(*ref_juego).niveles[nivel_actual].tope_paredes,(*ref_juego).personaje.posicion);
    hay_escalera = esta_dentro_elemento((*ref_juego).niveles[nivel_actual].herramientas,(*ref_juego).niveles[nivel_actual].tope_herramientas,(*ref_juego).personaje.posicion);
    if(esta_adentro == false){
        (*ref_juego).personaje.posicion =  posicion_mac;
        realizo_salto = false;
    }
    if(piso_pared && hay_escalera == false){
        (*ref_juego).personaje.posicion = posicion_mac;
        realizo_salto = false;
    }    
    return realizo_salto;
}
/*
*  Procedimiento recibe un vector de tipo elemento_t con su tope pasado
*  por referencia y el numero de la posicion que desea eliminar(indice)
*  Se encarga de pisar dentro del vector, el elemento a eliminar por el elemento que le sigue,
*  asi continuamente, y actualizar el tope.
*  El numero del elemento eliminar no debe de pasarse del tope del vector.
*/
void eliminacion_ordenada(elemento_t elementos[MAX_ELEMENTOS],int* tope_elementos,int elemento_a_eliminar){
    
    for(int i = elemento_a_eliminar; i < (*tope_elementos) - 1; i++){
        elementos[i] = elementos[i+1];
    }
    (*tope_elementos)--;
}
/*
*  Procedimiento que recibe juego_t por referencia, un movimiento y su nivel_actual
*  Ejecutara acciones dependiendo si la posicion de Mac es igual a la posicion de las herramientas y obstaculos:
*  ->Si la posicion de Mac es igual a Pozos -> Pierde 1 vida y cambia la posicion de Mac ALEATORIO y Bloo.
*  ->Si la posicion de Mac es igual a Interruptores -> El moviento de Bloo cambia a normal o espejado.
*  ->Si la posicion de Mac es igual a Velas -> Las apaga(Elimina del vector OBSTACULOS).
*  ->Si la posicion de Mac es igual a Monedas -> El puntaje de Mac aumentara en un numero random de 10 a 20.
*  ->Si la posicion de Mac es igual a Escalera -> Se aumentara una posicion dependiendo del Movimiento.
*  ->Si la posicion de Mac es igual a LLave -> Obtendra la llave, y se eliminara del vector.
*   El Movimiento debe ser W A S D y el nivel_actual debe ser menor que MAX_NIVEL y asu vez positivo.
*/
void pisada_mac(juego_t* ref_juego,char movimiento,int nivel_actual){
    int posicion_obstaculo = buscar_elemento((*ref_juego).niveles[nivel_actual].obstaculos,(*ref_juego).niveles[nivel_actual].tope_obstaculos,(*ref_juego).personaje.posicion);
    int posicion_herramienta = buscar_elemento((*ref_juego).niveles[nivel_actual].herramientas,(*ref_juego).niveles[nivel_actual].tope_herramientas,(*ref_juego).personaje.posicion);
    if(posicion_obstaculo != ELEMENTO_NO_ENCONTRADO){

        if((*ref_juego).niveles[nivel_actual].obstaculos[posicion_obstaculo].tipo == POZOS){
            (*ref_juego).personaje.vida -= 1;
            nueva_posicion_mac(&((*ref_juego)),nivel_actual);
        }
        else if((*ref_juego).niveles[nivel_actual].obstaculos[posicion_obstaculo].tipo == INTERRUPTORES){
            if((*ref_juego).personaje.interruptor_apretado == false){
                (*ref_juego).personaje.interruptor_apretado = true;
            }else{
                (*ref_juego).personaje.interruptor_apretado = false;
            }   
        }
        else if((*ref_juego).niveles[nivel_actual].obstaculos[posicion_obstaculo].tipo == VELAS){      
            eliminacion_ordenada((*ref_juego).niveles[nivel_actual].obstaculos,&((*ref_juego).niveles[nivel_actual].tope_obstaculos),posicion_obstaculo);
        }
    }
    if( posicion_herramienta != ELEMENTO_NO_ENCONTRADO){
        
        if((*ref_juego).niveles[nivel_actual].herramientas[posicion_herramienta].tipo == MONEDAS){
            (*ref_juego).personaje.puntos += rand() % 11 + 10;
            eliminacion_ordenada((*ref_juego).niveles[nivel_actual].herramientas,&((*ref_juego).niveles[nivel_actual].tope_herramientas),posicion_herramienta);  
        }
        else if((*ref_juego).niveles[nivel_actual].herramientas[posicion_herramienta].tipo == ESCALERAS){
            bool mac_salto = movimiento_escalera(&((*ref_juego)),movimiento,nivel_actual);
            if(mac_salto){
                eliminacion_ordenada((*ref_juego).niveles[nivel_actual].herramientas,&((*ref_juego).niveles[nivel_actual].tope_herramientas),posicion_herramienta);
                int nuevo_salto = hay_escalera((*ref_juego).niveles,nivel_actual,&((*ref_juego).personaje),movimiento);
                if(nuevo_salto != ELEMENTO_NO_ENCONTRADO){
                    eliminacion_ordenada((*ref_juego).niveles[nivel_actual].herramientas,&((*ref_juego).niveles[nivel_actual].tope_herramientas),nuevo_salto);
                }
            }
        }
        else if ((*ref_juego).niveles[nivel_actual].herramientas[posicion_herramienta].tipo == LLAVE){
            if(coordenadas_iguales((*ref_juego).personaje.posicion,(*ref_juego).sombra.posicion)==false){
                (*ref_juego).personaje.tiene_llave = true;                                              
                eliminacion_ordenada((*ref_juego).niveles[nivel_actual].herramientas,&((*ref_juego).niveles[nivel_actual].tope_herramientas),posicion_herramienta);
            }
        }
    }
    if(coordenadas_iguales((*ref_juego).personaje.posicion,(*ref_juego).sombra.posicion)&& (*ref_juego).sombra.esta_viva == false){
        (*ref_juego).sombra.esta_viva = true;
        (*ref_juego).personaje.puntos -= REVIVIR_BLOO;
    }
}
/*
*  Procedimiento que se encagara de vefiricar si la distancia de bloo
*  con respecto al OBSTACULO -> VELA , esta dentro de su rango 3x3 y si lo
*  esta BLOO morira.
*  Nivel_actual debe ser menor a MAX_NIVELES y no ser negativo.
*/
void bloo_cerca_vela(juego_t* ref_juego,int nivel_actual){ 
    int i = 0;
    while((*ref_juego).niveles[nivel_actual].obstaculos[i].tipo == VELAS){
        coordenada_t coord_vela = (*ref_juego).niveles[nivel_actual].obstaculos[i].coordenada;
        coordenada_t coord_bloo = (*ref_juego).sombra.posicion;
        if(abs(coord_vela.fila - coord_bloo.fila) + abs(coord_vela.col - coord_bloo.col) == 1){
            (*ref_juego).sombra.esta_viva = false;
        }
        else if(abs(coord_vela.fila - coord_bloo.fila) + abs(coord_vela.col - coord_bloo.col) == 2 && coord_bloo.fila != coord_vela.fila && coord_bloo.col != coord_vela.col){
            (*ref_juego).sombra.esta_viva = false;
        }
        i++;
    }
}
/*
*  Procedimiento que recibe juego_t por referencia y un nivel_actual.  
*  Ejectura una serie de acciones si la posicion de Bloo es igual a un OBSTACULO O
*  HERRAMIENTA:
*  ->Si la posicion de Bloo es igual a Portales -> Intercambiaran posiciones MAC Y BLOO.
*  ->Si la posicion de Bloo es igual a Monedas -> El puntaje de Mac aumentara en un numero random de 10 a 20.
*  ->Si la posicion de Bloo esta cerca a una Vela -> Bloo muere.
*/
void pisada_bloo(juego_t* ref_juego,int nivel_actual){
    
    int posicion_obstaculo = buscar_elemento((*ref_juego).niveles[nivel_actual].obstaculos,(*ref_juego).niveles[nivel_actual].tope_obstaculos,(*ref_juego).sombra.posicion);
    int posicion_herramienta = buscar_elemento((*ref_juego).niveles[nivel_actual].herramientas,(*ref_juego).niveles[nivel_actual].tope_herramientas,(*ref_juego).sombra.posicion);
    
    if( posicion_obstaculo != ELEMENTO_NO_ENCONTRADO){
        if((*ref_juego).niveles[nivel_actual].obstaculos[posicion_obstaculo].tipo == PORTALES){
            coordenada_t aux = (*ref_juego).sombra.posicion;
            (*ref_juego).sombra.posicion = (*ref_juego).personaje.posicion;
            (*ref_juego).personaje.posicion = aux;
        }
    }
    if( posicion_herramienta != ELEMENTO_NO_ENCONTRADO){
        if((*ref_juego).niveles[nivel_actual].herramientas[posicion_herramienta].tipo == MONEDAS){
            (*ref_juego).personaje.puntos += rand() % 11 + 10;
            eliminacion_ordenada((*ref_juego).niveles[nivel_actual].herramientas,&((*ref_juego).niveles[nivel_actual].tope_herramientas),posicion_herramienta); 
        }
    }
    bloo_cerca_vela(&((*ref_juego)),nivel_actual);
}
/*
* Recibira un personaje_t pasador por referencia y un movimiento valido
*  se evaluara si la nueva posicion de mac esta por fuera de rango.
*  ->Si esta por fuera de rango , hara lo contrario que el movimiento dado por parametro
*    y actualizara la nueva posicion para que no se salga del rango.
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
* Recibira una sombra_t pasador por referencia, un movimiento valido y personaje_t
*  se evaluara si la nueva posicion de bloo esta por fuera de rango.
*  ->Si esta por fuera de rango , hara lo contrario que el movimiento dado por parametro
*    y actualizara la nueva posicion para que no se salga del rango.
*  ->Este cambio dependera si personaje_t tiene interruptor_apretado o no.
*/
void evaluar_coord_sombra(coordenada_t* ref_sombra,char movimiento,personaje_t mac){    
    if (esta_dentro_rango((*ref_sombra),MAX_FILAS,MAX_COLUMNAS)!=true && movimiento == MOV_ARRIBA){
        (*ref_sombra).fila++;
    }
    else if (esta_dentro_rango((*ref_sombra),MAX_FILAS,MAX_COLUMNAS)!=true && movimiento == MOV_ABAJO){
        (*ref_sombra).fila--;
    }
    else if ((esta_dentro_rango((*ref_sombra),MAX_FILAS,MAX_COLUMNAS)!=true && movimiento == MOV_IZQUIERDA && mac.interruptor_apretado == false)){
        (*ref_sombra).col--;
    }
    else if ((esta_dentro_rango((*ref_sombra),MAX_FILAS,MAX_COLUMNAS)!=true && movimiento == MOV_IZQUIERDA && mac.interruptor_apretado)){
        (*ref_sombra).col++;
    }
    else if ((esta_dentro_rango((*ref_sombra),MAX_FILAS,MAX_COLUMNAS)!=true && movimiento == MOV_DERECHA  && mac.interruptor_apretado == false)){
        (*ref_sombra).col++;
    }
    else if ((esta_dentro_rango((*ref_sombra),MAX_FILAS,MAX_COLUMNAS)!=true && movimiento == MOV_DERECHA  && mac.interruptor_apretado)){
        (*ref_sombra).col--;
    }    
}
/*
* El procedimiento recibe el personaje y la sombra por referencia y el movimiento,
* y según este último, los mueve acordemente.
* 
* El personaje se mueve de la forma:
* -> W: Si el personaje debe moverse para la arriba. 
* -> A: Si el personaje debe moverse para la izquierda.
* -> S: Si el personaje debe moverse para la abajo.
* -> D: Si el personaje debe moverse para la derecha.
* -> V: Si el personaje desea CANJEAR 1 VIDA por 200 PTS.
*
* La sombra se mueve de igual forma para el eje vertical, pero
* para el eje horizontal se moverá de forma inversa si el interruptor esta en false;
*
* -> A: Si el personaje debe moverse para la derecha.
* -> D: Si el personaje debe moverse para la izquierda.
*  
* Por cada cambio de posicion se evaluara si cae en un elemento o este fuera del borde.
*/
void mover_personaje(personaje_t* ref_personaje, sombra_t* ref_sombra, char movimiento,juego_t* ref_juego){
    coordenada_t posicion_mac = (*ref_personaje).posicion;
    coordenada_t posicion_bloo = (*ref_sombra).posicion;
    if (movimiento == MOV_ARRIBA ){
        (*ref_personaje).posicion.fila--;
        if((*ref_sombra).esta_viva){
            (*ref_sombra).posicion.fila--;
        }
    }
    else if (movimiento == MOV_ABAJO ){
        (*ref_personaje).posicion.fila++;
        if((*ref_sombra).esta_viva){
            (*ref_sombra).posicion.fila++;       
        } 
    }
    else if (movimiento == MOV_IZQUIERDA && (*ref_juego).personaje.interruptor_apretado == false ){
        (*ref_personaje).posicion.col--;
        if((*ref_sombra).esta_viva){
            (*ref_sombra).posicion.col++;
        }
    }  
    else if (movimiento == MOV_IZQUIERDA && (*ref_juego).personaje.interruptor_apretado){
        (*ref_personaje).posicion.col--;
        if((*ref_sombra).esta_viva){
            (*ref_sombra).posicion.col--;
        }
    }
    else if (movimiento == MOV_DERECHA && (*ref_juego).personaje.interruptor_apretado == false ){
        (*ref_personaje).posicion.col++;
        if((*ref_sombra).esta_viva){
            (*ref_sombra).posicion.col--;
        }
    }
    else if (movimiento == MOV_DERECHA && (*ref_juego).personaje.interruptor_apretado){
        (*ref_personaje).posicion.col++;
        if((*ref_sombra).esta_viva){
            (*ref_sombra).posicion.col++;
        }
    }
    else if(movimiento == MOV_VIDA && (*ref_juego).personaje.puntos >= CANJEAR_VIDA && (*ref_juego).personaje.vida < VIDA_MAC ){
        (*ref_juego).personaje.vida += 1;
    }
    evaluar_coord_mac(&((*ref_personaje).posicion),movimiento);
    evaluar_coord_sombra(&((*ref_sombra).posicion),movimiento,(*ref_juego).personaje);
    pisada_mac(&((*ref_juego)),movimiento,(*ref_juego).nivel_actual-1);
    pisada_bloo(&((*ref_juego)),(*ref_juego).nivel_actual-1);
    bloqueo_paredes(&((*ref_juego)),posicion_mac,posicion_bloo,(*ref_juego).nivel_actual-1);
}

void imprimir_terreno(juego_t juego){
    char terreno[MAX_FILAS][MAX_COLUMNAS];
    for (int i=0;i < MAX_FILAS;i++){
        for (int j=0;j < MAX_COLUMNAS;j++){
            terreno[i][j] = '-';
        }
    }
    for(int i=0;i<juego.niveles[juego.nivel_actual-1].tope_paredes;i++){
        terreno[juego.niveles[juego.nivel_actual-1].paredes[i].fila][juego.niveles[juego.nivel_actual-1].paredes[i].col] = PARED;
    }
    for(int i=0;i<juego.niveles[juego.nivel_actual-1].tope_obstaculos;i++){
        terreno[juego.niveles[juego.nivel_actual-1].obstaculos[i].coordenada.fila][juego.niveles[juego.nivel_actual-1].obstaculos[i].coordenada.col] = juego.niveles[juego.nivel_actual-1].obstaculos[i].tipo;
         
    }
    for(int i=0;i<juego.niveles[juego.nivel_actual-1].tope_herramientas;i++){
        terreno[juego.niveles[juego.nivel_actual-1].herramientas[i].coordenada.fila][juego.niveles[juego.nivel_actual-1].herramientas[i].coordenada.col] = juego.niveles[juego.nivel_actual-1].herramientas[i].tipo;
    
    }
    terreno[juego.personaje.posicion.fila][juego.personaje.posicion.col]= MAC;
    terreno[juego.sombra.posicion.fila][juego.sombra.posicion.col]= BLOO;

    printf("   00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24\n");
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
/*
*  Procedimiento que llenara a un vector de tipo "coordenada_t" con coordenadas de las paredes y
*  coordenadas aleatorias no repetidas entre si, el Tope del Vector varia segun el nivel_actual.
*  -> nivel_actual no debe ser mayor a MAX_NIVELES, la cantidad_escaleras debe ser con respecto a cada nivel;
*  -> nivel_actual,tope_coord_dif y cantidad_escaleras no deben ser numeros negativos.
*/
void generador_coord_no_iguales(coordenada_t coord_diferentes[MAX_ELEMENTOS],int* ref_tope_coord_dif ,nivel_t niveles[MAX_NIVELES],int nivel_actual,int cantidad_escaleras){
    int tope_total = niveles[nivel_actual].tope_paredes + niveles[nivel_actual].tope_obstaculos + niveles[nivel_actual].tope_herramientas - cantidad_escaleras + 1; // +1 equivale a la posicion de MAC.
    int tope_paredes = niveles[nivel_actual].tope_paredes;
    for(int i = 0; i<tope_paredes; i++){
        coord_diferentes[i] = niveles[nivel_actual].paredes[i];
    }
    (*ref_tope_coord_dif) = tope_paredes;
    while((*ref_tope_coord_dif) < tope_total){
        coordenada_t coord_agregar = coordenada_aleatoria(MAX_FILAS,MAX_COLUMNAS);
        if(esta_dentro_pared(coord_diferentes,(*ref_tope_coord_dif),coord_agregar)==false){
            coord_diferentes[(*ref_tope_coord_dif)] = coord_agregar;
            (*ref_tope_coord_dif)++;
        }
    }
}
/*
*  Procedimiento que recibe vector "elemento_t",su tope, la suma de cantidades de velas y pozo, 
*  la cantidad de velas, la posicion del interruptor, la cantidad de paredes, y el vector "coordenada_t"
*   Se llenara el vector elemento_t con la coordenadas del vector "coordenada_t" y 
*  se le indicara el tipo que es, de acuerdo a las cantidades pasadas por parametro. 
*  -> Cada tope pasado por parametro no debe ser negativo ni mayor a MAX_ELEMENTOS
*/
void llenar_obstaculos(elemento_t obstaculos[MAX_ELEMENTOS],int tope_obstaculos,int tope_velas_pozo,int tope_velas,int pos_interruptor,int tope_paredes, coordenada_t coord_diferentes[MAX_ELEMENTOS]){
    int j = tope_paredes;
    for(int i=0;i<tope_velas_pozo;i++){
        obstaculos[i].tipo = i <= (tope_velas - 1) ? VELAS : POZOS;
        obstaculos[i].coordenada = coord_diferentes[j];
        j++;
    }
    for(int i=tope_velas_pozo;i<tope_obstaculos;i++){
        obstaculos[i].tipo = i <= pos_interruptor ? INTERRUPTORES : PORTALES;
        obstaculos[i].coordenada = coord_diferentes[j];
        j++;
        
    }
}
/*
*  Procedimiento que recibe vector "nivel_t",dichas cantidades de topes, posicion de la puerta y el vector "coordenada_t"
*   Se llenara el vector nivel_t las herramientas con la coordenadas del vector "coordenada_t" y 
*  se le indicara el tipo que es, de acuerdo a las cantidades pasadas por parametro. 
*  -> Los topes pasados por parametro no deben ser negativos ni mayores que MAX_ELEMENTOS
*  -> Nivel_actual debe ser menor a MAX_NIVELES y no ser negativo.
*  -> La posicion de la puerta no debe ser mayor al de tope_herramientas
*/
void llenar_herramientas(nivel_t niveles[MAX_NIVELES],int cantidad_escaleras,int nivel_actual,int tope_escalera_moneda,int pos_puerta,int tope_pards_obs,coordenada_t coord_diferentes[MAX_ELEMENTOS]){
    int j = tope_pards_obs;
    int tope_herramienta = niveles[nivel_actual].tope_herramientas;
    for (int i = 0; i < tope_escalera_moneda; i++){
        if( i < cantidad_escaleras){
            int posicion_aleatorio = rand() % niveles[nivel_actual].tope_paredes;
            niveles[nivel_actual].herramientas[i].tipo = ESCALERAS;
            niveles[nivel_actual].herramientas[i].coordenada = niveles[nivel_actual].paredes[posicion_aleatorio];
        }
        else{
            niveles[nivel_actual].herramientas[i].tipo = MONEDAS;
            niveles[nivel_actual].herramientas[i].coordenada = coord_diferentes[j];
            j++;
        }
    }
    for(int i=tope_escalera_moneda;i<tope_herramienta;i++){
        niveles[nivel_actual].herramientas[i].tipo = i<=pos_puerta ? PUERTA : LLAVE;
        niveles[nivel_actual].herramientas[i].coordenada = coord_diferentes[j];
        j++;
    }
}
/*
  Procedimiento que recibe juego_t por referencia , el nivel_actual, un vector de coordenads aleatorias
  y su tope por referencia
  Se encarga de llenar cada vector OBSTACULO y HERRAMIENTA; segun el Nivel_actual dado por parametro
*/
void llenar_nivel(juego_t* ref_juego, int i_juego, coordenada_t coord_diferentes[MAX_ELEMENTOS], int* ref_tope_coord_dif){
    
    int tope_paredes;
    int tope_velas_pozo;
    int tope_escalera_moneda;
    int tope_pared_obstaculo;

    if((*ref_juego).niveles[i_juego].numero_nivel == NIVEL_1){   
        (*ref_juego).niveles[i_juego].tope_obstaculos = CANT_OBS_NIVEL_1;
        (*ref_juego).niveles[i_juego].tope_herramientas = CANT_HERRA_NIVEL_1;
        tope_velas_pozo = CANT_VELAS_NIVEL_1 + CANT_POZOS_NIVEL_1;
        tope_escalera_moneda = CANT_HERRA_NIVEL_1 - CANT_PUERTA;
        tope_paredes = (*ref_juego).niveles[i_juego].tope_paredes;
        tope_pared_obstaculo = tope_paredes + CANT_OBS_NIVEL_1;
        generador_coord_no_iguales( coord_diferentes ,(&(*ref_tope_coord_dif)) , (*ref_juego).niveles , NIVEL_1 - 1, CANT_ESCALERA_NIVEL_1);     //POS -> POSICION. NV -> NIVEL
        llenar_obstaculos((*ref_juego).niveles[i_juego].obstaculos ,CANT_OBS_NIVEL_1, tope_velas_pozo , CANT_VELAS_NIVEL_1,POS_INTERRUP_NV1, tope_paredes, coord_diferentes);
        llenar_herramientas((*ref_juego).niveles,CANT_ESCALERA_NIVEL_1,NIVEL_1-1,tope_escalera_moneda ,POS_PUERTA_NV1 ,tope_pared_obstaculo ,coord_diferentes);
    }
    else if((*ref_juego).niveles[i_juego].numero_nivel == NIVEL_2){
        (*ref_juego).niveles[i_juego].tope_obstaculos = CANT_OBS_NIVEL_2;
        (*ref_juego).niveles[i_juego].tope_herramientas = CANT_HERRA_NIVEL_2;
        tope_velas_pozo = CANT_VELAS_NIVEL_2 + CANT_POZOS_NIVEL_2;
        tope_escalera_moneda = CANT_HERRA_NIVEL_2 - CANT_PUERTA - CANT_LLAVE;
        tope_paredes = (*ref_juego).niveles[i_juego].tope_paredes;
        tope_pared_obstaculo = tope_paredes + CANT_OBS_NIVEL_2;
        generador_coord_no_iguales( coord_diferentes ,(&(*ref_tope_coord_dif)) , (*ref_juego).niveles , NIVEL_2 - 1, CANT_ESCALERA_NIVEL_2);  
        llenar_obstaculos((*ref_juego).niveles[i_juego].obstaculos ,CANT_OBS_NIVEL_2, tope_velas_pozo, CANT_VELAS_NIVEL_2,POS_INTERRUP_NV2, tope_paredes, coord_diferentes);
        llenar_herramientas((*ref_juego).niveles,CANT_ESCALERA_NIVEL_2,NIVEL_2-1 ,tope_escalera_moneda,POS_PUERTA_NV2,tope_pared_obstaculo ,coord_diferentes);
    }
    else if ((*ref_juego).niveles[i_juego].numero_nivel == NIVEL_3){
        (*ref_juego).niveles[i_juego].tope_obstaculos = CANT_OBS_NIVEL_3;
        (*ref_juego).niveles[i_juego].tope_herramientas = CANT_HERRA_NIVEL_3;
        tope_velas_pozo = CANT_VELAS_NIVEL_3 + CANT_POZOS_NIVEL_3;
        tope_escalera_moneda = CANT_HERRA_NIVEL_3 - CANT_PUERTA - CANT_LLAVE;
        tope_paredes = (*ref_juego).niveles[i_juego].tope_paredes;
        tope_pared_obstaculo = tope_paredes + CANT_OBS_NIVEL_3; 
        generador_coord_no_iguales( coord_diferentes ,(&(*ref_tope_coord_dif)) , (*ref_juego).niveles , NIVEL_3 - 1, CANT_ESCALERA_NIVEL_3);
        llenar_obstaculos((*ref_juego).niveles[i_juego].obstaculos ,CANT_OBS_NIVEL_3 ,tope_velas_pozo ,CANT_VELAS_NIVEL_3 ,POS_INTERRUP_NV3 ,tope_paredes ,coord_diferentes);
        llenar_herramientas((*ref_juego).niveles,CANT_ESCALERA_NIVEL_3 ,NIVEL_3-1 ,tope_escalera_moneda ,POS_PUERTA_NV3,tope_pared_obstaculo ,coord_diferentes);
    }  
}

void inicializar_juego(juego_t* juego){
    
    coordenada_t coord_diferentes_1[MAX_ELEMENTOS];
    coordenada_t coord_diferentes_2[MAX_ELEMENTOS];     //se crea solo uno para serlo mas generico;
    coordenada_t coord_diferentes_3[MAX_ELEMENTOS];
    
    int tope_coord_diferentes_1 = 0;
    int tope_coord_diferentes_2 = 0;
    int tope_coord_diferentes_3 = 0;

    (*juego).nivel_actual = NIVEL_1;
    (*juego).niveles[(*juego).nivel_actual-1].numero_nivel = NIVEL_1;
    (*juego).niveles[(*juego).nivel_actual].numero_nivel = NIVEL_2;
    (*juego).niveles[(*juego).nivel_actual+1].numero_nivel = NIVEL_3;
    
    if((*juego).nivel_actual == NIVEL_1){
        cargar_mapas();
    }
    
    obtener_mapa((*juego).niveles[(*juego).nivel_actual-1].paredes,&((*juego).niveles[(*juego).nivel_actual-1].tope_paredes));
    obtener_mapa((*juego).niveles[(*juego).nivel_actual].paredes,&((*juego).niveles[(*juego).nivel_actual].tope_paredes));
    obtener_mapa((*juego).niveles[(*juego).nivel_actual+1].paredes,&((*juego).niveles[(*juego).nivel_actual+1].tope_paredes));
        
    
    llenar_nivel((&(*juego)),(*juego).nivel_actual-1,coord_diferentes_1,&tope_coord_diferentes_1);
    llenar_nivel((&(*juego)),(*juego).nivel_actual,coord_diferentes_2,&tope_coord_diferentes_2);
    llenar_nivel((&(*juego)),(*juego).nivel_actual+1,coord_diferentes_3,&tope_coord_diferentes_3);    
    
    int posicion_mac = (*juego).niveles[(*juego).nivel_actual-1].tope_paredes + (*juego).niveles[(*juego).nivel_actual-1].tope_obstaculos + (*juego).niveles[(*juego).nivel_actual-1].tope_herramientas - CANT_ESCALERA_NIVEL_1;

    inicializar_personaje(&((*juego).personaje),coord_diferentes_1[posicion_mac]);
    inicializar_sombra(&((*juego).sombra),coord_diferentes_1[posicion_mac]);
    
}

int estado_nivel(juego_t juego){
    int nivel = ESTA_JUGANDO;
    if(juego.niveles[juego.nivel_actual-1].numero_nivel == NIVEL_1){
        int tope_herramientas = juego.niveles[juego.nivel_actual-1].tope_herramientas;
        coordenada_t bloo = juego.sombra.posicion;
        coordenada_t puerta = juego.niveles[juego.nivel_actual-1].herramientas[tope_herramientas - 1].coordenada;
        coordenada_t mac = juego.personaje.posicion;
        int vida_actual = juego.personaje.vida;
        bool bloo_vive = juego.sombra.esta_viva;
        if(abs(mac.fila-puerta.fila)+abs(mac.col-puerta.col) <= DISTANCIA_PUERTA && abs(bloo.fila-puerta.fila)+abs(bloo.col-puerta.col) <= DISTANCIA_PUERTA && vida_actual>0 && bloo_vive){
            nivel = ESTA_GANADO;
            return nivel;                             
        }
    }
    else if (juego.niveles[juego.nivel_actual-1].numero_nivel == NIVEL_2 || juego.niveles[juego.nivel_actual-1].numero_nivel == NIVEL_3 ){
        int tope_herramientas = juego.niveles[juego.nivel_actual-1].tope_herramientas;
        coordenada_t bloo = juego.sombra.posicion;
        coordenada_t puerta = juego.niveles[juego.nivel_actual-1].herramientas[tope_herramientas - 1].coordenada;
        coordenada_t mac = juego.personaje.posicion;
        int vida_actual = juego.personaje.vida;
        bool bloo_vive = juego.sombra.esta_viva;
        if(abs(mac.fila-puerta.fila)+abs(mac.col-puerta.col) <= DISTANCIA_PUERTA && abs(bloo.fila-puerta.fila)+abs(bloo.col-puerta.col) <= DISTANCIA_PUERTA && juego.personaje.tiene_llave && vida_actual>0 && bloo_vive ){
            nivel = ESTA_GANADO;
            return nivel;
        }
    }
    return nivel;            
}

int estado_juego(juego_t juego){
    
    int jugador = ESTA_JUGANDO;
    if( juego.personaje.vida == 0 ){
        jugador = ESTA_PERDIDO;
    }
    else if (juego.nivel_actual-1 < MAX_NIVELES && estado_nivel(juego) == ESTA_JUGANDO){
        jugador = ESTA_JUGANDO;
    }
    else if ( juego.nivel_actual == MAX_NIVELES && estado_nivel(juego) == ESTA_GANADO && juego.personaje.vida>0 && juego.sombra.esta_viva){
        jugador = ESTA_GANADO;
    }
    return jugador;
}

void realizar_jugada(juego_t* juego){
    char movimiento;
    printf("Mueve el personaje con W,A,S,D: ");
    scanf(" %c",&movimiento);
    pedir_movimiento(&movimiento);
    mover_personaje(&((*juego).personaje),&((*juego).sombra),movimiento,&((*juego)));
    int partida = estado_juego((*juego));
    int nivel = estado_nivel((*juego));
    if(nivel == ESTA_GANADO && partida == ESTA_JUGANDO){

        printf("HAS TERMINADO EL NIVEL '%i' AHORA PASAS AL NIVEL '%i'\n",(*juego).nivel_actual,(*juego).nivel_actual+1);
        (*juego).nivel_actual++;
        (*juego).personaje.interruptor_apretado = false;
        (*juego).personaje.tiene_llave = false;
        nueva_posicion_mac(&((*juego)),(*juego).nivel_actual-1);
    }
    if(nivel == ESTA_JUGANDO && partida == ESTA_JUGANDO){
        printf("La posicion ahora de Mac es: (%i,%i)\n",(*juego).personaje.posicion.fila,(*juego).personaje.posicion.col);
        printf("La posicion ahora de Bloo es: (%i,%i)\n",(*juego).sombra.posicion.fila,(*juego).sombra.posicion.col);
        printf("Puntos de Mac son: %i\n",(*juego).personaje.puntos);
        printf("Tope herramientas es : %i\n",(*juego).niveles[(*juego).nivel_actual-1].tope_herramientas);
        printf("Tope obstaculos es : %i\n",(*juego).niveles[(*juego).nivel_actual-1].tope_obstaculos);
        printf("Tope paredes es : %i\n",(*juego).niveles[(*juego).nivel_actual-1].tope_paredes);
        printf("Vida de Mac es: %i\n",(*juego).personaje.vida);
    }
        
    if(partida == ESTA_PERDIDO){
            printf("HAS PERDIDO :C\n");
    }
    else if(partida == ESTA_GANADO){
            printf("GANASTE EL JUEGO!!!!\n");
    }
}



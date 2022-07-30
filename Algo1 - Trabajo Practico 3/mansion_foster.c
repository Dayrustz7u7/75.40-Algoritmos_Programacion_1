#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "la_sombra_de_mac.h"
#include "utiles.h"
#include <time.h>

#define ESTA_JUGANDO 0
#define ESTA_PERDIDO -1
#define ESTA_GANADO 1
#define NIVEL_1 1
#define NIVEL_2 2
#define NIVEL_3 3
#define ERROR -1
#define CAMPOS 5
#define GANO " Si"
#define PERDIO " No"
#define CAMPOS_ELIMINACION 4
#define AGREGAR "agregar_partida"
#define ELIMINAR "eliminar_partida"
#define ORDENAR "ordenar_partidas"
#define CONFIGURAR "config_juego"
#define MAX_LETRAS 100
#define MAX_GANO 10
#define MAX_JUGADORES 100
#define FORMATO_LECTURA "%[^;];%i;%i;%i;%[^\n]\n"
#define FORMATO_ESCRITURA "%s;%i;%i;%i;%s\n"

/*
* Procedimiento que evaluara si los parametros dados por referencia de tipo int
* no excedan ni sean negativos; si lo son pedira nuevamente que ingrese un valor
* valido.
*/
void vida_nivel_valido(int* vida,int* nivel){
    while( (*vida) < 0 || (*vida) > 3 ){
        printf("No mienta!. Ingrese con que Vida se quedo: ");
        scanf("%i",&(*vida));
    }
    while( (*nivel) < 0 || (*nivel) > 3 ){
        printf("No mienta!. Ingrese correctamente el Nivel donde se quedo: ");
        scanf("%i",&(*nivel));
    }
}
/*
* Procedimiento que recibira partida_t por referencia
* y se encargara de llenar cada campo por medio de scanfs
*
*/
void ingreso_jugador(partida_t* jugador){
    char gano[MAX_GANO];
    printf("Ingrese Su Nombre: ");
    scanf("%s",(*jugador).jugador);
    printf("Ingrese el Nivel que llego: ");
    scanf("%i",&(*jugador).nivel_llegado);
    printf("Cuantos puntos obtuviste?: ");
    scanf("%i",&(*jugador).puntos);
    printf("Las vidas que te quedaron?: ");
    scanf("%i",&(*jugador).vidas_restantes);
    printf("Ganaste o Perdiste? Si/No: ");
    scanf("%s",gano);
    (*jugador).gano = strcmp(gano,PERDIO);
    vida_nivel_valido(&((*jugador).vidas_restantes),&((*jugador).nivel_llegado));
}
/*
* Ordena el vector de manera ascendente segun el campo ".jugador"
* ->el tope pasado por parametro no debe exceder al MAX_JUGADORES;
* ->ni ser negativo.
*/
void ordenar_nombres(partida_t partidas[MAX_JUGADORES], int tope){
    int minimo;
    partida_t partida_aux;
    for(int i = 0; i< tope -1; i++){
        minimo = i;
        for(int j = i+1; j<tope; j++){
            if(strcmp(partidas[j].jugador, partidas[minimo].jugador) < 0){
                minimo = j;
            }
        }
       partida_aux = partidas[i];
       partidas[i] = partidas[minimo];
       partidas[minimo] = partida_aux;
    }
}
/*
* Recibira por parametro dos archivos .csv abiertos
*-> El primero pasado por parametro debera estar abierto de modo lectura
*-> El segundo pasado por parametro deber estar abierto de modo escritura
* Escribira en partida_aux los datos que tenga en partida, de manera ordenada segun
* el nombre.
*/
void ordenar_partida(FILE* partida,FILE* partida_aux){
    partida_t jugadores[MAX_JUGADORES];
    int tope = 0;
    char gano[MAX_GANO];
    int leidos = fscanf(partida,FORMATO_LECTURA,jugadores[tope].jugador,&(jugadores[tope].nivel_llegado),&(jugadores[tope].puntos),&(jugadores[tope].vidas_restantes),gano);
    jugadores[tope].gano = strcmp(gano,PERDIO);
    while(leidos == CAMPOS){
        tope++;
        leidos = fscanf(partida,FORMATO_LECTURA,jugadores[tope].jugador,&(jugadores[tope].nivel_llegado),&(jugadores[tope].puntos),&(jugadores[tope].vidas_restantes),gano);
        jugadores[tope].gano = strcmp(gano,PERDIO);
    }
    ordenar_nombres(jugadores,tope);
    for(int i=0; i<tope;i++){
        if(jugadores[i].gano){
            strcpy(gano,GANO);
        }else{
            strcpy(gano,PERDIO);
        }
        fprintf(partida_aux,FORMATO_ESCRITURA,jugadores[i].jugador,jugadores[i].nivel_llegado,jugadores[i].puntos,jugadores[i].vidas_restantes,gano);
    }
}
/*
* Recibira por parametro dos archivos .csv abiertos y partida_t jugador a agregar
*-> El primero pasado por parametro debera estar abierto de modo lectura.
*-> El segundo pasado por parametro deber estar abierto de modo escritura.
*-> El parametro nuevo_jugador, debera de estar lleno todos sus campos.
*Agregara de manera ordenada segun el nombre del nuevo_jugador en el archivo_partida_aux.
*/
void agregar_jugador(FILE* partida,FILE* partida_aux,partida_t nuevo_jugador){
    bool insertado = false;
    partida_t vieja_partida;
    char gano[MAX_GANO];
    char nuevo_gano[MAX_GANO];
    int leidos = fscanf(partida,FORMATO_LECTURA,vieja_partida.jugador,&vieja_partida.nivel_llegado,&vieja_partida.puntos,&vieja_partida.vidas_restantes,gano);
    vieja_partida.gano = strcmp(gano,PERDIO);
    while(leidos == CAMPOS){
        if(strcmp(nuevo_jugador.jugador,vieja_partida.jugador) <= 0 && insertado == false){
            if(nuevo_jugador.gano){
                strcpy(nuevo_gano,GANO);
            }else{
                strcpy(nuevo_gano,PERDIO);
            }
            fprintf(partida_aux,FORMATO_ESCRITURA,nuevo_jugador.jugador,nuevo_jugador.nivel_llegado,nuevo_jugador.puntos,nuevo_jugador.vidas_restantes,nuevo_gano);
            insertado = true;
        }
        fprintf(partida_aux,FORMATO_ESCRITURA,vieja_partida.jugador,vieja_partida.nivel_llegado,vieja_partida.puntos,vieja_partida.vidas_restantes,gano);
        leidos = fscanf(partida,FORMATO_LECTURA,vieja_partida.jugador,&vieja_partida.nivel_llegado,&vieja_partida.puntos,&vieja_partida.vidas_restantes,gano);
    }
    if( insertado == false ){
        if(nuevo_jugador.gano){
            strcpy(nuevo_gano,GANO);
        }else{
            strcpy(nuevo_gano,PERDIO);
        }
        fprintf(partida_aux,FORMATO_ESCRITURA,nuevo_jugador.jugador,nuevo_jugador.nivel_llegado,nuevo_jugador.puntos,nuevo_jugador.vidas_restantes,nuevo_gano);
    }
}
/*
* Recibira por parametro dos archivos .csv abiertos y un vector str (el nombre);
*-> El primero pasado por parametro debera estar abierto de modo lectura.
*-> El segundo pasado por parametro deber estar abierto de modo escritura.
*-> El vector string no debe superar el MAX_NOMBRE.
* Procedimiento que eliminara del archivo la partida del jugador dado por noombre en el parametro str;
* solo si se encuentra el jugadro en el archivo.
*/
void eliminar_partida(FILE* partida,FILE* partida_aux,char jugador[MAX_NOMBRE]){
    bool elimino = false;
    partida_t vieja_partida;
    char gano[MAX_GANO];
    int leidos = fscanf(partida,FORMATO_LECTURA,vieja_partida.jugador,&vieja_partida.nivel_llegado,&vieja_partida.puntos,&vieja_partida.vidas_restantes,gano); 
    while ( leidos == CAMPOS){
        if( (strcmp(vieja_partida.jugador,jugador)!= 0) || (strcmp(vieja_partida.jugador,jugador) == 0 && elimino)){
            fprintf(partida_aux,FORMATO_ESCRITURA,vieja_partida.jugador,vieja_partida.nivel_llegado,vieja_partida.puntos,vieja_partida.vidas_restantes,gano);
        }else{
            elimino = true;
        }
        leidos = fscanf(partida,FORMATO_LECTURA,vieja_partida.jugador,&vieja_partida.nivel_llegado,&vieja_partida.puntos,&vieja_partida.vidas_restantes,gano);
    }
    if( elimino == false){
        printf("No se encontro el jugador %s\n",jugador);
    }
}
/*
* Procedimiento que se encargara de comparar el vector string del parametro con el elemento 
* y asignara al campo de vector juego de acuerdo al nivel pasado por parametro,
* la cantidad dependiendo de la comparacion.
* ->La cantidad no debe ser negativo.
* ->El nivel no debe ser mayor al MAX_NIVELES ni ser negativo
*/
void asignar_cantidades(char elementos[MAX_LETRAS],int cantidad,config_t juego[MAX_NIVELES],int nivel){
    if(strcmp(elementos,"POZOS") == 0){
        juego[nivel].pozos = cantidad;
    }
    else if(strcmp(elementos,"VELAS") == 0){
        juego[nivel].velas = cantidad;
    }
    else if(strcmp(elementos,"INTERRUPTORES") == 0){
        juego[nivel].interruptores = cantidad;
    }
    else if(strcmp(elementos,"PORTALES") == 0){
        juego[nivel].portales = cantidad;
    }
    else if(strcmp(elementos,"MONEDAS") == 0){
        juego[nivel].monedas = cantidad;
    }
    else if(strcmp(elementos,"ESCALERAS") == 0){
        juego[nivel].escaleras = cantidad;
    }
    else if(strcmp(elementos,"LLAVES") == 0){
        juego[nivel].llaves = cantidad;
    }
}
/*
* Recibira dos vectores strings, cantidad y vector config_t
* Se encarga de comparar el vector NIVEL y llamar a asiganar_catidades
* segun el nivel que sea igual.
* -> Cantidad no debe ser negativo.
*/
void asignar_por_nivel(char nivel[MAX_LETRAS],char elementos[MAX_LETRAS],int cantidad,config_t juego[MAX_NIVELES]){
    if(strcmp(nivel,"N1") == 0 ){
        asignar_cantidades(elementos,cantidad,juego,NIVEL_1 - 1);
    }
    else if (strcmp(nivel,"N2") == 0){
        asignar_cantidades(elementos,cantidad,juego,NIVEL_2 - 1);
    }
    else if(strcmp(nivel,"N3") == 0){
        asignar_cantidades(elementos,cantidad,juego,NIVEL_3 - 1);
    }
}
/*
* Procedimiento que recibira un archivo ".txt" y un vector config_t
* Se encargara de asignar cada campo del vector config_t segun lo que lea 
* del archivo pasado por parametro
* -> el archivo ".txt" debe estar abiero en modo lectura y tener contenido completo 
* con respecto a los elementos de cada nivel.Con el formato correspondido.
*/
void configurar_partida(FILE* partida,config_t juego[MAX_NIVELES]){
    char linea[100];
    char* nivel;
    char* elemento;
    int cantidad;
    int leidos = fscanf(partida,"%s\n",linea);
    while(leidos == 1){
        nivel = strtok(linea,"_");
        elemento = strtok(NULL,"=");
        cantidad = atoi(strtok(NULL,"\0"));
        asignar_por_nivel(nivel,elemento,cantidad,juego);
        leidos = fscanf(partida,"%s\n",linea);
    }

}
/*
* Se encarga de llenar cada campo del vector config_t pasado por parametro
* con cantidades tomadas como constantes por default  de acuerdo al NIVEL.
*/
void configurar_partida_default(config_t juego[MAX_NIVELES]){
    int i = NIVEL_1 - 1;
    while(i < MAX_NIVELES){
        if( i ==  NIVEL_1 - 1 ){
            juego[i].pozos= N1_POZOS_DEFAULT;
            juego[i].velas = N1_VELAS_DEFAULT;
            juego[i].interruptores = N1_INTERRUPTORES_DEFAULT;
            juego[i].portales = N1_PORTALES_DEFAULT;
            juego[i].escaleras = N1_ESCALERAS_DEFAULT;
            juego[i].monedas = N1_MONEDAS_DEFAULT;
            juego[i].llaves = N1_LLAVES_DEFAULT;
        }
        else if ( i == NIVEL_2 - 1){
            juego[i].pozos= N2_POZOS_DEFAULT;
            juego[i].velas = N2_VELAS_DEFAULT;
            juego[i].interruptores = N2_INTERRUPTORES_DEFAULT;
            juego[i].portales = N2_PORTALES_DEFAULT;
            juego[i].escaleras = N2_ESCALERAS_DEFAULT;
            juego[i].monedas = N2_MONEDAS_DEFAULT;
            juego[i].llaves = N2_LLAVES_DEFAULT;   
        }
        else if ( i == NIVEL_3 - 1){
            juego[i].pozos= N3_POZOS_DEFAULT;
            juego[i].velas = N3_VELAS_DEFAULT;
            juego[i].interruptores = N3_INTERRUPTORES_DEFAULT;
            juego[i].portales = N3_PORTALES_DEFAULT;
            juego[i].escaleras = N3_ESCALERAS_DEFAULT;
            juego[i].monedas = N3_MONEDAS_DEFAULT;
            juego[i].llaves = N3_LLAVES_DEFAULT;   
        }
        i++; 
    }
}
/*
* Procedimiento dara inicio al juego y evaluara si este perdio o gano
* -> El vector configuraciones debera tener todos sus campos llenos 
* -> Hasta MAX_NIVELES.
*/
void iniciar_juego(juego_t juego,config_t configuraciones[MAX_NIVELES]){
    
    inicializar_juego(&juego,configuraciones);
    int partida = estado_juego(juego);
    while(partida == ESTA_JUGANDO ){
        imprimir_terreno(juego);
        realizar_jugada(&juego);
        partida = estado_juego(juego);
    }  
    printf("SE TERMINO EL JUEGO\n");
}

int main(int argc,char* argv[]){
    
    srand (( unsigned)time(NULL)); 
    
    if(argc >= 3){
        FILE* partida = fopen(argv[2],"r");
        if(!partida){
              perror("No se pudo abrir el archivo");
              return ERROR;
        }
        FILE* partida_aux = fopen("partida_aux.csv","w");
        if(!partida_aux){
              perror("No pudo abrir el archivo partida_aux");
              fclose(partida);
              return ERROR;
        }
        if(strcmp(argv[1],AGREGAR) == 0 ){
              partida_t jugador;
              ingreso_jugador(&(jugador));
              agregar_jugador(partida,partida_aux,jugador);          
        }
        else if (strcmp(argv[1],ELIMINAR) == 0){
              if(argc == CAMPOS_ELIMINACION){
                   eliminar_partida(partida,partida_aux,argv[3]);
              }else{
                   printf("No llenastes correctamente los campos\n");
              }
        }
        else if (strcmp(argv[1],ORDENAR) == 0){
              ordenar_partida(partida,partida_aux);
        }
        rename("partida_aux.csv",argv[2]);
        fclose(partida);
        fclose(partida_aux);
    }    
    if (strcmp(argv[1],CONFIGURAR) == 0){
        juego_t partida;
        config_t configuraciones[MAX_NIVELES];
        FILE* config = fopen("config.txt","r");
        if(!config){
            perror("No existe el archivo, se jugara con la configuracion predeterminada");
            configurar_partida_default(configuraciones);
            iniciar_juego(partida,configuraciones);
            return ERROR;
        }
        configurar_partida(config,configuraciones);
        iniciar_juego(partida,configuraciones);
        fclose(config);
    }    
    return 0;
}
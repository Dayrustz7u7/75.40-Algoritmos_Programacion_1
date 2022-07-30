/* 
ENUNCIADO DEL EJERCICIO:
-------------------------------------------------------------------------------------------------------------------------
Después de haber elegido el lugar y la fecha donde vacacionar, Tom, Jerry y Spike están haciendo las últimas compras 
necesarias para viajar. Su idea es gastar lo menos posible, para que les quede mucha plata para llevar y gastarla en el 
lugar.

Implementar un procedimiento que calcule el precio total que tienen que gastar, y lo escriba en el campo precio_total del
registro de lista de compras.
Lista de precios disponible:

Chocolate: 50.
Caramelos: 10.
Gaseosa: 70.
Pelota de playa: 120.
Ejemplo:

Si nos vienen las siguientes cantidades en nuestra lista:

Chocolates: 5.
Caramelos: 0.
Gaseosa: 1.
Pelota de playa: 1.
Al final de nuestra función el campo precio_total debería ser 440.
-------------------------------------------------------------------------------------------------------------------------
*/

// RESOLUCION 
#include <stdio.h>
#include "solucion.h"
#define CHOCOLATE 50
#define CARAMELOS 10
#define GASEOSA 70
#define PELOTA 120

typedef struct lista_compras{
	int cantidad_chocolates;
	int cantidad_caramelos;
	int cantidad_gaseosas;
	int cantidad_pelotas_playa;
	int precio_total;
}lista_compras_t;

void calcular_precio_total(lista_compras_t* lista_compras){
    (*lista_compras).precio_total = 0;
    int precio_chocolates = CHOCOLATE*(*lista_compras).cantidad_chocolates;
    int precio_caramelos = CARAMELOS*(*lista_compras).cantidad_caramelos;
    int precio_gaseosas = GASEOSA*(*lista_compras).cantidad_gaseosas;
    int precio_pelotas = PELOTA*(*lista_compras).cantidad_pelotas_playa;
	(*lista_compras).precio_total += precio_chocolates + precio_caramelos + precio_gaseosas + precio_pelotas;
}
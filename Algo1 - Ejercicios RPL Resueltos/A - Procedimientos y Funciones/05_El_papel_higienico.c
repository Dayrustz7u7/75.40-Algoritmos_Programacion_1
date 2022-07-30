/* 
ENUNCIADO DEL EJERCICIO:
-------------------------------------------------------------------------------------------------------------------------
En la mansión Foster algún amigo imaginario problemático ha estado dando vuelta el papel higiénico, algo inadmisible 
para el Señor Conejo. Es por esto que estuvo todo el día verificando cada baño para poner los papeles higiénicos en la 
orientación que corresponde.
Después de 5 horas de estar saltando de baño en baño, el Señor Conejo ya está muy cansado, y además 
necesita hacerse cargo de otras cosas en la mansión. Así que nos pidió ayuda:

Implementar un procedimiento que dado por parámetro la orientación del papel higiénico, cambie ésta misma a la 
posición correcta si es que no lo está. Las posiciones pueden ser:

La correcta: al frente (F).
La incorrecta: al reverso (R).

Pensá cómo debería pasarse y recibir el parámetro de la posición al procedimiento corregir_posicion_papel_higienico 
para que el cambio que hagas en este se pueda ver “por fuera” cuando termine de ejecutarse el procedimiento.
-------------------------------------------------------------------------------------------------------------------------
*/

// RESOLUCION 
#include <stdio.h>
const char CORRECTA = 'F';
const char INCORRECTA = 'R';

void corregir_posicion_papel_higienico(char* ref_posicion) {
    if (*ref_posicion == INCORRECTA) {
        (*ref_posicion) = CORRECTA;
    }
}
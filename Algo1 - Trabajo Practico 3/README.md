# TP Tercera Parte: La Sombra de Mac 👾​🕹️​
## 1) Introduccion 📑​
   **Mac** es un niño de ocho años con gran inteligencia y creatividad. Él es una persona sensata y moral, y puede ser
   a través de Bloo, su amigo imaginario, que hace y dice todas las cosas que quiere pero no puede. Por lo tanto, Bloo
   existe como un desafío a la moralidad de Mac. Pasa una gran porción de sus días involucrándose en sus travesuras
   dentro y fuera de Foster’s. La Mansión Foster para amigos imaginarios es un inmenso orfanato con estilo victoriano
   al que los amigos imaginarios se van a vivir cuando ya no pueden pertenecerle a sus creadores. Ahí se muda Bloo, y
   Mac lo visita todos los días para asegurarse de que Bloo no sea adoptado.
   
   **Bloo** es el amigo imaginario de Mac, a menudo egoísta, rebelde, inquieto, arrogante o en busca de atención. No
   obstante, puede cambiar su actitud en lealtad a su creador. Su cuerpo humanoide completamente azul es comparable
   a la de un guante de cocina o un fantasma del videojuego Pac-Man. A menudo, tiene una tendencia a aceptar ideas
   escandalosas como un hecho para explicar sucesos aparentemente mundanos, y somete a otros a su voluntad, yendo
   tan lejos como para hacerlos ir en contra de sus estándares morales. Bloo también muestra pasión por la pelota de
   pádel, aunque nunca logra hacer que la pelota golpee la paleta, a lo que insiste en que todas sus paletas están rotas.
   
## 2) Objetivo 🎯​
   El presente trabajo práctico tiene como objetivo evaluar a los alumnos en aspectos fundamentales de la programación.
   Estos aspectos son:
   - Validación de datos ingresados por el usuario.
   - Diseño y desarrollo de funcionalidades de una biblioteca con un contrato preestablecido.
   - El correcto uso de estructuras de control.
   - Tipos de dato simples y estructurados.
   - Buenas prácticas de programación.
   - Modularización.
   - Manejo de archivos en C.
   - Línea de comandos.
## 3) Enunciado 📂​
   Ya ayudamos a Mac y a Bloo a volver de la mansión luego de haber pasado una tarde explorando la ciudad.
   Pero, ahora desde La Mansión Foster, debido a que recibieron mucha ayuda, nos piden empezar a llevar registro
   de todas las partidas que se fueron jugando, y así recompensar a quienes más hayan ayudado para que ellos puedan
   volver a la mansión. Para esto se usará una estructura del tipo partida_t, la cual se especificará más adelante.
   
   Podrás ayudarlos una vez más?
   - ## **3.1) Obstáculos** 🧱​
        Los obstáculos son elementos que estarán en cualquier posición del mapa e intentarán matar o distraer a los
        personajes.
        
        - **🕯️​ Velas:** Dejarán sin vida a la sombra, dejándola inmóvil, por lo que el personaje deberá ir a apagar la vela, y luego
               revivir a Bloo. El rango de su efecto será de una matriz de 3x3, ubicandose la vela en el centro. Descontarán
               50 puntos al personaje, cada vez que este la reviva.
        
        - **🕳️ Pozos:** Quitarán una vida al personaje en caso de que éste pise uno. Al morir, ambos personajes vuelven a
               iniciar de 0, es decir, Mac en una coordenada random, y Bloo en una posición dependiente del personaje.
               
        - **🖲️ Interruptor:** Si Mac pisa un interruptor, lo activará e intercambiará la forma en que se mueve su sombra. Si
               interruptor_apretado es false, Bloo caminará en sentido espejo. En caso contrario, si es true, caminará en el
               mismo sentido.
               
        - **🌌 Portales:** Si Bloo pisa un portal, las posiciones de los personajes serán intercambiadas, por lo que Bloo quedará
               en la posición de Mac, y Mac en la de Bloo.
               
        Todos los obstáculos empezarán en posiciones aleatorias. Cabe destacar que no pueden posicionarse distintos
        obstáculos en la misma posición que otro objeto, o personaje.
        El orden de posicionamiento de los obstáculos al inicializar el nivel es indiferente, siempre y cuando se respete lo
        enunciado en el párrafo anterior.
        Cuando Mac apague una vela, se requiere que la vela sea eliminada del vector y no se muestre más en el terreno.
   - ## **3.2) Herramientas 🛠️**
        Las herramientas son elementos que ayudarán a Mac y a Bloo a volver a la mansión.
        
        - **📐​ Escaleras:** Se posicionarán sobre las paredes. Tienen un solo uso, por lo que al usarla deberá desaparecer y
               poner una pared en su lugar. Permitirán a los personajes saltarse una posición.
               
        - **💲​ Monedas:** Al agarrar una moneda, le dará puntos al personaje. Los puntos seran un número aleatorio entre 10
               y 20, ambos inclusive.
               
        - **❤️ Vidas:** El personaje puede elegir intercambiar 200 puntos por una vida al apretar la letra ’V’. Como máximo,
               el personaje puede contar con 3 vidas al mismo tiempo.
  
        - **🔑 Llave:** Sólo puede ser agarrada por Mac. Le permitirá a ambos personajes terminar el nivel, al pasar por la
               puerta de la mansión.
        
        El hecho de agarrar cualquiera de estos objetos, con excepción de las vidas, está dado por pararse en la posición
        en la que se encuentra la herramienta.
        Las herramientas deben posicionarse aleatoriamente al inicializar el juego, cabe destacar que no pueden posicionarse
        distintas herramientas en la misma posición o en una posición donde ya existe un obstáculo, o la posición de
        uno de los dos personajes.
        El orden de posicionamiento de las herramientas al inicializar el juego es indiferente, siempre y cuando se respete
        lo enunciado en el párrafo anterior.
        El agarrar una moneda o una llave, o el uso de la escalera, requerirá que se elimine del vector de herramientas.
        
   - ## **3.3) Niveles** 🎰​
        Habrá 3 niveles a lo largo de todo el juego. Para pasar cada uno, Mac deberá contar con la llave y ambos
        personajes deberán estar a una distancia manhattan menor a uno, de la puerta. En cada nivel habrá distinta cantidad
        de herramientas y obstáculos.
        
        ### **Nivel 1** 🟢
        - **Cantidad obstáculos:**
           - **🕯️​ Velas:** 5
           - **🕳️ Pozos:** 15
           - **🖲️ Interruptores:** 1
           - **🌌 Portales:** 0
        - **Cantidad herramientas:**
          - **📐​ Escaleras:** 10
          - **💲​ Monedas:** 10
          - **🔑 Llave:** 0
        ### **Nivel 2** 🟡
        - **Cantidad obstáculos:**
          - **🕯️​ Velas:** 10
          - **🕳️ Pozos:** 20
          - **🖲️ Interruptores:** 2
          - **🌌 Portales:** 2
        - **Cantidad herramientas:**
          - **📐​ Escaleras:** 15
          - **💲​ Monedas:** 15
          - **🔑 Llave:** 1
        ### **Nivel 3** 🔴​
        - **Cantidad obstáculos:**
          - **🕯️​ Velas:** 12
          - **🕳️ Pozos:** 30
          - **🖲️ Interruptores:** 4
          - **🌌 Portales:** 4
        - **Cantidad herramientas:**
          - **📐​ Escaleras:** 15
          - **💲​ Monedas:** 15
          - **🔑 Llave:** 1
               
## 4) Especificaciones ​📖
   Nos manejaremos con una única estructura, partida_t, la cual es:
   - ## **4.1) Estructuras**
        Nos manejaremos con una única estructura, partida_t, la cual es:
        ```c
        #include <stdbool.h>
2
3 #define MAX_NOMBRE 100
4
5 typedef struct partida {
6 char jugador[MAX_NOMBRE];
7 int nivel_llegado;
8 int puntos;
9 int vidas restantes;
10 bool gano;
11 } partida_t;
        ```
        **Observación:** Queda a critero del alumno/a el hacer o no, más funciones y/o procedimientos para resolver los
           problemas presentados. No se permite agregar dichas firmas al .h. Algunas funciones y procedimientos, ya no se
           encuetran más en la_sombra_de_mac.h debido a que ahora pasarán a ser privadas.
   - ## **4.2) Convenciones** 📝​
        Se deberá utilizar la siguiente convención para los obstáculos y herramientas:
        
        - 🚪 Puerta: **D**.
        - ​📐​Escaleras: **E**.
        - 🔑 Llave: **L**.
        - 💲​ Monedas: **C**.
        - 🕳️ Pozos: **W**.
        - 🖲️ Interruptores: **O**.
        - 🌌 Portales: **P**.
        - 🕯️ Velas: **V**.
        
        Y para los personajes:
        
        - 🧍‍♂️​ Mac: **M**.
        - 👻 Bloo: **B**.
   
## 5) Resultado Esperado 📊
   Se espera que el trabajo creado cumpla con las buenas prácticas de programación y todas las funciones y procedimientos
   pedidos funcionen acorde a lo solicitado, respetando las pre y post condiciones propuestas.

## 6) Compilacion y Entrega 👨‍💻
   El trabajo práctico debe ser realizado en un archivo llamado la_sombra_de_mac.c, lo que sería la implementación
   de la biblioteca la_sombra_de_mac.h. El objetivo es que sea compilado sin errores al correr desde la terminal el
   comando:
   ```c
   1 gcc *.c -o mansion_foster -std=c99 -Wall -Wconversion -Werror -lm
   ```
   Utiles.o es un archivo compilado realizado por la cátedra, que pondrá a su disposición funciones que pueden ser,
   justamente, útiles y su funcionamiento se explica en el anexo.
   
   Por último debe ser entregado en la plataforma de corrección de trabajos prácticos Chanutron2021 (patente
   pendiente), en la cual deberá tener la etiqueta ¡Exito! significando que ha pasado las pruebas a las que la cátedra
   someterá al trabajo.
   
   Para la entrega en Chanutron2021 (patente pendiente), recuerde que deberá subir un archivo zip que contenga
   únicamente los archivos antes mencionados, sin carpetas internas ni otros archivos. De lo contrario, la entrega no
   será validada por la plataforma.
   
   **IMPORTANTE!** Obtener la etiqueta ¡Exito! en Chanutron2021 (patente pendiente) no implica necesariamente
   haber aprobado el trabajo. El trabajo será corregido por un colaborador que verificará que se cumplan las buenas
   prácticas de programación.

## 7) Anexos
   - ## **7.1) Argumentos por línea de comando** 🎲​
        Para poder pasar parámetros a un programa a través de la línea de comandos nos valemos de la siguiente
        declaración de la función main:
        ```c
        int main(int argc , char *argv[]){..
        ```
        **Argc** contiene la cantidad de argumentos recibidos por el programa, debemos considerar que siempre será el número
        de argumentos pasados más 1, ya que el primer argumento se reserva para contener el nombre del programa. **Argv**
        es un vector de strings que contiene los parámetros pasados en el mismo orden en que fueron escritos.
        
        El siguiente programa muestra un ejemplo de cómo hacer uso de estos parámetros:
        ```c
          #include <stdio.h>
          #include <string.h>
          #include <stdlib.h>
         
          int main(int argc , char *argv[]){
         
                  printf ("El programa recibió %i argumentos\n", argc);
                  for(int i = 0; i < argc; i++) {
                          printf("Parámetro %d: %s\n", i, argv[i]);
                  }
         
                  if (strcmp (argv[1], "saludar") == 0){
                          printf ("Hola!\n");
                  } else if (strcmp (argv[1], "sumar") == 0 && argc == 4){
                          int sumando_1 = atoi (argv [2]); // convierte el argumento argv[2] de string a numero
                          int sumando_2 = atoi (argv [3]);
                          printf (" %i + %i = %i\n", sumando_1 , sumando_2 , sumando_1 + sumando_2);
                  }
          return 0;
          }
        ```
        

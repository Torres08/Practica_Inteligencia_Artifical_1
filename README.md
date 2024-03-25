## Practica Inteligencia Artificial 1

## Procedimiento para el Movimiento del Agente Reactivo

En este redme, se describe el procedimiento seguido para definir el movimiento del agente reactivo, junto con una explicación detallada de las variables más importantes y las funciones requeridas.

### 1. Variables

- `fil (int):` Corresponde a la fila de la posición del agente.
- `col (int):` Corresponde a la columna de la posición del agente.
- `brújula (int):` Indica la dirección en la que está mirando el agente (norte: 0, este: 1, sur: 2, oeste: 3).
- `ultimaAccion (action):` Devuelve la última acción realizada por el agente.
- `bien_situado (boolean):` Indica si el agente puede escribir en el mapa.
- `modo_aleatorio (boolean):` Indica si el agente está en modo aleatorio.
- `modo_busqueda (boolean):` Indica si el agente está en modo de búsqueda.
- `girar_derecha (boolean):` Indica si el agente debe girar a la derecha.
- `bikini (boolean):` Indica si el agente está en la casilla de bikini.
- `zapatillas (boolean):` Indica si el agente está en la casilla de zapatillas.
- `recarga (boolean):` Indica si el agente está en la casilla de recarga.
- `comienzo (boolean):` Indica si es el inicio del juego.
- `posicionamiento (int):` Guarda la posición cuando se encuentra una casilla especial.
- `contador (int):` Contador que habilita bikini y zapatillas cuando llega a cero.

### 2. Procedimiento

Para definir el movimiento del agente, se sigue el siguiente procedimiento:

- `Actualizar Mapa:` Esta función registra las zonas de terreno que ve el agente según su rango de visión.
- `Sensor VistaNivel:` Determina si el agente puede escribir en el mapa según el nivel y la posición.
- `MoverAleatorio:` Define el movimiento aleatorio del agente, incluyendo la gestión de recarga, la evaluación de los sensores y el giro.
- `Mover_Busqueda:` Implementa el movimiento del agente hacia una casilla especial cuando está en modo de búsqueda.

3. Resumen

Belkan, el agente, comienza moviéndose aleatoriamente y busca las casillas especiales. Si encuentra una, cambia al modo de búsqueda y se dirige hacia ella. Una vez completada la búsqueda, vuelve al modo aleatorio. Si un lobo lo come, se reinician sus variables y se coloca en una nueva posición. Cuando la batería está baja, Belkan gira con mayor frecuencia. Además, se habilitan las habilidades de bikini y zapatillas si Belkan queda atascado sin hacer nada.

Este procedimiento asegura que Belkan se mueva de manera efectiva y responda adecuadamente a diferentes situaciones en el juego.
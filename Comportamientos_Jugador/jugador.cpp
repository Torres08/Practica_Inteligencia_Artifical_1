#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
using namespace std;

Action ComportamientoJugador::think(Sensores sensores) {

  Action accion = actIDLE;
  // brujula= sensores.sentido;
  cout << "Posicion: fila " << sensores.posF << " columna " << sensores.posC
       << " ";
  switch (sensores.sentido) {
  case 0:
    cout << "Norte" << endl;
    break;
  case 1:
    cout << "Este" << endl;
    break;
  case 2:
    cout << "Sur " << endl;
    break;
  case 3:
    cout << "Oeste" << endl;
    break;
  }
  cout << "Terreno: ";
  for (int i = 0; i < sensores.terreno.size(); i++)
    cout << sensores.terreno[i];
  cout << endl;

  cout << "Superficie: ";
  for (int i = 0; i < sensores.superficie.size(); i++)
    cout << sensores.superficie[i];
  cout << endl;

  cout << "Colisión: " << sensores.colision << endl;
  cout << "Reset: " << sensores.reset << endl;
  cout << "Vida: " << sensores.vida << endl;
  cout << "Bikini: " << bikini << endl;
  cout << "Zapatillas: " << zapatillas << endl;
  cout << "Recarga: " << recarga << endl;
  cout << "Nivel: " << nivel << endl;
  cout << "Tiempo Recarga: " << tiempo_recarga << endl;
  cout << "Pasos Giro: " << pasos << endl;
  cout << "Ahorro bateria: " << modo_bajabateria << endl;
  cout << endl;

  // Metodo think
  switch (ultimaAccion) {
  case actFORWARD:
    switch (brujula) {
    case 0:
      fil--;
      break;
    case 1:
      col++;
      break;
    case 2:
      fil++;
      break;
    case 3:
      col--;
      break;
    }
    break;

  case actTURN_L:
    brujula = (brujula + 3) % 4;
    // girar_derecha = (rand() % 2 == 0);
    break;

  case actTURN_R:
    brujula = (brujula + 1) % 4;
    // girar_derecha = (rand() % 2 == 0);
    break;
  }

  /*

  //if (sensores.terreno[0] == 'G' and !bien_situado) {
    fil = sensores.posF;
    col = sensores.posC;
    brujula= sensores.sentido;
    //bien_situado = true;
  //}


   if (bien_situado){
                ActualizarMapa(sensores);
      //mapaResultado[fil][col]=sensores.terreno[0];
   }

  // Decidir la nueva accion

  if (Avanzar(sensores)){
    accion = actFORWARD;
  } else {
   accion= Girar(sensores);
   //brujula= sensores.sentido;
  }

  // compruebo si he pasado por una casilla de bikini o de zapatillas
  // Compruebo casilla especial

  CasillaEspecial(sensores);

  if (sensores.terreno[2] == 'K')
    bikini = true;

  if (sensores.terreno[2] == 'D')
    zapatillas = true;

  if (sensores.terreno[2] == 'X')
    recarga = true;
bien_situado=true;
  */

  /*
   if (Avanzar(sensores)){
     accion = actFORWARD;
   } else {
    accion= Girar(sensores);
    //brujula= sensores.sentido;
   }
  */

  // dependiendo de la accion hago una cosa u otra
  








  if (bien_situado3)
  switch (sensores.nivel) {
  case 0:
    // accion = Comportamiento_nivel0(sensores, accion);
    accion = Prueba(sensores, accion);
    nivel = 0;
    break;
  case 1:
    nivel = 1;
    accion = Comportamiento_nivel1_2(sensores, accion);
    break;
  case 2:
    nivel = 2;
    accion = Comportamiento_nivel1_2(sensores, accion);
    break;
  case 3:
    nivel = 3;
    accion = Comportamiento_nivel1_2(sensores, accion);
    break;

  case 4:
    nivel = 4;
    //accion = Comportamiento_nivel1_2(sensores, accion);
    accion = Prueba(sensores, accion);
    break;

  default:
    accion = Comportamiento_nivel0(sensores, accion);
    nivel = 0;
    break;

    /*
    default:
        Comportamiento_nivel0(sensores, accion);
      break;
      */
  }

  // TENGO QUE BUSCAR UNA FORMA QUE VAYA A LA CASILLA AZUL

  /*
    If(Avanzar(sensores)){
      accion = actFORWARD;
    else {
        Giro(sensores);
    }
    }
  */

  /*
  if ((sensores.terreno[2] == 'T' or sensores.terreno[2] == 'S' or
       sensores.terreno[2] == 'G') and
      sensores.superficie[2] == '_') {
    accion = actFORWARD;
  } else if (!girar_derecha) {
    accion = actTURN_L;
  } else {
    accion = actTURN_R;
  }
  */

  // reconoce la casilla G la azul deja un rastro de lo visto
  // cono de visualización

  // Recordar la ultima accion
 
  bien_situado3 = true;
  ultimaAccion = accion;
  return accion;

  // Determinar el efecto de la ultima accion enviada
  return accion;
}

int ComportamientoJugador::interact(Action accion, int valor) { return false; }

// Mis funciones

// Mientras que no sea un muro o un precipicio paso
/*
bool hayObstaculo(unsigned char casilla) {
  if (casilla == 'P' or casilla == 'M') {
    return true;
  } else {
    return false;
  }
}
*/

// Cono, actualizo el mapa
/*
        norte 0
        Este 1
        sur 2
        oeste 3

        guardamos toda la informacion de los sensores de terreno
        desde 0 hasta 15 en mapaResultado

*/

// ---------------------------------------------------------------------------------------------------------------------------------------------

/*
  Niveles de Profundidad
*/

/*
  Nivel 0: El sistema sensorial funciona correctamente y en todo
  momento el agente conoce su posicion y su orientacion a traves
  de los sensores correspondientes
*/

Action ComportamientoJugador::Prueba(Sensores sensores, Action accion) {
  fil = sensores.posF;
  col = sensores.posC;
  brujula = sensores.sentido;

  if (bien_situado2)
    ActualizarMapa(sensores);

  if (sensores.terreno[0] == 'G' and !bien_situado2) {
    fil = sensores.posF; // sensores devuelven -1
    col = sensores.posC;
    // ActualizarMapa(sensores);
    bien_situado2 = true;
  }

  // 1º buscamos

  if (!casilla_azul_encontrada) {
    for (int i = 0; i < 15; i++)
      if (sensores.terreno[i] == 'G') {
        // Hay_casilla = true;
        x = i;
        //inicioc = col;
        //iniciof = fil;
        modo_busqueda = true;
        modo_aleatorio = false;
        terminado5 = false;
        casilla_azul_encontrada = true;
        
      } 
  } else if (!zapatillas_encontradas){
    for (int i = 0; i < 15; i++)
      if (sensores.terreno[i] == 'D'){
        x = i;
        modo_busqueda = true;
        modo_aleatorio = false;
        zapatillas_encontradas = true;
        terminado5 = false;
      }
  } else if (!bikini_encontrado){
    for (int i = 0; i < 15; i++)
      if (sensores.terreno[i] == 'K'){
        x = i;
        modo_busqueda = true;
        modo_aleatorio = false;
        bikini_encontrado = true;
        terminado5 = false;
      }
  } else if (!cargador_encontrado){
    for (int i = 0; i < 15; i++)
      if (sensores.terreno[i] == 'X'){
        x = i;
        modo_busqueda = true;
        modo_aleatorio = false;
        cargador_encontrado = true;
        terminado5 = false;
      }
  }
  

  cout << "Cual es: " << x << endl;
  cout << "Modo Busqueda: " << modo_busqueda << endl;
  cout << "Modo Aleatorio: " << modo_aleatorio << endl;
  //cout << "Modo Cambio: " << modo_cambio << endl;

  if (modo_busqueda ) {
    
    accion = Mover_Dirigido_v2(x);
    //accion = actFORWARD;

  } else if (modo_aleatorio) { // modo aleatorio

    accion= Mover_Aleatorio(sensores);
  } 

  if (sensores.terreno[0] == 'G'){
     
      modo_busqueda = false;
      modo_aleatorio = true;
      inicializamos2 = true;
      
  } else if (sensores.terreno[0] == 'D'){

      modo_busqueda = false;
      modo_aleatorio = true;
      inicializamos2 = true;      
  } else if (sensores.terreno[0] == 'K'){
      modo_busqueda = false;
      modo_aleatorio = true;
      inicializamos2 = true; 
  } else if (sensores.terreno[0] == 'X'){
      modo_busqueda = false;
      modo_aleatorio = true;
      inicializamos2 = true; 
  }
  
  
  bien_situado3 = true;
  CasillaEspecial(sensores);
  return accion;
}

Action ComportamientoJugador::Comportamiento_nivel0(Sensores sensores,
                                                    Action accion) {

  fil = sensores.posF;
  col = sensores.posC;
  brujula = sensores.sentido;

  if (bien_situado) {
    ActualizarMapa(sensores);
  }
  // Decidir la nueva accion
  if (Avanzar(sensores)) {
    accion = actFORWARD;

  } else if (recarga) {
    cout << "Hola " << endl;
    accion = actIDLE; // paro 5 acciones
    Recargar();
    /*
    tiempo_recarga--;
    if (tiempo_recarga == 0){
      recarga = false;
      tiempo_recarga = 5;
    }
    */

  } else {
    accion = Girar(sensores);
  }

  bien_situado = true;
  CasillaEspecial(sensores);
  return accion;
}

/*
  Nivel 1:
  -no se conoce la posicion del agente, aunque si su orientacion
  -entonces posF y posC devuelven -1
  -Estos sensores devuelven valor correcto de fila y columna cuando el agente
  este en una casilla G "Posicionamiento"
  mapa no funciona bien
  TUTORIAL

  Nivel 2:Ahora tmp se conoce la orientacion

    -Sabemos que se empieza en el norte
    buscamos una casilla de posicionamiento para situarse correctamente
    en el mapa
    -sensor de orientacion siempre devuelve norte
    - usamos el nuestro propio

    2 TUTORIAL

*/

Action ComportamientoJugador::Comportamiento_nivel1_2(Sensores sensores,
                                                      Action accion) {

  brujula = sensores.sentido;

  if (bien_situado) {
    ActualizarMapa(sensores);
  }

  // volcado del mapa
  if (sensores.terreno[0] == 'G' and !bien_situado) {
    fil = sensores.posF; // sensores devuelven -1
    col = sensores.posC;
    // ActualizarMapa(sensores);
    bien_situado = true;
  }

  // Decidir la nueva accion
  if (Avanzar(sensores)) {
    accion = actFORWARD;
  } else if (recarga) {
    accion = actIDLE; // paro 5 acciones
  } else {
    accion = Girar(sensores);
  }

  CasillaEspecial(sensores);
  return accion;
}

/*
  Nivel 2:Ahora tmp se conoce la orientacion

    -Sabemos que se empieza en el norte
    buscamos una casilla de posicionamiento para situarse correctamente
    en el mapa
    -sensor de orientacion siempre devuelve norte
    - usamos el nuestro propio

    2 TUTORIAL
*/

/*
  Nivel 3:
    - Ahora aparecen aldeanos en la simulacion y obstaculizan
    al agente
*/

/*
  Nivel 4:
    - Aparecen lobos
    - colision con los lobos provoca reinicio del mapa
    es decir, aparece en una nueva casilla del mapa desconocida
    con orientacion al norte y si zapatillas ni bikini.
*/

// ---------------------------------------------------------------------------------------------------------------------------------------------
/*
  Funciones Auxiliares
*/

Action ComportamientoJugador::Mover_Aleatorio(Sensores sensores){
    Action accion = actIDLE;

    if (recarga){
      cout << "Hola " << endl;
      accion = actIDLE; // paro 5 acciones
      Recargar();

    } else if (Avanzar(sensores)) {
      
      accion = actFORWARD;

    }  else {
      accion = Girar(sensores);
    }

    return accion;
}

Action ComportamientoJugador::Mover_Dirigido_v2 (int x){
  // me muevo hacia un sensor, compruebo cuantas casillas y eso me tendre que mover
  Action accion = actIDLE;
  
  // calculo el numero de filas y columnas que me tendre que mover
  // fild y cold son 2 contadores que me dicen el numero de filas a mover
  if (inicializamos2){
    //int arriba = 0; // cuando termine arriba determinamos el giro
    //int lados = 0;
    // numero de filas a mover
    
        if ((x == 1 or x == 2 or x == 3)) {
          arriba = 1;
        } else if ((x == 4 || x == 5 || x == 6 || x == 7 || x == 8)) {
          arriba = 2;
        } else if (x == 0) {
          arriba = 0;
        } else {
          arriba = 3;
        }
        
   

    // Vemos que columna es
    if ((x == 9 || x == 15)) {
      lados = 3;
    } else if ((x == 4 || x == 10 || x == 14 || x == 8)) {
      lados = 2;
    } else if ((x == 2 || x == 6 || x == 12)) {
      lados = 0;
    } else {
      lados = 1;
    }

    inicializamos2 = false;
  }

  cout << "Arriba: " << arriba << endl;
  cout << "Lados: " << lados << endl;
  
  if (arriba != 0){
    accion = actFORWARD; 
    arriba--;
  } else if (arriba == 0 && !terminado5){
    if ((x == 9 || x == 10 || x == 11 || x == 4 || x == 5 || x == 1)){
         cout << "hola" << endl;
        accion = actTURN_L;
    } else if ((x == 13|| x == 14 || x == 15 || x == 7 || x == 8 || x == 3)){
        cout << "hola2" << endl;
        accion = actTURN_R;
    }

    terminado5 = true;
  }else if (lados != 0){
    accion = actFORWARD;
    lados--;
  }

  //cout << "\nModo busqueda v2 hacia el sensor " << x << endl;
  //cout << "Arriba: " << arriba << endl;
  //cout << "Lados: " << lados << endl;

  return accion;

}
bool ComportamientoJugador::Avanzar(Sensores sensores) {

  bool b1 = (sensores.terreno[2] == 'T' or sensores.terreno[2] == 'S' or
             sensores.terreno[2] == 'G' or sensores.terreno[2] == 'D' or
             sensores.terreno[2] == 'K' or sensores.terreno[2] == 'X');
  bool b2 = (sensores.superficie[2] == '_');
  bool condicion_zapatillas = (sensores.terreno[2] == 'B');
  bool condicion_bikini = (sensores.terreno[2] == 'A');

  if (zapatillas)
    b1 = b1 || condicion_zapatillas;

  if (bikini)
    b1 = b1 || condicion_bikini;

  return b1 && b2;
  // return ((sensores.terreno[2] == 'T' or sensores.terreno[2] == 'S' or
  // sensores.terreno[2] == 'G' or sensores.terreno[2] == 'D') &&
  // (sensores.superficie[2] == '_'));
}

/*
  Quiero añadir una variable de gro aleatorio
*/
Action ComportamientoJugador::Girar(Sensores sensores) {
  Action accion;

  if (!girar_derecha) {
    accion = actTURN_L;
    girar_derecha = (rand() % 2 == 0);
    // girar_derecha = (rand()%50) + 1;

  } else {
    accion = actTURN_R;
    girar_derecha = (rand() % 2 == 0);
    // girar_derecha = (rand()%50) + 1;
  }

  return accion;
}

void ComportamientoJugador::Recargar() {
  tiempo_recarga--;
  if (tiempo_recarga == 0) {
    recarga = false;
    tiempo_recarga = 5;
  }
}

/**
 * @brief Casilla Especial
 *
 * @param sensores
 */

void ComportamientoJugador::CasillaEspecial(Sensores sensores) {
  if (sensores.terreno[2] == 'K')
    bikini = true;

  if (sensores.terreno[2] == 'D')
    zapatillas = true;

  if (sensores.terreno[2] == 'X'){
      recarga = true;
  } 
}

/**
 * @brief Calculo Punto
 *
 * @param sensores
 * @param fil
 * @param col
 * @param x
 * @return ComportamientoJugador::punto
 */


void ComportamientoJugador::ActualizarMapa(Sensores sensores) {

  mapaResultado[fil][col] = sensores.terreno[0];

  switch (brujula) {
  case 0:
    mapaResultado[fil - 1][col - 1] = sensores.terreno[1];
    mapaResultado[fil - 1][col] = sensores.terreno[2];
    mapaResultado[fil - 1][col + 1] = sensores.terreno[3];

    mapaResultado[fil - 2][col - 2] = sensores.terreno[4];
    mapaResultado[fil - 2][col - 1] = sensores.terreno[5];
    mapaResultado[fil - 2][col] = sensores.terreno[6];
    mapaResultado[fil - 2][col + 1] = sensores.terreno[7];
    mapaResultado[fil - 2][col + 2] = sensores.terreno[8];

    mapaResultado[fil - 3][col - 3] = sensores.terreno[9];
    mapaResultado[fil - 3][col - 2] = sensores.terreno[10];
    mapaResultado[fil - 3][col - 1] = sensores.terreno[11];
    mapaResultado[fil - 3][col] = sensores.terreno[12];
    mapaResultado[fil - 3][col + 1] = sensores.terreno[13];
    mapaResultado[fil - 3][col + 2] = sensores.terreno[14];
    mapaResultado[fil - 3][col + 3] = sensores.terreno[15];
    break;

  case 1:
    mapaResultado[fil - 1][col + 1] = sensores.terreno[1];
    mapaResultado[fil][col + 1] = sensores.terreno[2];
    mapaResultado[fil + 1][col + 1] = sensores.terreno[3];

    mapaResultado[fil - 2][col + 2] = sensores.terreno[4];
    mapaResultado[fil - 1][col + 2] = sensores.terreno[5];
    mapaResultado[fil][col + 2] = sensores.terreno[6];
    mapaResultado[fil + 1][col + 2] = sensores.terreno[7];
    mapaResultado[fil + 2][col + 2] = sensores.terreno[8];

    mapaResultado[fil - 3][col + 3] = sensores.terreno[9];
    mapaResultado[fil - 2][col + 3] = sensores.terreno[10];
    mapaResultado[fil - 1][col + 3] = sensores.terreno[11];
    mapaResultado[fil][col + 3] = sensores.terreno[12];
    mapaResultado[fil + 1][col + 3] = sensores.terreno[13];
    mapaResultado[fil + 2][col + 3] = sensores.terreno[14];
    mapaResultado[fil + 3][col + 3] = sensores.terreno[15];
    break;

  case 2:
    mapaResultado[fil + 1][col + 1] = sensores.terreno[1];
    mapaResultado[fil + 1][col] = sensores.terreno[2];
    mapaResultado[fil + 1][col - 1] = sensores.terreno[3];

    mapaResultado[fil + 2][col + 2] = sensores.terreno[4];
    mapaResultado[fil + 2][col + 1] = sensores.terreno[5];
    mapaResultado[fil + 2][col] = sensores.terreno[6];
    mapaResultado[fil + 2][col - 1] = sensores.terreno[7];
    mapaResultado[fil + 2][col - 2] = sensores.terreno[8];

    mapaResultado[fil + 3][col + 3] = sensores.terreno[9];
    mapaResultado[fil + 3][col + 2] = sensores.terreno[10];
    mapaResultado[fil + 3][col + 1] = sensores.terreno[11];
    mapaResultado[fil + 3][col] = sensores.terreno[12];
    mapaResultado[fil + 3][col - 1] = sensores.terreno[13];
    mapaResultado[fil + 3][col - 2] = sensores.terreno[14];
    mapaResultado[fil + 3][col - 3] = sensores.terreno[15];
    break;

  case 3:
    mapaResultado[fil + 1][col - 1] = sensores.terreno[1];
    mapaResultado[fil][col - 1] = sensores.terreno[2];
    mapaResultado[fil - 1][col - 1] = sensores.terreno[3];

    mapaResultado[fil + 2][col - 2] = sensores.terreno[4];
    mapaResultado[fil + 1][col - 2] = sensores.terreno[5];
    mapaResultado[fil][col - 2] = sensores.terreno[6];
    mapaResultado[fil - 1][col - 2] = sensores.terreno[7];
    mapaResultado[fil - 2][col - 2] = sensores.terreno[8];

    mapaResultado[fil + 3][col - 3] = sensores.terreno[9];
    mapaResultado[fil + 2][col - 3] = sensores.terreno[10];
    mapaResultado[fil + 1][col - 3] = sensores.terreno[11];
    mapaResultado[fil][col - 3] = sensores.terreno[12];
    mapaResultado[fil - 1][col - 3] = sensores.terreno[13];
    mapaResultado[fil - 2][col - 3] = sensores.terreno[14];
    mapaResultado[fil - 3][col - 3] = sensores.terreno[15];
    break;
  }
}

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
    accion = Comportamiento_nivel1_2(sensores, accion);
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

  if (aun_no) {
    for (int i = 0; i < 15; i++)
      if (sensores.terreno[i] == 'G') {
        // Hay_casilla = true;
        x = i;
        inicioc = col;
        iniciof = fil;
        modo_busqueda = true;
        modo_aleatorio = false;
      }
  }

  // cout << "Cual es: " << x << endl;
  cout << "Modo Busqueda: " << modo_busqueda << endl;
  cout << "Modo Aleatorio: " << modo_aleatorio << endl;

  if (modo_busqueda) {

    // modo_busqueda = true;
    aun_no = false; // no quiero sobreescribirla ya tengo x

    cout << "\nEstoy en modo busqueda" << endl;
    cout << "Casilla inicio: " << iniciof << " " << inicioc << endl;
    if (modo_busqueda && !destino_visto) {
      destino = Calculo_Punto(sensores, iniciof, inicioc, x);
      destino_visto = true;
    }

    cout << "Casilla destino: " << destino.f << " " << destino.c << endl;

    // accion =  Mover_Dirigido(sensores, iniciof, inicioc, destino.f,
    // destino.c);
    if (bien_situado) {
      accion = Mover_Dirigido(sensores, iniciof, inicioc, destino.f, destino.c);
      cout << "Muestro destino luego de accion: " << destino.f << " "
           << destino.c << endl;
      // accion = Mover_Dirigido(sensores, 7, 9, 4, 8);
    }

    if (fil == destino.f && col == destino.c)
      modo_busqueda = false;

  } else {

    if (Avanzar(sensores)) {
      accion = actFORWARD;

    } else if (recarga) {
      accion = actIDLE; // paro 5 acciones
      Recargar();

    } else {
      accion = Girar(sensores);
    }
  }

  bien_situado = true;
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

  if (sensores.terreno[2] == 'X')
    recarga = true;
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

ComportamientoJugador::punto
ComportamientoJugador::Calculo_Punto(Sensores sensores, int fil, int col,
                                     int x) {

  brujula = sensores.sentido;
  punto final;
  final.c = 0;
  final.f = 0;
  int fild = 0;
  int cold = 0;

  if (brujula == 0 || brujula == 2) {
    if ((x == 1 or x == 2 or x == 3)) {
      fild = 1;
    } else if ((x == 4 || x == 5 || x == 6 || x == 7 || x == 8)) {
      fild = 2;
    } else if (x == 0) {
      fild = 0;
    } else {
      fild = 3;
    }

    // Vemos que columna es
    if ((x == 9 || x == 15)) {
      cold = 3;
    } else if ((x == 4 || x == 10 || x == 14 || x == 8)) {
      cold = 2;
    } else if ((x == 2 || x == 6 || x == 12)) {
      cold = 0;
    } else {
      cold = 1;
    }
  } else {
    if ((x == 1 or x == 2 or x == 3)) {
      cold = 1;
    } else if ((x == 4 || x == 5 || x == 6 || x == 7 || x == 8)) {
      cold = 2;
    } else if (x == 0) {
      cold = 0;
    } else {
      cold = 3;
    }

    // Vemos que columna es
    if ((x == 9 || x == 15)) {
      fild = 3;
    } else if ((x == 4 || x == 10 || x == 14 || x == 8)) {
      fild = 2;
    } else if ((x == 2 || x == 6 || x == 12)) {
      fild = 0;
    } else {
      fild = 1;
    }
  }

  // cout << "A sumar: " << fild << " " << cold << endl;

  // cout << "Brujula: " << brujula << endl;

  if (brujula == 0) {

    fild = abs(fild - fil);

    if ((x == 9 || x == 10 || x == 11 || x == 4 || x == 5 || x == 1))
      cold = abs(col - cold);
    else
      cold = abs(col + cold);

  } else if (brujula == 1) {
    // cout << "¿Que resto? " << cold <<" - "<< col << endl;// cout <<"A sumar:
    // " << fild << " " << cold << endl;
    cold = abs(col + cold);

    if ((x == 9 || x == 10 || x == 11 || x == 4 || x == 5 || x == 1))
      fild = abs(fil - fild);
    else
      fild = abs(fil + fild);

  } else if (brujula == 2) {
    fild = abs(fil + fild);

    if ((x == 9 || x == 10 || x == 11 || x == 4 || x == 5 || x == 1))
      cold = abs(col + cold);
    else
      cold = abs(col - cold);

  } else if (brujula == 3) {
    cold = abs(col - cold);

    if ((x == 9 || x == 10 || x == 11 || x == 4 || x == 5 || x == 1))
      fild = abs(fil + fild);
    else
      fild = abs(fil - fild);
  }

  final.c = cold;
  final.f = fild;
  // cout << fil << " " << col << endl;
  // cout << "A devolver: " << final.f << " " << final.c << endl;

  return final;
}

/**
 * @brief Movimiento Dirigido
 *
 * @param sensores
 * @param origenf
 * @param origenc
 * @param destinof
 * @param destinoc
 * @return Action
 */

Action ComportamientoJugador::Mover_Dirigido(Sensores sensores, int origenf,
                                             int origenc, int destinof,
                                             int destinoc) {
  Action accion = actIDLE;
  cout << "Mover dirigido " << endl;

  if (inicializamos) {
    filas_mover = abs(origenf - destinof);
    columnas_mover = abs(origenc - destinoc);
    inicializamos = false; // solo quiero una vez
  }

  cout << filas_mover << " " << columnas_mover << endl;

  // pongo la brujula donde quiero
  // si cambio pos brujula -> giro
  // si no pa lante
  // movimiento filas
  // arriba o abajo

  if (filas_mover == 0)
    hago_columnas = true;

  if (hago_filas && filas_mover != 0) {

    if ((origenf - destinof) > 0) {
      // arriba

      if (brujula != 0) {

        accion = actTURN_L;
      } else {

        filas_mover--;
        accion = actFORWARD;
      }

    } else if ((origenf - destinof) < 0) {
      // abajo
      if (brujula != 2)
        accion = actTURN_L;
      else {

        filas_mover--;
        accion = actFORWARD;
      }
    }
  }

  // izquierda, derecha
  // mover columnas

  if (hago_columnas && columnas_mover != 0) {

    if ((origenc - destinoc) > 0) {
      // arriba

      if (brujula != 3) { // OESTE ES cuando
        accion = actTURN_R;
      } else {

        accion = actFORWARD;
        columnas_mover--;
      }

    } else if ((origenc - destinoc) < 0) {
      // abajo
      if (brujula != 1) // oeste
        accion = actTURN_R;
      else {

        accion = actFORWARD;
        columnas_mover--;
      }
    }
  }

  // cout << filas_mover << " " << columnas_mover << endl;

  if (!hago_filas && !hago_columnas)
    TT = true;
  //  movimiento columnas

  return accion;
}

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

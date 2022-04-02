#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
using namespace std;

Action ComportamientoJugador::think(Sensores sensores) {

  Action accion = actIDLE;
  
  if (sensores.reset){
    cout << "Reinicio " << endl;
    reiniciar();
  }

  if (contador == 0){
    contador = 50;
    bikini = true;
    zapatillas = true;
  }

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
  cout << "Tiempo Recarga: " << tiempo_recarga << endl;
  cout << "Contador: " << contador << endl;

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

  if (comienzo) {
    // Accion
    fil = sensores.posF;
    col = sensores.posC;
    brujula = sensores.sentido;

    if (bien_situado)
      ActualizarMapa(sensores);

    SensorVistaNivel(sensores);

    if (bien_busqueda){
      VistaAgente(sensores);
      bien_busqueda = false;
    }
      

    // busco casillas

    cout << endl << inicializamos << " " << terminamos << endl;
    cout << "\n**************************************" << endl;
    cout << " Modo Busqueda: " << modo_busqueda << endl;
    cout << " Modo Aleatorio: " << modo_aleatorio << endl;
    cout << "**************************************" << endl;
    cout << " Casillla encontrada: " << posicionamiento << endl;
    cout << "**************************************" << endl;
    // movimiento segun el modo

    if (modo_busqueda) {
      if (SensoresAvanzar(sensores))
         accion = MoverBusqueda(posicionamiento);
    } else if (modo_aleatorio){
      bien_busqueda = true;
      accion = MoverAleatorio(sensores);
    }
  }
  // reconoce la casilla G la azul deja un rastro de lo visto
  // cono de visualización

  // Recordar la ultima accion

  if( (accion == actIDLE && ultimaAccion == actIDLE) || (accion == actTURN_R && ultimaAccion == actTURN_R) || (accion == actTURN_L && ultimaAccion == actTURN_L) )
    contador--;

  comienzo = true;
  SensorCasilla(sensores);
  ultimaAccion = accion;
  return accion;

  // Determinar el efecto de la ultima accion enviada
  return accion;
}

int ComportamientoJugador::interact(Action accion, int valor) { return false; }

// ---------------------------------------------------------------------------------------------------------------------------------------------

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

void ComportamientoJugador::SensorVistaNivel(Sensores sensores) {
  if (sensores.nivel == 0) {
    bien_situado = true;
  } else {

    if (sensores.terreno[0] == 'G' and !bien_situado) {
      fil = sensores.posF; // sensores devuelven -1
      col = sensores.posC;
      bien_situado = true;
    }
  }
}

Action ComportamientoJugador::MoverAleatorio(Sensores sensores) {
  Action accion = actIDLE;

  if (recarga) {
    accion = actIDLE;
    Recargar();
  } else if (SensoresAvanzar(sensores)) {
    accion = actFORWARD;
  } else {
    accion = Girar(sensores);
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

bool ComportamientoJugador::SensoresAvanzar(Sensores sensores) {

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
}

Action ComportamientoJugador::Girar(Sensores sensores) {
  Action accion;

  if (!girar_derecha) {
    accion = actTURN_L;
    girar_derecha = (rand() % 2 == 0);

  } else {
    accion = actTURN_R;
    girar_derecha = (rand() % 2 == 0);
  }

  return accion;
}

void ComportamientoJugador::SensorCasilla(Sensores sensores) {

  if (sensores.terreno[0] == 'K' || sensores.terreno[0] == 'D' ||
      sensores.terreno[0] == 'X' || sensores.terreno[0] == 'G') {
    modo_busqueda = false;
    modo_aleatorio = true;
    inicializamos = true;
  }

  if (sensores.terreno[2] == 'K') {
    bikini = true;
  }

  if (sensores.terreno[2] == 'D') {
    zapatillas = true;
  }

  if (sensores.terreno[2] == 'X') {
    recarga = true;
  }
}

void ComportamientoJugador::VistaAgente(Sensores sensores) {
  cout << encontrada_posicion<< encontrada_zapas << encontrada_bikini << encontrada_recarga << endl;
  
  if (!encontrada_posicion) { // posicion
    for (int i = 0; i < 15; i++)
      if (sensores.terreno[i] == 'G') {
        posicionamiento = i;
        modo_busqueda = true;
        modo_aleatorio = false;
        terminamos = false;
        encontrada_posicion = true;
      }
  }
  else if (!encontrada_zapas) { // zapas
    for (int i = 0; i < 15; i++)
      if (sensores.terreno[i] == 'D') {
        posicionamiento = i;
        modo_busqueda = true;
        modo_aleatorio = false;
        encontrada_zapas = true;
        terminamos = false;
      }
  }
  else if (!encontrada_bikini) { // bikini
    for (int i = 0; i < 15; i++)
      if (sensores.terreno[i] == 'K') {
        posicionamiento = i;
        modo_busqueda = true;
        modo_aleatorio = false;
        encontrada_bikini = true;
        terminamos = false;
      }
  }
  else if (!encontrada_recarga) {
    for (int i = 0; i < 15; i++)
      if (sensores.terreno[i] == 'X') {
        posicionamiento = i;
        modo_busqueda = true;
        modo_aleatorio = false;
        encontrada_recarga = true;
        terminamos = false;
      }
  }
}

Action ComportamientoJugador::MoverBusqueda(int x) {
  Action accion = actIDLE;
  if (inicializamos) {

    // fila
    if ((x == 1 or x == 2 or x == 3)) {
      filax = 1;
    } else if ((x == 4 || x == 5 || x == 6 || x == 7 || x == 8)) {
      filax = 2;
    } else if (x == 0) {
      filax = 0;
    } else {
      filax = 3;
    }

    // columnas
    if ((x == 9 || x == 15)) {
      columnasx = 3;
    } else if ((x == 4 || x == 10 || x == 14 || x == 8)) {
      columnasx = 2;
    } else if ((x == 2 || x == 6 || x == 12)) {
      columnasx = 0;
    } else {
      columnasx = 1;
    }
    
    inicializamos = false;
  }

  cout << " Filas a avanzar: " << filax << endl;
  cout << " Columnas a avanzar: " << columnasx << endl;
  cout << "**************************************" << endl;
  
  if (filax != 0){
    accion = actFORWARD; 
    filax--;
  } else if (filax == 0 && !terminamos){
    
    if ((x == 9 || x == 10 || x == 11 || x == 4 || x == 5 || x == 1)){
        cout << "adios" << endl;
        accion = actTURN_L;
    } else if ((x == 13|| x == 14 || x == 15 || x == 7 || x == 8 || x == 3)){
        cout << "121212" << endl;
        accion = actTURN_R;
    }
    terminamos = true;

  }else if (columnasx != 0){
    accion = actFORWARD;
    columnasx--;
  }
  return accion;
}

void ComportamientoJugador::reiniciar (){
  fil=col=99;
  //brujula=0;
  ultimaAccion= actIDLE;
  girar_derecha=false;
  bien_situado=false;
  bikini = zapatillas = recarga = false;
  tiempo_recarga = 5;
  
      
  modo_aleatorio = true;
  modo_busqueda = false;
  comienzo = false;
      
  encontrada_posicion= encontrada_zapas = encontrada_bikini =encontrada_recarga = false;
  posicionamiento = 0;

  terminamos = false;
  inicializamos = true;
}
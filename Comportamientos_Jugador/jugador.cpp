#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
using namespace std;

Action ComportamientoJugador::think(Sensores sensores) {

  Action accion = actIDLE;

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
    //girar_derecha = (rand() % 2 == 0);
    break;

  case actTURN_R:
    brujula = (brujula + 1) % 4;
    //girar_derecha = (rand() % 2 == 0);
    break;
  }

   

  if (sensores.terreno[0] == 'G' and !bien_situado) {
    fil = sensores.posF;
    col = sensores.posC;
    bien_situado = true;
  }

   if (bien_situado){
   		ActualizarMapa(sensores);
      //mapaResultado[fil][col]=sensores.terreno[0];
   } 

  

  // Decidir la nueva accion

  if (Avanzar(sensores)){
    accion = actFORWARD;
  } else {
   accion= Girar(sensores);
  }
  

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
bool hayObstaculo(unsigned char casilla) {
  if (casilla == 'P' or casilla == 'M') {
    return true;
  } else {
    return false;
  }
}


// Cono, actualizo el mapa
/*
	norte 0 
	Este 1
	sur 2
	oeste 3

	guardamos toda la informacion de los sensores de terreno
	desde 0 hasta 15 en mapaResultado

*/

/*
  Cuando muera reinicio
*/

bool ComportamientoJugador::Avanzar(Sensores sensores){
	return ((sensores.terreno[2] == 'T' or sensores.terreno[2] == 'S' or sensores.terreno[2] == 'G' or sensores.terreno[2] == 'D') && (sensores.superficie[2] == '_'));
}

/*
  Cuando muera reinicio
*/
void ComportamientoJugador::Reiniciar(){
  fil = col = 99;
  ultimaAccion= actIDLE;
  bien_situado = false;
  brujula = 0;
}

/*
  Quiero añadir una variable de gro aleatorio
*/
Action ComportamientoJugador::Girar(Sensores sensores){
  Action accion;

  if (!girar_derecha){
    accion = actTURN_L;
    girar_derecha= (rand()%2 == 0);
    
  } else {
    accion = actTURN_R;
    girar_derecha= (rand()%2 == 0);

  }

  return accion;
}

void ComportamientoJugador::ActualizarMapa(Sensores sensores) {
		mapaResultado[fil][col]=sensores.terreno[0];
	
		switch (brujula) {
		case 0:
			mapaResultado[fil-1][col-1] = sensores.terreno[1];
			mapaResultado[fil-1][col] = sensores.terreno[2];
			mapaResultado[fil-1][col+1] = sensores.terreno[3];

			mapaResultado[fil-2][col-2] = sensores.terreno[4];
			mapaResultado[fil-2][col-1] = sensores.terreno[5];
			mapaResultado[fil-2][col] = sensores.terreno[6];
			mapaResultado[fil-2][col+1] = sensores.terreno[7];
			mapaResultado[fil-2][col+2] = sensores.terreno[8];

			mapaResultado[fil-3][col-3] = sensores.terreno[9];
			mapaResultado[fil-3][col-2] = sensores.terreno[10];
			mapaResultado[fil-3][col-1] = sensores.terreno[11];
			mapaResultado[fil-3][col] = sensores.terreno[12];
			mapaResultado[fil-3][col+1] = sensores.terreno[13];
			mapaResultado[fil-3][col+2] = sensores.terreno[14];
			mapaResultado[fil-3][col+3] = sensores.terreno[15];
		break;

		case 1:
			mapaResultado[fil-1][col+1] = sensores.terreno[1];
			mapaResultado[fil][col+1] = sensores.terreno[2];
			mapaResultado[fil+1][col+1] = sensores.terreno[3];

			mapaResultado[fil-2][col+2] = sensores.terreno[4];
			mapaResultado[fil-1][col+2] = sensores.terreno[5];
			mapaResultado[fil][col+2] = sensores.terreno[6];
			mapaResultado[fil+1][col+2] = sensores.terreno[7];
			mapaResultado[fil+2][col+2] = sensores.terreno[8];

			mapaResultado[fil-3][col+3] = sensores.terreno[9];
			mapaResultado[fil-2][col+3] = sensores.terreno[10];
			mapaResultado[fil-1][col+3] = sensores.terreno[11];
			mapaResultado[fil][col+3] = sensores.terreno[12];
			mapaResultado[fil+1][col+3] = sensores.terreno[13];
			mapaResultado[fil+2][col+3] = sensores.terreno[14];
			mapaResultado[fil+3][col+3] = sensores.terreno[15];
		break;
		
		case 2:
			mapaResultado[fil+1][col+1] = sensores.terreno[1];
			mapaResultado[fil+1][col] = sensores.terreno[2];
			mapaResultado[fil+1][col-1] = sensores.terreno[3];

			mapaResultado[fil+2][col+2] = sensores.terreno[4];
			mapaResultado[fil+2][col+1] = sensores.terreno[5];
			mapaResultado[fil+2][col] = sensores.terreno[6];
			mapaResultado[fil+2][col-1] = sensores.terreno[7];
			mapaResultado[fil+2][col-2] = sensores.terreno[8];

			mapaResultado[fil+3][col+3] = sensores.terreno[9];
			mapaResultado[fil+3][col+2] = sensores.terreno[10];
			mapaResultado[fil+3][col+1] = sensores.terreno[11];
			mapaResultado[fil+3][col] = sensores.terreno[12];
			mapaResultado[fil+3][col-1] = sensores.terreno[13];
			mapaResultado[fil+3][col-2] = sensores.terreno[14];
			mapaResultado[fil+3][col-3] = sensores.terreno[15];
		break;
		
		case 3:
			mapaResultado[fil+1][col-1] = sensores.terreno[1];
			mapaResultado[fil][col-1] = sensores.terreno[2];
			mapaResultado[fil-1][col-1] = sensores.terreno[3];

			mapaResultado[fil+2][col-2] = sensores.terreno[4];
			mapaResultado[fil+1][col-2] = sensores.terreno[5];
			mapaResultado[fil][col-2] = sensores.terreno[6];
			mapaResultado[fil-1][col-2] = sensores.terreno[7];
			mapaResultado[fil-2][col-2] = sensores.terreno[8];

			mapaResultado[fil+3][col-3] = sensores.terreno[9];
			mapaResultado[fil+2][col-3] = sensores.terreno[10];
			mapaResultado[fil+1][col-3] = sensores.terreno[11];
			mapaResultado[fil][col-3] = sensores.terreno[12];
			mapaResultado[fil-1][col-3] = sensores.terreno[13];
			mapaResultado[fil-2][col-3] = sensores.terreno[14];
			mapaResultado[fil-3][col-3] = sensores.terreno[15];
		break;

		}
	
	
  

}

#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
using namespace std;

Action ComportamientoJugador::think(Sensores sensores) {

  Action accion = actIDLE;
  //brujula= sensores.sentido;
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
  cout << "Zapatillas: " << zapatillas  << endl;
  cout << "Recarga: " << recarga << endl;
  cout << "Nivel: " << nivel << endl;
  cout << "Tiempo Recarga: " << tiempo_recarga << endl;
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
        accion = Comportamiento_nivel0(sensores, accion);
        nivel = 0;
      break;
    case 1:
        nivel = 1;
        sensores_nivel1=false;
        accion = Comportamiento_nivel1(sensores, accion);
      break;
    case 2:
        nivel = 2;
      break;
    case 3:
        nivel = 3;
      
      break;
    
    case 4:
        nivel = 4;
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
Action ComportamientoJugador::Comportamiento_nivel0(Sensores sensores, Action accion){

  
   fil = sensores.posF;
   col = sensores.posC;
   brujula= sensores.sentido;
   
   if (bien_situado){
   		ActualizarMapa(sensores);
   } 

  // Decidir la nueva accion
  if (Avanzar(sensores)){
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
    accion= Girar(sensores);
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
*/

Action ComportamientoJugador::Comportamiento_nivel1(Sensores sensores, Action accion){
  
   brujula= sensores.sentido;
   
   /*
   if (bien_situado){
   		ActualizarMapa(sensores);
   } 
   */
  
  // volcado del mapa
  if (sensores.terreno[0] == 'G'){

    fil = sensores.posF; // sensores devuelven -1
    col = sensores.posC;
    ActualizarMapa(sensores);

    for(int i = 0; i < 100; ++i){
			for(int j = 0; j < 100; ++j){
				if(mapaResultado[i][j]=='?'){
					mapaResultado[i][j] = mapaAux[i][j];
				}
			}
		}

    bien_situado = true;
    
  }

  // Decidir la nueva accion
  if (Avanzar(sensores)){
    accion = actFORWARD;
  } else if (recarga) {
    accion = actIDLE; // paro 5 acciones
  } else {
    accion= Girar(sensores);
  }

  bien_situado = true;
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
bool ComportamientoJugador::Avanzar(Sensores sensores){
	
  bool b1 = (sensores.terreno[2] == 'T' or sensores.terreno[2] == 'S' or sensores.terreno[2] == 'G' or sensores.terreno[2] == 'D' or sensores.terreno[2] == 'K' or sensores.terreno[2] == 'X');
  bool b2 = (sensores.superficie[2] == '_');
  bool condicion_zapatillas = (sensores.terreno[2] == 'B');
  bool condicion_bikini = (sensores.terreno[2] == 'A');
  
  if (zapatillas)
    b1 = b1 || condicion_zapatillas;

  if (bikini)
    b1 = b1 || condicion_bikini;


  return b1 && b2;
  //return ((sensores.terreno[2] == 'T' or sensores.terreno[2] == 'S' or sensores.terreno[2] == 'G' or sensores.terreno[2] == 'D') && (sensores.superficie[2] == '_'));
}


/*
  Quiero añadir una variable de gro aleatorio
*/
Action ComportamientoJugador::Girar(Sensores sensores){
  Action accion;


  if (!girar_derecha){
    accion = actTURN_L;
    girar_derecha= (rand()%2 == 0);
    //girar_derecha = (rand()%50) + 1;
    
  } else {
    accion = actTURN_R;
    girar_derecha= (rand()%2 == 0);
    //girar_derecha = (rand()%50) + 1;

  }

  return accion;
}

void ComportamientoJugador::Recargar (){
    tiempo_recarga--;
    if (tiempo_recarga == 0){
      recarga = false;
      tiempo_recarga = 5;
    }
}

void ComportamientoJugador::CasillaEspecial(Sensores sensores){
  if (sensores.terreno[2] == 'K')
    bikini = true;

  if (sensores.terreno[2] == 'D')
    zapatillas = true;

  if (sensores.terreno[2] == 'X') 
    recarga = true;
  
  

  

  //bien_situado = true;
}


void ComportamientoJugador::ActualizarMapa(Sensores sensores) {


  if (sensores_nivel1){

  mapaResultado[fil][col] = sensores.terreno[0];
  

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

  } else { // si no funcionan los sonsores lo guardo en un mapa auxiliar que dibuja cuando estoy en la casilla K
  cout << "Imprimo mapaAux" << endl;
  switch (brujula) {
		case 0:
			mapaAux[fil-1][col-1] = sensores.terreno[1];
			mapaAux[fil-1][col] = sensores.terreno[2];
			mapaAux[fil-1][col+1] = sensores.terreno[3];

			mapaAux[fil-2][col-2] = sensores.terreno[4];
			mapaAux[fil-2][col-1] = sensores.terreno[5];
			mapaAux[fil-2][col] = sensores.terreno[6];
			mapaAux[fil-2][col+1] = sensores.terreno[7];
			mapaAux[fil-2][col+2] = sensores.terreno[8];

			mapaAux[fil-3][col-3] = sensores.terreno[9];
			mapaAux[fil-3][col-2] = sensores.terreno[10];
			mapaAux[fil-3][col-1] = sensores.terreno[11];
			mapaAux[fil-3][col] = sensores.terreno[12];
			mapaAux[fil-3][col+1] = sensores.terreno[13];
			mapaAux[fil-3][col+2] = sensores.terreno[14];
			mapaAux[fil-3][col+3] = sensores.terreno[15];
		break;

		case 1:
			mapaAux[fil-1][col+1] = sensores.terreno[1];
			mapaAux[fil][col+1] = sensores.terreno[2];
			mapaAux[fil+1][col+1] = sensores.terreno[3];

			mapaAux[fil-2][col+2] = sensores.terreno[4];
			mapaAux[fil-1][col+2] = sensores.terreno[5];
			mapaAux[fil][col+2] = sensores.terreno[6];
			mapaAux[fil+1][col+2] = sensores.terreno[7];
			mapaAux[fil+2][col+2] = sensores.terreno[8];

			mapaAux[fil-3][col+3] = sensores.terreno[9];
			mapaAux[fil-2][col+3] = sensores.terreno[10];
			mapaAux[fil-1][col+3] = sensores.terreno[11];
			mapaAux[fil][col+3] = sensores.terreno[12];
			mapaAux[fil+1][col+3] = sensores.terreno[13];
			mapaAux[fil+2][col+3] = sensores.terreno[14];
			mapaAux[fil+3][col+3] = sensores.terreno[15];
		break;
		
		case 2:
			mapaAux[fil+1][col+1] = sensores.terreno[1];
			mapaAux[fil+1][col] = sensores.terreno[2];
			mapaAux[fil+1][col-1] = sensores.terreno[3];

			mapaAux[fil+2][col+2] = sensores.terreno[4];
			mapaAux[fil+2][col+1] = sensores.terreno[5];
			mapaAux[fil+2][col] = sensores.terreno[6];
			mapaAux[fil+2][col-1] = sensores.terreno[7];
			mapaAux[fil+2][col-2] = sensores.terreno[8];

			mapaAux[fil+3][col+3] = sensores.terreno[9];
			mapaAux[fil+3][col+2] = sensores.terreno[10];
			mapaAux[fil+3][col+1] = sensores.terreno[11];
			mapaAux[fil+3][col] = sensores.terreno[12];
			mapaAux[fil+3][col-1] = sensores.terreno[13];
			mapaAux[fil+3][col-2] = sensores.terreno[14];
			mapaAux[fil+3][col-3] = sensores.terreno[15];
		break;
		
		case 3:
			mapaAux[fil+1][col-1] = sensores.terreno[1];
			mapaAux[fil][col-1] = sensores.terreno[2];
			mapaAux[fil-1][col-1] = sensores.terreno[3];

			mapaAux[fil+2][col-2] = sensores.terreno[4];
			mapaAux[fil+1][col-2] = sensores.terreno[5];
			mapaAux[fil][col-2] = sensores.terreno[6];
			mapaAux[fil-1][col-2] = sensores.terreno[7];
			mapaAux[fil-2][col-2] = sensores.terreno[8];

			mapaAux[fil+3][col-3] = sensores.terreno[9];
			mapaAux[fil+2][col-3] = sensores.terreno[10];
			mapaAux[fil+1][col-3] = sensores.terreno[11];
			mapaAux[fil][col-3] = sensores.terreno[12];
			mapaAux[fil-1][col-3] = sensores.terreno[13];
			mapaAux[fil-2][col-3] = sensores.terreno[14];
			mapaAux[fil-3][col-3] = sensores.terreno[15];
		break;

		}
  }
	
	  
  

}



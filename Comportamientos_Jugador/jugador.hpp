#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"
using namespace std;

class ComportamientoJugador : public Comportamiento{

  public:
    ComportamientoJugador(unsigned int size) : Comportamiento(size){
      // Constructor de la clase
      // Dar el valor inicial a las variables de estado
      fil=col=99;
      //brujula=0;
      ultimaAccion= actIDLE;
      girar_derecha=false;
      bien_situado=false;
      bikini = zapatillas = recarga = false;

      sensores_nivel1 = true;
      nivel = 100;
    }

    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);

  private:
  
  // Declarar aquí las variables de estado
  int fil,col,brujula, nivel;
  Action ultimaAccion;
  bool girar_derecha, bien_situado, bikini, zapatillas, recarga;
  char mapaAux[100][100]; // por si lo necesito
  bool sensores_nivel1;

  // necesito variable para que gire aleatoriamente, cuando llegue a 0

  // funciones privadas 
  void ActualizarMapa(Sensores sensores);
  bool Avanzar(Sensores sensores);
  Action Girar(Sensores sensores);
  void Recargar(Sensores sensores);
  void CasillaEspecial(Sensores sensores);

  char Mapa(Sensores sensores);

  Action Comportamiento_nivel0(Sensores sensores, Action accion);
  Action Comportamiento_nivel1(Sensores sensores, Action accion);
};

#endif

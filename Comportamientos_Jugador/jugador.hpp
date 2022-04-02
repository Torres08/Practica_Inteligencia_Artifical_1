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
      tiempo_recarga = 15;
      
      
      modo_aleatorio = true;
      modo_busqueda = false;
      comienzo = false;
      
      encontrada_posicion= encontrada_zapas = encontrada_bikini =encontrada_recarga = false;
      posicionamiento = 0;

      terminamos = false;
      inicializamos = true;

      bien_busqueda = true;

      contador = 50;
      }

    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);

  private:
  
  // Variables de estado
  int fil,col,brujula,  tiempo_recarga, pasos;  // fila, columna , brujula, nivel , tiempo_recarga, pasos
  Action ultimaAccion; // ulltima accion
  bool girar_derecha, bien_situado, bikini, zapatillas, recarga; // bien_situado deberia cambiarlo
  bool modo_aleatorio, modo_busqueda;
  bool comienzo;

  bool encontrada_posicion, encontrada_zapas, encontrada_bikini, encontrada_recarga;

  bool inicializamos, terminamos;

  int filax,columnasx;

  int posicionamiento;

  bool bien_busqueda;

  int contador;

  // funciones
  void ActualizarMapa(Sensores sensores);
  void SensorVistaNivel(Sensores sensores);
  void VistaAgente(Sensores sensores);
  Action MoverAleatorio(Sensores sensores);
  void Recargar();
  bool SensoresAvanzar(Sensores sensores);
  Action Girar(Sensores sensores);
  void SensorCasilla(Sensores sensores);
  Action MoverBusqueda(int x);
  void reiniciar();
  
};

#endif

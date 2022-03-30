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
      tiempo_recarga = 5;
      nivel = -1;
      modo_bajabateria = false;
      pasos = 0;
      destino.c = 0;
      destino.f = 0;
      modo_busqueda = false;
      modo_aleatorio = true;
      

      }

    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);

  private:
  
  // Variables de estado
  int fil,col,brujula, nivel, tiempo_recarga, pasos;  // fila, columna , brujula, nivel , tiempo_recarga, pasos
  Action ultimaAccion; // ulltima accion
  bool girar_derecha, bien_situado, bikini, zapatillas, recarga; // bien_situado deberia cambiarlo
 
  

  bool modo_busqueda; // modos del robot - busqueda si hay una casilla cerca
  bool modo_aleatorio; // modo del robot - aleatorio, modo general si encuantra pared gira
  bool modo_bajabateria; // modo del robot - gira mas al tener menos bateria, cada x pasos hace un giro
  

  // Busqueda de la casilla
  bool aun_no = true; // aun no he encontrado una casilla azul
  int fild = 0;
  int cold = 0;
  int x = 0;
  int iniciof = 0;
  int inicioc = 0;
  int filas_mover = 0;
  int columnas_mover = 0;
  bool inicializamos = true;
  bool destino_visto = false;
  bool bien_situado2 = false;
  

  //bool ahorro_bateria;
  //bool una_vez = true;
  bool terminado = false;
  bool hago_filas = true;
  bool hago_columnas = false;
  bool TT = false; // fin hago filas y columnas ya he llegado
  struct punto{
        int f;
        int c;
  }destino;






  
  // necesito variable para que gire aleatoriamente, cuando llegue a 0

  // funciones privadas 
  void ActualizarMapa(Sensores sensores);
  bool Avanzar(Sensores sensores);
  Action Girar(Sensores sensores);
  void Recargar();
  void CasillaEspecial(Sensores sensores);
  char Mapa(Sensores sensores);

  Action Mover_Dirigido(Sensores sensores, int origenf, int origenc, int destinof, int destinoc);
  punto Calculo_Punto(Sensores sensores, int fil, int col, int x);

  Action Comportamiento_nivel0(Sensores sensores, Action accion);
  Action Comportamiento_nivel1_2(Sensores sensores, Action accion);
  Action Prueba(Sensores sensores, Action accion);
};

#endif

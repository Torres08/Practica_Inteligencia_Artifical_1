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
      ultimaAccion= actIDLE;
      girar_derecha=false;
      bien_situado=false;
      bikini = zapatillas = recarga = false;
      tiempo_recarga = 5;
      tiempo_giro = 15;
     
      nivel = -1;
      modo_busqueda = false;
      modo_aleatorio = true;
      
      arriba = 0;
      lados = 0;
      

      }

    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);

  private:
  
  // Variables de estado
  int fil,col,brujula, nivel, tiempo_recarga, tiempo_giro, pasos;  // fila, columna , brujula, nivel , tiempo_recarga, pasos
  Action ultimaAccion; // ulltima accion
  bool girar_derecha, bien_situado, bikini, zapatillas, recarga; // bien_situado deberia cambiarlo
 
  bool modo_busqueda; // modos del robot - busqueda si hay una casilla cerca
  bool modo_aleatorio; // modo del robot - aleatorio, modo general si encuantra pared gira
  
  

  // Busqueda de la casilla
  
  int arriba,lados;
  int x = 0;
  bool inicializamos = true;
  bool destino_visto = false;
  bool bien_situado2 = false;
  bool inicializamos2 = true;
  bool terminado5 = false;
  bool bien_situado3 = false;
 
  bool primera_vez = true;


  bool casilla_azul_encontrada = false;
  bool bikini_encontrado = false;
  bool zapatillas_encontradas = false;
  bool cargador_encontrado = false;
  
  

  
  // necesito variable para que gire aleatoriamente, cuando llegue a 0

  // funciones privadas 
  void ActualizarMapa(Sensores sensores);
  bool Avanzar(Sensores sensores);
  Action Girar(Sensores sensores);
  void Recargar();
  void CasillaEspecial(Sensores sensores);
  void reiniciar();
  char Mapa(Sensores sensores);

  
  Action Mover_Aleatorio(Sensores sensores);
  Action Mover_Dirigido_v2(int x);
  Action Comportamiento_nivel0(Sensores sensores, Action accion);
  Action Comportamiento_nivel1_2(Sensores sensores, Action accion);

  Action Prueba(Sensores sensores, Action accion);


};

#endif

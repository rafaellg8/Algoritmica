#include<iostream>
#include <ctime>
#include <chrono>
#include "tablero.h"
using namespace std;

typedef struct coordenadas {
   int x,y;
}coordenadas;



// Imprimir el recorrido
void imprimirRecorrido(int tablero[8][8]) {
   int i,j;
   for (i = 0; i < 8; i++) {
      for (j = 0; j < 8; j++) {
          cout<<tablero[i][j]<<"\t";
      }
      cout<<endl;
   }
}

/*
@brief Funcion para calcular si es factible
* Comprueba que esté dentro del tablero y que no haya pasado ya por esa casilla
*/
bool esFactible(coordenadas movimiento, Tablero recorrido) {
   int i = movimiento.x;
   int j = movimiento.y;
   /*Si está entre la casilla 0 y 8 y no ha pasado por allí nunca*/
   if ((i >= 0 && i < 8) && (j >= 0 && j < 8) && (recorrido.getPos(i,j) == 0))
      return true;
   return false;
}


/*
@brief Encontrar el camino en el tablero
* Funcion recursiva
*/
bool buscarRecorrido(Tablero recorrido, coordenadas movimientos[],
               coordenadas posicionActual, int numMovimientos) {
   int i;
   coordenadas siguienteMov; //Siguiente movimiento
   if (numMovimientos == 8*8-1) {
     //Si ha visitado cada una de las casillas del tablero una vez, el recorrido ha sido completado

      return true;
   }

   //Posibles movimientos desde donde estamos
   //Vamos recorriendo una por una las casillas
   for (i = 0; i < 8; i++) {
      siguienteMov.x = posicionActual.x + movimientos[i].x;
      siguienteMov.y = posicionActual.y + movimientos[i].y;
//Heos asignado las coordenadas mediante el bucle para los siguientes movimientos

      if (esFactible(siguienteMov, recorrido)) {
        //Si es factible, buscamos el recorrido y ponemos un 1 en la matriz, el recorrido
         recorrido.setPos(siguienteMov.x,siguienteMov.y, numMovimientos+1);
         if (buscarRecorrido(recorrido, movimientos, siguienteMov, numMovimientos+1) == true) {
            return true;
         }
         else {
            //Movimiento invalido por ahí no se pasa
            //Ponemos 0 en la matriz recorrido
            recorrido.setPos(siguienteMov.x,siguienteMov.y, 0);
         }
      }
   }
   return false;
}

/*
@brief Funcion recorrido
Simula el recorrido del caballo
*/
void recorridoCaballo() {
  Tablero recorrido; //Llamada al constructor

  clock_t tantes;    // Valor del reloj antes de la ejecuón
  clock_t tdespues;  // Valor del reloj después de la ejecución


   //Mapa de coordenadas que puede hacer un caballo
   //Posibles movimientos en L
   coordenadas movimientos[8] = { {2,1},{1,2},{-1,2},{-2,1},
                              {-2,-1},{-1,-2},{1,-2},{2,-1} };



// //Inicializamos la matriz del recorrido
//    for (i = 0; i < 8; i++) {
//       for (j = 0; j < 8; j++) {
//          recorrido[i][j] = 0;
//       }
//    }

   coordenadas posicionActual = {0,0};

   tantes = clock();
   if(buscarRecorrido(recorrido, movimientos, posicionActual, 0) == false) {
      cout<<"\nError el recorrido no existe";
   }
   else {
     tdespues = clock();
      recorrido.imprimirRecorrido();
      cout << ((double)(tdespues-tantes))/CLOCKS_PER_SEC //Obtenemos el tiempo transcurrido
       << "segundos" << endl;
   }
}

// main
int main() {
   recorridoCaballo();
   return 0;
}

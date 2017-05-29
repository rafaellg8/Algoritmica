#include <iostream>
#include "tablero.h"
using namespace std;


//Reservamos memoria
void Tablero::reservar (){
        tablero = new int *[TAM];

        for (int i=0; i<TAM; i++) {
                tablero[i]=new int [TAM];
        }
}

void Tablero::destructor (){
    cout<<"\nDestructor"<<endl;
    if (tablero)
        for (int i=0; i<TAM; i++)
                delete tablero[i];
        delete tablero[0];
}


  Tablero::Tablero (){
    reservar();

    //Inicializamos la matriz del recorrido
       for (int i = 0; i < TAM; i++) {
          for (int j = 0; j < TAM; j++) {
             tablero[i][j] = 0;
          }
       }
  }

  Tablero::~Tablero(){
    destructor();
  }

  void Tablero::imprimirRecorrido(){
    for (int i = 0; i < TAM; i++) {
       for (int j = 0; j < TAM; j++) {
           cout<<tablero[i][j]<<"\t";
       }
       cout<<endl;
    }
  }

  int Tablero::getPos(int i,int j){
    return tablero[i][j];
  }

  void Tablero::setPos(int i,int j, int valor){
    tablero[i][j]=valor;
  }

#ifndef __Tablero_H_
#define __Tablero_H_

class Tablero{

private:
  const int TAM=8;

  int **tablero;

  void reservar();
  void destructor();

public:
  Tablero();
  ~Tablero();
  void imprimirRecorrido();
  int getPos(int i,int j);
  void setPos(int i,int j,int valor);

};
#endif

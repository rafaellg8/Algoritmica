// II.1. Deseamos almacenar en una cinta magnética de longitud L un conjunto de n programas
// {P1, P2, ... , Pn}. Sabemos que cada Pi necesita un espacio ai de la cinta y que
// ( ∑ ai ) > L
// 1≤i ≤n
// Construir un algoritmo que seleccione aquel subconjunto de programas que hace que el
// número de programas almacenado en la cinta sea máximo.
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <math.h>
using namespace std;

const int TAM = 10;

// Tenemos 2 opciones para la función de seleccion bastante claras
// 1) Seleccionar por P i más pequeños. Así metemos muchos programas y el tamaño desperdiciado en la cinta es menor
// Problema, que podríamos tener muchos huecos vacíos
// 2) Seleccionar P i más grande, pero tenemos menos bloques vacíos

// Ordenamos por tamaños
// Seleccion
// Como esta ordenado por tamaño de menor a mayor, la seleccion es simplemente ir metiendo mientras haya espacio en la cinta

/**
   Devuelve true o false, depediendo de si es factible o no introducir el elemento o no.
   @param elemento elemento a introducir. Contiene el tamaño que ocupa ese programa
   @param tamanio tamaño restante en la cinta
 */
bool factible(int elemento, int tamanio){
        if (elemento <= (tamanio/2)+1) //Si el elemento es menor que la mitad restante lo metemos. El objetivo es intentar meter el mayor número posible de programas en la cinta
                return true;
        else return false;
}

/**
  Devuelve true o false, si selecciona el programa para introducir dentro de la cinta. Funcion de seleccion.
  @param pi programa a evaluar su seleccion
  @tamanioRest tamanio restante en la cinta
  @media media geometrica de los valores de los programas, espacio que ocupan

bool seleccion(int pi, int tamanioRest,int media,int j){

        //Funcion factible
        if (factible(pi,tamanioRest)) {
          if (pi <= tamanioRest) //Entra dentro de la cinta
                return true;
        }
        else{
                if (media<(TAM/2)+1 && j>0) //Lo introducimos, probablemente el siguiente sea menor y podamos introducirlo tambien
                {
                        if (pi<=tamanioRest) { //Si cabe
                          return true;
                        }
                        else return false;
                }
        }
        return false;
}




int main(){
        int * cintaL;
        int * valores;

        valores = new int [TAM]; //Conjunto de programas con los valores
        cintaL = new int [TAM/2]; //Cinta
        /* initialize random seed: */
        srand (time(NULL));

        for (int i=0; i<TAM; i++) {
                int valor = rand() % 10 + 1;
                valores[i] = valor;
                cout<<valores[i]<<" ";
        }
        std::cout << '\n';

        /*
           Podemos ir analizando los valores que vamos metiendo y ir como midiendo una probabilidad de que sea bueno meter el programa actual,
           si la probabilidad de que el siguiente es que sea menor de la mitad.

         */
        int tamanioRest = TAM/2;
        int j=0;
        int media= 1; //Media de valores
        for (int i=0; i<TAM; i++) {
                media = sqrt(valores[i]*media);
                if (seleccion(valores[i],tamanioRest,media,j)) {
                        cintaL[j]=valores[i];
                        tamanioRest -= valores[i]; //Actualizamos el tamaño
                        j++;
                        cout<<"\nActualizando el tamaño: "<<tamanioRest<<endl;
                }
        }

        for (int i=0; i<TAM/2; i++) {
                cout<<cintaL[i]<<" ";
        }
        std::cout << '\n';

}

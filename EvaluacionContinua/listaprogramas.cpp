#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <unistd.h>
#include <vector>
using namespace std;

/**
   ORDENACION
 */

// Función para dividir el array y hacer los intercambios
int divide(int *array, int start, int end) {
        int left;
        int right;
        int pivot;
        int temp;

        pivot = array[start];
        left = start;
        right = end;

        // Mientras no se cruzen los índices
        while (left < right) {
                while (array[right] > pivot) {
                        right--;
                }

                while ((left < right) && (array[left] <= pivot)) {
                        left++;
                }

                // Si todavía no se cruzan los indices seguimos intercambiando
                if (left < right) {
                        temp = array[left];
                        array[left] = array[right];
                        array[right] = temp;
                }
        }

        // Los índices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
        temp = array[right];
        array[right] = array[start];
        array[start] = temp;

        // La nueva posición del pivot
        return right;
}

// Función recursiva para hacer el ordenamiento
void quicksort(int *array, int start, int end)
{
        int pivot;

        if (start < end) {
                pivot = divide(array, start, end);

                // Ordeno la lista de los menores
                quicksort(array, start, pivot - 1);

                // Ordeno la lista de los mayores
                quicksort(array, pivot + 1, end);
        }
}

void ejecucion(int * l,int tamanio){
        int tiempoTotal = 0;
        int tiempoEspera = 0;
        int tiempoEjecucion = 0;
        for (int i=0; i<tamanio; i++) {
                tiempoTotal += l[i];
                cout<<"\nEjecutando "<<l[i]<< " tiempo tiempo total: "<<tiempoTotal<<endl;
        }

}

/**
   Devuelve el tiempo de respuesta para cada programa.
   Esta constituido por el tiempo de espera, mas el tempo de ejecucion
 */
int * tiempoRespuesta(int * l,int tamanio){
        int * tiempo = new int [tamanio];

        tiempo[0] = l[0];
        for (int i=1; i<tamanio; i++) {
                //Ejecutamos
                tiempo[i]=tiempo[i-1]+l[i];
                for (int j=0; j<tamanio; j++) ;  //rebobinamos la cinta
        }

        return tiempo;
}

float tiempoMedioLectura (int * tiempo,int tamanio){
        int N = tamanio;

        float tiempoT=0.0;

        float tN = 1.0/(float) N;
        for (int i=0; i<N-1; i++) { //El ultimo proceso no cuenta para el tiempo de lectura, porque después de él no hay ningno más
                tiempoT+= (tiempo[i]);
        }


        return tiempoT*tN;
}

/**
   @brief Devuelve la posicion del valor más pequeño del vector
   @param cinta cinta con los programas
   return posicion del elemento mas pequeño
 */
int seleccion(vector<int> cinta){
        int menor = cinta[0];
        int posMenor = 0;
        if (cinta.size()>1) {
                for (int i=1; i<cinta.size(); i++) {
                        if (cinta[i]<menor) {
                                menor = cinta[i];
                                posMenor = i;
                        }
                }
        }

        return posMenor;
}

/**
* @brief Funcion leer. Lee los programas de la cinta de procesos
* @param cinta cinta de procesos
*/
void leer (vector<int> cinta){

        float TLecturaMedio = 0.0; //Tiempo de lectura medio
        float TN = (float)(cinta.size());
        while(cinta.size()>0){ //Mientras haya elementos en la cinta
                int posLectura = seleccion(cinta); //Funcion de seleccion

                if (cinta.size()>1) //No es el último tiempo
                  TLecturaMedio += cinta[posLectura];

                cinta.erase(cinta.begin()+posLectura); //Borramos de la cinta
                //Volvemos al principio, releyendo
                for (int j=0;j<cinta.size();j++){
                  cout<<cinta[j]<<" ";
                }
                cout<<endl;
        }
        cout<<"\nTML :"<<((float)TLecturaMedio/(float)TN)<<endl;
}

int main(){
        const int TAM = 5;
        vector<int> cinta(TAM);
        int * listaProgramas = new int [TAM];
        /* initialize random seed: */
        srand (time(NULL));

        for (int i=0; i<TAM; i++) {
                int valor = rand()%100;
                listaProgramas[i] = valor;
                cinta[i] = valor;
                cout<<listaProgramas[i]<<" ";
        }
        std::cout << '\n';

        int * tiempo = tiempoRespuesta(listaProgramas,TAM);
        for (int i=0; i<TAM; i++) {
                // cout<<"\nTiempo "<< i<< " "<<tiempo[i]<<endl;
        }

        cout<<"TML : "<<tiempoMedioLectura(listaProgramas,TAM);

        leer(cinta);

        // quicksort(listaProgramas,0,TAM-1);
        //
        // cout<<"\nQuicksort "<<endl;
        // tiempo = tiempoRespuesta(listaProgramas,TAM);
        //  for (int i=0;i<TAM;i++){
        //   //  cout<<"\nTiempo "<< i<< " "<<tiempo[i]<<endl;
        //  }
        //  cout<<"TML : "<<tiempoMedioLectura(listaProgramas,TAM);



}

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
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

/**
   Funcion recursiva busquedaTernaria
   Inicio ej: 0
   Fin: 20
   Esto en el caso de que tengamos 20 elementos. Ejemplo
   @param numeroBusqueda Numero a buscar
   @param array el array de busquedaTernaria
   @param inicio el primer elemento del array que queremos buscar
   @param fin el ultimo elemento de nuestro array
 */
int busquedaTernaria (int * array, int inicio, int fin, int numeroBusqueda){
        int tamanioActual = fin - inicio;
        int pCentro, pIzda, pDcha;

        //Partimos el vector en 3 partes
        int tamParte = (fin - inicio)/3;
        pIzda = inicio;
        pCentro = inicio+tamParte;
        pDcha = pCentro+tamParte;

        cout<<"\nPos izda: "<<pIzda;
        cout<<"\nPos central: "<<pCentro;
        cout<<"\nPos Dcha: "<<pDcha;
        cout<<endl;

        if (tamanioActual==1) { //Caso base
            cout<<"\nCaso base";
                return fin+1;
        }

        //Ahora lo tenemos dividido por 3 pivotes, vemos en que parte estará, en que subconjunto, ya que el array
        //suponemos está ordenado
        if (numeroBusqueda >= array[pDcha]) { //Esta en el último subconjunto
                if (numeroBusqueda == array[pDcha])
                        return pDcha+1;
                else{
                        busquedaTernaria(array,(pDcha+1),fin,numeroBusqueda);
                }
        }
        else{
                if (numeroBusqueda >= array[pCentro]) { //Esta en el centro
                        if (numeroBusqueda == array[pCentro])
                                return pCentro+1;
                        else
                                busquedaTernaria(array,(pCentro+1),fin,numeroBusqueda);
                }
                else{ //Esta en la parte izda
                        if (numeroBusqueda == array[pIzda])
                                return pIzda+1;
                        else
                                busquedaTernaria(array,(pIzda+1),fin,numeroBusqueda);
                }
        }


}

int main(){

        const int TAM = 20;
        int * v = new int [TAM]; //Creamos vector

        /* initialize random seed: */
        srand (time(NULL));
        int valor = 0;
        for (int i = 0; i < TAM; i++) {
                /* code */
                valor = rand() % 1000 + 1;
                v[i] = valor;
        }

        for (int i=0; i<TAM; i++)
                cout<<v[i]<<" ";
        cout<<endl;

        quicksort(v,0,TAM);

        for (int i=0; i<TAM; i++)
                cout<<v[i]<<" ";
        cout<<endl;

        int numeroBusqueda;

        cout<<"\nIntroduzca el num. a buscar";
        cin >> numeroBusqueda;

        cout<<"\n"<<busquedaTernaria(v,0,TAM,numeroBusqueda)<<endl;

        delete [] v; //Liberamos memoria

}

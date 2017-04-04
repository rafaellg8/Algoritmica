/**
* @title Practica 2 Algorítmica. Uso de mergesort para ordenar k vectores de n elementos
* @author Rafa L.Garrido
*/

#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <string>
#include <fstream>
//#include <algorithm>
#include <vector>
#include <chrono>
#include "mergesort.cpp"


using namespace std::chrono;
high_resolution_clock::time_point tantes, tdespues;
duration<double> transcurrido;


// std::vector<int> merge_sort(std::vector<int> v; arr[], int n)
// {
//     if(n < 2){return arr;}
//     int mid = n/2;
//     arr1 = merge_sort<T>(arr,mid);
//     T *arr2 = merge_sort<T>(arr+mid,n-mid);
//     return merge(arr1, mid, arr2, n-mid);
// }


vector<int> merge(vector<int> arr1, int size1, vector<int> arr2, int size2)
{
        int i = 0,j = 0;

        vector <int> out_array;
        out_array.resize(size1+size2);

        //Copiamos los datos
        for (int i=0;i<size1;i++){
          out_array[i]=arr1[i];
        }

        for (int i=size1;i<size1+size2;i++){
          out_array[i]=arr2[i-size1];
        }

        for (int i=0;i<out_array.size();i++)
          cout<<out_array[i]<<" ";
          cout<<endl;

        mergesort(out_array,out_array.size());
        //
        // while((i < size1) && (j < size2))
        // {
        //         if(arr1[i] >= arr2[j])
        //         {
        //                 out_array[i+j] = arr2[j];
        //                 ++j;
        //         }
        //         else
        //         {
        //                 out_array[i+j] = arr1[i];
        //                 ++i;
        //         }
        // }
        // while(i < size1)
        // {
        //         //copy the reminder
        //         out_array[i+j] = arr1[i];
        //         i++;
        // }
        // while( j < size2)
        // {
        //         out_array[i+j] = arr2[j];
        //         j++;
        // }
        return out_array;
}

int main(int argc, char * argv[])
{

        if (argc != 2)
        {
                cerr << "Formato " << argv[0] << "<ruta_del_archivo_de_entrada>" << endl;
                return -1;
        }

        /*
           Lo que haremos será leer cual es el archivo de entrada, la cantidad de filas y la cantidad de elementos por fila


         */
        int n;
        int k=n;
        int a=0;
        int num;
        string ruta=argv[1];
        ifstream archivo(ruta);
        vector<int> gigante;
        vector<int> submezcla;

        cout<<ruta<<endl;

//Leemos k y n
        archivo >> k;
        archivo >> n;

        cout<< "\nK vectores "<<k << " de n elementos "<<n<<endl;

        gigante.resize(n); //Asignamos el tamaño del vector
        submezcla.resize(n);

        tantes = high_resolution_clock::now();

        for (int i=0; i<n; i++) {
                archivo >> a;
                gigante[i]=a;
        }


        for (int j=0; j<k-1; j++) { //Recorremos los k vectores
                //Leemos los datos del vector k-esimo
                for (int i=0; i<n; i++) {
                        archivo >> a;
                        submezcla[i]=a;
                }

                gigante = merge(gigante,gigante.size(),submezcla,submezcla.size());
        }



        tdespues = high_resolution_clock::now();
        transcurrido = duration_cast<duration<double> >(tdespues - tantes);
        cout <<  n << " "<< transcurrido.count() << endl;

for (int i=0;i<gigante.size();i++)
 cout<<gigante[i]<< " ";


        cout<<k*n<<endl;
        cout<<gigante.size()<<endl;
}

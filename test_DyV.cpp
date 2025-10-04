#include <iostream>
#include <vector>
#include <chrono>
#include "DyV.h"
using namespace std;



template <typename T>
void imprimirVector(const vector<T>& v) {
    for (const auto& e : v)
        cout << e << " ";
    cout << endl;
}


template <typename T>
void testQuickSort(vector<T> original, const string& nombre,
                   void (*sortFunction)(vector<T>&, int, int)) {
    vector<T> v = original;

    auto start = chrono::high_resolution_clock::now();
    sortFunction(v, 0, v.size() - 1);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> duracion = end - start;

    cout << nombre << " | Tiempo: " << duracion.count() << " ms | Resultado: ";
    imprimirVector(v);
} 




int main(){
//vector<int> vect = { 1, 2, 4, 9, 11, 15, 21, 25, 30};
  //  cout << "Busqueda ascendente (4): " << BusquedaBinaria(4, vect, 0, vect.size() - 1) << endl;

    //vector<int> vectDesc = {30, 25, 21, 15, 11, 9, 4, 2, 1};
    //cout << "Busqueda descendente (4): " << BusquedaBinaria_INV(4, vectDesc, 0, vectDesc.size() - 1) << endl;
    srand(time(0));

    vector<int> enteros = {7, 2, 9, 4, 1, 8, 3};
    vector<float> flotantes = {4.4, 1.2, 3.1, 2.0, 5.5};
    vector<char> caracteres = {'z', 'a', 'q', 'm', 'b'};

    cout << "PRUEBA CON VECTOR ENTERO\n";
    testQuickSort(enteros, "QuickSort - Ultimo", QuickSort<int>);
    testQuickSort(enteros, "QuickSort - Primero", QuickSortPrimero<int>);
    testQuickSort(enteros, "QuickSort - Central", QuickSortCentral<int>);
    testQuickSort(enteros, "QuickSort - Aleatorio", QuickSortAleatorio<int>);

    cout << "\nPRUEBA CON VECTOR FLOAT\n";
    testQuickSort(flotantes, "QuickSort - Ultimo", QuickSort<float>);
    testQuickSort(flotantes, "QuickSort - Primero", QuickSortPrimero<float>);
    testQuickSort(flotantes, "QuickSort - Central", QuickSortCentral<float>);
    testQuickSort(flotantes, "QuickSort - Aleatorio", QuickSortAleatorio<float>);

    cout << "\nPRUEBA CON VECTOR CHAR\n";
    testQuickSort(caracteres, "QuickSort - Ultimo", QuickSort<char>);
    testQuickSort(caracteres, "QuickSort - Primero", QuickSortPrimero<char>);
    testQuickSort(caracteres, "QuickSort - Central", QuickSortCentral<char>);
    testQuickSort(caracteres, "QuickSort - Aleatorio", QuickSortAleatorio<char>);

return 0;
}

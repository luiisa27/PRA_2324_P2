#ifndef DYV_H
#define DYV_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//busqueda binaria
template<typename T>
int BusquedaBinaria(int x,std::vector<T> vect, int ini, int fin){

if (ini > fin){
cout << "No se encuentra en el array" << endl;
return -1;
}

int medio = (ini + fin)/2;

if(vect[medio] == x){
return medio;
}

else if (vect[medio]>x){
return BusquedaBinaria(x,vect,ini,medio-1);
}

else{
return BusquedaBinaria(x,vect,medio+1,fin);
}

}

template<typename T>
int BusquedaBinaria_INV(int x, std::vector<T> vect, int ini, int fin) {
    if (ini > fin) {
        cout << "No se encuentra en el array" << endl;
        return -1;
    }

    int medio = (ini + fin) / 2;

    if (vect[medio] == x) {
        return medio;
    }
    else if (vect[medio] < x) {
        return BusquedaBinaria_INV(x, vect, ini, medio - 1);
    }
    else {
        return BusquedaBinaria_INV(x, vect, medio + 1, fin);
    }
}

//quick sort
//pivote en posicion final
template<typename T>
int Partition(std::vector<T>& v, int ini, int fin) {
    T pivote = v[fin];
    int i = ini;

    for (int j = ini; j < fin; ++j) {
        if (v[j] <= pivote) {
            std::swap(v[i], v[j]);
            i++;
        }
    }
    std::swap(v[i], v[fin]);
    return i;
}

template<typename T>
void QuickSort(std::vector<T>& v, int ini, int fin) {
    if (ini < fin) {
        int pivote = Partition(v, ini, fin);
        QuickSort(v, ini, pivote - 1);
        QuickSort(v, pivote + 1, fin);
    }
}

// pivote posicion primero
template <typename T>
int PartitionPrimero(std::vector<T>& v, int ini, int fin) {
    std::swap(v[ini], v[fin]); // mueve el primer elemento al final
    return Partition(v, ini, fin); // reutiliza Partition con pivote al final
}

template <typename T>
void QuickSortPrimero(std::vector<T>& v, int ini, int fin) {
    if (ini < fin) {
        int pivot = PartitionPrimero(v, ini, fin);
        QuickSortPrimero(v, ini, pivot - 1);
        QuickSortPrimero(v, pivot + 1, fin);
    }
}

//pivote posicion central
template <typename T>
int PartitionCentral(std::vector<T>& v, int ini, int fin) {
    int centro = (ini + fin) / 2;
    std::swap(v[centro], v[fin]);
    return Partition(v, ini, fin);
}

template <typename T>
void QuickSortCentral(std::vector<T>& v, int ini, int fin) {
    if (ini < fin) {
        int pivot = PartitionCentral(v, ini, fin);
        QuickSortCentral(v, ini, pivot - 1);
        QuickSortCentral(v, pivot + 1, fin);
    }
}

// posicion pivote aleatoria
#include <cstdlib> // al inicio del archivo

template <typename T>
int PartitionAleatorio(std::vector<T>& v, int ini, int fin) {
    int randIndex = ini + rand() % (fin - ini + 1);
    std::swap(v[randIndex], v[fin]);
    return Partition(v, ini, fin);
}

template <typename T>
void QuickSortAleatorio(std::vector<T>& v, int ini, int fin) {
    if (ini < fin) {
        int pivot = PartitionAleatorio(v, ini, fin);
        QuickSortAleatorio(v, ini, pivot - 1);
        QuickSortAleatorio(v, pivot + 1, fin);
    }
}

#endif

#include <iostream>
#include <vector>
using namespace std;

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


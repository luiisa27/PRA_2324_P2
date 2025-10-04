#include <iostream>
#include <vector>
#include "DyV.h"
using namespace std;

int main(){
vector<int> vect = { 1, 2, 4, 9, 11, 15, 21, 25, 30};
    cout << "Busqueda ascendente (4): " << BusquedaBinaria(4, vect, 0, vect.size() - 1) << endl;

    vector<int> vectDesc = {30, 25, 21, 15, 11, 9, 4, 2, 1};
    cout << "Busqueda descendente (4): " << BusquedaBinaria_INV(4, vectDesc, 0, vectDesc.size() - 1) << endl;

return 0;
}

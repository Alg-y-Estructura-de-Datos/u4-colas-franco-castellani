#include <iostream>
#include "../Librerias/Cola/Cola.h"

void func_X(Cola<int>& cola) {
    Cola<int> aux;
    int dato;
    while (!cola.esVacia()) {
        dato = cola.desencolar();
        if (dato % 3 == 0) {
            aux.encolar(dato);
            aux.encolar(dato);

        }else if(dato % 2 == 0){
            aux.encolar(dato + 2);
        }
    }
    while (!aux.esVacia()) {
        cola.encolar(aux.desencolar());
    }
    
}

int main() {
    Cola<int> c;
    c.encolar(9);
    c.encolar(4);
    c.encolar(15);
    c.encolar(6);
    c.encolar(8);
    func_X(c);
    while (!c.esVacia()) std::cout << c.desencolar() << " ";
    return 0;
}
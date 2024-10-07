/*Ejercicio N°5
Implementar una función que reciba una cola de números enteros y una pila entera vacía, y
separe los elementos de la cola de tal manera que los elementos pares de la cola permanezcan
en la cola, y los elementos impares formen parte de la pila.
Observaciones:
● Al insertar los elementos en la pila, deberán aparecer en orden inverso a como estaban
en la cola: el elemento de la posición 1 de la cola estará al fondo de la pila, el de la
posición 3 será el segundo desde el fondo, etc.
● Si la cola estuviera vacía mostrar mensaje de error.
*/

#include <iostream>
#include "../Librerias/Cola/Cola.h"
#include "../Librerias/Pila/Pila.h"
using namespace std;

void separarParesImpares (Cola<int>&cola, Pila<int> &pila){
    if(cola.esVacia()){
        std::cout << "La cola esta vacia" << std::endl;
        return;
    }
    Cola<int> colaAux;
    while(!cola.esVacia()){
        int dato = cola.desencolar();
        if(dato % 2 == 0){
            colaAux.encolar(dato);
        }else{
            pila.push(dato);
        }
    }
    while(!colaAux.esVacia()){
        cola.encolar(colaAux.desencolar());
    }
}

void mostrarCola(Cola<int>cola){
    Cola<int>colaAux;
    while(!cola.esVacia()){
        int dato = cola.desencolar();
        std::cout << dato << " ";
        colaAux.encolar(dato);
    }

    while(!colaAux.esVacia()){
        cola.encolar(colaAux.desencolar());
    }
}


int main() {

    cout << "Ejercicio 04/03" << endl;

    Cola<int> cola;
    Pila<int> pila;

    // Lectura de la cola
    cout << "Ingrese numeros para la cola (ingrese -1 para terminar): " << endl;
    int input;
    while (cin >> input && input != -1) {
        cola.encolar(input);
    }

    // Separar pares e impares
    separarParesImpares(cola, pila);

    // Mostrar el contenido de la cola después de la separación
    cout << "Cola despues de quitar numeros impares: ";
    mostrarCola(cola);

    // Mostrar el contenido de la pila
    cout << "Pila con elementos impares (orden inverso): ";
    while (!pila.esVacia()) {
        cout << pila.pop() << " ";
    }
    cout << endl;

    return 0;
}
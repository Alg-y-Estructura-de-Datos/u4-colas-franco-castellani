/*Ejercicio N°4
Crear un programa que solicite números enteros al usuario hasta que desee, almacenar los
números en una cola, pedir también un numero entero "n". Luego crear una función que
recibiendo una cola y un número entero “n”, si el "n" se encuentra en una de las posiciones de
la cola. Devuelva la suma de los elementos de la cola hasta llegar a "n" (sin incluir a n). Si el
número "n" no se encuentra en la cola, la función devuelve la suma de todos los elementos de
la cola. Imprimir primero la cola antes de la suma de sus elementos.*/

#include <iostream>
#include "../Librerias/Cola/Cola.h"

using namespace std;


int sumarHastaN(Cola<int> &cola, int n) {
    Cola<int> colaAux;  // Cola auxiliar para mantener el orden original
    int suma = 0;
    bool encontrado = false;

    // Recorremos la cola original
    while (!cola.esVacia()) {
        int dato = cola.desencolar();

        if (dato == n) {
            encontrado = true;  // Si encontramos el número "n", dejamos de sumar
            colaAux.encolar(dato);  // Almacenamos el número "n" en la cola auxiliar
            break;
        }
        else {
            // Sumar el dato si no es "n"
            suma += dato;
            colaAux.encolar(dato);  // Almacenamos el dato en la cola auxiliar
        }
    }

    while (!colaAux.esVacia()) {
        cola.encolar(colaAux.desencolar());
    }

    // Si "n" no se encuentra, sumar los elementos restantes de la cola
    if (!encontrado) {
        int sumaTotal = 0;

        // Transferir todos los elementos restantes a colaAux
        while (!cola.esVacia()) {
           sumaTotal += cola.desencolar();
        }

        // Restaurar la cola original después de sumar
        while (!colaAux.esVacia()) {
            cola.encolar(colaAux.desencolar());
        }

        return sumaTotal;
    }

    return suma;
}

void mostrarCola(Cola<int> &cola) {
    Cola<int> colaAux;

    // Mostrar los elementos de la cola sin modificarla
    while (!cola.esVacia()) {
        int dato = cola.desencolar();
        cout << dato << " ";
        colaAux.encolar(dato);
    }
    cout << endl;

    // Transferir los elementos de vuelta a la cola original
    while (!colaAux.esVacia()) {
        cola.encolar(colaAux.desencolar());
    }
}

int main() {

    cout << "Ejercicio 04/03" << endl;

    Cola<int> cola;
    int n;

    // Lectura de la cola
    cout << "Ingrese numeros para la cola (ingrese -1 para terminar): " << endl;
    int input;
    while (cin >> input && input != -1) {
        cola.encolar(input);
    }

    // Lectura del número n
    cout << "Ingrese el numero n: ";
    cin >> n;

    // Mostrar la cola antes de realizar la suma
    cout << "Cola original: ";
    mostrarCola(cola);

    // Calcular la suma hasta n
    int suma = sumarHastaN(cola, n);

    // Mostrar el resultado
    cout << "La suma de los elementos hasta llegar a " << n << " (sin incluirlo) es: " << suma << endl;

    return 0;
}
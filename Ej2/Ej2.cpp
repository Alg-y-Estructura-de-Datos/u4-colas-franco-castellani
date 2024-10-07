/*Ejercicio N°2
Implementar una función que suprima de la cola todos los elementos mayores que un número
“n” dado como límite. Al final se debe imprimir la cola depurada sin perder el orden que había
desde la cola original.*/

#include <iostream>
#include "../Librerias/Cola/Cola.h"
using namespace std;

void eliminarMayor(Cola<int> cola, int n)
{

    Cola<int> aux; // cola auxiliar para agregar los menores a n

    while (!cola.esVacia())
    {
        if (cola.peek() <= n)
        {
            aux.encolar(cola.peek());
        }
    }

    while (!aux.esVacia())
    {
        cola.encolar(aux.desencolar());
    }
}

int main()
{
    cout << "Ejercicio 04/02" << endl;

    Cola<int> cola;
    int limite;

    // Lectura de la cola
    cout << "Ingrese numeros para la cola (ingrese -1 para terminar): " << endl;
    int nro = 0;
    while (nro > -1)
    {
        cin >> nro;
        cola.encolar(nro);
    }

    while(!cola.esVacia()){
        cola.desencolar();
    }

    // Lectura del límite
    cout << "Ingrese el limite: ";
    cin >> limite;

    // Eliminar los elementos mayores que el límite
    eliminarMayor(cola, limite);

    // Mostrar la cola depurada
    cout << "Cola depurada: ";
    while (!cola.esVacia())
    {
        cout << cola.desencolar() << " ";
    }
    cout << endl;

    return 0;
}

#include "ListaNotas.h"

void ListaNotas::insertar(Nota* nuevaNota) {
    if (!cabeza) {
        cabeza = nuevaNota;
    } else {
        Nota* aux = cabeza;
        while (aux->getSiguiente()) {
            aux = aux->getSiguiente();
        }
        aux->setSiguiente(nuevaNota);
    }
}

float ListaNotas::calcularPromedio() const {
    if (!cabeza) return 0.0f;
    
    float suma = 0.0f;
    int count = 0;
    Nota* aux = cabeza;
    
    while (aux) {
        suma += aux->getValor();
        count++;
        aux = aux->getSiguiente();
    }
    
    return (count > 0) ? suma / count : 0.0f;
}

void ListaNotas::limpiar() {
    while (cabeza) {
        Nota* temp = cabeza;
        cabeza = cabeza->getSiguiente();
        delete temp;
    }
}
#pragma once
#ifndef LISTANOTAS_H
#define LISTANOTAS_H

#include "Nota.h"

class ListaNotas {
private:
    Nota* cabeza;
    
public:
    ListaNotas() : cabeza(nullptr) {}
    ~ListaNotas() { limpiar(); }
    
    void insertar(Nota* nuevaNota);
    float calcularPromedio() const;
    void limpiar();
};

#endif
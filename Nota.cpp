#include "Nota.h"

Nota::Nota(float v) : valor(v), siguiente(nullptr) {}   

Nota::~Nota() {}

float Nota::getValor() const { return valor; }

Nota* Nota::getSiguiente() const { return siguiente; }  

void Nota::setSiguiente(Nota* sig) { siguiente = sig; }
#include "Inscripcion.h"
#include <iostream>

Inscripcion::Inscripcion(Alumno* alum, Curso* cur) 
    : alumno(alum), curso(cur), siguiente(nullptr) {}

Inscripcion::~Inscripcion() {}

Alumno* Inscripcion::getAlumno() const { return alumno; }
Curso* Inscripcion::getCurso() const { return curso; }
ListaNotas& Inscripcion::getNotas() { return notas; }

Inscripcion* Inscripcion::getSiguiente() const { return siguiente; }
void Inscripcion::setSiguiente(Inscripcion* sig) { siguiente = sig; }

float Inscripcion::calcularPromedio() const {
    return notas.calcularPromedio();
}

void Inscripcion::agregarNota(float nota) {
    notas.insertar(new Nota(nota));
}
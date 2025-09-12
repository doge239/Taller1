#pragma once
#ifndef INSCRIPCION_H
#define INSCRIPCION_H

#include "Alumno.h"
#include "Curso.h"
#include "ListaNotas.h"

class Inscripcion {
private:
    Alumno* alumno;
    Curso* curso;
    ListaNotas notas;
    Inscripcion* siguiente;
    
public:
    Inscripcion(Alumno* alum, Curso* cur);
    ~Inscripcion();
    
    Alumno* getAlumno() const;
    Curso* getCurso() const;
    ListaNotas& getNotas();
    
    Inscripcion* getSiguiente() const;
    void setSiguiente(Inscripcion* sig);
    
    float calcularPromedio() const;
    void agregarNota(float nota);
};

#endif
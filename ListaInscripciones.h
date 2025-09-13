#pragma once
#ifndef LISTAINSCRIPCIONES_H
#define LISTAINSCRIPCIONES_H

#include "Inscripcion.h"

class ListaInscripciones {
private:
    Inscripcion* cabeza;
public:
    ListaInscripciones();
    ~ListaInscripciones();
    
    Inscripcion* getCabeza() const;
    void setCabeza(Inscripcion* nuevaCabeza);

    void insertar(Inscripcion* nuevo);
    Inscripcion* buscarInscripcion(int idAlumno, const std::string& codigoCurso);
    bool eliminarInscripcion(int idAlumno, const std::string& codigoCurso);
    void eliminarInscripcionesAlumno(int idAlumno);
    void eliminarInscripcionesCurso(const std::string& codigoCurso);
    void limpiar();
};

#endif
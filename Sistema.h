#pragma once
#ifndef SISTEMA_H
#define SISTEMA_H

#include "Alumno.h"
#include "Curso.h"
#include "Inscripcion.h"
#include "ListaAlumnos.h"
#include "ListaCursos.h"
#include "ListaInscripciones.h"

class Sistema {
private:
    ListaAlumnos alumnos;
    ListaCursos cursos;
    ListaInscripciones inscripciones;
    
    
    void mostrarAlumno(Alumno* alumno) const;
    void mostrarCurso(Curso* curso) const;
    void mostrarInscripcionesAlumno(int idAlumno) const;

    void eliminarInscripcionesAlumno(int idAlumno);
    void eliminarInscripcionesCurso(const std::string& codigoCurso);
    
public:
    Sistema();
    ~Sistema();
    
    void menu();
    
    
    void crearAlumno();
    void buscarAlumno();
    void eliminarAlumno();
    void listarAlumnos();
    void listarAlumnosPorCarrera();
    
    
    void crearCurso();
    void buscarCurso();
    void eliminarCurso();
    void listarCursos();
    
    
    void inscribirAlumno();
    void eliminarInscripcion();
    
    
    void agregarNota();
    
    
    void reporteAlumno();
    void promediosCurso();
};

#endif
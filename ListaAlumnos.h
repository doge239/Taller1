#pragma once
#ifndef LISTAALUMNOS_H
#define LISTAALUMNOS_H

#include "Alumno.h"
#include <vector>

class ListaAlumnos {
private:
    Alumno* cabeza;
public:
    ListaAlumnos();
    ~ListaAlumnos();
    
    Alumno* getCabeza() const;
    void setCabeza(Alumno* nuevaCabeza);

    void insertar(Alumno* nuevo);
    Alumno* buscarPorId(int id);
    Alumno* buscarPorNombre(const std::string& nombre);
    std::vector<Alumno*> buscarTodosPorNombre(const std::string& nombre);
    std::vector<Alumno*> buscarPorCarrera(const std::string& carrera);
    bool eliminarPorId(int id);
    void limpiar();
};

#endif
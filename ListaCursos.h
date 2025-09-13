#pragma once
#ifndef LISTACURSOS_H
#define LISTACURSOS_H

#include "Curso.h"
#include <vector>

class ListaCursos {
private:
    Curso* cabeza;
public:
    ListaCursos();
    ~ListaCursos();
    
    Curso* getCabeza() const;
    void setCabeza(Curso* nuevaCabeza);

    void insertar(Curso* nuevo);
    Curso* buscarPorCodigo(const std::string& codigo);
    Curso* buscarPorNombre(const std::string& nombre);
    std::vector<Curso*> buscarTodosPorNombre(const std::string& nombre); // AÑADIDO
    bool eliminarPorCodigo(const std::string& codigo);
    void limpiar();
};

#endif
#include "ListaAlumnos.h"
#include <vector>

ListaAlumnos::ListaAlumnos() : cabeza(nullptr) {}

ListaAlumnos::~ListaAlumnos() {
    limpiar();
}

Alumno* ListaAlumnos::getCabeza() const {
    return cabeza;
}

void ListaAlumnos::setCabeza(Alumno* nuevaCabeza) {
    cabeza = nuevaCabeza;
}

void ListaAlumnos::insertar(Alumno* nuevo) {
    if (!cabeza) {
        cabeza = nuevo;
    } else {
        Alumno* aux = cabeza;
        while (aux->getSiguiente()) {
            aux = aux->getSiguiente();
        }
        aux->setSiguiente(nuevo);
    }
}

Alumno* ListaAlumnos::buscarPorId(int id) {
    Alumno* aux = cabeza;
    while (aux) {
        if (aux->getId() == id) return aux;
        aux = aux->getSiguiente();
    }
    return nullptr;
}

Alumno* ListaAlumnos::buscarPorNombre(const std::string& nombre) {
    Alumno* aux = cabeza;
    while (aux) {
        if (aux->getNombre() == nombre) return aux;
        aux = aux->getSiguiente();
    }
    return nullptr;
}


std::vector<Alumno*> ListaAlumnos::buscarTodosPorNombre(const std::string& nombre) {
    std::vector<Alumno*> resultados;
    Alumno* aux = cabeza;
    while (aux) {
        if (aux->getNombre() == nombre) {
            resultados.push_back(aux);
        }
        aux = aux->getSiguiente();
    }
    return resultados;
}

std::vector<Alumno*> ListaAlumnos::buscarPorCarrera(const std::string& carrera) {
    std::vector<Alumno*> resultados;
    Alumno* aux = cabeza;
    while (aux) {
        if (aux->getCarrera() == carrera) {
            resultados.push_back(aux);
        }
        aux = aux->getSiguiente();
    }
    return resultados;
}

bool ListaAlumnos::eliminarPorId(int id) {
    if (!cabeza) return false;
    
    if (cabeza->getId() == id) {
        Alumno* temp = cabeza;
        cabeza = cabeza->getSiguiente();
        delete temp;
        return true;
    }
    
    Alumno* aux = cabeza;
    while (aux->getSiguiente()) {
        if (aux->getSiguiente()->getId() == id) {
            Alumno* temp = aux->getSiguiente();
            aux->setSiguiente(temp->getSiguiente());
            delete temp;
            return true;
        }
        aux = aux->getSiguiente();
    }
    return false;
}

void ListaAlumnos::limpiar() {
    while (cabeza) {
        Alumno* temp = cabeza;
        cabeza = cabeza->getSiguiente();
        delete temp;
    }
}
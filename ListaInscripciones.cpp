#include "ListaInscripciones.h"

ListaInscripciones::ListaInscripciones() : cabeza(nullptr) {}

ListaInscripciones::~ListaInscripciones() {
    limpiar();
}

Inscripcion* ListaInscripciones::getCabeza() const {
    return cabeza;
}

void ListaInscripciones::setCabeza(Inscripcion* nuevaCabeza) {
    cabeza = nuevaCabeza;
}

void ListaInscripciones::insertar(Inscripcion* nuevo) {
    if (!cabeza) {
        cabeza = nuevo;
    } else {
        Inscripcion* aux = cabeza;
        while (aux->getSiguiente()) {
            aux = aux->getSiguiente();
        }
        aux->setSiguiente(nuevo);
    }
}

Inscripcion* ListaInscripciones::buscarInscripcion(int idAlumno, const std::string& codigoCurso) {
    Inscripcion* aux = cabeza;
    while (aux) {
        if (aux->getAlumno()->getId() == idAlumno && 
            aux->getCurso()->getCodigo() == codigoCurso) {
            return aux;
        }
        aux = aux->getSiguiente();
    }
    return nullptr;
}

bool ListaInscripciones::eliminarInscripcion(int idAlumno, const std::string& codigoCurso) {
    if (!cabeza) return false;
    
    if (cabeza->getAlumno()->getId() == idAlumno && 
        cabeza->getCurso()->getCodigo() == codigoCurso) {
        Inscripcion* temp = cabeza;
        cabeza = cabeza->getSiguiente();
        delete temp;
        return true;
    }
    
    Inscripcion* aux = cabeza;
    while (aux->getSiguiente()) {
        if (aux->getSiguiente()->getAlumno()->getId() == idAlumno && 
            aux->getSiguiente()->getCurso()->getCodigo() == codigoCurso) {
            Inscripcion* temp = aux->getSiguiente();
            aux->setSiguiente(temp->getSiguiente());
            delete temp;
            return true;
        }
        aux = aux->getSiguiente();
    }
    return false;
}

void ListaInscripciones::eliminarInscripcionesAlumno(int idAlumno) {
    Inscripcion* aux = cabeza;
    Inscripcion* prev = nullptr;
    
    while (aux) {
        if (aux->getAlumno()->getId() == idAlumno) {
            Inscripcion* temp = aux;
            if (prev) {
                prev->setSiguiente(aux->getSiguiente());
            } else {
                cabeza = aux->getSiguiente();
            }
            aux = aux->getSiguiente();
            delete temp;
        } else {
            prev = aux;
            aux = aux->getSiguiente();
        }
    }
}

void ListaInscripciones::eliminarInscripcionesCurso(const std::string& codigoCurso) {
    Inscripcion* aux = cabeza;
    Inscripcion* prev = nullptr;
    
    while (aux) {
        if (aux->getCurso()->getCodigo() == codigoCurso) {
            Inscripcion* temp = aux;
            if (prev) {
                prev->setSiguiente(aux->getSiguiente());
            } else {
                cabeza = aux->getSiguiente();
            }
            aux = aux->getSiguiente();
            delete temp;
        } else {
            prev = aux;
            aux = aux->getSiguiente();
        }
    }
}

void ListaInscripciones::limpiar() {
    while (cabeza) {
        Inscripcion* temp = cabeza;
        cabeza = cabeza->getSiguiente();
        delete temp;
    }
}
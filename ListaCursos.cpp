#include "ListaCursos.h"
#include <vector>

ListaCursos::ListaCursos() : cabeza(nullptr) {}

ListaCursos::~ListaCursos() {
    limpiar();
}

Curso* ListaCursos::getCabeza() const {
    return cabeza;
}

void ListaCursos::setCabeza(Curso* nuevaCabeza) {
    cabeza = nuevaCabeza;
}

void ListaCursos::insertar(Curso* nuevo) {
    if (!cabeza) {
        cabeza = nuevo;
    } else {
        Curso* aux = cabeza;
        while (aux->getSiguiente()) {
            aux = aux->getSiguiente();
        }
        aux->setSiguiente(nuevo);
    }
}

Curso* ListaCursos::buscarPorCodigo(const std::string& codigo) {
    Curso* aux = cabeza;
    while (aux) {
        if (aux->getCodigo() == codigo) return aux;
        aux = aux->getSiguiente();
    }
    return nullptr;
}

Curso* ListaCursos::buscarPorNombre(const std::string& nombre) {
    Curso* aux = cabeza;
    while (aux) {
        if (aux->getNombre() == nombre) return aux;
        aux = aux->getSiguiente();
    }
    return nullptr;
}

// ¡MÉTODO FALTANTE! - Agrégalo aquí
std::vector<Curso*> ListaCursos::buscarTodosPorNombre(const std::string& nombre) {
    std::vector<Curso*> resultados;
    Curso* aux = cabeza;
    while (aux) {
        if (aux->getNombre() == nombre) {
            resultados.push_back(aux);
        }
        aux = aux->getSiguiente();
    }
    return resultados;
}

bool ListaCursos::eliminarPorCodigo(const std::string& codigo) {
    if (!cabeza) return false;
    
    if (cabeza->getCodigo() == codigo) {
        Curso* temp = cabeza;
        cabeza = cabeza->getSiguiente();
        delete temp;
        return true;
    }
    
    Curso* aux = cabeza;
    while (aux->getSiguiente()) {
        if (aux->getSiguiente()->getCodigo() == codigo) {
            Curso* temp = aux->getSiguiente();
            aux->setSiguiente(temp->getSiguiente());
            delete temp;
            return true;
        }
        aux = aux->getSiguiente();
    }
    return false;
}

void ListaCursos::limpiar() {
    while (cabeza) {
        Curso* temp = cabeza;
        cabeza = cabeza->getSiguiente();
        delete temp;
    }
}
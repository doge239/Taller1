#include "Curso.h"

Curso::Curso(std::string cod, std::string nom, int cupo, std::string carr, std::string prof)
    : codigo(cod), nombre(nom), cupoMaximo(cupo), Carrera(carr), Profesor(prof), siguiente(nullptr) {}

Curso::~Curso() {}

std::string Curso::getCodigo() const { return codigo; }
std::string Curso::getNombre() const { return nombre; }
std::string Curso::getCarrera() const { return Carrera; }
int Curso::getCupoMaximo() const { return cupoMaximo; } 
std::string Curso::getProfesor() const { return Profesor; } 

Curso* Curso::getSiguiente() const { return siguiente; }   
void Curso::setSiguiente(Curso* sig) { siguiente = sig; }
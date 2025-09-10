#include "Alumno.h"

Alumno::Alumno(int id, std::string nom, std::string ape, std::string carr, std::string fecha)
    : id(id), nombre(nom), apellido(ape), carrera(carr), fechaIngreso(fecha), siguiente(nullptr) {}

Alumno::~Alumno() {}

int Alumno::getId() const { return id; }
std::string Alumno::getNombre() const { return nombre; }
std::string Alumno::getApellido() const { return apellido; }
std::string Alumno::getCarrera() const { return carrera; }
std::string Alumno::getFechaIngreso() const { return fechaIngreso; } 

Alumno* Alumno::getSiguiente() const { return siguiente; }
void Alumno::setSiguiente(Alumno* sig) { siguiente = sig; }
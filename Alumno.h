#pragma once
#ifndef ALUMNO_H
#define ALUMNO_H
#include <string>

class Alumno {
private:
    int id;
    std::string nombre;
    std::string apellido;
    std::string carrera;
    std::string fechaIngreso;
    Alumno* siguiente;
public:
    Alumno(int id, std::string nom, std::string ape, std::string carr, std::string fecha);
    ~Alumno();

    int getId() const;
    std::string getNombre() const;
    std::string getApellido() const;
    std::string getCarrera() const;
    std::string getFechaIngreso() const; 

    Alumno* getSiguiente() const;
    void setSiguiente(Alumno* sig);
};

#endif
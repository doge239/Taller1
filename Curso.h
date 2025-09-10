#ifndef CURSO_H
#define CURSO_H
#include <string>

class Curso {
private:
    std::string codigo;
    std::string nombre;
    int cupoMaximo;
    std::string Carrera;
    std::string Profesor;
    Curso* siguiente;   
public:
    Curso(std::string cod, std::string nom, int cupo, std::string carr, std::string prof);
    ~Curso();

    std::string getCodigo() const;
    std::string getNombre() const;
    std::string getCarrera() const;
    int getCupoMaximo() const; // Nuevo método
    std::string getProfesor() const; // Nuevo método

    Curso* getSiguiente() const;   
    void setSiguiente(Curso* sig); 
};

#endif
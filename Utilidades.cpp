#include "Utilidades.h"

int Utilidades::leerEntero(const std::string& mensaje) {
    int valor;
    while (true) {
        std::cout << mensaje;
        if (std::cin >> valor) {
            limpiarBuffer();
            return valor;
        } else {
            std::cout << "Error: Por favor ingrese un numero entero valido.\n";
            std::cin.clear();
            limpiarBuffer();
        }
    }
}

float Utilidades::leerFloat(const std::string& mensaje) {
    float valor;
    while (true) {
        std::cout << mensaje;
        if (std::cin >> valor) {
            limpiarBuffer();
            return valor;
        } else {
            std::cout << "Error: Por favor ingrese un numero decimal valido.\n";
            std::cin.clear();
            limpiarBuffer();
        }
    }
}

std::string Utilidades::leerString(const std::string& mensaje) {
    std::string valor;
    std::cout << mensaje;
    std::getline(std::cin, valor);
    return valor;
}

void Utilidades::limpiarBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
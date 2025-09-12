#pragma once
#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <iostream>
#include <string>
#include <limits>

class Utilidades {
public:
    static int leerEntero(const std::string& mensaje);
    static float leerFloat(const std::string& mensaje);
    static std::string leerString(const std::string& mensaje);
    static void limpiarBuffer();
};

#endif
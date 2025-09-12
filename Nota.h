#pragma once
#ifndef NOTA_H
#define NOTA_H

class Nota {
private:
    float valor;
    Nota* siguiente;
public:
    Nota(float v);
    ~Nota();

    float getValor() const;
    Nota* getSiguiente() const;
    void setSiguiente(Nota* sig);
};

#endif
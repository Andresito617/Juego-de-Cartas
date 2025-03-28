#ifndef CARTA_H
#define CARTA_H

#include <string>
#include <iostream>

class Carta {
public:
    std::string color;
    int numero;

    Carta(std::string color, int numero);
    void mostrar() const;
};

#endif // CARTA_H
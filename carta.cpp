#include "carta.h"
#include <iostream>

// Definiciones de colores para la consola
#define BG_AZUL "\x1B[44m"
#define BG_VERDE "\x1B[42m"
#define BG_ROJO "\x1B[41m"
#define BG_NARANJA "\x1B[48;2;255;128;0m"
#define RESET "\x1B[0m"

Carta::Carta(std::string color, int numero) : color(color), numero(numero) {}

void Carta::mostrar() const {
    if (color == "azul") {
        std::cout << BG_AZUL << " " << numero << " " << RESET << " ";
    } else if (color == "verde") {
        std::cout << BG_VERDE << " " << numero << " " << RESET << " ";
    } else if (color == "rojo") {
        std::cout << BG_ROJO << " " << numero << " " << RESET << " ";
    } else if (color == "naranja") {
        std::cout << BG_NARANJA << " " << numero << " " << RESET << " ";
    }
}

bool Carta::operator==(const Carta& otraCarta) const {
    return color == otraCarta.color && numero == otraCarta.numero;
}
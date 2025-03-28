#include "jugador.h"
#include <iostream>

void Jugador::mostrarMano() const {
    std::cout << "Tus cartas son: ";
    for (const auto& carta : mano) {
        carta.mostrar();
    }
    std::cout << std::endl;
}
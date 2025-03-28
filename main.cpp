#include <iostream>
#include "juego.h"
#include <ostream>

int main() {
    int numJugadores;
    std::cout << "Número de jugadores (Mínimo 2, Máximo 4): ";
    std::cin >> numJugadores;

    Juego juego(numJugadores);
    juego.iniciarJuego();

    for (int i = 0; i < juego.numRondas; i++) {
        std::cout << "--- Ronda " << i + 1 << " ---" << std::endl;
        juego.jugarRonda();
    }

    juego.determinarGanador();

    return 0;
}
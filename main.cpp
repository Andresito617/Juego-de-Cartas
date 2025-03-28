#include <iostream>
#include "juego.h"
#include <limits>

int main() {
    int numJugadores;
    while (true) {
        std::cout << "Número de jugadores (Mínimo 2, Máximo 4): ";
        std::cin >> numJugadores;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada inválida. Introduce un número válido." << std::endl;
        } else if (numJugadores < 2 || numJugadores > 4) {
            std::cout << "Número de jugadores fuera de rango. Introduce un número válido (2-4)." << std::endl;
        } else {
            break;
        }
    }

    Juego juego(numJugadores);
    juego.iniciarJuego();

    // Jugar rondas
    for (int i = 0; i < juego.numRondas; i++) {
        std::cout << "--- Ronda " << i + 1 << " ---" << std::endl;
        juego.jugarRonda();
    }

    // Determinar el ganador del juego
    juego.determinarGanador();

    return 0;
}
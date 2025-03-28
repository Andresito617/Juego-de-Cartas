#include "juego.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
#include <stdlib.h>

using namespace std;

Juego::Juego(int numJugadores) {
    jugadores.resize(numJugadores);
    turnoActual = 0;
}

void Juego::iniciarJuego() {
    crearMazo();
    barajarMazo();
    repartirCartas();
    turnoActual = obtenerJugadorInicial();
    numRondas = jugadores[0].mano.size(); // Número de rondas = cartas por jugador
}

void Juego::crearMazo() {
    std::string colores[] = { "azul", "verde", "rojo", "naranja" };
    for (const auto& color : colores) {
        for (int numero = 1; numero <= 9; numero++) {
            mazo.emplace_back(color, numero);
        }
    }
}

void Juego::barajarMazo() {
    std::shuffle(mazo.begin(), mazo.end(), std::default_random_engine(std::time(0)));
}

void Juego::repartirCartas() {
    int cartasPorJugador = mazo.size() / jugadores.size();
    for (int i = 0; i < jugadores.size(); i++) {
        jugadores[i].mano.assign(mazo.begin() + i * cartasPorJugador, mazo.begin() + (i + 1) * cartasPorJugador);
    }
}

int Juego::obtenerJugadorInicial() const {
    return std::rand() % jugadores.size();
}

void Juego::jugarRonda() {
    cout << "--- Ronda ---" << std::endl;

    cartasJugadas.clear(); // Limpiar cartas jugadas de la ronda anterior

    // El jugador inicial elige una carta de su mano
    jugadores[turnoActual].mostrarMano();
    int cartaIndex;
    cout << "Jugador " << turnoActual + 1 << ", elige una carta (1-" << jugadores[turnoActual].mano.size() << "): ";
    std::cin >> cartaIndex;
    Carta cartaJugada = jugadores[turnoActual].mano[cartaIndex - 1];
    jugadores[turnoActual].mano.erase(jugadores[turnoActual].mano.begin() + cartaIndex - 1);
    cartasJugadas.push_back(cartaJugada);

    cout << "Jugador " << turnoActual + 1 << " juega: ";
    cartaJugada.mostrar();
    cout << std::endl;

    // Los demás jugadores juegan sus cartas
    for (int i = 0; i < jugadores.size(); i++) {
        if (i != turnoActual) {
            jugadores[i].mostrarMano();
            cout << "Jugador " << i + 1 << ", elige una carta (1-" << jugadores[i].mano.size() << "): ";
            std::cin >> cartaIndex;
            Carta cartaJugador = jugadores[i].mano[cartaIndex - 1];
            jugadores[i].mano.erase(jugadores[i].mano.begin() + cartaIndex - 1);
            cartasJugadas.push_back(cartaJugador);

            cout << "Jugador " << i + 1 << " juega: ";
            cartaJugador.mostrar();
            cout << std::endl;
            
        }
    }

    // Determinar el ganador de la ronda
    int ganadorRonda = determinarGanadorRonda();

    cout << "El ganador de la ronda es el jugador " << ganadorRonda + 1 << std::endl;

    // Retirar las cartas jugadas
    retirarCartasJugadas();

    // Actualizar el puntaje de los jugadores
    jugadores[ganadorRonda].puntaje++;

    // Mostrar puntaje de los jugadores
    for (int i = 0; i < jugadores.size(); i++) {
        cout << "Jugador " << i + 1 << ": " << jugadores[i].puntaje << " puntos" << std::endl;
    }

    // Actualizar el turno actual
    turnoActual = ganadorRonda; // El ganador de la ronda inicia la siguiente ronda
    
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int Juego::determinarGanadorRonda() {
    int ganadorRonda = 0;
    for (int i = 1; i < cartasJugadas.size(); i++) {
        if (cartasJugadas[i].color == cartasJugadas[ganadorRonda].color &&
            cartasJugadas[i].numero > cartasJugadas[ganadorRonda].numero) {
            ganadorRonda = i;
        }
    }
    return ganadorRonda;
}

void Juego::retirarCartasJugadas() {
    // Las cartas jugadas ya se han retirado de las manos de los jugadores
}

void Juego::determinarGanador() const {
    int ganadorJuego = 0;
    for (int i = 1; i < jugadores.size(); i++) {
        if (jugadores[i].puntaje > jugadores[ganadorJuego].puntaje) {
            ganadorJuego = i;
        }
    }
    cout << "El ganador del juego es el jugador " << ganadorJuego + 1 << std::endl;
}
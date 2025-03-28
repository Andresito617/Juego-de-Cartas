#ifndef JUEGO_H
#define JUEGO_H

#include <vector>
#include "jugador.h"
#include "carta.h"

class Juego {
public:
    std::vector<Jugador> jugadores;
    std::vector<Carta> mazo;
    int turnoActual;
    int numRondas;

    Juego(int numJugadores);
    void iniciarJuego();
    void jugarRonda();
    void determinarGanador() const;

private:
    void crearMazo();
    void barajarMazo();
    void repartirCartas();
    int obtenerJugadorInicial() const;
    int determinarGanadorRonda();
    void retirarCartasJugadas(const std::vector<Carta>& cartasJugadasRonda);
    std::vector<Carta> cartasJugadas;
};

#endif // JUEGO_H
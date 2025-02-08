# Juego de Triqui en C++

Este repositorio contiene la implementación del clásico juego de Triqui (Tic-Tac-Toe) en C++. El juego permite la interacción entre un jugador humano y la computadora, con una inteligencia artificial básica que permite a la máquina realizar jugadas estratégicas.

## Requisitos

- Compilador de C++ (por ejemplo, `g++`).
- Sistema operativo compatible con la ejecución de programas en C++.

## Instalación

1. Clona este repositorio en tu máquina local:

   ```bash
    git clone https://github.com/tu-usuario/triqui-cpp.git
    cd triqui-cpp
    g++ -o triqui main.cpp

## Ejecucion
- Después de compilar el código, ejecuta el programa:

   ```bash
    ./triqui

## Instrucciones de Juego

1. **Inicio del Juego**: Al iniciar el programa, se lanzará un dado virtual para determinar quién comienza el juego: el jugador humano o la computadora.

2. **Turnos**:
    - El jugador humano selecciona una casilla del tablero ingresando un número del 1 al 9.
    - La computadora realizará su jugada automáticamente, intentando ganar o bloquear al jugador humano.

3. **Objetivo**: El objetivo es completar una línea horizontal, vertical o diagonal con tu símbolo (`X` o `O`).

4. **Fin del Juego**: El juego termina cuando un jugador gana o cuando se produce un empate.

5. **Jugar de Nuevo**: Después de cada partida, se te preguntará si deseas jugar de nuevo.

## Estructura de codigo
- main.cpp: Contiene la lógica principal del juego, incluyendo la interacción con el usuario y la inteligencia artificial de la computadora.
- Funciones principales:

  - **dado()**: Determina quién comienza el juego.

  - **tablero()**: Muestra el estado actual del tablero.

  - **victoria()**: Verifica si hay un ganador.

  - **turnoJugador()**: Maneja el turno del jugador humano.

  - **turnoComputadora()**: Maneja el turno de la computadora.

## Licencia

Este proyecto está bajo la licencia MIT. Consulta el archivo LICENSE para más detalles.


## ¡Diviértete jugando al Triqui! 🎮
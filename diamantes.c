#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "diamantes.h"

void jugador () {
	mostrar_tablero(JUGADOR);
}

void pc () {
	mostrar_tablero(PC);
}

void ganar () {

}

void guardar () {

}

void mostrar_tablero (int tipo_juego) {
	// Preguntamos y validamos la dimensión
	cls();
	int dimension;
	printf("Dimension: ");
	scanf("%i", &dimension);
	getchar();
	
	if (dimension < 4) {
		printf("El tablero debe poseer una dimension superior o igual a 4.\n");
		getchar();

		return;
	}

	// Llenamos los valores iniciales de las casillas
	int ultimo = dimension - 1;
	int casillas[ dimension ][ dimension ];
	int x, y;
	srand(time(NULL));

	for (y = 0; y < dimension; y++) {
		for (x = 0; x < dimension; x++) {
			casillas[ y ][ x ] = rand() % dimension + 1;
		}
	}

	// Inicializamos el jugador
	int jugador = (tipo_juego == PC) ? JUGADOR : JUGADOR_1 ;
	// Empezamos el loop del juego y lo vamos mostrando
	int huecos = 0;
	int puntaje1 = 0;
	int puntaje2 = 0;
	int f, c, fila, columna, casilla_y, casilla_x, numero, by;

	while (1) {
		// Mostramos el estado
		cls();

		if (tipo_juego == PC) {
			printf("Jugador: %i\n", puntaje1);
			printf("Maquina: %i\n\n", puntaje2);
		} else {
			printf("Jugador1: %i\n", puntaje1);
			printf("Jugador2: %i\n\n", puntaje2);
		}

		for (y = 0; y <= dimension; y++) {
			for (x = 0; x <= dimension; x++) {
				if (y == 0 || x == 0) {
					// Mostramos las columnas
					printf("%i |", (y == 0) ? x : y );
				} else {
					f = y - 1;
					c = x - 1;
					printf("%i |", casillas[ f ][ c ]);
				}
			}

			printf("\n");
		}

		switch (jugador) {
			case JUGADOR   : printf("\nTurno: Jugador\n");  break;
			case PC        : printf("\nTurno: Maquina\n");  break;
			case JUGADOR_1 : printf("\nTurno: Jugador1\n"); break;
			case JUGADOR_2 : printf("\nTurno: Jugador2\n");
		}

		// Manejamos la entrada dependiento del jugador
		if (jugador == JUGADOR || jugador == JUGADOR_1 || jugador == JUGADOR_2) {
			// Pedimos la casilla
			printf("Fila: ");
			scanf("%i", &fila);
			getchar();

			if (fila == 0) {
				
			} else 
			if (fila == -1) {

			}

			printf("Columna: ");
			scanf("%i", &columna);
			getchar();

			if (fila < 1 || columna < 1 || fila > dimension || columna > dimension) {
				printf("\nCasilla invalida.\n");
				getchar();

				continue;
			}
		} else {
			printf("Fila: ");
			sleep(3);
			fila = rand() % dimension + 1;
			printf("%i\nColumna: ", fila);
			sleep(3);
			columna = rand() % dimension + 1;
			printf("%i", columna);
			sleep(3);
		}

		// Procesamos la lógica
		// Comprobamos la casilla y sus vecinos y barremos de arriba a abajo
		huecos = 0;
		casilla_y = fila - 1;
		casilla_x = columna - 1;
		numero = casillas[ casilla_y ][ casilla_x ];
		by;
		f = casilla_y + 1;
		c = casilla_x + 1;

		for (y = casilla_y - 1; y <= f; y++) {
			for (x = casilla_x - 1; x <= c; x++) {
				if (x < 0 || y < 0 || x > ultimo || y > ultimo) {
					continue;
				}

				if (casillas[ y ][ x ] == 0 || casillas[ y ][ x ] != numero) {
					continue;
				}

				// Barremos la columna hacia abajo
				for (by = y - 1; by >= -1; by--) {
					if (by < 0) {
						casillas[ by + 1 ][ x ] = 0;
						huecos++;
					} else {
						casillas[ by + 1 ][ x ] = casillas[ by ][ x ];
					}
				}
			}
		}

		if (jugador == JUGADOR || jugador == JUGADOR_1) {
			puntaje1 += huecos;
		} else {
			puntaje2 += huecos;
		}

		// Comprobamos si la partida terminó
		if (puntaje1 + puntaje2 == dimension * dimension) {
			return;
		}
		
		// Cambiamos de turno
		switch (jugador) {
			case JUGADOR   : jugador = PC;        ; break;
			case PC        : jugador = JUGADOR;   ; break;
			case JUGADOR_1 : jugador = JUGADOR_2; ; break;
			case JUGADOR_2 : jugador = JUGADOR_1; ;
		}
	}
}

void cls () {
	// Para borrar la pantalla en Windows y Linux
	#ifdef _WIN32
	system("cls");
	#else
	printf("\033[H\033[J");
	#endif
}

int main () {
	pc();

	return 0;
}

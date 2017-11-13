#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
	int f, c, fila, columna;

	while (1) {
		// Mostramos el estado
		cls();

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

		// Pedimos la casilla y procesamos la lógica
		printf("\nFila: ");
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

		// Comprobamos la casilla y sus vecinos y barremos de arriba a abajo
		int casilla_y = fila - 1;
		int casilla_x = columna - 1;
		int numero = casillas[ casilla_y ][ casilla_x ];
		int by;
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
					casillas[ by + 1 ][ x ] = (by < 0) ? 0 : casillas[ by ][ x ] ;
				}
			}
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

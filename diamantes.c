#include <stdio.h>
#include <stdlib.h>
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
	system("cls");
	int dimension;
	printf("Dimension: ");
	scanf("%i", &dimension);
	
	if (dimension < 4) {
		printf("El tablero debe poseer una dimension superior o igual a 4.\n");
		system("pause");

		return;
	}

	// Llenamos los valores iniciales de las casillas
	int casillas[ dimension ][ dimension ];
	int x, y;

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
		system("cls");

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

		if (fila == 0) {
			
		} else 
		if (fila == -1) {

		}

		printf("Columna: ");
		scanf("%i", &columna);

		if (fila < 1 || columna < 1 || fila > dimension || columna > dimension) {
			printf("\nCasilla invalida.\n");
			system("pause");

			continue;
		}

		// TODO: agregar lógica aquí...
	}
}

int main () {
	pc();

	return 0;
}

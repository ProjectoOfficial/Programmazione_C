#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

double** crea_matrice(int r, int h) {

	double** matrix = malloc(sizeof(double) * r * h);

	for (int i = 0; i < r; i++)
		for (int j = 0; j < h; j++)
			matrix[i * r + j] = rand();

	return matrix;
}

void show_matrix(double** matrix, int r, int h) {


	for (int i = 0; i < r; i++)
		for (int j = 0; j < h; j++) {
			printf(" %d ", matrix[i * r + j]);
			if (j + 1 == h)
				printf(" fine riga ");
		}

}

int main() {

	int righe;
	int colonne;

	printf("inserire numero righe\n");
	scanf("%d", &righe);


	printf("inserire numero colonne\n");
	scanf("%d", &colonne);

	double** m = crea_matrice(righe, colonne);
	show_matrix(m, righe, colonne);

}
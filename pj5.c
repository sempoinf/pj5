#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int main() {//вводить с 0!!!!
	int N;

	printf("Number vershin: ");
	scanf("%d", &N);

	int* a = (int*)malloc(N * sizeof(int));
	int* b = (int*)malloc(N * N * sizeof(int));

	for (int i = 0; i < N; i++)
		*(a + i) = 0;

	for (int i = 0; i < N * N; i++)
		(*(b + i)) = 0;


	int error = 0;//Работает корректно
	int i, j, c;
	c = scanf("%d-%d\n", &i, &j); // вводим граф по примеру (1-2)

	while (c != 0) {
		if (c == 2) {
			if ((i >= N) || (j >= N)) {
				printf("Vertex greater than N\n");
				exit(1);
			}

			if (i > j) {
				int buf = i;
				i = j;
				j = buf;
			}

			if (i == j) (*(b + i * N + j))++;//просто удваиваем дополнительно
			(*(b + i * N + j))++;
		}
		c = scanf("%d-%d\n", &i, &j);
	}


	for (int i = 0; i < N; i++)
		for (int j = i; j < N; j++) {
			*(b + j * N + i) = *(b + i * N + j);//копирование через главную диагональ
		}
	
	printf("\n");//вычисление степеней
	for (int i = 0; i < N; i++) {//складывать надо всю! строку, а не только один её кусок
		for (int j = 0; j < N; j++) {
			*(a + i) += *(b + i * N + j);
		}
	}
	

	int min = *(a);// *(a) значение самого первого(нулевого)
	for (int i = 0; i < N; i++) {
		if (*(a + i) < min) min = *(a + i);
	}
	printf("%d - min\n", min);

	printf("List of vertices with min degrees:\n");
	for (int i = 0; i < N; i++) {
		if (*(a + i) == min) printf("%d ", i);
	}
	printf("\n");
}

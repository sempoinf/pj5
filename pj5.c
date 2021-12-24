#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>


int main(void) {

	int knots, edge;
	
	printf("Number of your knots: ");
	if (scanf("%d", &knots) != 1)
		exit(1);
	printf("Number of your edges: ");
	if (scanf("%d", &edge) != 1)
		exit(1);

	int** graph = NULL;

	graph = (int**)malloc(edge * sizeof(int));
	if (graph == NULL)
		exit(1);
	for (int i = 0; i < edge; i++)
		graph[i] = (int*)malloc(knots * sizeof(int));

	int num = '1';

	printf("Complete array:\n  |");
	for (int i = 0; i < edge; i++)
		printf("%c ", num++);
	printf("\n");

	int num1 = '0';

	for (int i = 0; i < knots; i++) {
		printf(" %c|", num1++);
		for (int j = 0; j < edge; j++) {
			if (graph[j] == NULL)
				exit(1);
			if (scanf("%d", &graph[j][i]) != 1)
				exit(1);
		}
	}
	int* a = (int*)malloc(knots * sizeof(int));

	for (int i = 0; i < knots; i++)
		*(a + i) = 0;



	printf("\n");//вычисление степеней
	for (int i = 0; i < knots; i++) {//складывать надо всю! строку, а не только один её кусок
		int count = 0;
		for (int j = 0; j < edge; j++) {
			count += graph[j][i];
		}
		a[i] = count;
	}
	/*
	for (int i = 0; i < knots; i++) { //массив a выводим,чтобы понять какая степень вершины
		printf("%d ", *(a + i));
	}
	*/
	printf("\n");
	int min = *(a);// *(a) значение самого первого(нулевого)
	for (int i = 0; i < knots; i++) {
		if (*(a + i) < min) min = *(a + i);
	}
	printf("%d - min\n", min);//вывод min степени вершины

	printf("Edges of min levels:\n");
	for (int i = 0; i < knots; i++) {
		if (*(a + i) == min) {
			for (int j = 0; j < edge; j++) {
				if (graph[j][i] == 1) printf("%d\t", j);
			}
		}
	}
	printf("\n");
}

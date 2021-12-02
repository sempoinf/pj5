#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int main(void) {
	int N;
	printf("Введите размер квадратной матрицы\n");
	scanf("%d", &N);						//Пользователь вводит размер матрицы.
	getchar();
	int** matrix = NULL;
	matrix = (int**)malloc(sizeof(*matrix) * N);
	for (int i = 0; i < N; i++) {
		matrix[i] = (int*)malloc(sizeof(**matrix) * N);
	}

	char* s, c;

	s = (char*)malloc(sizeof(char) * CHAR_MAX);

	int i = 0, m = 0;

	for (int j = 0; j < N; j++) {

		while ((c = getchar()) != '\n') {

			if (c != ' ')
				s[m++] = c;

			else {
				s[m] = '\0';

				if (i >= N) {
					printf("Error,matrix input uncorrect!\n ");
					return -1;
				}

				matrix[i][j] = atoi(s);
				i++;
				free(s);
				s = (char*)malloc(sizeof(char) * CHAR_MAX);
				m = 0;

			}

		}

		s[m] = '\0';
		m = 0;

		if (i >= N) {
			printf("Error,matrix input uncorrect!\n ");
			return -1;
		}

		matrix[i][j] = atoi(s);

		if (i < N) {             // Замена числа на 0, если оно не введено.
			++i;
			while (i < N)
				matrix[i++][j] = 0;
		}

		i = 0;
		free(s);
		s = (char*)malloc(sizeof(char) * CHAR_MAX);
	}
	free(s);
    
    int count = 0, min = 100001,knot;
    for(i = 0; i<N;i++){
         for(j = 0; j<N;j++){
             if matrix[i][j] = 1
             count =+1;}
        if (count<=min) { min = count;  knot = i;}  
         
    }
}

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void write_dot(File* fname, int** mas, int size)
{    fprintf (fname, "graph G{\n");

    for(int i = 0; i < size; i++)
        fprintf(fname,"%d;\n", i);
    
    for(int j = 0; j < size; j++)
        for(int i = 0; i < size; i++)
            for(int k = 0; k < mass[i][j]; k++)
                 fprintf(fname,"%d;\n", i);}
    
    fprintf(fname,"}");
    fclose(fname);


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

	int i = 0, m = 0, j = 0;

	for (; j < N; j++) {

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

		free(s);
		s = (char*)malloc(sizeof(char) * CHAR_MAX);
	}
	free(s);
	
	
	File* fout;
	fout= fopen("graph.gv","w");
	write_dot(fout,mas,N);
	
    
    /*int count = 0,knot,min;
    for(i = 0; i<N;i++){
         for(int j = 0; j<N;j++){
             if (matrix[i][j] = 1)
             count =+1;}
        if (count<=min) { min = count;  knot = i;}  
         
    }*/
    
    int Top[i];
    
    for(int y;y<=i;y++){
        for(int yy;yy<=j;yy++){
        Top[y]+=matrix[y][yy];
    }
    }
    
    int MinTopRuts = 1000;
    int MinTop[5];
    int u++;
    for(int y;y<=i;y++){
        if(Top[y]<MinTopRuts){
            MinTop[0]=y;
            MinTopRuts=Top[y];
        }
    }
    for(int y; y<=i;y++){
        if(Top[y]==MinTop[0]){
            MinTop[u]=y;
            u++;
        }
    }
    int routs[1000];
    int o=0;
    for(int y;y<u;y++){
        for(int yy;yy<j;yy++)
            if(matrix[MinTop[u]][yy]){
                routs[o]=yy;
                o++;
            }
        
    }
    
    
    
  
}

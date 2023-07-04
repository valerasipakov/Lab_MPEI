#define _CRT_SECURE_NO_WARNINGS
 /*Дана матрица A из N строк и N столбцов. Если в матрице А элементы, равные нулю, встречаются
не более, чем в двух строках, задать элементам X1 , Х2, ..., ХN значения соответствующих по номеру
элементов главной диагонали.*/

#include <iostream>
#include <stdio.h>
#include "moduleHeader.h"


int main(int argc, char* argv[]){
	int** A, N, R, * C, i;
	FILE* finp, * fout;
	bool flag = true;
	R = 3;
	fout = fopen(argv[2], "w");
	finp = fopen(argv[1], "r");

	
	if (true){
		input(A, C, &N, &R, finp, fout);

		checkTheConditions(A, N, flag);

		if (flag) {
			newmass(A, C, N, flag);
		}
		vivod(A, C, N, finp, fout, flag);
		delete[] C;
		for (i = 0; i < N; i++)
		{
			delete[] A[i];
		}
		delete[] A;
		fclose(fout);
	}
	else {
		printf("File is empty");
	}
	return 0;
}



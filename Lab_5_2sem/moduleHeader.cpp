#include "moduleHeader.h"
#include <iostream>
#include <stdio.h>
using namespace std;


void input(int**& A, int*& C, int* N, int* R, FILE* finp, FILE* fout)
{
    int i, j;
    fscanf_s(finp, "%i", N);
    A = new int* [*N];
    C = new int[*N];
    for (i = 0; i < *N; i++) A[i] = new int[*N];
    for (i = 0; i < *N; i++)
    {
        for (j = 0; j < *N; j++)
        {
            fscanf_s(finp, "%i", &A[i][j]);
        }
    }
    fclose(finp);

    return;
}

bool nulInTheLine(int** A, int N, int i, bool& flag) {
    int j = 0;
    while (not flag and j < N)
    {

        if (A[i][j] == 0) {
            flag = true;
        }
        j += 1;
    }
    return flag;
}

bool is_empty( FILE* finp)
{
    return (feof(finp));
}

void checkTheConditions(int** A, int N, bool& flag)
{
    int i, counter;
    counter = 0;
    for (i = 0; i < N && counter < 3 ; i++) {
        flag = false;
        if (nulInTheLine(A, N, i, flag)) {
            counter += 1;
        }
    }
    if (counter < 3) {
        flag = true;
    }
    else
    {
        flag = false;
    }
    return;
}



void newmass(int** A, int* C, int N, bool flag)
{
    int i;

    if (flag) {

        for (i = 0; i < N; i++) {
            C[i] = A[i][i];

        }
    }
    return;
}


void vivod(int** A, int* C, int N, FILE* finp, FILE* fout, bool& flag)
{
    int i, j;

    fprintf(fout, "Лабораторная работа №5\nN=%i\n", N);
    fprintf(fout, "Исходная матрица:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            fprintf(fout, "%1i ", A[i][j]);
        }
        fprintf(fout, "\n");
    }
    if (!flag) {
        fprintf(fout, "Данные не удовлетворяют условию :(\n");
    }
    else {
        fprintf(fout, "Ответ:\n");
        fprintf(fout, "Х: ");
        for (i = 0; i < N; i++) {
            fprintf(fout, "%i ", C[i]);
        }
    }
    fprintf(fout, "\n");
    return;
}

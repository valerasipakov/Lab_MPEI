#pragma once
#include <stdio.h>

void input(int**& A, int*& C, int* N, int* R, FILE* finp, FILE* fout);

void checkTheConditions(int** A, int N, bool& flag);

bool nulInTheLine(int** A, int N, int i, bool& flag);

bool is_empty(FILE* finp);

void newmass(int** A, int* C, int N, bool flag);


void vivod(int** A, int* C, int N, FILE* finp, FILE* fout, bool& flag);

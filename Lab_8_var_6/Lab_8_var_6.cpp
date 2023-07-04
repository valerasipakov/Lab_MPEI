// Lab_8_var_6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <stdio.h> // printf, scanf
#include <conio.h> // getch
#include <math.h> // fabs, pow, ceil\floor, log, log10, exp, sqrt
#include <stdlib.h> // randomize, rand
#include <windows.h> // SetConsoleOutputCP(1251); SetConsoleCP(1251);
#include <time.h>
#include <iostream>
#include"modul.h"

void main()
{
	double ansBisection[10];
	int N, Var, i, z, k1, k2;
	double A, B;
	SetConsoleOutputCP(1251);
	srand(time(NULL));


	double(*function_var)(double x);

	bool retflag;
	getAllInfo(A, B, Var, N, retflag);
	if (retflag) return;
	fflush(stdin); // очищаем буфер (лишние символы после ввода e)

	if (Var == 6) {
		function_var = func6Var;
	}
	else
	{
		function_var = func9Var;
	}


	if (not isRootExists(A, B, function_var)) {
		printf_s("На заданном отрезке нет подходящих корней");
	}
	else {
		printf("  Функция №%d | Метод деления отрезка пополам | Метод Ньютона (касательных)\n", Var);
		printf("  Погрешность |        Корень |      Итераций |        Корень |   Итераций \n");
		printf("--------------|---------------|---------------|---------------|------------\n");
		for (int i = 1; i <= N; i++) {
			double epsilon = pow(10, -i);
			double r1 = bisectionMethod(A, B, function_var, epsilon, k1);
			double r2 = newtonMethod(A, B, function_var, epsilon, k2);
			printf("%13.*f | %13.*f | %13d | %13.*f | %11d\n", i, pow(10, -i), i, r1, k1, i, r2, k2);

		}


	}




	return;
}




// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

#include <stdio.h> // printf, scanf
#include <conio.h> // getch
#include<cmath> // fabs, pow, ceil\floor, log, log10, exp, sqrt
#include <stdlib.h> // randomize, rand
#include <windows.h> // SetConsoleOutputCP(1251); SetConsoleCP(1251);
#include <time.h>


void getAllInfo(double& A, double& B, int& Var, int& N, bool& retflag)
{
	retflag = true;
	printf_s("Введите A=? "); // приглашение – шрифт Lucida Console нужен
	scanf_s("%lf", &A);
	if (A <= 0 || A > 2) {
		printf_s("Неверно введено значение А %F  \nPress any key", A);
		_getch(); // ожидание нажатия клавиши
		return; // выход из функции main
	}
	fflush(stdin); // очищаем буфер (лишние символы после ввода e)




	printf_s("Введите B=? "); // приглашение – шрифт Lucida Console нужен
	scanf_s("%lf", &B);
	if (B < A || B >= 2) {
		printf_s("Неверно введено значение В  %F \nPress any key", B);
		_getch(); // ожидание нажатия клавиши
		return; // выход из функции main
	}
	fflush(stdin); // очищаем буфер (лишние символы после ввода e)

	printf_s("Уточните вариант (6 или 9) Met=? "); // приглашение – шрифт Lucida Console нужен
	scanf_s("%i", &Var);
	if ((Var != 6) && Var != 9) {
		printf_s("Неверно указан вариант \nPress any key");
		printf_s("%i", Var);
		_getch(); // ожидание нажатия клавиши
		return; // выход из функции main
	}

	printf_s("Введите до какой точности 1*е^-N считать N=? "); // приглашение – шрифт Lucida Console нужен
	scanf_s("%i", &N); // ввод числа с плавающей точкой двойной точности(%lf) e
	if (N < 0 || N > 10) {
		printf("Некорректная точность 1≤N≤10. \nPress any key");
		_getch(); // ожидание нажатия клавиши
		return; // выход из функции main
	}
	retflag = false;

}


double func6Var(double x) {
	double b = static_cast<double>(1) / 3;
	double a = atan(sqrt(x)) - (2 * x) + (pow(0.07, b));
	return a;
}
double func9Var(double x) {

	double c = (static_cast<double>(10) / 3) * exp(0.01 * x);
	double b = (2 * sqrt(x));
	double a = (log1p(x) + c) / b - x;
	return a;
}

bool isRootExists(double A, double B, double(*function_var)(double x)) {
	if (function_var(A) * function_var(B) > 0) {

		return false;
	}
	return true;
}

double bisectionMethod(double A, double B, double(*function_var)(double x), double epsilon, int& k1) {
	double x;
	k1 = 0;

	double varA = A;
	double varB = B;
	do {
		x = ((varA + varB) / 2);

		if (isRootExists(A, x, function_var)) {
			varB = x;
		}
		else
		{
			varA = x;
		}

		k1 += 1;
	} while ((fabs(varA - varB)) > epsilon);

	return x;
}


double newtonMethod(double A, double B, double(*function_var)(double x), double epsilon, int& k2) {
	double x1 = (A + B) / 2;
	double x = x1;
	double h = epsilon / 2;
	double df = (function_var(x1 + h) - function_var(x1)) / h;
	k2 = 0;
	bool flag = true;
	do {
		x = x1 - function_var(x1) / df;
		k2++;
		if ((fabs(x - x1)) >= epsilon) {
			x1 = x;
		}
		else
		{
			flag = false;
		}
	} while (flag);

		return x;

}

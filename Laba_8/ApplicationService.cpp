#include <stdio.h> // printf, scanf
#include <conio.h> // getch
#include <math.h> // fabs, pow, ceil\floor, log, log10, exp, sqrt
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
	double a = pow(0.07, 1 / 3);
	double b = a - (2 * x);
	double c = b +atan(sqrt(x));
	return c;
}
double func9Var(double x) {
	double a = log(x + 1); 
	double b = (10/3*exp(0.01*x));
	double c = (2 * sqrt(x) - x);
	double d = (a + b) / c;
	return d;
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


double simpleIterationMethod(double A, double B, double(*function_var)(double x), double epsilon, int& k2) {
	double x1 = (A+B)/2;
	double x2 = function_var(x1) / 2 + x1;
	k2 = 1;
	while (fabsf(x2 - x1) > epsilon) {
		x1 = x2;
		x2 = function_var(x1) / 2 + x1;
		k2 += 1;
	}
	return x2;
}


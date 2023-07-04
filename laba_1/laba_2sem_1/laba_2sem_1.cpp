//---------------------------------------------------------------------------
#include <stdio.h> // printf, scanf
#include <conio.h> // getch
#include <math.h> // fabs, pow, ceil\floor, log, log10, exp, sqrt
#include <stdlib.h> // randomize, rand
#include <windows.h> // SetConsoleOutputCP(1251); SetConsoleCP(1251);
#include <time.h>

//---------------------------------------------------------------------------
const double xx[7] = { 0.00001, -0.99, -1, -0.1, 0.1, 1, 0.99 };

#pragma argsused
void main()
{
	int n, i, k, z;
	double e, sl, sum, f, * x; // четыре простого типа и один – дин.массив(указатель)
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	printf("Введите e=? "); // приглашение – шрифт Lucida Console нужен
	scanf("%lf", &e); // ввод числа с плавающей точкой двойной точности(%lf) e
	if (e < 1e-13 || e>0.11) {
		printf("Некорректная точность e (0..0.1] \nPress any key");
		_getch(); // ожидание нажатия клавиши
		return; // выход из функции main
	}
	fflush(stdin); // очищаем буфер (лишние символы после ввода e)

	printf("Введите n=? "); // приглашение
	scanf("%d", &n); // ввод десятичного(%d) n
	if (n < 1 || n>20) {
		printf("Invalid n [1..20]! \nPress any key");
		_getch(); // ожидание нажатия клавиши
		return; // выход из функции main
	}
	fflush(stdin);

	x = new double[n]; // выделяем память для n элементов массива

	printf("Введите n=%d значений X из интервала (-1,+1):\n", n); // приглашение
	for (i = 0; i < n; i++) { // ввод x[0]...x[n-1]
		scanf("%lf", &x[i]); // типа long float (%lf)

		if (fabs(x[i]) >= 1) {
			x[i] = xx[rand() % 7]; // одно из семи значений массива xx
			if (fabs(x[i]) == 1) {
				x[i] = x[i] * (rand() % 100) / 100;
				if (x[i] == 0) x[i] = e; // для некоторых вариантов x=/=0
			}
			printf("Некорректное значение заменено на %15.10lf\n", x[i]);
		}
	}

	z = ceil(fabs(log(e) / log(10.0))) + 1;

	printf("e = %*.*lf\n", z + 2, z, e); // вывод e:(z+2):z
	printf("N | X | Sum(X) | K| F(X) | |Sum(X)-F(X)|\n");
	for (i = 1; i < 80; i++) printf("="); printf("\n");
	for (i = 0; i < n; i++) {

		// поиск суммы ряда
		sum = sl = (x[i]/6); // sl=pow(x[i],2); sum=sl; // первое слагаемое
		k = 2;
		while ((fabs(sl) >= e) && (k != 5000)) {
			sl *= -pow(x[i], 2)/ ((2 * k + 1)*2*k);
			sum += sl;

			k++;
		};

		f = (x[i] - sin(x[i]))/ pow(x[i], 2);

		printf("%2d|%17.*lf|%17.*lf|%2d|%17.*lf|%17.*lf\n",
			i + 1, z, x[i], z, sum, k, z, f, z + 2, fabs(sum - f));
	}

	delete[] x; // освобождение памяти для одномерного дин.массива

	printf("Нажмите любую клавишу - Press any key");
	_getch();
	return;
}

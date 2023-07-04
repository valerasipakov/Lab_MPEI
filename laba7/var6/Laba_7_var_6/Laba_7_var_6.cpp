// Laba_7_var_6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <windows.h>
#include <stdio.h>
#include <cmath>
#include <conio.h>
#pragma warning(disable : 4996)


struct TToy
{
    char name[31];
    int maxAge;
    int minAge;
    int price;
};

void CreateBinaryFile(int argc, char* argv[]) {
	if (argc < 3) {
		printf("Мало параметров\nPress any key");
		getchar();
		return;
	}
	FILE* ft = fopen(argv[2], "rt");
	if (ft == NULL) {
		printf("Error: не удалось открыть файл с \
исходными данными %s\n", argv[2]);
		printf("Press any key ");
		getchar();
		return;
	}
	FILE* fb = fopen(argv[1], "wb");
	if (fb == NULL) {
		fclose(ft);
		printf("Error: не удалось создать \
двоичный файл %s\n", argv[1]);
		printf("Press any key");
		getchar();
		return;
	}
	TToy toy;
	int kol = 0, nw = 1;
	while (nw) {
		fscanf(ft, "%30s", toy.name);
		// ввод слова
	   //признак конца файла - имя ** или конец файла
		if (feof(ft)) break;
		//для ввода строки из нескольких слов см.Указание выше
		fscanf_s(ft, "%d", &toy.maxAge);
		fscanf_s(ft, "%d", &toy.minAge);
		fscanf_s(ft, "%d", &toy.price);
		nw = fwrite(&Mountin, sizeof(Mountin), 1, fb);
		kol++;
	}
	if (nw != 1) printf("Error: Ошибка при записи");
	fclose(ft);
	fclose(fb);
	printf("Создан двоичный файл из %d записей", kol);
	printf("Press any key to continue");
	getchar();
	return;
}

//-------------- вторая часть: поиск в двоичном файле ----
void FindMountin(int argc, char* argv[], int maxPrice) {
	if (argc < 2) {
		printf("Мало параметров\nPress any key");

		return;
	}
	FILE* fb = fopen(argv[1], "rb");
	if (fb == NULL) {
		printf("Error: не удалось открыть двоичный \
файл %s\n", argv[1]);
		printf("Press ENTER");
		getchar();
		return;
	}

	TToy toy;
	char SUp[31];
	int kol = 0, nr = 1;
	while (nr) {
		nr = fread(&toy, sizeof(toy), 1, fb);
		if (nr > 0)
			if (toy.price > maxPrice && (toy.minAge > 4 )) {
				printf("Найденa игрушка: %s %d %d %d\n", toy.name, toy.price, toy.minAge, toy.maxAge);
				kol++;
			}
	}
	if (kol == 0)
		printf("Данные, соответствующие запросу,не найдены\n");
	else
		printf("Всего найдено: %d\n", kol);
	fclose(fb);
	printf("Press any key to continue");
	getchar();
	return;
}

//-------третья часть: корректировка в двоичном файле ----
void CorrectFile(int argc, char* argv[]) {
	if (argc < 2) {
		printf("Мало параметров\nPress any key");
		return;
	}
	FILE* fb = fopen(argv[1], "rb+");
	if (fb == NULL) {
		printf("Error: не удалось открыть двоичный файл %s\n", argv[1]);
		printf("Press ENTER");
		getchar();
		return;
	}
	TToy toy;
	int kol = 0, nr = 1, nw = 1, flag;
	nr = fread(&toy, sizeof(toy), 1, fb);
	while (nr == 1 && nw == 1) {
		printf("Считана запись:\n");
		printf("%s %d %d %d ", toy.name, toy.price, toy.minAge, toy.maxAge);
		flag = 0;
		if (toy.maxAge > 150) { toy.maxAge = 150; flag = 1; }
		if (toy.minAge < 0) { toy.minAge = 0; flag = 1; }
		if (toy.minAge - toy.maxAge < -2) { toy.maxAge = toy.maxAge +2; flag = 1; }
		if (toy.minAge - toy.maxAge < -2 && toy.maxAge + 2 > 150) { toy.minAge = toy.minAge - 4; flag = 1; }

		if (flag) {
			kol++;
			fseek(fb, 0 - sizeof(toy), SEEK_CUR);
			nw = fwrite(&toy, sizeof(toy), 1, fb);
			fseek(fb, 0, SEEK_CUR);
			printf("Сделана корректировка:\n");
			printf("%s %d %d %d \n", toy.name, toy.price, toy.minAge, toy.maxAge);
		}
		nr = fread(&Mountin, sizeof(Mountin), 1, fb);
	}
	if (kol == 0)
		printf("Ни одной корректировки\n");
	else
		printf("Всего корректировок: %d\n", kol);
	fclose(fb);
	printf("Press any key to continue");
	return;
}



void ViewFile(int argc, char* argv[]) { //Выводим на экран все записи
	if (argc < 2) {
		printf("Мало параметров\nPress any key");
		getchar();
		return;
	}
	FILE* fb = fopen(argv[1], "rb+");
	if (fb == NULL) {
		printf("Error: не удалось открыть двоичный файл %s\n", argv[1]);
		printf("Press ENTER");
		getchar();
		return;
	}
	TToy toy;
	int nr = 1;
	nr = fread(&toy, sizeof(toy), 1, fb);
	printf("Просмотр:\n");
	while (nr == 1) {
		printf("Название              |         Цена          |          Мин возраст        |      Макс возраст      |\n");
		printf("%22.s|%23.d|%29.d|%24.d", toy.name, toy.price, toy.minAge, toy.maxAge);
		printf("\n");
		nr = fread(&toy, sizeof(toy), 1, fb);
	}
	fclose(fb);
	printf("Press any key to continue");
	getchar();
	return;
}


// ------------------главная функция---------------------- -
int main(int argc, char* argv[])
{
	char ch;
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	do {
		printf("\n N - создать новый тип.файл; F - сразу поиск; \C - коррекция; \V - просмотр,  E - конец.\n Ваш выбор?");
		ch = getchar(); fflush(stdin);
		ch = toupper(ch);
		switch (ch) {
			//----------первая часть: создание двоичного из текстового
		case 'N': CreateBinaryFile(argc, argv); break;
			//-------------- вторая часть: поиск в двоичном файле ----
		case 'F': FindMountin(argc, argv); break;
			//-------четвертая часть: просмотр------------------------
		case 'C': CorrectFile(argc, argv); break;
			//-------четвертая часть: просмотр------------------------
		case 'V': ViewFile(argc, argv); break;
			//-----------выход----------------------------------------
		case 'E': return 0;
			//--------------------------------------------------------
		default:
			printf("Нет такой команды\nPress any key");
			getchar();
		}
	} while (ch != 'E');
	return 0;
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

#include <windows.h>
#include <stdio.h>
#include <cmath>
#include <conio.h>
//------------------------------------------------------------ SysUtils, Windows;
struct TMountin {
	float s, d;
	int h;
};
// ---------создание копии строки, но с символами
//---------------в верхнем регистре в Win1251
char* ANSIUpperCase(char* s, char* S) {
	S = strcpy(S, s);
	char* ch = S;
	while (*ch) {
		if (*ch >= 'a' && *ch <= 'z' || *ch >= 'а' && *ch <= 'я')
			*ch =*ch - 32;
		if (*ch == 'ё') *ch = 'Ё';
		ch++;
	}
	return S;
}
//----------первая часть: создание двоичного из текстового
void CreateBinaryFile(int argc, char* argv[]) {
	if (argc < 3) {
		printf("Мало параметров\nPress any key");
		getch();
		return;
	}
	FILE* ft = fopen(argv[2], "rt");
	if (ft == NULL) {
		printf("Error: не удалось открыть файл с \
исходными данными %s\n", argv[2]);
		printf("Press any key "); getch();
		return;
	}
	FILE* fb = fopen(argv[1], "wb");
	if (fb == NULL) {
		fclose(ft);
		printf("Error: не удалось создать \
двоичный файл %s\n", argv[1]);
		printf("Press any key"); getch();
		return;
	}
	TMountin Mountin; // либо struct TMountin Mountin; в С
	int kol = 0, nw = 1;
	char s[3];
	while (nw) {
		fscanf(ft, "%30s", Mountin.d); // ввод слова
		//признак конца файла - фамилия ** или конец файла
		if (feof(ft)) break;
		//для ввода строки из нескольких слов см.Указание выше
		fscanf(ft, "%30s", Mountin.s);
		fscanf(ft, "%30s", Mountin.h);
		nw = fwrite(&Mountin, sizeof(Mountin), 1, fb);
		kol++;
	}
	if (nw != 1) printf("Error: Ошибка при записи");
	fclose(ft);
	fclose(fb);
	printf("Создан двоичный файл из %d записей \
по %d байт\n", kol, sizeof(TMountin));
	printf("Press any key to continue");
	getch();
	return;
}
//-------------- вторая часть: поиск в двоичном файле ----
void FindMountin(int argc, char* argv[]) {
	if (argc < 2) {
		printf("Мало параметров\nPress any key");
		getch();
		return;
	}
	FILE* fb = fopen(argv[1], "rb");
	if (fb == NULL) {
		printf("Error: не удалось открыть двоичный \
файл %s\n", argv[1]);
		printf("Press ENTER");
		getch();
		return;
	}

	TMountin Mountin;
	char SUp[31];
	int kol = 0, nr = 1;
	while (nr) {
		nr = fread(&Mountin, sizeof(Mountin), 1, fb);
		if (nr > 0)
			if (Mountin.h > 3000 && (abs(Mountin.d) < 180) && (abs(Mountin.d) < 180)) {
				printf("Найденa гора:  %s %s %s\n", Mountin.h, Mountin.d, Mountin.s);
				kol++;
			}
	}
	if (kol == 0)
		printf("Данные, соответствующие запросу,не найдены\n");
	else
		printf("Всего найдено: %d\n", kol);
	fclose(fb);
	printf("Press any key to continue");
	getch();
	return;
}

	//-------третья часть: корректировка в двоичном файле ----
	void CorrectFile(int argc, char* argv[]){
		if (argc < 2) {
			printf("Мало параметров\nPress any key");
			getch();
			return;
		}
		FILE* fb = fopen(argv[1], "rb+");
		if (fb == NULL) {
			printf("Error: не удалось открыть двоичный файл %s\n",argv[1]);
			printf("Press ENTER");
			getch();
			return;
		}
		TMountin Mountin;
		int kol = 0, nr = 1, nw = 1, flag;
		nr = fread(&Mountin, sizeof(Mountin), 1, fb);
		while (nr == 1 && nw == 1) {
			printf("Считана запись:\n");
			printf("%25s%20s%25s%2d%2d%2d\n", Mountin.h, Mountin.d, Mountin.s);
			flag = 0;
			if (Mountin.h > 8846) { Mountin.h = 8846; flag = 1; }
			if (abs(Mountin.d) > 180) { Mountin.d = fmod(Mountin.d, 180); flag = 1; }
			if (abs(Mountin.s) > 90) { Mountin.s = fmod(Mountin.s, 90); flag = 1; }
			if (Mountin.h < 0) { Mountin.h = 8846; flag = 1; }
			if (flag) {
				kol++;
				fseek(fb, 0 - sizeof(Mountin), SEEK_CUR);
				nw = fwrite(&Mountin, sizeof(Mountin), 1, fb);
				fseek(fb, 0, SEEK_CUR);
				printf("Сделана корректировка:\n");
				printf("%25s%20s%25s%2d%2d%2d\n", Mountin.h, Mountin.d, Mountin.s);
			}
			nr = fread(&Mountin, sizeof(Mountin), 1, fb);
		}
		if (kol == 0)
			printf("Ни одной корректировки\n");
		else
			printf("Всего корректировок: %d\n", kol);
		fclose(fb);
		printf("Press any key to continue");
		getch();
		return;
	}

	// ------------------главная функция---------------------- -
		int main(int argc, char* argv[])
	{
		char ch;
		SetConsoleOutputCP(1251);
		SetConsoleCP(1251);
		do {
			printf("\nN - создать новый тип.файл; F - сразу поиск;\
C - коррекция; \V - просмотр,  E - конец.\nВаш выбор?");
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

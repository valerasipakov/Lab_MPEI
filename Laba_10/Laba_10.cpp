#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

struct Stack {
	char word[30];
	Stack* pNext;
};

Stack Stack[club56642267 | *top_element, char* word];
char* pop(Stack** top_element);
void TopToTop(Stack** stack1, Stack** stack2);
Stack* Create_Stack(Stack* stack, char* argv);

void Output_Stack(Stack*& stack);
Stack* ClearStack(Stack* stack);

//Добавление элемента в стек
Stack Stack[club56642267 | *top_element, char* word]
{
Stack * push_element = new Stack;
strcpy(push_element->word, word);
push_element->pNext = top_element;
return push_element;
}

//Удаление элемента из стека и возврат его значения
char* pop(Stack** top_element)
{
	Stack* delete_element = *top_element;
	char info[30];
	strcpy(info, delete_element->word);
	*top_element = delete_element->pNext;
	delete delete_element;
	return info;
}

//Из одного стека в другой
void TopToTop(Stack** stack1, Stack** stack2)
{
	Stack* st, * stTop = *stack1, * stDop = *stack2;
	st = stTop;
	stTop = stTop->pNext;
	st->pNext = stDop;
	stDop = st;
	*stack1 = stTop;
	*stack2 = stDop;
	return;
}

Stack* Create_Stack(Stack* stack, char* argv)
{
	FILE* fin = fopen(argv, "r");
	if (!fin) {
		printf("Ошибка открытия первого входного файла\n");
		return NULL;
	}
	char* n;
	char info[30];
	int count = 0;
	while (true) {
		fgets(info, 30, fin);
		fflush(fin);
		n = strchr(info, '\n');
		if (n) *n = '\0';
		if (feof(fin)) {
			break;
		}
		stack = push(stack, info);
		count++;
	}
	printf("Создан стек из %d элементов\n", count);
	fclose(fin);
	return stack;
}

//Вывод стека в консоль
void Output_Stack(Stack*& stack)
{
	Stack* Dop = nullptr;
	char info[30];
	if (!stack) {
		printf("Пустой\n");
	}
	while (stack) {
		strcpy(info, pop(&stack));
		printf("%s\n", info);
		Dop = push(Dop, info);
	}
	while (Dop) {
		TopToTop(&Dop, &stack);
	}
	return;
}

//char ANSIUpperCase(char s) {
// if (s >= 'a' && s <= 'z' || s >= 'а' && s <= 'я')
// s = s - 32;
// if (s == 'ё')
// s = 'Ё';
// return s;
//}

//Очищение стека
Stack* ClearStack(Stack* stack)
{
	while (stack) {
		pop(&stack);
	}
	return stack;

}
int FindSize(char* str)
{
	int size = 0;
	for (; str[size] != '\0'; size++);
	return size;
}

//Решение
Stack Stack** PSt1, Stack** PSt2, Stack* StSolution
{
Stack * St1 = *PSt1, *St2 = *PSt2, *Dop1 = NULL, *Dop2 = NULL;
StSolution = ClearStack(StSolution);

//isalpha(g)//если латиница истина
char info[30];
int N1 = 0, N2 = 0;
while (St1 || St2) {
bool flag1 = true;
bool flag2 = true;

if (St1 != NULL) {
while (flag1 && St1 != NULL) {
strcpy(info, St1->word);
N1 = FindSize(info);
printf("%d %d %d %d %s\n",N1, info[0],info[1],info[N1 - 1], info);
if (toupper(info[0]) == toupper(info[N1 - 1])) {
StSolution = push(StSolution, St1->word);
flag1 = false;
}
TopToTop(&St1, &Dop1);
}
}



if (St2 != NULL) {
while (flag2 && St2 != NULL) {
	// strcpy(info, St2->word);
	N2 = FindSize(St2->word);
	if (toupper(St2->word[0]) == toupper(St2->word[N2 - 1])) {
	StSolution = push(StSolution, St2->word);
	flag2 = false;
	}
	TopToTop(&St2, &Dop2);
	}
	}

	}

	while (Dop1) {
	TopToTop(&Dop1, &St1);
	}
	while (Dop2) {
	TopToTop(&Dop2, &St2);
	}
	printf("success\n");
	*PSt1 = St1;
	*PSt2 = St2;
	return StSolution;

}

int main(int argc, char* argv[]) {
	char ch;
	Stack* stack_One = NULL, * stack_Two = NULL, * stac_Solution = NULL;
	setlocale(LC_ALL, "RU");

	do {

		printf("\nN - создать новый стек; \nV - просмотр; \nS - решение; \nС - очистить; \
\nE - конец.\nВаш выбор?\n");

		ch = getchar(); fflush(stdin);
		ch = toupper(ch);
		switch (ch) {
		case 'N':
			if (argc < 3) {
				printf("Недостаточно аргументов вызова\n");
				break;
			}
			if (stack_One || stack_Two) {
				printf("Error: сначала надо освободить память!");
				break;
			}

			stack_One = Create_Stack(stack_One, argv[1]);
			stack_Two = Create_Stack(stack_Two, argv[2]);
			break;
		case 'V':
			printf("Первый стек:\n");
			Output_Stack(stack_One);
			printf("\nВторой стек:\n");
			Output_Stack(stack_Two);
			printf("\nCТЕК С ОТВЕТОМ: \n");
			Output_Stack(stac_Solution);
			break;
		case 'C':
			stack_One = ClearStack(stack_One);
			stack_Two = ClearStack(stack_Two);
			stac_Solution =
				ClearStack(stac_Solution);
			printf("Вся память под стеки особождена\n");
			break;
		case 'S':
			stac_Solution = Solution(&stack_One, &stack_Two, stac_Solution);

			break;

		case 'E':
			return 0;
		default:
			printf("Нет такой команды\n");

		}

	} while (ch != 'E');

	return 0;
}
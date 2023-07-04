// Labar_9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
struct answer
{
    int min;
    int numb;
};

void importData(int& N, int* B, FILE* fp)
{
    int c = 0;
    for (int i = 0; i < N; i++) {
        fscanf_s(fp, "%d", &B[i]);
    }
}

answer findMinRecursion(int arr[], int i, int j) {
    int mid = (int)(i + j) / 2;

    if (i == j) {
        answer ans;
        ans.min = arr[i];
        ans.numb = i;
        return ans;
    }
    else
    {
        answer firstHalf = findMinRecursion(arr, i, mid);
        answer secondHalf = findMinRecursion(arr, mid + 1, j);

        if (abs(firstHalf.min) < abs(secondHalf.min)) {
            return firstHalf;
        }
        else {
            return secondHalf;
        }


    }
}


void writeAns(answer answ, FILE* fr) {
    fprintf_s(fr, "Минимальный квадрат из дает число: %d, в массиве оно находиться под индексом: %d", answ.min, answ.numb);

}


int main()
{

    FILE* fr;
    FILE* fp;

    fopen_s(&fp, "input.txt", "r");
    if (fp == NULL) {
        printf_s("Can't open input.txt");
        return 0;
    }
    fopen_s(&fr, "answer.txt", "w");
    int N;
    fscanf_s(fp, "%d", &N);
    int* B = new int[N];

    importData(N, B, fp);

    answer answ = findMinRecursion(B, 0, N-1);

    writeAns(answ, fr);

    fclose(fr);
    fclose(fp);
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
